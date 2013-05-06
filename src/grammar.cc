/* A Bison parser, made from grammar.yy
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	T_UNKNOWNCHAR	257
# define	T_ID	258
# define	T_NEWID	259
# define	T_NUM	260
# define	T_CLEAR	261
# define	T_ALL	262
# define	T_LIMIT	263
# define	T_PRINT	264
# define	T_SHOW	265
# define	T_PRINTSOP	266
# define	T_SATISFY	267
# define	T_SATCOUNT	268
# define	T_SIZE	269
# define	T_STATS	270
# define	T_TIMER	271
# define	T_OFF	272
# define	T_VARS	273
# define	T_AGETS	274
# define	T_GETS	275
# define	T_EXISTS	276
# define	T_FORALL	277
# define	T_SUBST	278
# define	T_QUIT	279
# define	T_HELP	280
# define	T_IMPLIES	281
# define	T_NONE	282
# define	T_VERSION	283

#line 20 "grammar.yy"

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

#line 52 "grammar.yy"
#ifndef YYSTYPE
typedef union
{
    st_entry *e;
    bdd *f;
    long i;
    bddPair *p;
    char *s;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		99
#define	YYFLAG		-32768
#define	YYNTBASE	45

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 283 ? yytranslate[x] : 66)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,     2,     2,     2,    35,     2,
      42,    43,     2,     2,     2,     2,     2,    44,    40,    41,
       2,     2,     2,     2,     2,     2,     2,     2,    31,    38,
       2,    36,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    39,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     4,     6,     8,    10,    12,    14,    16,    18,
      20,    21,    23,    25,    27,    29,    31,    33,    35,    41,
      45,    47,    49,    51,    53,    55,    59,    63,    67,    71,
      75,    79,    82,    88,    94,   102,   108,   113,   114,   116,
     118,   120,   122,   125,   128,   131,   134,   137,   139,   142,
     145,   148,   151,   154,   157,   159,   162,   164,   166,   169
};
static const short yyrhs[] =
{
      45,    38,    46,     0,    46,     0,    48,     0,    56,     0,
      58,     0,    59,     0,    60,     0,    55,     0,    61,     0,
       0,    62,     0,    63,     0,    54,     0,    47,     0,    29,
       0,    25,     0,    26,     0,    64,    21,    32,    51,    39,
       0,    64,    21,    49,     0,    50,     0,     5,     0,     4,
       0,    40,     0,    41,     0,    42,    50,    43,     0,    50,
      27,    50,     0,    50,    35,    50,     0,    50,    34,    50,
       0,    50,    33,    50,     0,    50,    36,    50,     0,    37,
      50,     0,    22,    50,    42,    50,    43,     0,    23,    50,
      42,    50,    43,     0,    24,    32,    51,    39,    42,    50,
      43,     0,    24,    52,    42,    50,    43,     0,    51,    53,
      44,    53,     0,     0,     5,     0,     4,     0,     5,     0,
       4,     0,    14,    49,     0,    13,    49,     0,     7,     8,
       0,     7,    57,     0,    57,     4,     0,     4,     0,     9,
       6,     0,     9,    28,     0,    10,    49,     0,    11,    49,
       0,    15,    49,     0,    17,    18,     0,    17,     0,    19,
      65,     0,     5,     0,     4,     0,    65,    64,     0,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   110,   112,   117,   119,   121,   127,   129,   131,   143,
     145,   147,   149,   151,   153,   155,   160,   167,   181,   188,
     199,   213,   219,   231,   236,   241,   246,   268,   275,   282,
     289,   296,   302,   309,   316,   323,   331,   337,   343,   349,
     360,   366,   376,   383,   395,   401,   409,   414,   420,   425,
     433,   442,   468,   476,   493,   520,   526,   531,   539,   552
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "T_UNKNOWNCHAR", "T_ID", "T_NEWID", "T_NUM", 
  "T_CLEAR", "T_ALL", "T_LIMIT", "T_PRINT", "T_SHOW", "T_PRINTSOP", 
  "T_SATISFY", "T_SATCOUNT", "T_SIZE", "T_STATS", "T_TIMER", "T_OFF", 
  "T_VARS", "T_AGETS", "T_GETS", "T_EXISTS", "T_FORALL", "T_SUBST", 
  "T_QUIT", "T_HELP", "T_IMPLIES", "T_NONE", "T_VERSION", "'?'", "':'", 
  "'['", "'^'", "'|'", "'&'", "'='", "'!'", "';'", "']'", "'0'", "'1'", 
  "'('", "')'", "'/'", "file", "command", "help", "assignment", "expr", 
  "expraux", "pairs", "pairsvar", "var", "satcount", "satisfy", "clear", 
  "clearIds", "limit", "print", "show", "size", "timer", "vars", "newid", 
  "vardecls", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    48,    48,
      49,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    55,    56,    56,    57,    57,    58,    58,
      59,    60,    61,    62,    62,    63,    64,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     5,     5,     7,     5,     4,     0,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     1,     2,     1,     1,     2,     0
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
      10,    57,    56,     0,     0,     0,     0,     0,     0,     0,
      54,    59,    16,    17,    15,     0,     2,    14,     3,    13,
       8,     4,     5,     6,     7,     9,    11,    12,     0,    47,
      44,    45,    48,    49,    22,    21,     0,     0,     0,     0,
      23,    24,     0,    50,    20,    51,    43,    42,    52,    53,
      55,    10,     0,    46,     0,     0,    39,    38,    37,     0,
      31,     0,     0,     0,     0,     0,     0,    58,     1,    37,
      19,     0,     0,     0,     0,    25,    26,    29,    28,    27,
      30,     0,     0,     0,    41,    40,     0,     0,     0,    18,
      32,    33,     0,     0,    35,     0,    36,    34,     0,     0
};

static const short yydefgoto[] =
{
      15,    16,    17,    18,    43,    44,    73,    59,    87,    19,
      20,    21,    31,    22,    23,    24,    25,    26,    27,    28,
      50
};

static const short yypact[] =
{
      78,-32768,-32768,    44,    27,    39,    39,    39,    39,    39,
     -16,-32768,-32768,-32768,-32768,    11,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    18,-32768,
  -32768,    41,-32768,-32768,-32768,-32768,    39,    39,    14,    39,
  -32768,-32768,    39,-32768,   119,-32768,-32768,-32768,-32768,-32768,
      10,    78,     0,-32768,   105,   109,-32768,-32768,-32768,   -11,
  -32768,    31,    39,    39,    39,    39,    39,-32768,-32768,-32768,
  -32768,    39,    39,     8,    39,-32768,    21,   122,    33,    -2,
      23,    12,    75,    79,-32768,-32768,    28,     6,    90,-32768,
  -32768,-32768,    39,    16,-32768,    94,-32768,-32768,    54,-32768
};

static const short yypgoto[] =
{
  -32768,    20,-32768,-32768,     1,   -36,     3,-32768,   -20,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    25,
  -32768
};


#define	YYLAST		158


static const short yytable[] =
{
      54,    55,    49,    60,    34,    35,    61,    45,    46,    47,
      48,    98,    84,    85,     1,     2,    84,    85,    56,    57,
      84,    85,    36,    37,    38,    62,    76,    77,    78,    79,
      80,    74,    69,    32,    66,    82,    83,    39,    88,    52,
      40,    41,    42,    34,    35,    53,    58,    86,    29,    51,
      93,    89,    30,    70,    99,    33,    95,    66,    62,-32768,
      62,    36,    37,    38,    63,    64,    65,    66,    65,    66,
      92,    68,    81,    96,    75,    67,    39,     0,     0,    40,
      41,    42,     1,     2,     0,     3,     0,     4,     5,     6,
       0,     7,     8,     9,     0,    10,     0,    11,     0,     0,
       0,     0,    62,    12,    13,     0,    62,    14,    63,    64,
      65,    66,    63,    64,    65,    66,     0,    62,    90,     0,
       0,    62,    91,    63,    64,    65,    66,    63,    64,    65,
      66,     0,    62,    94,     0,     0,    62,    97,    63,    64,
      65,    66,    63,    64,    65,    66,    62,    71,     0,    62,
       0,    72,    63,    64,    65,    66,    64,    65,    66
};

static const short yycheck[] =
{
      36,    37,    18,    39,     4,     5,    42,     6,     7,     8,
       9,     0,     4,     5,     4,     5,     4,     5,     4,     5,
       4,     5,    22,    23,    24,    27,    62,    63,    64,    65,
      66,    42,    32,     6,    36,    71,    72,    37,    74,    21,
      40,    41,    42,     4,     5,     4,    32,    39,     4,    38,
      44,    39,     8,    52,     0,    28,    92,    36,    27,    36,
      27,    22,    23,    24,    33,    34,    35,    36,    35,    36,
      42,    51,    69,    93,    43,    50,    37,    -1,    -1,    40,
      41,    42,     4,     5,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    14,    15,    -1,    17,    -1,    19,    -1,    -1,
      -1,    -1,    27,    25,    26,    -1,    27,    29,    33,    34,
      35,    36,    33,    34,    35,    36,    -1,    27,    43,    -1,
      -1,    27,    43,    33,    34,    35,    36,    33,    34,    35,
      36,    -1,    27,    43,    -1,    -1,    27,    43,    33,    34,
      35,    36,    33,    34,    35,    36,    27,    42,    -1,    27,
      -1,    42,    33,    34,    35,    36,    34,    35,    36
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison-1.35/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

#line 315 "/usr/share/bison-1.35/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 15:
#line 157 "grammar.yy"
{
    print_version();
}
    break;
case 16:
#line 162 "grammar.yy"
{
    terminated = true;
}
    break;
case 17:
#line 169 "grammar.yy"
{
    int pid;
    int i;
    if ( (pid = fork()) == 0) { 
	execl("/bin/sh", "sh", "-c", "man iben", NULL); 
	perror("iben"); 
	exit(1);
    }
    do { i = wait(0); } while (i != -1 && i != pid);
}
    break;
case 18:
#line 183 "grammar.yy"
{
  yyvsp[-4].e->free();
  yyvsp[-4].e->type = VARASSOC;
  yyvsp[-4].e->info.varassoc.p = yyvsp[-1].p;
}
    break;
case 19:
#line 190 "grammar.yy"
{
  yyvsp[-2].e->type = EXPR;
  yyvsp[-2].e->info.expr.f=*yyvsp[0].f;
  delete yyvsp[0].f;
}
    break;
case 20:
#line 201 "grammar.yy"
{
  if (yyvsp[0].f)
    yyval.f=yyvsp[0].f;
  else
    {
      yyerror("node limit exceeded");
      YYERROR;
    }
}
    break;
case 21:
#line 215 "grammar.yy"
{
  yyerror(undefined(yyvsp[0].e->id.c_str()));
  YYERROR;
}
    break;
case 22:
#line 221 "grammar.yy"
{
  if (yyvsp[0].e->type == VAR) {
      yyval.f=new bdd(bdd_ithvar(yyvsp[0].e->info.var));
  } else if (yyvsp[0].e->type == EXPR) {
      yyval.f = new bdd(yyvsp[0].e->info.expr.f);
  } else {
      yyerror("expression expected");
      YYERROR;
  }
}
    break;
case 23:
#line 233 "grammar.yy"
{
  yyval.f= new bdd(bddfalse);
}
    break;
case 24:
#line 238 "grammar.yy"
{
  yyval.f= new bdd(bddtrue);
}
    break;
case 25:
#line 243 "grammar.yy"
{
  yyval.f=yyvsp[-1].f;
}
    break;
case 26:
#line 263 "grammar.yy"
{
    yyval.f = new bdd(*yyvsp[-2].f >> *yyvsp[0].f);
    delete yyvsp[-2].f;
    delete yyvsp[0].f;
}
    break;
case 27:
#line 270 "grammar.yy"
{
  yyval.f= new bdd(*yyvsp[-2].f & *yyvsp[0].f);
  delete yyvsp[-2].f;
  delete yyvsp[0].f;
}
    break;
case 28:
#line 277 "grammar.yy"
{
  yyval.f= new bdd(*yyvsp[-2].f | *yyvsp[0].f);
  delete yyvsp[-2].f;
  delete yyvsp[0].f;
}
    break;
case 29:
#line 284 "grammar.yy"
{
  yyval.f= new bdd(*yyvsp[-2].f ^ *yyvsp[0].f);
  delete yyvsp[-2].f;
  delete yyvsp[0].f;
}
    break;
case 30:
#line 291 "grammar.yy"
{
  yyval.f= new bdd (!(*yyvsp[-2].f ^ *yyvsp[0].f));
  delete yyvsp[-2].f;
  delete yyvsp[0].f;
}
    break;
case 31:
#line 298 "grammar.yy"
{
  yyval.f= new bdd(!*yyvsp[0].f);
  delete yyvsp[0].f;
}
    break;
case 32:
#line 304 "grammar.yy"
{
    yyval.f = new bdd(bdd_exist(*yyvsp[-1].f, *yyvsp[-3].f));
    delete yyvsp[-3].f;
    delete yyvsp[-1].f;
}
    break;
case 33:
#line 311 "grammar.yy"
{
    yyval.f = new bdd(bdd_forall(*yyvsp[-1].f, *yyvsp[-3].f));
    delete yyvsp[-3].f;
    delete yyvsp[-1].f;
}
    break;
case 34:
#line 318 "grammar.yy"
{
    yyval.f = new bdd(bdd_replace(*yyvsp[-1].f, yyvsp[-4].p));
    bdd_freepair(yyvsp[-4].p);
    delete yyvsp[-1].f;
}
    break;
case 35:
#line 325 "grammar.yy"
{
    yyval.f = new bdd(bdd_replace(*yyvsp[-1].f, yyvsp[-3].p));
    delete yyvsp[-1].f;
}
    break;
case 36:
#line 333 "grammar.yy"
{
    bdd_setpair(yyvsp[-3].p, yyvsp[0].i, yyvsp[-2].i);
    yyval.p = yyvsp[-3].p;
}
    break;
case 37:
#line 338 "grammar.yy"
{
    yyval.p = bdd_newpair();
}
    break;
case 38:
#line 345 "grammar.yy"
{
    yyerror(undefined(yyvsp[0].e->id.c_str()));
    YYERROR;
}
    break;
case 39:
#line 351 "grammar.yy"
{
    if (yyvsp[0].e->type != VARASSOC) {
	yyerror("Association reference expected");
	YYERROR;
    }
    yyval.p=yyvsp[0].e->info.varassoc.p;
}
    break;
case 40:
#line 362 "grammar.yy"
{
  yyerror(undefined(yyvsp[0].e->id.c_str()));
  YYERROR;
}
    break;
case 41:
#line 368 "grammar.yy"
{
    if (yyvsp[0].e->type != VAR) {
	yyerror("Variable reference expected");
	YYERROR;
    }
    yyval.i=yyvsp[0].e->info.var;
}
    break;
case 42:
#line 378 "grammar.yy"
{
    printf("%.0f satisfying assignments\n", bdd_satcount(*yyvsp[0].f));
    delete yyvsp[0].f;
}
    break;
case 43:
#line 385 "grammar.yy"
{
    bdd f;
    if (*yyvsp[0].f == bddfalse)
	printf("Expression has no satisfying assignments\n");
    else 
	print_sat(*yyvsp[0].f);
    delete yyvsp[0].f;
}
    break;
case 44:
#line 397 "grammar.yy"
{
  symbol_table.clear();
  name_table.clear();
}
    break;
case 45:
#line 403 "grammar.yy"
{
  // Nothing to do
}
    break;
case 46:
#line 411 "grammar.yy"
{
  symbol_table.erase(symbol_table.find(yyvsp[0].e->id));
}
    break;
case 47:
#line 415 "grammar.yy"
{
  symbol_table.erase(symbol_table.find(yyvsp[0].e->id));
}
    break;
case 48:
#line 422 "grammar.yy"
{
    bdd_setmaxnodenum(yyvsp[0].i);
}
    break;
case 49:
#line 427 "grammar.yy"
{
    bdd_setmaxnodenum(0);
}
    break;
case 50:
#line 435 "grammar.yy"
{
    bdd_printset(*yyvsp[0].f);
    printf("\n");
    delete yyvsp[0].f;
}
    break;
case 51:
#line 444 "grammar.yy"
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
    printdot(stream, *yyvsp[0].f);
    delete yyvsp[0].f;
    pclose(stream); 

    snprintf(cmd, 128, PSV" /tmp/iben%ld.ps; rm /tmp/iben%ld.ps", pid, pid); 
    if (!fork()) { 
	printf("executing "PSV" \n"); 
	execl("/bin/sh", "sh", "-c", cmd, NULL); 
	perror("iben"); 
	exit(1);
    } 
}
    break;
case 52:
#line 470 "grammar.yy"
{
    printf("%d nodes\n", bdd_nodecount(*yyvsp[0].f));
    delete yyvsp[0].f;
}
    break;
case 53:
#line 478 "grammar.yy"
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
    break;
case 54:
#line 495 "grammar.yy"
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
}
    break;
case 55:
#line 522 "grammar.yy"
{
}
    break;
case 56:
#line 528 "grammar.yy"
{
  yyval.e = yyvsp[0].e;
}
    break;
case 57:
#line 533 "grammar.yy"
{
  yyvsp[0].e->free();
  yyval.e = yyvsp[0].e;
}
    break;
case 58:
#line 541 "grammar.yy"
{
    int i = bdd_extvarnum(1);
    if (i >= 0) {
	yyvsp[0].e->info.var = i;
	yyvsp[0].e->type = VAR;
	name_table[i] = yyvsp[0].e->id;
    } else {
	yyerror("node limit exceeded");
	YYERROR;
    }
}
    break;
case 59:
#line 553 "grammar.yy"
{
}
    break;
}

#line 705 "/usr/share/bison-1.35/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 557 "grammar.yy"


