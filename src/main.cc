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

#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>
#include "config.h"

#include <sys/resource.h>

extern "C" {
#ifdef HAVE_LIBREADLINE
#  if defined(HAVE_READLINE_READLINE_H)
#    include <readline/readline.h>
#  elif defined(HAVE_READLINE_H)
#    include <readline.h>
#  else /* !defined(HAVE_READLINE_H) */
extern char *readline ();
#  endif /* !defined(HAVE_READLINE_H) */
char *cmdline = NULL;
#else /* !defined(HAVE_READLINE_READLINE_H) */
#error "IBEN requires readline to compile"
#endif /* HAVE_LIBREADLINE */

#ifdef HAVE_READLINE_HISTORY
#  if defined(HAVE_READLINE_HISTORY_H)
#    include <readline/history.h>
#  elif defined(HAVE_HISTORY_H)
#    include <history.h>
#  else /* !defined(HAVE_HISTORY_H) */
extern void add_history ();
extern int write_history ();
extern int read_history ();
#  endif /* defined(HAVE_READLINE_HISTORY_H) */
  /* no history */
#endif /* HAVE_READLINE_HISTORY */
}

#ifdef NEW
#undef NEW
#endif
#include "iben.h"
#include "grammar.h"

using std::map;
using std::string;
using std::set;

extern int getrusage(int, struct rusage *);

bool terminated = false;
bool interactive = true;
bool timer_running = false;
int line_number;
map<string,st_entry> symbol_table;
map<int,string> name_table;
map<string,int> keywords;
double user_start;
double system_start;
double user_last;
double system_last;

const char *undefined(const char *id)
{
    static char buff[1000];
    snprintf(buff, 1000, "`%s' undefined", id);
    return buff;
}

static void make_keyword(const char *word, int code)
{
  keywords[word] = code;
}

void init_tables()
{
    make_keyword("clear", T_CLEAR);
    make_keyword("all", T_ALL);
    make_keyword("help", T_HELP);
    make_keyword("limit", T_LIMIT);
    make_keyword("print", T_PRINT);
    make_keyword("show", T_SHOW);
    make_keyword("none", T_NONE);
    make_keyword("satisfy", T_SATISFY);
    make_keyword("size", T_SIZE);
    make_keyword("sop", T_PRINTSOP);
    make_keyword("stats", T_STATS);
    make_keyword("timer", T_TIMER);
    make_keyword("off", T_OFF);
    make_keyword("vars", T_VARS);
    make_keyword("exists", T_EXISTS);
    make_keyword("forall", T_FORALL);
    make_keyword("subst", T_SUBST);
    make_keyword("quit", T_QUIT);
    make_keyword("satcount", T_SATCOUNT);
    make_keyword("version", T_VERSION);
}

st_entry::~st_entry()
{
    free();
}

void st_entry::free()
{
    switch (type)
    {
    case EXPR:
    case VAR:
      info.expr.f = bddfalse;
      break;
    case VARASSOC:
      bdd_freepair(info.varassoc.p);
      break;
    }
    type = NEW;
}

void get_cpu_time(double *user, double *system)
{
    struct rusage resources;

    getrusage(RUSAGE_SELF, &resources);
    *user=resources.ru_utime.tv_sec+resources.ru_utime.tv_usec/1.0e6;
    *system=resources.ru_stime.tv_sec+resources.ru_stime.tv_usec/1.0e6;
}

static const char *getname(int var)
{
  return name_table[var].c_str();
}

void print_sat(bdd r)
{
  bdd sat = bdd_satone(r);
  bdd_printset(r);
  printf("\n");
}

static set<int> visited;

static void printdot_rec(FILE* ofile, bdd b)
{
    if (b == bdd_false() || b == bdd_true()
	|| visited.find(b.id()) != visited.end())
    {
	return;
    }

    fprintf(ofile, "%d [label=\"%s\"];\n",
	    b.id(), getname(bdd_var(b)));
    if (bdd_low(b) != bdd_false())
	fprintf(ofile, "%d -> %d [style=dotted];\n", b.id(), bdd_low(b).id());
    if (bdd_high(b) != bdd_false())
	fprintf(ofile, "%d -> %d [style=filled];\n", b.id(), bdd_high(b).id());

    visited.insert(b.id());
   
    printdot_rec(ofile, bdd_low(b));
    printdot_rec(ofile, bdd_high(b));
}

void printdot(FILE* ofile, bdd r)
{
    visited.clear();
    fprintf(ofile, "digraph G {\n");
    fprintf(ofile, "preroot[style=invis]\n");
    if (r != bdd_false()) fprintf(ofile, "preroot->%d\n", r.id());
    fprintf(ofile, "1 [shape=box, label=\"1\", style=filled, shape=box, height=0.3, width=0.3];\n");

    printdot_rec(ofile, r);

    fprintf(ofile, "}\n");
}

static void print_copyright()
{
    printf("IBEN version 1.1, Copyright (C) 1998,2003 Gerd Behrmann\n");
    printf("IBEN comes with ABSOLUTELY NO WARRANTY\n");
    printf("This is free software, and you are welcome to redistribute it\n");
    printf("under the conditions of the GPL.\n\n");
}

void print_version()
{
  printf("IBEN version 1.1, Copyright (C) 1998,2003 Gerd Behrmann\n");
  printf("Compiled %s %s", __DATE__, __TIME__);
#ifdef __GNUC__    
  printf(" with GCC %s", __VERSION__);
#endif
  printf("\n\n");
}

int main(int argc, char **argv)
{
  char *s;
  print_copyright();
    
    bdd_init(100000, 20000);
    rl_bind_key ('\t', rl_insert);
    init_tables();
    line_number = 1;

    terminated = false;
    while (!terminated) {
	s = readline("iben> ");
	if (s == NULL)
	  break;
	if (*s) {
#ifdef HAVE_READLINE_HISTORY
	  add_history(s);
#endif
	  parse(s);
	}
	free(s);
    }
    printf("\n");
    return (0);
}
