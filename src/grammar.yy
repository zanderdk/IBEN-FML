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

%{
#include <cstdlib>
#include <cstdio>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "iben.h"

//#include "unistd.h"

extern int yylex();
extern char **environ;

void yyerror(const char *s)
{
  if (interactive)
    fprintf(stderr, "Error: %s\n", s);
  else
    fprintf(stderr, "Error: %s at line %d\n", s, line_number);
}

extern "C" {
int yywrap(void)
{
  return (1);
}
}
%}


%union
{
    st_entry *e;
    bdd *f;
    long i;
    bddPair *p;
    char *s;
}


%token T_UNKNOWNCHAR
%token <e> T_ID T_NEWID
%token <i> T_NUM
%token T_CLEAR T_ALL
%token T_LIMIT
%token T_PRINT
%token T_SHOW
%token T_PRINTSOP
%token T_SATISFY
%token T_SATCOUNT
%token T_SIZE
%token T_STATS
%token T_TIMER T_OFF
%token T_VARS
%token T_AGETS
%token T_GETS
%token T_EXISTS
%token T_FORALL
%token T_SUBST
%token T_QUIT
%token T_HELP
%token T_IMPLIES
%token T_NONE
%token T_VERSION
%nonassoc '?'
%nonassoc ':'
%nonassoc '['
%left '^'
%left '|'
%left '&'
%left T_IMPLIES
%nonassoc '='
%nonassoc '!'


%type <e> newid
%type <f> expr
%type <f> expraux
%type <i> var
%type <p> pairs pairsvar

%start file


%%


file
:
file ';' command
|
command
;

command
:
assignment
|
clear
|
/*funcprofile
|
gc
|*/
limit
|
print
|
show
|/*
printsop
|
profile
|
reorder
|
satisfysupport
|
satisfyfraction
|*/
satisfy
|
size
|
/*stats*/
|
timer
|
vars
|
satcount
|
help
|
T_VERSION
{
    print_version();
}
|
T_QUIT
{
    terminated = true;
}
;

help:
T_HELP
{
    int pid;
    int i;
    if ( (pid = fork()) == 0) { 
	execl("/bin/sh", "sh", "-c", "man iben", NULL); 
	perror("iben"); 
	exit(1);
    }
    do { i = wait(0); } while (i != -1 && i != pid);
};

assignment
:
newid T_GETS '[' pairs ']'
{
  $1->free();
  $1->type = VARASSOC;
  $1->info.varassoc.p = $4;
}
|
newid T_GETS expr
{
  $1->type = EXPR;
  $1->info.expr.f=*$3;
  delete $3;
}
;


expr
:
expraux
{
  if ($1)
    $$=$1;
  else
    {
      yyerror("node limit exceeded");
      YYERROR;
    }
};


expraux
:
T_NEWID
{
  yyerror(undefined($1->id.c_str()));
  YYERROR;
}
|
T_ID
{
  if ($1->type == VAR) {
      $$=new bdd(bdd_ithvar($1->info.var));
  } else if ($1->type == EXPR) {
      $$ = new bdd($1->info.expr.f);
  } else {
      yyerror("expression expected");
      YYERROR;
  }
}
|
'0'
{
  $$= new bdd(bddfalse);
}
|
'1'
{
  $$= new bdd(bddtrue);
}
|
'(' expraux ')'
{
  $$=$2;
}
|
/*expraux '[' var T_GETS expraux ']'
{
  $$=bdd_compose(bddm, $1, $3, $5);
  bdd_free(bddm, $1);
  bdd_free(bddm, $5);
}
|
expraux '?' expraux ':' expraux
{
  $$=bdd_ite(bddm, $1, $3, $5);
  bdd_free(bddm, $1);
  bdd_free(bddm, $3);
  bdd_free(bddm, $5);
}
|*/
expraux T_IMPLIES expraux
{
    $$ = new bdd(*$1 >> *$3);
    delete $1;
    delete $3;
}
|
expraux '&' expraux
{
  $$= new bdd(*$1 & *$3);
  delete $1;
  delete $3;
}
|
expraux '|' expraux
{
  $$= new bdd(*$1 | *$3);
  delete $1;
  delete $3;
}
|
expraux '^' expraux
{
  $$= new bdd(*$1 ^ *$3);
  delete $1;
  delete $3;
}
|
expraux '=' expraux
{
  $$= new bdd (!(*$1 ^ *$3));
  delete $1;
  delete $3;
}
|
'!' expraux
{
  $$= new bdd(!*$2);
  delete $2;
}
|
T_EXISTS expraux '(' expraux ')' 
{
    $$ = new bdd(bdd_exist(*$4, *$2));
    delete $2;
    delete $4;
} 
| 
T_FORALL expraux '(' expraux ')' 
{
    $$ = new bdd(bdd_forall(*$4, *$2));
    delete $2;
    delete $4;
} 
|
T_SUBST '[' pairs ']' '(' expraux ')'
{
    $$ = new bdd(bdd_replace(*$6, $3));
    bdd_freepair($3);
    delete $6;
}
|
T_SUBST pairsvar '(' expraux ')'
{
    $$ = new bdd(bdd_replace(*$4, $2));
    delete $4;
};

pairs  
:
pairs var '/' var
{
    bdd_setpair($1, $4, $2);
    $$ = $1;
}
|
{
    $$ = bdd_newpair();
};

pairsvar
:
T_NEWID
{
    yyerror(undefined($1->id.c_str()));
    YYERROR;
}
|
T_ID
{
    if ($1->type != VARASSOC) {
	yyerror("Association reference expected");
	YYERROR;
    }
    $$=$1->info.varassoc.p;
};

var
:
T_NEWID
{
  yyerror(undefined($1->id.c_str()));
  YYERROR;
}
|
T_ID
{
    if ($1->type != VAR) {
	yyerror("Variable reference expected");
	YYERROR;
    }
    $$=$1->info.var;
};

satcount:
T_SATCOUNT expr
{
    printf("%.0f satisfying assignments\n", bdd_satcount(*$2));
    delete $2;
};

satisfy:
T_SATISFY expr
{
    bdd f;
    if (*$2 == bddfalse)
	printf("Expression has no satisfying assignments\n");
    else 
	print_sat(*$2);
    delete $2;
};

clear
:
T_CLEAR T_ALL 
{
  symbol_table.clear();
  name_table.clear();
}
|
T_CLEAR clearIds
{
  // Nothing to do
};


clearIds
:
clearIds T_ID
{
  symbol_table.erase(symbol_table.find($2->id));
}
| T_ID
{
  symbol_table.erase(symbol_table.find($1->id));
};

limit
:
T_LIMIT T_NUM
{
    bdd_setmaxnodenum($2);
}
|
T_LIMIT T_NONE 
{
    bdd_setmaxnodenum(0);
};


print 
:
T_PRINT expr
{
    bdd_printset(*$2);
    printf("\n");
    delete $2;
};

show 
: 
T_SHOW expr 
{ 
    FILE *stream; 
    char cmd[128];
    int pid = getpid();
    snprintf(cmd, 128, "dot -Tps -Gcenter=1 -Gsize=\"7,10\" > /tmp/iben%ld.ps", pid);
    stream = popen(cmd, "w"); 
    if (stream == NULL) { 
	fprintf(stderr, "Could not open external process\n"); 
	YYERROR;
    }
    printdot(stream, *$2);
    delete $2;
    pclose(stream); 

    snprintf(cmd, 128, PSV" /tmp/iben%ld.ps; rm /tmp/iben%ld.ps", pid, pid); 
    if (!fork()) { 
	printf("executing "PSV" \n"); 
	execl("/bin/sh", "sh", "-c", cmd, NULL); 
	perror("iben"); 
	exit(1);
    } 
};

size
:
T_SIZE expr
{
    printf("%d nodes\n", bdd_nodecount(*$2));
    delete $2;
};

timer
:
T_TIMER T_OFF
{
  double user_time, system_time;

  if (!timer_running)
    puts("Timer is already off");
  else
    {
      get_cpu_time(&user_time, &system_time);
      user_time-=user_start;
      system_time-=system_start;
      printf("%g user, %g system since timer started\n", user_time, system_time);
      printf("%g user, %g system since last timer command\n", user_time-user_last, system_time-system_last);
      timer_running=false;
    }
}
|
T_TIMER
{
  double user_time, system_time;

  get_cpu_time(&user_time, &system_time);
  if (!timer_running)
    {
      user_start=user_time;
      system_start=system_time;
      user_last=0.0;
      system_last=0.0;
      timer_running=true;
      puts("Timer started");
    }
  else
    {
      user_time-=user_start;
      system_time-=system_start;
      printf("%g user, %g system since timer started\n", user_time, system_time);
      printf("%g user, %g system since last timer command\n", user_time-user_last, system_time-system_last);
      user_last=user_time;
      system_last=system_time;
    }
};

vars
:
T_VARS vardecls
{
};

newid
:
T_NEWID
{
  $$ = $1;
}
|
T_ID
{
  $1->free();
  $$ = $1;
};

vardecls
:
vardecls newid
{
    int i = bdd_extvarnum(1);
    if (i >= 0) {
	$2->info.var = i;
	$2->type = VAR;
	name_table[i] = $2->id;
    } else {
	yyerror("node limit exceeded");
	YYERROR;
    }
}
|
{
};


%%

