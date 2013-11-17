/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "lexya_e.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"

Node *opr(int name,int num,...);
Node *set_index(int value);
Node *set_content(float value);

void NodeFree(Node *p);
int NodeExecute(Node *p);

typedef union {
    float val;
    int index;
    Node *node;
}yystype;

#define YYSTYPE yystype

void debug_vsp(YYSTYPE,char *,YYSTYPE *,char *);

void print_stmt();

void add_var(char *);

int G_iVarMaxIndex = 0;
int G_iVarCurIndex = -1;
struct VarIndex G_Var[MAX_VARS];

void yyerror(char *s);


/* Line 268 of yacc.c  */
#line 106 "lexya_e.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     VARIABLE = 259,
     INT = 260,
     FLOAT = 261,
     PRINT = 262,
     FOR = 263,
     FOREACH = 264,
     WHILE = 265,
     BREAK = 266,
     IN = 267,
     FUNCTION = 268,
     IF = 269,
     ELSE = 270,
     OR = 271,
     AND = 272,
     NE = 273,
     EQ = 274,
     LE = 275,
     GE = 276,
     MUS_TT = 277,
     MUS_T = 278,
     ADD_TT = 279,
     ADD_T = 280,
     UMINUS = 281
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 36 "lexya_e.y"

    float val;
    int index;
    Node *node;



/* Line 293 of yacc.c  */
#line 176 "lexya_e.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 188 "lexya_e.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    26,    24,     2,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      19,    40,    18,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    20,    21,    22,    23,    28,    29,    30,
      31,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    17,    21,
      25,    35,    43,    49,    55,    63,    67,    70,    72,    75,
      78,    81,    86,    91,    97,   101,   105,   107,   114,   117,
     120,   123,   126,   130,   134,   138,   142,   146,   150,   154,
     158,   162,   166,   168,   170,   173,   177,   181,   185,   189,
     193
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    43,    44,    -1,    -1,    11,
      35,    -1,    35,    -1,    47,    35,    -1,     7,    50,    35,
      -1,     7,    47,    35,    -1,     8,    36,    47,    35,    49,
      35,    47,    37,    44,    -1,     9,    36,     4,    12,     4,
      37,    44,    -1,    10,    36,    49,    37,    44,    -1,    14,
      36,    49,    37,    44,    -1,    14,    36,    49,    37,    44,
      15,    44,    -1,    38,    45,    39,    -1,    46,    35,    -1,
      44,    -1,    45,    44,    -1,     5,     4,    -1,     6,     4,
      -1,     5,     4,    40,    50,    -1,     6,     4,    40,    50,
      -1,     5,     4,    32,    50,    33,    -1,     4,    40,    50,
      -1,     4,    40,    48,    -1,    48,    -1,     4,    32,    50,
      33,    40,    50,    -1,    31,     4,    -1,    29,     4,    -1,
       4,    31,    -1,     4,    29,    -1,    36,    48,    37,    -1,
      50,    19,    50,    -1,    50,    18,    50,    -1,    50,    23,
      50,    -1,    50,    22,    50,    -1,    50,    20,    50,    -1,
      50,    21,    50,    -1,    49,    17,    49,    -1,    49,    16,
      49,    -1,    36,    49,    37,    -1,     3,    -1,     4,    -1,
      25,     3,    -1,    50,    24,    50,    -1,    50,    25,    50,
      -1,    50,    26,    50,    -1,    50,    27,    50,    -1,    36,
      50,    37,    -1,     4,    32,    50,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    70,    72,    79,    81,    83,    85,    87,
      89,    91,    93,    95,    97,    99,   101,   108,   110,   118,
     120,   122,   124,   126,   133,   135,   137,   139,   146,   148,
     150,   152,   154,   161,   163,   165,   167,   169,   171,   173,
     175,   177,   184,   186,   188,   190,   192,   194,   196,   198,
     200
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "VARIABLE", "INT", "FLOAT",
  "PRINT", "FOR", "FOREACH", "WHILE", "BREAK", "IN", "FUNCTION", "IF",
  "ELSE", "OR", "AND", "'>'", "'<'", "NE", "EQ", "LE", "GE", "'+'", "'-'",
  "'*'", "'/'", "MUS_TT", "MUS_T", "ADD_TT", "ADD_T", "'['", "']'",
  "UMINUS", "';'", "'('", "')'", "'{'", "'}'", "'='", "$accept", "program",
  "function", "stmt", "stmt_list", "var_decl", "expr_set", "expr_setself",
  "expr_comp", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    62,    60,
     273,   274,   275,   276,    43,    45,    42,    47,   277,   278,
     279,   280,    91,    93,   281,    59,    40,    41,   123,   125,
      61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    45,    45,    46,
      46,    46,    46,    46,    47,    47,    47,    47,    48,    48,
      48,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      50
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     2,     3,     3,
       9,     7,     5,     5,     7,     3,     2,     1,     2,     2,
       2,     4,     4,     5,     3,     3,     1,     6,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     2,     3,     3,     3,     3,     3,
       4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     3,     0,
       0,    26,    31,    30,     0,     0,    19,    20,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     5,     0,    29,
      28,     0,     0,    17,     0,    16,     7,    43,     0,     0,
      43,    25,    24,     0,     0,     0,     0,    44,     0,     9,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,    32,    15,    18,     0,     0,     0,    21,    22,     0,
      49,    45,    46,    47,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    50,     0,     0,    41,    40,    39,    12,    34,
      33,    37,    38,    36,    35,    13,    50,    27,     0,     0,
       0,     0,    11,    14,     0,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    18,    44,    19,    20,    21,    68,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -27
static const yytype_int16 yypact[] =
{
     -27,     3,   108,   -27,   132,     9,    14,    41,    -6,     1,
       4,    32,    35,    72,    79,   -27,    69,   108,   -27,    51,
      59,   -27,   -27,   -27,    29,    49,   -15,    57,   -27,   138,
      98,    49,    67,   133,    92,   106,    43,   -27,    43,   -27,
     -27,    95,    83,   -27,     0,   -27,   -27,    77,    29,   165,
     142,   -27,   109,    29,    29,    29,    29,   -27,   105,   -27,
      29,    29,    29,    29,   -27,   103,   113,    43,     5,   161,
      44,   -27,   -27,   -27,    29,   100,   169,   109,   109,   179,
     -27,    -3,    -3,   -27,   -27,    43,   137,    90,   129,    43,
      43,   108,    29,    29,    29,    29,    29,    29,   108,   183,
      29,   -27,   100,    -1,   125,   -27,   -27,   -27,   -27,   109,
     109,   109,   109,   109,   109,   130,   -27,   109,    92,   108,
     108,   128,   -27,   -27,   108,   -27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,   -27,   -16,   -27,   -27,    -7,    68,   -26,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      32,    43,    33,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    70,    26,    12,    89,    90,    53,    27,    49,
      52,    89,    90,    62,    63,    54,    58,    65,    73,    13,
      34,    14,    28,    47,   118,    15,    16,    35,    17,    72,
      36,    87,    91,    58,    28,    29,    28,    47,    76,    77,
      78,    79,    28,    50,    30,    81,    82,    83,    84,   103,
      89,    90,    88,   106,   107,    48,    30,    37,    30,    99,
      13,    38,    14,    41,    30,   108,    39,    31,    13,    67,
      14,    98,   115,    40,    42,    31,    45,   109,   110,   111,
     112,   113,   114,    51,    46,   117,     4,    55,    13,    42,
      14,    57,    59,   122,   123,    16,    89,    90,   125,    74,
      66,   121,     4,     5,     6,     7,     8,     9,    10,    11,
      71,    13,    12,    14,    22,    86,    23,   105,    16,    60,
      61,    62,    63,    60,    61,    62,    63,    13,    85,    14,
     100,   104,    80,    15,    16,   120,    17,    92,    93,    94,
      95,    96,    97,    60,    61,    62,    63,    60,    61,    62,
      63,    22,   119,    23,    24,   124,    80,    22,    64,    23,
      56,    22,    25,    23,    74,     0,     0,     0,    25,    92,
      93,    94,    95,    96,    97,    60,    61,    62,    63,    60,
      61,    62,    63,    60,    61,    62,    63,     0,    75,     0,
       0,     0,   101,    60,    61,    62,    63,    60,    61,    62,
      63,     0,   102,     0,     0,     0,   116
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-27))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       7,    17,     7,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    38,     4,    14,    16,    17,    32,     4,    24,
      25,    16,    17,    26,    27,    40,    31,    34,    44,    29,
      36,    31,     3,     4,    35,    35,    36,    36,    38,    39,
      36,    67,    37,    48,     3,     4,     3,     4,    53,    54,
      55,    56,     3,     4,    25,    60,    61,    62,    63,    85,
      16,    17,    67,    89,    90,    36,    25,    35,    25,    74,
      29,    36,    31,     4,    25,    91,     4,    36,    29,    36,
      31,    37,    98,     4,    16,    36,    35,    92,    93,    94,
      95,    96,    97,    25,    35,   100,     4,    40,    29,    31,
      31,     3,    35,   119,   120,    36,    16,    17,   124,    32,
       4,   118,     4,     5,     6,     7,     8,     9,    10,    11,
      37,    29,    14,    31,    29,    12,    31,    37,    36,    24,
      25,    26,    27,    24,    25,    26,    27,    29,    35,    31,
      40,     4,    37,    35,    36,    15,    38,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    24,    25,    26,
      27,    29,    37,    31,    32,    37,    37,    29,    35,    31,
      32,    29,    40,    31,    32,    -1,    -1,    -1,    40,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    24,
      25,    26,    27,    24,    25,    26,    27,    -1,    33,    -1,
      -1,    -1,    33,    24,    25,    26,    27,    24,    25,    26,
      27,    -1,    33,    -1,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    14,    29,    31,    35,    36,    38,    44,    46,
      47,    48,    29,    31,    32,    40,     4,     4,     3,     4,
      25,    36,    47,    50,    36,    36,    36,    35,    36,     4,
       4,     4,    48,    44,    45,    35,    35,     4,    36,    50,
       4,    48,    50,    32,    40,    40,    32,     3,    50,    35,
      24,    25,    26,    27,    35,    47,     4,    36,    49,    50,
      49,    37,    39,    44,    32,    33,    50,    50,    50,    50,
      37,    50,    50,    50,    50,    35,    12,    49,    50,    16,
      17,    37,    18,    19,    20,    21,    22,    23,    37,    50,
      40,    33,    33,    49,     4,    37,    49,    49,    44,    50,
      50,    50,    50,    50,    50,    44,    33,    50,    35,    37,
      15,    47,    44,    44,    37,    44
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 64 "lexya_e.y"
    { exit(0); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 70 "lexya_e.y"
    { NodeExecute((yyvsp[(2) - (2)].node));NodeFree((yyvsp[(2) - (2)].node)); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 79 "lexya_e.y"
    { (yyval.node) = opr(BREAK,0); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 81 "lexya_e.y"
    { (yyval.node)=opr(';',2,NULL,NULL); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 83 "lexya_e.y"
    { (yyval.node)=(yyvsp[(1) - (2)].node); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 85 "lexya_e.y"
    { (yyval.node)=opr(PRINT,1,(yyvsp[(2) - (3)].node)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 87 "lexya_e.y"
    { (yyval.node) = opr(PRINT, 1, (yyvsp[(2) - (3)].node)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 89 "lexya_e.y"
    { (yyval.node) = opr(FOR, 4, (yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 91 "lexya_e.y"
    { (yyval.node) = opr(FOREACH, 3, set_index((yyvsp[(3) - (7)].index)), set_index((yyvsp[(5) - (7)].index)), (yyvsp[(7) - (7)].node)); printf("haha");}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 93 "lexya_e.y"
    { (yyval.node) = opr(WHILE, 2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 95 "lexya_e.y"
    { (yyval.node)=opr(IF,2,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 97 "lexya_e.y"
    { (yyval.node)=opr(IF,3,(yyvsp[(3) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(7) - (7)].node)); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 99 "lexya_e.y"
    { (yyval.node)=(yyvsp[(2) - (3)].node); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 101 "lexya_e.y"
    {}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 108 "lexya_e.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 110 "lexya_e.y"
    { (yyval.node)=opr(';',2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 118 "lexya_e.y"
    { (yyval.node) = set_index((yyvsp[(2) - (2)].index));}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 120 "lexya_e.y"
    {(yyval.node) = set_index((yyvsp[(2) - (2)].index));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 122 "lexya_e.y"
    {(yyval.node) = opr('=', 2, set_index((yyvsp[(2) - (4)].index)), (yyvsp[(4) - (4)].node));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 124 "lexya_e.y"
    { (yyval.node) = opr('=', 2, set_index((yyvsp[(2) - (4)].index)), (yyvsp[(4) - (4)].node)); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 126 "lexya_e.y"
    { (yyval.node) = set_index((yyvsp[(2) - (5)].index)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 133 "lexya_e.y"
    { (yyval.node) = opr('=', 2, set_index((yyvsp[(1) - (3)].index)), (yyvsp[(3) - (3)].node)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 135 "lexya_e.y"
    { (yyval.node) = opr('=', 2, set_index((yyvsp[(1) - (3)].index)), (yyvsp[(3) - (3)].node)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 139 "lexya_e.y"
    { (yyval.node) = opr('=', 3, set_index((yyvsp[(1) - (6)].index)), (yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 146 "lexya_e.y"
    { (yyval.node) = opr(ADD_T, 1, set_index((yyvsp[(2) - (2)].index))); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 148 "lexya_e.y"
    { (yyval.node) = opr(MUS_T, 1, set_index((yyvsp[(2) - (2)].index))); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 150 "lexya_e.y"
    { (yyval.node) = opr(ADD_TT, 1, set_index((yyvsp[(1) - (2)].index))); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 152 "lexya_e.y"
    { (yyval.node) = opr(MUS_TT, 1, set_index((yyvsp[(1) - (2)].index))); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 154 "lexya_e.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 161 "lexya_e.y"
    { (yyval.node) = opr('<', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 163 "lexya_e.y"
    { (yyval.node) = opr('>', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 165 "lexya_e.y"
    { (yyval.node) = opr(GE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 167 "lexya_e.y"
    { (yyval.node) = opr(LE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 169 "lexya_e.y"
    { (yyval.node) = opr(NE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 171 "lexya_e.y"
    { (yyval.node) = opr(EQ, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 173 "lexya_e.y"
    { (yyval.node) = opr(AND, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 175 "lexya_e.y"
    { (yyval.node) = opr(OR, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 177 "lexya_e.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 184 "lexya_e.y"
    { (yyval.node) = set_content((yyvsp[(1) - (1)].val)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 186 "lexya_e.y"
    { (yyval.node) = set_index((yyvsp[(1) - (1)].index)); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 188 "lexya_e.y"
    { (yyval.node) = set_content(-(yyvsp[(2) - (2)].val)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 190 "lexya_e.y"
    { (yyval.node) = opr('+', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 192 "lexya_e.y"
    { (yyval.node) = opr('-', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 194 "lexya_e.y"
    { (yyval.node) = opr('*', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 196 "lexya_e.y"
    { (yyval.node) = opr('/', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 198 "lexya_e.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 200 "lexya_e.y"
    { (yyval.node) = opr('[',2,set_index((yyvsp[(1) - (4)].index)),(yyvsp[(3) - (4)].node)); }
    break;



/* Line 1806 of yacc.c  */
#line 1855 "lexya_e.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 205 "lexya_e.y"



#define SIZE_OF_NODE  ((char*)&p->content-(char*)p)

Node *set_content(float value){

    Node *p;

    size_t sizeNode;

    sizeNode = SIZE_OF_NODE + sizeof(float);

    if((p = malloc(sizeNode)) == NULL)
	yyerror("out of memory");


    p->type = TYPE_CONTENT;
    p->content = value;

    return p;

}

Node *set_index(int value){

    Node *p;
    size_t sizeNode;

    sizeNode = SIZE_OF_NODE + sizeof(int);

    if((p = malloc(sizeNode)) == NULL)
	yyerror("out of memory");


    p->type = TYPE_INDEX;
    p->index = value;

    return p;
}

Node *opr(int name,int num,...){

    va_list valist;
    Node *p;
    size_t sizeNode;
    int i;

    sizeNode = SIZE_OF_NODE + sizeof(OpNode) + (num - 1) * sizeof(Node*);

    if((p = malloc(sizeNode)) == NULL)
	yyerror("out of memory");


    
    p->type = TYPE_OP;
    p->op.name = name;
    p->op.num = num;

    va_start(valist,num);

    for(i = 0;i < num;i++)
	p->op.node[i] = va_arg(valist,Node*);

    va_end(valist);
    return p;
}

void debug_vsp(YYSTYPE yval, char * info, YYSTYPE * vsp, char * mark) {

#ifdef PARSE_DEBUG
    printf("\n -RULE  0x%x  %s \n ", yval.node, info  );

    int i;
    int ilen=strlen(mark);

    for(i=1-ilen;i<=0;i++) {
		
	switch(mark[ilen+i-1]){
	
	    case '0':
	
		printf(" [ 0x%x ",vsp[i].node);//「」
		
		switch(vsp[i].node->type) {
		
		    case TYPE_CONTENT:
		
			printf("%g ] ",vsp[i].node->content);
							      
			break;
			
		    case TYPE_INDEX:
			
			printf("%s ] ",G_Var[vsp[i].node->index].mark);
			
			break;
			
		    case TYPE_OP:

			if(vsp[i].node->op.name<USER_DEF_NUM)
			    printf("%c ] ",vsp[i].node->op.name);

			else			
			    printf("%s ] ",G_Def[vsp[i].node->op.name-USER_DEF_NUM].name);
			break;      
		}
		break;
	    case '1':
		printf(" %c ",vsp[i].index);   /* 打印运算符 */
		break;
	    case '2':
		printf(" %s ",G_Var[vsp[i].index].mark);
		break;
	    case '3':
		printf(" %g ",vsp[i].val);
		break;
	    case '4':
		printf(" %s ",G_Def[vsp[i].index].name);		
		break;  
		
	}
	
    }
    printf("\n");
    print_stmt();

#endif

}


void add_var(char *mark){

    if(G_iVarMaxIndex == 0){
	strcpy(G_Var[0].mark,mark);
	G_iVarMaxIndex++;
	G_iVarCurIndex=0;
	return;
    }

    int i; 
    for(i=0;i<=G_iVarMaxIndex-1;i++) {
	 if(strcmp(G_Var[i].mark,mark)==0) {
	     G_iVarCurIndex=i;
	     return;
	 }
     }

    strcpy(G_Var[G_iVarMaxIndex].mark,mark);
    G_iVarCurIndex=G_iVarMaxIndex;
    G_iVarMaxIndex++;
}


void print_stmt() {
     printf(" -STMT: \n");

     if(G_iBuffColCount==0)
	 printf("  %s \n",G_sBuff[G_iBuffRowCount-1]);  
     else
	 printf("  %s \n",G_sBuff[G_iBuffRowCount]);
   
     printf("\n");
}


void NodeFree(Node *p){
    int i;
    if(!p)return;
    if(p->type == TYPE_OP){
	for(i = 0;i<p->op.num;i++)
	    NodeFree(p->op.node[i]);
    }
    free(p);
}

void yyerror(char *s){
	 
    printf("<Parser Error> Line %d ,Col %d \n",G_iBuffRowCount+1,G_iBuffColCount+1);

    printf(" %s\n",G_sBuff[G_iBuffRowCount]);
}

int main(void){
    yyparse();
    return 0;
}

