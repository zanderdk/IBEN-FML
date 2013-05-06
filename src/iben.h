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

#ifndef __IBEN_H_
#define __IBEN_H_

#include <map>
#include <string>

#include <bdd.h>
#include <string.h>

#define EXPR 1
#define VARASSOC 2
#define NEW 3
#define VAR 4

struct st_entry
{
    int type;
    std::string id;
    struct {
	struct
	{
	    bdd f;
	} expr;
	struct
	{
	    bddPair *p;
	} varassoc;
	int var;
    } info;
  ~st_entry();
  void free();
};

extern bool terminated;
extern bool interactive;
extern bool timer_running;
extern int line_number;
extern std::map<std::string,st_entry> symbol_table;
extern std::map<int,std::string> name_table;
extern std::map<std::string,int> keywords;
extern double user_start;
extern double system_start;
extern double user_last;
extern double system_last;

extern void printdot(FILE*, bdd);
extern void print_sat(bdd);
extern const char *undefined(const char *);

extern void get_cpu_time(double *, double *);
extern int yyparse();
extern void parse(const char *);
extern void yyerror(const char *);
extern void print_version();

#endif
