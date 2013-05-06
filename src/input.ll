/*
 * IBEN, An Interactive BDD Environment
 * Copyright (C) 2003 Gerd Behrmann
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

%x incl

%{
#include "iben.h"
#include "grammar.h"

using std::map;
using std::string;

void parse(const char *s)
{
    YY_BUFFER_STATE buffer;
    buffer = yy_scan_string(s);
    yyparse();
    yy_delete_buffer(buffer);
}

/* Strips surrounding quotes and converts double quotes 
 * to single quotes. A pointer to the resulting string 
 * is returned.
 */
char *strip_quotes(const char *s)
{
        char *newstr; /* Pointer to newly allocated string */
        char *q;      /* Pointer to tail of newly allocated string */

        q = newstr = (char*)malloc(strlen(s) - 1);
        s++;
        while(*s){
                if (*s == '"') {
                        s++;
                        if (*s == '"'){
                                *q = *s;
                                q++;
                                s++;
                        }
                } else {
                        *q = *s;
                        q++;
                        s++;
                }
        }
        *q = '\0';
        return newstr;
}

#define MAX_INCLUDE_DEPTH 10
YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH];
int linenum_stack[MAX_INCLUDE_DEPTH];
int include_stack_ptr = 0;
int interact;
%}

TEXT            \"([^\"]|\"\")*\"

%%


[ \t\f]		{ ; }
\n		{ ++line_number; }
"--".*\n	{ ++line_number; }
";"		{ return (';'); }
"("		{ return ('('); }
")"		{ return (')'); }
":="		{ return (T_GETS); }
"[="		{ return (T_AGETS); }
"=>"		{ return (T_IMPLIES); }
"="		{ return ('='); }
"&"		{ return ('&'); }
"*"		{ return ('&'); }
"|"		{ return ('|'); }
"+"		{ return ('|'); }
"^"		{ return ('^'); }
"/"		{ return ('/'); }
"!"		{ return ('!'); }
"~"		{ return ('!'); }
"["		{ return ('['); }
"]"		{ return (']'); }
"0"		{ return ('0'); }
"1"		{ return ('1'); }
"?"		{ return ('?'); }
":"		{ return (':'); }

[0-9]+ {
  sscanf(yytext, "%ld", &yylval.i);
  return (T_NUM);
}

"load" BEGIN(incl);

<incl>[ \t]*

<incl>{TEXT} {
  if (include_stack_ptr >= MAX_INCLUDE_DEPTH) {
    if (include_stack_ptr > 0) {
      include_stack_ptr = 0;
      interactive = interact;
    }
    BEGIN(INITIAL);
    yyerror("Includes nested too deaply");
    yyterminate();
  }

  char *fname = strip_quotes(yytext);
  yyin = fopen(fname, "r");
  free(fname);
  if (!yyin) {
    if (include_stack_ptr > 0) {
      include_stack_ptr = 0;
      interactive = interact;
    }
    BEGIN(INITIAL);
    yyerror("File not found");
    yyterminate();
  }

  if (include_stack_ptr == 0)
      interact = interactive;
  interactive = false;
  
  linenum_stack[include_stack_ptr] = line_number;
  include_stack[include_stack_ptr] = YY_CURRENT_BUFFER;
  include_stack_ptr++;
  line_number = 0;
  yy_switch_to_buffer(
    yy_create_buffer(yyin, YY_BUF_SIZE));
  BEGIN(INITIAL);
}

<incl>. {
  BEGIN(INITIAL);
  if (include_stack_ptr > 0) {
    include_stack_ptr = 0;
    interactive = interact;
  }
  yyerror("file name expected");
  yyterminate();
}

<<EOF>> {
  if ( --include_stack_ptr < 0 ){
    yyterminate();
  } else {
    yy_delete_buffer( YY_CURRENT_BUFFER );
    yy_switch_to_buffer(include_stack[include_stack_ptr] );
    line_number = linenum_stack[include_stack_ptr];
    if (include_stack_ptr == 0)
	interactive = interact;
  }
}  

[-.A-Za-z0-9_$%#@\<>]* {
  if (keywords.find(yytext) != keywords.end()) 
    return keywords[yytext];

  map<string,st_entry>::iterator i = symbol_table.find(yytext);
  if (i == symbol_table.end()) 
    {
      st_entry &entry = symbol_table[yytext];
      entry.type = NEW;
      entry.id = yytext;
      yylval.e = &entry;
      return (T_NEWID);
    }
  yylval.e = &i->second;
  return (yylval.e->type == NEW ? T_NEWID : T_ID);
}

.		{ return (T_UNKNOWNCHAR); }


