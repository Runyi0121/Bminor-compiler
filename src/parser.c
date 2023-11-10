/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 59 "src/parser.bison" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/decl.h"
#include "../inc/expr.h"
#include "../inc/stmt.h"
#include "../inc/symbol.h"


extern char* yytext;
extern int yylex();
extern int yyerror(char *str);
struct decl * parser_result;

#line 82 "src/parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_INC_PARSER_H_INCLUDED
# define YY_YY_INC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_EOF = 0,
    TOKEN_CCOMMENT = 258,
    TOKEN_CPLUSCOMMENT = 259,
    TOKEN_ARRAY = 260,
    TOKEN_AUTO = 261,
    TOKEN_BOOLEAN = 262,
    TOKEN_CHAR = 263,
    TOKEN_ELSE = 264,
    TOKEN_FALSE = 265,
    TOKEN_FLOAT = 266,
    TOKEN_FOR = 267,
    TOKEN_FUNCTION = 268,
    TOKEN_IF = 269,
    TOKEN_INTEGER = 270,
    TOKEN_PRINT = 271,
    TOKEN_RETURN = 272,
    TOKEN_STRING = 273,
    TOKEN_TRUE = 274,
    TOKEN_VOID = 275,
    TOKEN_WHILE = 276,
    TOKEN_SPECIALCHAR = 277,
    TOKEN_ADD = 278,
    TOKEN_SUBTRACT = 279,
    TOKEN_INCREMENT = 280,
    TOKEN_DECREMENT = 281,
    TOKEN_FRONTPARENTHESE = 282,
    TOKEN_BACKPARENTHESE = 283,
    TOKEN_FRONTSQUAREBRACKET = 284,
    TOKEN_BACKSQUAREBRACKET = 285,
    TOKEN_FRONTCURLYBRACKET = 286,
    TOKEN_BACKCURLYBRACKET = 287,
    TOKEN_NEGATIVE = 288,
    TOKEN_LOGICALNOT = 289,
    TOKEN_EXPONENTIAL = 290,
    TOKEN_MULTIPLY = 291,
    TOKEN_DIVIDE = 292,
    TOKEN_REMAIN = 293,
    TOKEN_LESSTHAN = 294,
    TOKEN_LESSEQUAL = 295,
    TOKEN_GREATERTHAN = 296,
    TOKEN_GREATEREQUAL = 297,
    TOKEN_EQUAL = 298,
    TOKEN_NOTEQUAL = 299,
    TOKEN_AND = 300,
    TOKEN_OR = 301,
    TOKEN_ASSIGN = 302,
    TOKEN_COLON = 303,
    TOKEN_SEMICOLON = 304,
    TOKEN_COMMA = 305,
    TOKEN_PERCENT = 306,
    TOKEN_TYPE_CHAR = 307,
    TOKEN_TYPE_INT = 308,
    TOKEN_TYPE_FLOAT = 309,
    TOKEN_TYPE_IDENT = 310,
    TOKEN_TYPE_STRING = 311,
    TOKEN_ERROR = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 75 "src/parser.bison" /* yacc.c:355  */

    struct decl *decl;
    struct expr *expr;
    struct stmt *stmt;
    struct symbol *symbol;
    struct type *type;
    struct param_list *param_list;
    char *name;

#line 191 "src/parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "src/parser.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    98,   101,   104,   106,   108,   110,   114,
     117,   120,   122,   126,   129,   131,   133,   135,   137,   139,
     141,   143,   145,   148,   151,   154,   156,   160,   164,   166,
     170,   172,   176,   178,   180,   184,   186,   188,   193,   195,
     197,   199,   201,   205,   208,   211,   213,   217,   219,   223,
     225,   229,   231,   235,   237,   239,   241,   243,   245,   247,
     251,   253,   255,   259,   261,   263,   265,   269,   271,   275,
     277,   279,   283,   285,   287,   291,   293,   297,   299,   301,
     303,   305,   307,   309,   313,   315,   318
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "TOKEN_EOF", "error", "$undefined", "TOKEN_CCOMMENT",
  "TOKEN_CPLUSCOMMENT", "TOKEN_ARRAY", "TOKEN_AUTO", "TOKEN_BOOLEAN",
  "TOKEN_CHAR", "TOKEN_ELSE", "TOKEN_FALSE", "TOKEN_FLOAT", "TOKEN_FOR",
  "TOKEN_FUNCTION", "TOKEN_IF", "TOKEN_INTEGER", "TOKEN_PRINT",
  "TOKEN_RETURN", "TOKEN_STRING", "TOKEN_TRUE", "TOKEN_VOID",
  "TOKEN_WHILE", "TOKEN_SPECIALCHAR", "TOKEN_ADD", "TOKEN_SUBTRACT",
  "TOKEN_INCREMENT", "TOKEN_DECREMENT", "TOKEN_FRONTPARENTHESE",
  "TOKEN_BACKPARENTHESE", "TOKEN_FRONTSQUAREBRACKET",
  "TOKEN_BACKSQUAREBRACKET", "TOKEN_FRONTCURLYBRACKET",
  "TOKEN_BACKCURLYBRACKET", "TOKEN_NEGATIVE", "TOKEN_LOGICALNOT",
  "TOKEN_EXPONENTIAL", "TOKEN_MULTIPLY", "TOKEN_DIVIDE", "TOKEN_REMAIN",
  "TOKEN_LESSTHAN", "TOKEN_LESSEQUAL", "TOKEN_GREATERTHAN",
  "TOKEN_GREATEREQUAL", "TOKEN_EQUAL", "TOKEN_NOTEQUAL", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_ASSIGN", "TOKEN_COLON", "TOKEN_SEMICOLON",
  "TOKEN_COMMA", "TOKEN_PERCENT", "TOKEN_TYPE_CHAR", "TOKEN_TYPE_INT",
  "TOKEN_TYPE_FLOAT", "TOKEN_TYPE_IDENT", "TOKEN_TYPE_STRING",
  "TOKEN_ERROR", "$accept", "program", "decl_list", "decl", "stmt_array",
  "array_content", "ident", "type", "arg_lists", "arg_list", "arg",
  "stmt_list", "stmt", "stmt_recursive", "stmt_closed", "stmt_base",
  "optional_stmt", "expr_list", "expr", "expr_or", "expr_and", "expr_comp",
  "expr_arith1", "expr_arith2", "expr_expo", "expr_not", "expr_crement",
  "expr_group", "expr_base", "others", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

#define YYPACT_NINF -113

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-113)))

#define YYTABLE_NINF -13

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,  -113,    56,    78,   -35,    53,  -113,  -113,  -113,   132,
      61,  -113,  -113,  -113,  -113,   132,  -113,  -113,  -113,   -22,
      79,    60,    39,  -113,  -113,  -113,    79,    79,    79,  -113,
    -113,  -113,  -113,    10,    84,    68,    70,    80,   115,    73,
      47,    91,  -113,    82,  -113,  -113,   -35,    -1,    81,    -5,
    -113,   -18,  -113,    79,    79,  -113,   132,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,  -113,  -113,    88,    99,  -113,    92,   101,   114,
      79,    79,    -1,  -113,   116,   119,    -8,  -113,    -1,  -113,
    -113,  -113,    25,   128,  -113,    79,  -113,   118,   -23,  -113,
      70,    80,   115,    73,    73,    73,    73,    73,    73,    47,
      47,    91,    91,    91,  -113,   132,  -113,   -35,    79,    79,
     112,     1,   130,    32,  -113,   117,  -113,  -113,    79,  -113,
    -113,    10,  -113,  -113,   120,    -6,  -113,  -113,  -113,  -113,
    -113,    30,  -113,    79,    -1,   121,  -113,   154,    79,    -1,
     136,  -113,  -113,    -1,  -113,  -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    13,     0,     0,     4,     0,     1,     2,     3,     0,
       0,    21,    15,    17,    18,     0,    14,    19,    20,     0,
      44,     0,     0,     5,    80,    79,     0,     0,     0,    77,
      78,    81,    82,    86,     0,    43,    48,    50,    52,    59,
      62,    66,    68,    71,    74,    76,    24,    10,     0,    46,
      69,     0,    70,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,    23,    26,     0,     0,
       0,     0,     0,    42,     0,     0,    86,     9,    29,    30,
      31,    37,     0,    76,     6,     0,    75,     0,     0,    16,
      47,    49,    51,    53,    54,    55,    56,    57,    58,    60,
      61,    63,    64,    65,    67,     0,    22,     0,    44,     0,
       0,     0,     0,     0,     7,     0,    28,    38,     0,    45,
      85,    86,    27,    25,     0,     0,    40,    39,    41,     8,
      11,     0,    84,    44,     0,     0,    34,    31,    44,     0,
       0,    33,    36,     0,    32,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,   161,    64,  -113,    40,     0,   -13,  -113,    50,
    -113,   -50,    27,   -82,   -84,  -113,  -112,   -36,   -19,   122,
     123,   113,    58,    38,    42,   -14,  -113,  -113,   -42,    43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    83,    84,    85,    33,    19,    75,    76,
      77,    87,    88,    89,    90,    91,    34,    48,   123,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    35,    21,    49,     5,    93,   134,   131,    51,    24,
      96,    78,    50,    79,    52,    80,    81,    97,    25,    53,
       1,    54,   144,    26,    57,    22,    27,    23,    92,    57,
      82,   145,   122,    28,    49,    98,   150,    53,   126,    54,
       9,    57,    57,    99,   120,    95,    74,    86,    57,    24,
     137,    29,    30,    31,     1,    32,     6,   114,    25,   129,
     147,    49,   121,    26,     4,   152,    27,   151,     4,   155,
      47,   154,    57,    28,   127,   128,    49,    57,     7,    57,
     128,   127,    86,    68,    69,    70,    93,    46,    86,    24,
      20,    29,    30,    31,     1,    32,    66,    67,    25,    35,
     135,     9,   132,    26,   109,   110,    27,    72,    73,   141,
     111,   112,   113,    28,    56,    57,    58,    74,   103,   104,
     105,   106,   107,   108,    35,    59,    71,   116,   118,    35,
      94,    29,    30,    31,     1,    32,   115,    10,    11,    12,
      13,   119,   117,    14,    86,    15,   130,    16,   124,    86,
      17,   125,    18,    86,    60,    61,    62,    63,    64,    65,
     -12,   136,   138,   149,   153,     8,   139,   133,   140,   143,
     148,   146,   102,     0,   142,     0,     0,     0,     0,   100,
       0,   101
};

static const yytype_int16 yycheck[] =
{
       0,    20,    15,    22,     4,    47,   118,    30,    27,    10,
      28,    12,    26,    14,    28,    16,    17,    53,    19,    27,
      55,    29,    28,    24,    47,    47,    27,    49,    47,    47,
      31,   143,    82,    34,    53,    54,   148,    27,    88,    29,
      48,    47,    47,    56,    80,    50,    46,    47,    47,    10,
      49,    52,    53,    54,    55,    56,     0,    71,    19,    95,
     144,    80,    81,    24,     0,   149,    27,   149,     4,   153,
      31,   153,    47,    34,    49,    50,    95,    47,     0,    47,
      50,    49,    82,    36,    37,    38,   128,    27,    88,    10,
      29,    52,    53,    54,    55,    56,    23,    24,    19,   118,
     119,    48,   115,    24,    66,    67,    27,    25,    26,   128,
      68,    69,    70,    34,    30,    47,    46,   117,    60,    61,
      62,    63,    64,    65,   143,    45,    35,    28,    27,   148,
      49,    52,    53,    54,    55,    56,    48,     5,     6,     7,
       8,    27,    50,    11,   144,    13,    28,    15,    32,   149,
      18,    32,    20,   153,    39,    40,    41,    42,    43,    44,
      32,    49,    32,     9,    28,     4,    49,   117,   128,    49,
      49,   144,    59,    -1,   131,    -1,    -1,    -1,    -1,    57,
      -1,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    59,    60,    61,    64,     0,     0,    60,    48,
       5,     6,     7,     8,    11,    13,    15,    18,    20,    65,
      29,    65,    47,    49,    10,    19,    24,    27,    34,    52,
      53,    54,    56,    64,    74,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    27,    31,    75,    76,
      83,    76,    83,    27,    29,    87,    30,    47,    46,    45,
      39,    40,    41,    42,    43,    44,    23,    24,    36,    37,
      38,    35,    25,    26,    64,    66,    67,    68,    12,    14,
      16,    17,    31,    61,    62,    63,    64,    69,    70,    71,
      72,    73,    76,    86,    49,    50,    28,    75,    76,    65,
      77,    78,    79,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    82,    83,    48,    28,    50,    27,    27,
      75,    76,    69,    76,    32,    32,    69,    49,    50,    75,
      28,    30,    65,    67,    74,    76,    49,    49,    32,    49,
      63,    76,    87,    49,    28,    74,    70,    72,    49,     9,
      74,    71,    72,    28,    71,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    68,    69,    69,
      70,    70,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    80,    81,    81,    81,    81,    82,    82,    83,
      83,    83,    84,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     4,     6,     7,     8,     1,
       0,     3,     1,     1,     1,     1,     5,     1,     1,     1,
       1,     1,     5,     1,     0,     3,     1,     3,     2,     1,
       1,     1,     9,     7,     5,     9,     7,     1,     2,     3,
       3,     3,     1,     1,     0,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     1,     2,
       2,     1,     2,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 95 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[-1].decl); parser_result = (yyval.decl); }
#line 1413 "src/parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 99 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[-1].decl) -> next = (yyvsp[0].decl); (yyval.decl) = (yyvsp[-1].decl); }
#line 1419 "src/parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = 0; }
#line 1425 "src/parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 105 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-3].name), (yyvsp[-1].type), 0, 0, 0);}
#line 1431 "src/parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-5].name), (yyvsp[-3].type), (yyvsp[-1].expr), 0, 0);}
#line 1437 "src/parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-6].name), (yyvsp[-4].type), 0, stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0, 0), 0); }
#line 1443 "src/parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 111 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-7].name), (yyvsp[-5].type), (yyvsp[-2].expr) , 0, 0);  }
#line 1449 "src/parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 115 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1455 "src/parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 117 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = 0;}
#line 1461 "src/parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 121 "src/parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = expr_create_decl(EXPR_ARR_DECL, (yyvsp[-2].expr)); (yyvsp[-2].expr) -> next = (yyvsp[0].expr); }
#line 1467 "src/parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1473 "src/parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "src/parser.bison" /* yacc.c:1646  */
    {(yyval.name) = strdup(yytext); }
#line 1479 "src/parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 130 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, 0, 0); }
#line 1485 "src/parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 132 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0);}
#line 1491 "src/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 134 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), 0); (yyval.type) -> arr_expr = (yyvsp[-2].expr);}
#line 1497 "src/parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 136 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0);}
#line 1503 "src/parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 138 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FLOAT, 0, 0);}
#line 1509 "src/parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 140 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, 0, 0);}
#line 1515 "src/parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 142 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_VOID, 0, 0);}
#line 1521 "src/parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 144 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_AUTO, 0, 0);}
#line 1527 "src/parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 146 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[-3].type), (yyvsp[-1].param_list));}
#line 1533 "src/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 149 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1539 "src/parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 151 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = 0;}
#line 1545 "src/parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 155 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[-2].param_list) ->next = (yyvsp[0].param_list); (yyval.param_list) = (yyvsp[-2].param_list);}
#line 1551 "src/parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "src/parser.bison" /* yacc.c:1646  */
    {(yyval.param_list) = (yyvsp[0].param_list);}
#line 1557 "src/parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 161 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create( (yyvsp[-2].name), (yyvsp[0].type), 0); }
#line 1563 "src/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 165 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[-1].stmt) -> next = (yyvsp[0].stmt); (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1569 "src/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1575 "src/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 171 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1581 "src/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 173 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1587 "src/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 177 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[0].stmt) -> indent = 0; (yyval.stmt) = stmt_create( STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0);}
#line 1593 "src/parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 179 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[-2].stmt) -> indent = 0; (yyvsp[0].stmt) -> else_if = 0; (yyval.stmt) = stmt_create( STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0);}
#line 1599 "src/parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 181 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[0].stmt) -> indent = 0; (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-2].expr), 0, (yyvsp[0].stmt), 0, 0);}
#line 1605 "src/parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 185 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[0].stmt) -> indent = 0; (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0 ,0); }
#line 1611 "src/parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 187 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[-2].stmt) -> indent = 0; (yyvsp[0].stmt) -> else_if = 0; (yyval.stmt) = stmt_create( STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0); }
#line 1617 "src/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 189 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1623 "src/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 194 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create( STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1629 "src/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create( STMT_RETURN, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1635 "src/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 198 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create( STMT_PRINT, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0);}
#line 1641 "src/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 200 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create( STMT_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0, 0);}
#line 1647 "src/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 202 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create( STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0, 0); }
#line 1653 "src/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 206 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1659 "src/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 208 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1665 "src/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 212 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[-2].expr) -> next = (yyvsp[0].expr); (yyval.expr) = (yyvsp[-2].expr); }
#line 1671 "src/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 214 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1677 "src/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create (EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1683 "src/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 220 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1689 "src/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 224 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1695 "src/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 226 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1701 "src/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 230 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1707 "src/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 232 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1713 "src/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 236 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LT,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1719 "src/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 238 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LE,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1725 "src/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 240 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GT,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1731 "src/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 242 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GE,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1737 "src/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 244 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EQ,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1743 "src/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 246 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NE,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1749 "src/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 248 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1755 "src/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 252 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ADD,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1761 "src/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 254 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUB,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1767 "src/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 256 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1773 "src/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 260 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MUL,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1779 "src/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 262 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); if ((yyvsp[0].expr) == 0) {printf("cannot divide by zero!\n");} }
#line 1785 "src/parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 264 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_REMAIN,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1791 "src/parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 266 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1797 "src/parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 270 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EXPON, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1803 "src/parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 272 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1809 "src/parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 276 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUB, 0, (yyvsp[0].expr)); }
#line 1815 "src/parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 278 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LOGICALNOT, 0, (yyvsp[0].expr)); }
#line 1821 "src/parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 280 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1827 "src/parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 284 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_INCREMENT, (yyvsp[-1].expr), 0); }
#line 1833 "src/parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 286 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DECREMENT, (yyvsp[-1].expr), 0); }
#line 1839 "src/parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 288 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1845 "src/parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 292 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[-1].expr) -> group = 1; (yyval.expr) = (yyvsp[-1].expr); }
#line 1851 "src/parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 294 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1857 "src/parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 298 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_char_literal(strdup(yytext));}
#line 1863 "src/parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 300 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_integer_literal(atoi(yytext));}
#line 1869 "src/parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 302 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(0);}
#line 1875 "src/parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 304 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(1);}
#line 1881 "src/parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 306 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_float_literal(atof(yytext));}
#line 1887 "src/parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 308 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_string_literal(strdup(yytext));}
#line 1893 "src/parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 310 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr)  = expr_create_mid(EXPR_ARRAY, (yyvsp[-1].name), (yyvsp[0].expr));}
#line 1899 "src/parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 314 "src/parser.bison" /* yacc.c:1646  */
    { (yyvsp[-2].expr)->next = (yyvsp[0].expr); (yyval.expr) = (yyvsp[-2].expr); }
#line 1905 "src/parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 316 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1911 "src/parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 318 "src/parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1917 "src/parser.c" /* yacc.c:1646  */
    break;


#line 1921 "src/parser.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 320 "src/parser.bison" /* yacc.c:1906  */


int yyerror(char* str) {
    printf("parse error: %s\n", str);
    return 1;
}
