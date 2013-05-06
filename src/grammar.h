#ifndef BISON_GRAMMAR_H
# define BISON_GRAMMAR_H

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


extern YYSTYPE yylval;

#endif /* not BISON_GRAMMAR_H */
