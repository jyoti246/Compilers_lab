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
#line 1 "ass6_17CS10059.y" /* yacc.c:339  */

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
extern int yylex();
void yyerror(string s);
extern int yydebug;
extern int yyparse();

#include "ass6_17CS10059_translator.h"

Quad_Array Q_arr;
symboltable GT;
symboltable *sym = &GT;
symboltable *curr_sym = sym;
type_inf *global_type;
int global_width;

vector<string> string_lits;
int literal_count = 0;

int keep_count = 0;

void increase_k(){
    keep_count++;
}


#line 96 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT = 270,
    FOR = 271,
    GOTO_KEYWORD = 272,
    IF = 273,
    INLINE = 274,
    INT = 275,
    LONG = 276,
    REGISTER = 277,
    RESTRICT = 278,
    RETURN_KEYWORD = 279,
    SHORT = 280,
    SIGNED = 281,
    SIZEOF = 282,
    STATIC = 283,
    STRUCT = 284,
    SWITCH = 285,
    TYPEDEF = 286,
    UNION = 287,
    UNSIGNED = 288,
    VOID = 289,
    VOLATILE = 290,
    WHILE = 291,
    BOOL = 292,
    COMPLEX = 293,
    IMAGINARY = 294,
    POINTER = 295,
    INCREMENT = 296,
    DECREMENT = 297,
    LEFT_SHIFT = 298,
    RIGHT_SHIFT = 299,
    LESS_EQUALS = 300,
    GREATER_EQUALS = 301,
    EQUALS = 302,
    NOT_EQUALS = 303,
    AND_OP = 304,
    OR_OP = 305,
    ELLIPSIS = 306,
    MULTIPLY_ASSIGN = 307,
    DIVIDE_ASSIGN = 308,
    MODULO_ASSIGN = 309,
    ADD_ASSIGN = 310,
    SUBTRACT_ASSIGN = 311,
    LEFT_SHIFT_ASSIGN = 312,
    RIGHT_SHIFT_ASSIGN = 313,
    AND_ASSIGN = 314,
    XOR_ASSIGN = 315,
    OR_ASSIGN = 316,
    SCOMMENT = 317,
    MCOMMENT = 318,
    ID = 319,
    CONST_INT = 320,
    CONST_ENUM = 321,
    CONST_FLT = 322,
    STRING = 323,
    CONST_CHAR = 324
  };
#endif
/* Tokens.  */
#define AUTO 258
#define BREAK 259
#define CASE 260
#define CHAR 261
#define CONST 262
#define CONTINUE 263
#define DEFAULT 264
#define DO 265
#define DOUBLE 266
#define ELSE 267
#define ENUM 268
#define EXTERN 269
#define FLOAT 270
#define FOR 271
#define GOTO_KEYWORD 272
#define IF 273
#define INLINE 274
#define INT 275
#define LONG 276
#define REGISTER 277
#define RESTRICT 278
#define RETURN_KEYWORD 279
#define SHORT 280
#define SIGNED 281
#define SIZEOF 282
#define STATIC 283
#define STRUCT 284
#define SWITCH 285
#define TYPEDEF 286
#define UNION 287
#define UNSIGNED 288
#define VOID 289
#define VOLATILE 290
#define WHILE 291
#define BOOL 292
#define COMPLEX 293
#define IMAGINARY 294
#define POINTER 295
#define INCREMENT 296
#define DECREMENT 297
#define LEFT_SHIFT 298
#define RIGHT_SHIFT 299
#define LESS_EQUALS 300
#define GREATER_EQUALS 301
#define EQUALS 302
#define NOT_EQUALS 303
#define AND_OP 304
#define OR_OP 305
#define ELLIPSIS 306
#define MULTIPLY_ASSIGN 307
#define DIVIDE_ASSIGN 308
#define MODULO_ASSIGN 309
#define ADD_ASSIGN 310
#define SUBTRACT_ASSIGN 311
#define LEFT_SHIFT_ASSIGN 312
#define RIGHT_SHIFT_ASSIGN 313
#define AND_ASSIGN 314
#define XOR_ASSIGN 315
#define OR_ASSIGN 316
#define SCOMMENT 317
#define MCOMMENT 318
#define ID 319
#define CONST_INT 320
#define CONST_ENUM 321
#define CONST_FLT 322
#define STRING 323
#define CONST_CHAR 324

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "ass6_17CS10059.y" /* yacc.c:355  */

  int intval;
  float floatval;
  char charval;
  string *str;
  exp_attr *expr_attr;
  declaration *decclist;
  init_dec_list *init_dec_list_;
  type_inf *type_;
  func_def *func_def_;
  func_list *func_list_;

#line 287 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 304 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  365

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,     2,     2,     2,    85,    78,     2,
      70,    71,    79,    80,    77,    81,    74,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    93,
      86,    92,    87,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    89,    76,    82,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   121,   128,   137,   154,   171,   188,   197,
     204,   208,   229,   231,   251,   253,   255,   277,   299,   301,
     304,   314,   325,   327,   349,   372,   406,   408,   411,   414,
     417,   420,   423,   426,   430,   432,   435,   439,   553,   665,
     777,   780,   891,  1002,  1005,  1064,  1125,  1128,  1161,  1194,
    1225,  1257,  1260,  1291,  1324,  1326,  1358,  1360,  1391,  1393,
    1425,  1427,  1471,  1473,  1517,  1519,  1566,  1569,  1572,  1575,
    1578,  1581,  1584,  1587,  1590,  1593,  1596,  1600,  1603,  1630,
    1634,  1638,  1643,  1646,  1770,  1773,  1776,  1780,  1783,  1786,
    1789,  1792,  1801,  1806,  1812,  1817,  1823,  1826,  1829,  1832,
    1836,  1842,  1848,  1851,  1857,  1860,  1866,  1869,  1872,  1875,
    1878,  1881,  1884,  1888,  1892,  1896,  1899,  1903,  1905,  1907,
    1910,  1913,  1917,  1920,  1924,  1926,  1929,  1932,  1935,  1939,
    1943,  1948,  1961,  1966,  1971,  1978,  1982,  1986,  1990,  2042,
    2045,  2047,  2049,  2051,  2054,  2062,  2065,  2075,  2079,  2082,
    2085,  2086,  2090,  2095,  2099,  2105,  2111,  2133,  2137,  2140,
    2145,  2150,  2154,  2158,  2163,  2167,  2171,  2175,  2180,  2184,
    2187,  2191,  2194,  2199,  2202,  2205,  2208,  2211,  2214,  2218,
    2221,  2224,  2228,  2231,  2236,  2241,  2248,  2252,  2256,  2261,
    2265,  2269,  2281,  2292,  2296,  2308,  2316,  2330,  2334,  2337,
    2340,  2343,  2352,  2379,  2382,  2386,  2389,  2393,  2396,  2430,
    2432
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO_KEYWORD", "IF", "INLINE", "INT", "LONG", "REGISTER",
  "RESTRICT", "RETURN_KEYWORD", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE",
  "WHILE", "BOOL", "COMPLEX", "IMAGINARY", "POINTER", "INCREMENT",
  "DECREMENT", "LEFT_SHIFT", "RIGHT_SHIFT", "LESS_EQUALS",
  "GREATER_EQUALS", "EQUALS", "NOT_EQUALS", "AND_OP", "OR_OP", "ELLIPSIS",
  "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "MODULO_ASSIGN", "ADD_ASSIGN",
  "SUBTRACT_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "SCOMMENT", "MCOMMENT", "ID",
  "CONST_INT", "CONST_ENUM", "CONST_FLT", "STRING", "CONST_CHAR", "'('",
  "')'", "'['", "']'", "'.'", "'{'", "'}'", "','", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "':'", "'='", "';'", "$accept", "M", "N", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "AND_expression", "exclusive_OR_expression",
  "inclusive_OR_expression", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression", "assignment_operator",
  "assignment_expression", "constant_expression", "expression",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "specifier_qualifier_list", "specifier_qualifier_list_opt",
  "enum_specifier", "ID_opt", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "assignment_expression_opt",
  "type_qualifier_list_opt", "pointer", "type_qualifier_list",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "expression_opt", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      40,    41,    91,    93,    46,   123,   125,    44,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59
};
# endif

#define YYPACT_NINF -271

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-271)))

#define YYTABLE_NINF -121

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1157,  -271,  -271,  -271,  -271,   -44,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,   -15,  1157,  1157,  -271,  1157,  1157,  1120,
    -271,  -271,   -28,     5,  -271,    43,    18,  -271,    12,  -271,
     301,   121,    -3,  -271,  -271,  -271,  -271,  -271,  -271,   -12,
      30,  -271,  -271,    18,    43,  -271,   381,   848,  -271,   -15,
    -271,    37,   782,    95,   121,    22,    55,  -271,  -271,  -271,
    -271,  -271,    71,    11,   928,    93,   101,  -271,   139,   171,
     176,   143,   948,   179,  -271,   978,   978,   162,  -271,  -271,
    -271,  -271,   701,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,   223,   289,   928,  -271,    81,    74,   160,    39,   185,
     182,   169,   183,   222,   -21,  -271,  -271,   197,  -271,  -271,
    -271,  -271,   200,  -271,  -271,   184,  -271,  -271,  -271,  -271,
     828,  -271,  -271,  -271,  -271,  -271,    43,   207,  -271,   205,
    -271,    32,   144,   998,   145,   928,  -271,   -30,  -271,  -271,
    -271,   192,  -271,   623,   623,   543,   196,   928,  -271,    82,
     701,  -271,   928,   215,   701,  -271,  -271,   623,    50,  1191,
    -271,  1191,   219,   227,  -271,  -271,   878,   928,   232,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
     928,  -271,   928,   928,   928,   928,   928,   928,   928,   928,
     928,   928,   928,   928,   928,   928,   928,   928,   249,   -11,
     928,  -271,   462,  -271,   928,   235,  -271,   161,   848,   -55,
    -271,  -271,  -271,  1079,  -271,   236,   928,   144,   228,  -271,
     230,   928,  -271,  -271,  -271,   623,  -271,  -271,   928,   212,
    -271,   197,  -271,   238,   110,   928,   239,  -271,  -271,  -271,
    -271,  -271,   898,  -271,  -271,   111,  -271,    51,  -271,  -271,
    -271,  -271,  -271,    81,    81,    74,    74,   160,   160,   160,
     160,    39,    39,   185,   182,   169,  -271,  -271,  -271,  -271,
    -271,   244,  -271,  -271,   602,  -271,  -271,  -271,  -271,  -271,
    -271,   245,  -271,  -271,   246,  -271,   292,   237,  -271,   254,
     256,   623,   197,   256,   828,  -271,  -271,   928,  -271,   928,
     928,   928,  -271,  -271,  -271,   848,  -271,  -271,   262,   928,
     928,  -271,  -271,   266,   163,  -271,   183,  -271,   197,  -271,
     928,   280,  -271,   623,  -271,  -271,   784,  -271,   249,   242,
     112,   623,   259,  -271,   623,  -271,  -271,   260,  -271,  -271,
     342,  -271,   928,  -271,   928,  -271,  -271,  -271,   623,   284,
    -271,  -271,  -271,   623,  -271
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    98,   101,   126,   106,   121,    96,   105,   129,   103,
     104,    99,   127,   102,   107,    97,   108,   100,   128,   109,
     110,   111,   206,     0,    85,    86,   112,    90,    91,     0,
     203,   205,   119,     0,   132,     0,   144,    82,     0,    92,
      94,   131,     0,    84,    87,    88,    89,     1,   204,     0,
       0,   148,   146,   145,     0,    83,   190,     0,   209,     0,
     208,     0,   151,   143,   130,   124,     0,   122,   133,   149,
     147,    93,    94,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     4,     5,     6,
       8,     7,     0,   182,    28,    29,    30,    31,    32,    33,
      10,    22,    34,     0,    36,    40,    43,    46,    51,    54,
      56,    58,    60,    62,    64,    77,    80,   189,   186,   187,
     173,   174,     2,   184,   175,     0,   176,   177,   178,     4,
       0,   161,    95,   210,   207,   158,   157,     0,   150,   152,
     154,     0,   143,   141,   142,     0,   117,     0,   200,    34,
      79,     0,   199,   190,   190,   190,     0,     0,   201,     0,
       0,    26,     0,     0,     0,    23,    24,   190,     0,   116,
     160,   116,     0,     0,    16,    17,     0,     0,     0,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    66,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   190,   188,     0,     0,   164,     0,     0,     0,
     169,   156,   138,     0,   139,     0,     0,   142,    29,   140,
       0,     0,   125,   118,   123,   190,   181,     2,   190,     0,
     198,     3,   202,     0,     0,     0,     0,   179,     9,   115,
     113,   114,     0,    15,    12,     0,    20,     0,    14,    78,
      37,    38,    39,    41,    42,    44,    45,    49,    50,    47,
      48,    52,    53,    55,    57,    59,     2,     2,     2,    81,
     185,     0,   172,   162,     0,   165,   168,   170,   153,   155,
     159,     0,   137,   134,     0,   180,     0,     0,     2,     0,
      27,   190,     3,     0,     0,    35,    13,     0,    11,     0,
       0,     0,   171,   163,   166,     0,   135,   136,     0,   190,
     190,     2,   193,     0,     0,    21,     3,     3,     3,   167,
       0,     0,     3,   190,     2,    18,     0,    61,    63,     0,
       0,   190,     0,     3,   190,    19,     2,     0,   197,     2,
     192,   194,     0,   195,   190,     2,    65,     3,   190,     0,
       3,     2,   191,   190,   196
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -271,   -80,  -112,  -271,  -271,  -271,   -58,  -271,   -94,    60,
      46,     0,    64,   151,   152,   150,    52,    49,  -271,   -64,
    -271,   -57,  -137,   -69,   -35,     6,  -271,   306,  -271,   -54,
      48,   191,  -271,  -271,  -271,   216,   142,  -271,   -20,   322,
    -271,   224,    58,   -50,  -271,  -271,  -271,   147,  -271,  -142,
     -56,    61,  -270,  -271,   148,   -71,  -271,   -29,  -271,   156,
    -271,  -148,  -271,  -271,  -271,  -271,   343,  -271,  -271
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   154,   208,   100,   101,   255,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     190,   116,   151,   117,    22,    59,    38,    39,    24,    25,
     170,   250,    26,    33,    66,    67,    27,    28,    72,    41,
     230,   143,    42,    53,   137,   138,   139,   140,   141,   172,
     216,   217,   218,   219,   220,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    29,    30,    31,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     131,   132,   209,    40,   163,    58,    23,   239,   232,   191,
     150,    60,   159,   144,   315,    50,   149,   214,   243,   215,
      32,   118,   246,   168,   161,     3,   133,   165,   166,    -3,
      43,    44,   134,    45,    46,    23,    65,   286,   169,   277,
       1,    12,   212,     2,     3,   149,   233,  -120,     4,    34,
       5,     6,     7,    18,    65,    35,     8,     9,    10,    11,
      12,    34,    13,    14,    36,    15,   315,    35,   136,    -3,
      16,    17,    18,   131,    19,    20,    21,   281,    37,   278,
      49,   150,   236,   237,   199,   200,   229,   149,   241,    54,
     297,   168,   227,   244,    52,   168,   247,    36,   260,   261,
     262,    68,     3,   224,   148,    55,   169,    34,   257,   225,
     169,    70,    56,    35,   145,   169,   221,   169,    12,   256,
     238,   248,    36,   142,   308,   201,   202,   210,   210,   299,
      18,   146,   147,   259,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     150,     3,     3,   279,   195,   196,   149,   296,   305,   210,
     192,   131,   285,    57,   295,   193,   194,    12,    12,   291,
      82,   331,   332,   231,   294,   242,   302,   118,    51,    18,
      18,   301,   306,   347,    85,    86,   152,   210,   307,   210,
     323,    62,   153,    63,   149,    69,   309,   310,   311,   267,
     268,   269,   270,   197,   198,    51,   357,   129,    88,   155,
      89,    90,    91,    92,   337,   338,   339,   249,   320,   249,
     342,    94,    95,    96,    97,    98,    99,   131,   314,   136,
     322,   350,   203,   204,   171,   156,   158,   283,   284,   335,
     336,   333,   328,   265,   266,   359,   157,   131,   362,   162,
     325,   149,   149,   167,   344,   263,   264,   206,   131,   329,
     205,   340,   343,   173,   174,   175,   352,   271,   272,   354,
     348,    -3,   207,   351,   210,   358,   211,   213,   222,   131,
     314,   363,   223,   235,    51,   245,    69,   360,   356,   240,
     252,   253,   364,   176,   149,   177,   258,   178,   276,   282,
     290,   292,   171,   293,     1,   298,   171,     2,     3,   300,
     303,   171,     4,   171,     5,     6,     7,   312,   316,   317,
       8,     9,    10,    11,    12,   321,    13,    14,   318,    15,
     319,   304,   330,   346,    16,    17,    18,   334,    19,    20,
      21,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   341,   349,   353,   355,   361,   273,   275,   274,   327,
      71,   326,   251,   234,    64,   324,   226,   287,   280,    69,
     289,     0,    48,     0,     0,     0,    56,     0,     0,     0,
       0,   189,     0,     0,     1,    73,    74,     2,     3,    75,
      76,    77,     4,    57,     5,     6,     7,    78,    79,    80,
       8,     9,    10,    11,    12,    81,    13,    14,    82,    15,
       0,    83,     0,     0,    16,    17,    18,    84,    19,    20,
      21,     0,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,     0,    89,    90,
      91,    92,     0,     0,     0,     0,    56,    93,     0,    94,
      95,    96,    97,    98,    99,     1,    73,    74,     2,     3,
      75,    76,    77,     4,     0,     5,     6,     7,    78,    79,
      80,     8,     9,    10,    11,    12,    81,    13,    14,    82,
      15,     0,    83,     0,     0,    16,    17,    18,    84,    19,
      20,    21,     0,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,     0,    89,
      90,    91,    92,     0,     0,     0,     0,    56,     0,     0,
      94,    95,    96,    97,    98,    99,     1,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
      82,    15,     0,     0,     0,     0,    16,    17,    18,     0,
      19,    20,    21,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,    88,     0,
      89,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,    73,    74,    82,
       0,    75,    76,    77,     0,     0,     0,     0,     0,    78,
      79,    80,     0,    85,    86,     0,     0,    81,     0,     0,
      82,     0,     0,    83,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,    85,    86,   129,    88,     0,    89,
      90,    91,    92,     0,   214,     0,   215,   130,   313,     0,
      94,    95,    96,    97,    98,    99,     0,    87,    88,     0,
      89,    90,    91,    92,     0,     0,     0,     0,    56,     0,
       0,    94,    95,    96,    97,    98,    99,     2,     3,     0,
       0,     0,     4,     0,     5,     0,     7,     0,     0,     0,
       0,     9,    10,     0,    12,     0,    13,    14,    82,     0,
       0,     0,     0,     0,    16,    17,    18,     0,    19,    20,
      21,     0,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,    88,     0,    89,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,     1,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,    11,    12,     0,    13,    14,     0,
      15,    82,     0,     0,     0,    16,    17,    18,     0,    19,
      20,    21,     0,     0,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   129,    88,
       0,    89,    90,    91,    92,    82,   214,     0,   215,   130,
     345,     0,    94,    95,    96,    97,    98,    99,     0,    85,
      86,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,     0,   129,    88,     0,    89,    90,    91,    92,     0,
     214,     0,   215,   130,     0,    82,    94,    95,    96,    97,
      98,    99,   129,    88,     0,    89,    90,    91,    92,    85,
      86,     0,     0,   130,     0,    82,    94,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,     0,    85,
      86,     0,   129,    88,     0,    89,    90,    91,    92,   254,
       0,     0,     0,     0,     0,    82,    94,    95,    96,    97,
      98,    99,   129,    88,     0,    89,    90,    91,    92,    85,
      86,     0,     0,   304,     0,    82,    94,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,     0,    85,
      86,     0,   129,    88,     0,    89,    90,    91,    92,     0,
       0,     0,     0,     0,     0,    82,    94,    95,    96,    97,
      98,    99,   129,    88,     0,    89,    90,    91,   160,    85,
      86,     0,     0,     0,     0,    82,    94,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,     0,    85,
      86,     0,   129,    88,     0,    89,    90,    91,   164,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   129,    88,     0,    89,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,    94,   228,    96,    97,
      98,    99,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     0,
      47,     0,     0,     1,     0,     0,     2,     3,     0,     0,
     288,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    14,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,    19,    20,    21,     2,     3,     0,
       0,     0,     4,     0,     5,     0,     7,     0,     0,     0,
       0,     9,    10,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,     0,    16,    17,    18,     0,    19,    20,
      21
};

static const yytype_int16 yycheck[] =
{
      57,    57,   114,    23,    84,    40,     0,   155,   145,   103,
      74,    40,    81,    63,   284,    35,    74,    72,   160,    74,
      64,    56,   164,    92,    82,     7,    61,    85,    86,    50,
      24,    25,    61,    27,    28,    29,    66,    92,    92,    50,
       3,    23,   122,     6,     7,   103,    76,    75,    11,    64,
      13,    14,    15,    35,    66,    70,    19,    20,    21,    22,
      23,    64,    25,    26,    79,    28,   336,    70,    62,    90,
      33,    34,    35,   130,    37,    38,    39,   214,    93,    90,
      75,   145,   153,   154,    45,    46,   143,   145,   157,    77,
     238,   160,   142,   162,    36,   164,   167,    79,   192,   193,
     194,    71,     7,    71,    93,    93,   160,    64,   177,    77,
     164,    53,    75,    70,    92,   169,   136,   171,    23,   176,
     155,    71,    79,    28,    73,    86,    87,    77,    77,   241,
      35,    76,    77,   190,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     214,     7,     7,   210,    80,    81,   214,   237,   252,    77,
      79,   218,   218,    92,   235,    84,    85,    23,    23,   226,
      27,   319,   320,    28,   231,    93,   245,   212,    36,    35,
      35,    71,    71,    71,    41,    42,    93,    77,    77,    77,
     302,    70,    91,    72,   252,    53,   276,   277,   278,   199,
     200,   201,   202,    43,    44,    63,   354,    64,    65,    70,
      67,    68,    69,    70,   326,   327,   328,   169,   298,   171,
     332,    78,    79,    80,    81,    82,    83,   284,   284,   223,
     301,   343,    47,    48,    92,    64,    93,    76,    77,    76,
      77,   321,   311,   197,   198,   357,    70,   304,   360,    70,
     307,   309,   310,    91,   334,   195,   196,    88,   315,   315,
      78,   330,   333,    40,    41,    42,   346,   203,   204,   349,
     341,    49,    89,   344,    77,   355,    76,    93,    71,   336,
     336,   361,    77,    91,   142,    70,   144,   358,   352,    93,
      71,    64,   363,    70,   352,    72,    64,    74,    49,    64,
      64,    73,   160,    73,     3,    93,   164,     6,     7,    71,
      71,   169,    11,   171,    13,    14,    15,    73,    73,    73,
      19,    20,    21,    22,    23,    71,    25,    26,    36,    28,
      93,    75,    70,    91,    33,    34,    35,    71,    37,    38,
      39,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    71,    93,    93,    12,    71,   205,   207,   206,   310,
      54,   309,   171,   147,    42,   304,   142,   219,   212,   227,
     223,    -1,    29,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    92,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    92,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    80,    81,    82,    83,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,     4,     5,    27,
      -1,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    -1,    41,    42,    -1,    -1,    24,    -1,    -1,
      27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    64,    65,    -1,    67,
      68,    69,    70,    -1,    72,    -1,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    -1,    64,    65,    -1,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    80,    81,    82,    83,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    -1,    23,    -1,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,     3,    -1,    -1,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      28,    27,    -1,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    39,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    64,    65,
      -1,    67,    68,    69,    70,    27,    72,    -1,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    -1,    41,
      42,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    64,    65,    -1,    67,    68,    69,    70,    -1,
      72,    -1,    74,    75,    -1,    27,    78,    79,    80,    81,
      82,    83,    64,    65,    -1,    67,    68,    69,    70,    41,
      42,    -1,    -1,    75,    -1,    27,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    64,    65,    -1,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    27,    78,    79,    80,    81,
      82,    83,    64,    65,    -1,    67,    68,    69,    70,    41,
      42,    -1,    -1,    75,    -1,    27,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    64,    65,    -1,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    78,    79,    80,    81,
      82,    83,    64,    65,    -1,    67,    68,    69,    70,    41,
      42,    -1,    -1,    -1,    -1,    27,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    64,    65,    -1,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    64,    65,    -1,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,    -1,
       0,    -1,    -1,     3,    -1,    -1,     6,     7,    -1,    -1,
      51,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    37,    38,    39,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,
      39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   118,   119,   122,   123,   126,   130,   131,   159,
     160,   161,    64,   127,    64,    70,    79,    93,   120,   121,
     132,   133,   136,   119,   119,   119,   119,     0,   160,    75,
     132,   130,   136,   137,    77,    93,    75,    92,   118,   119,
     151,   162,    70,    72,   133,    66,   128,   129,    71,   130,
     136,   121,   132,     4,     5,     8,     9,    10,    16,    17,
      18,    24,    27,    30,    36,    41,    42,    64,    65,    67,
      68,    69,    70,    76,    78,    79,    80,    81,    82,    83,
      97,    98,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   115,   117,   118,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    64,
      75,   115,   144,   118,   151,    64,   119,   138,   139,   140,
     141,   142,    28,   135,   137,    92,    76,    77,    93,   100,
     113,   116,    93,    91,    95,    70,    64,    70,    93,   117,
      70,   100,    70,    95,    70,   100,   100,    91,   117,   123,
     124,   130,   143,    40,    41,    42,    70,    72,    74,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    92,
     114,   102,    79,    84,    85,    80,    81,    43,    44,    45,
      46,    86,    87,    47,    48,    78,    88,    89,    96,    96,
      77,    76,    95,    93,    72,    74,   144,   145,   146,   147,
     148,   132,    71,    77,    71,    77,   135,   137,    79,   115,
     134,    28,   116,    76,   129,    91,   149,   149,   118,   155,
      93,   117,    93,   143,   117,    70,   143,   149,    71,   124,
     125,   125,    71,    64,    71,    99,   115,   117,    64,   115,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   105,
     105,   106,   106,   107,   108,   109,    49,    50,    90,   115,
     153,   116,    64,    76,    77,   144,    92,   148,    51,   141,
      64,   115,    73,    73,   115,   149,    95,   155,    93,    96,
      71,    71,   117,    71,    75,   102,    71,    77,    73,    95,
      95,    95,    73,    76,   144,   146,    73,    73,    36,    93,
      95,    71,   149,    96,   145,   115,   110,   111,   117,   144,
      70,   155,   155,    95,    71,    76,    77,    96,    96,    96,
     117,    71,    96,   149,    95,    76,    91,    71,   149,    93,
      96,   149,    95,    93,    95,    12,   113,   155,    95,    96,
     149,    71,    96,    95,   149
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    96,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   116,
     117,   117,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   125,   125,   126,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   131,
     132,   132,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   144,   144,   144,   145,   145,   145,   145,   146,   147,
     147,   148,   148,   149,   149,   149,   149,   149,   149,   150,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   155,
     155,   156,   156,   156,   157,   157,   157,   157,   158,   158,
     158,   158,   158,   159,   159,   160,   160,   161,   161,   162,
     162
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     1,     3,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     6,     1,     6,     1,     9,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     2,     3,     2,     1,     1,     2,     2,     2,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     0,     5,     6,     2,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     1,     1,     3,     5,     6,     6,     5,     4,     4,
       1,     0,     1,     0,     1,     2,     2,     3,     1,     2,
       1,     0,     1,     3,     1,     3,     2,     1,     1,     3,
       1,     1,     3,     4,     1,     2,     3,     4,     2,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     1,     3,     1,     1,     2,     1,
       0,    12,     8,     5,     8,     9,    14,     8,     3,     2,
       2,     2,     3,     1,     2,     1,     1,     4,     3,     1,
       2
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
#line 117 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
    (yyval.expr_attr) = new exp_attr;
    (yyval.expr_attr)->instr = Q_arr.index;}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 121 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
    (yyval.expr_attr) = new exp_attr;
    (yyval.expr_attr)->nextlist = makelist(Q_arr.index);
    Q_arr.emit(GOTO,"","","");
}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 128 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    string t = (*((yyvsp[0].str)));
                                    increase_k();
                                    symtab *h = curr_sym->lookup(t);
                                    (yyval.expr_attr)->loc = t;
                                    increase_k();
                                    /* h -> nested_table = NULL; */
                                }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 137 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    increase_k();
                                    type.type_name = "int";
                                    opcodeType op = COPY;
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    increase_k();
                                    Q_arr.emit(op,(yyval.expr_attr)->loc, (yyvsp[0].intval));
                                    init_value *init = new init_value;
                                    increase_k();
                                    init->int_val = (yyvsp[0].intval);
                                    increase_k();
                                    curr_sym->lookup((yyval.expr_attr)->loc)->init_val = init;
                                    (yyval.expr_attr)->is_pointer_type = 0;
                                }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 154 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    increase_k();
                                    type.type_name = "float";
                                    opcodeType op = COPY;
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,(yyval.expr_attr)->loc, (yyvsp[0].floatval));
                                    increase_k();
                                    init_value *init = new init_value;
                                    init->int_val = (yyvsp[0].floatval);
                                    curr_sym->lookup((yyval.expr_attr)->loc)->init_val = init;
                                    increase_k();
                                    (yyval.expr_attr)->is_pointer_type = 0;
                                }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 171 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    increase_k();
                                    type.type_name = "char";
                                    opcodeType op = COPY;
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,(yyval.expr_attr)->loc, (yyvsp[0].charval));
                                    init_value *init = new init_value;
                                    init->int_val = (yyvsp[0].charval);
                                    increase_k();
                                    curr_sym->lookup((yyval.expr_attr)->loc)->init_val = init;
                                    (yyval.expr_attr)->is_pointer_type = 0;
                                    increase_k();
                                }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 188 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    string s = ".LC";
                                    string temp = to_string(literal_count);
                                    s = s + temp;
                                    (yyval.expr_attr)->loc = s;
                                    literal_count++;
                                    string_lits.push_back(*(yyvsp[0].str));
                                }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 197 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = (yyvsp[-1].expr_attr);
                                    increase_k();
                               }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 204 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                    increase_k();
                                }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 209 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    type_inf t = curr_sym->lookup((yyvsp[-3].expr_attr)->loc)->type;
                                	string s;
                                    type_inf t1;
                                    t1.type_name = "int";
                                	int idx;
                                	string s1;
                                	idx = t.idx;
                                	s = curr_sym->gentemp(t1);
                                        Q_arr.emit(COPY, s, 0);
                                        (yyvsp[-3].expr_attr) -> inner = new string(s);    //temporary for inner dimension
                                	s = *((yyvsp[-3].expr_attr)->inner);
                                	s1 = to_string(idx);

                                    Q_arr.emit(MULT, s, s, s1);
                                    Q_arr.emit(PLUS, s, s, (yyvsp[-1].expr_attr)->loc);
                                    Q_arr.emit(MULT, s, s, string("4"));
                                    (yyval.expr_attr) = (yyvsp[-3].expr_attr);
                                }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 229 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 231 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    string f = (yyvsp[-3].expr_attr)->loc;
                                    increase_k();
                                    symboltable *fsym = GT.lookup(f)->nested_table;
                                    func_list *flist = ((yyvsp[-1].func_list_));
                                    list<func_def*>::iterator it;
                                    increase_k();
                                    int c = 0;
                                    for(it = flist->func_def_list.begin(); it!=flist->func_def_list.end();it++)
                                    {
                                        func_def *f = *it;
                                        c++;
                                        Q_arr.emit(PARAM, f->param_name,"","");
                                    }
                                    increase_k();
                                    string s = to_string(c);
                                    Q_arr.emit(CALL,f,s,"");
                                    increase_k();
                                }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 251 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 253 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 255 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    increase_k();
                                    string s = (yyvsp[-1].expr_attr)->loc;
                                    symtab * f = curr_sym->lookup((yyvsp[-1].expr_attr)->loc);
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(f->type);
                                    increase_k();
                                    if(f->type.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(f->type);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-1].expr_attr)->loc, *((yyvsp[-1].expr_attr)->inner));
                                        Q_arr.emit(COPY, (yyval.expr_attr)->loc, temp, "");
                                        Q_arr.emit(PLUS, temp, temp, "1");
                                        Q_arr.emit(ARRAY_DEREFERENCE, (yyvsp[-1].expr_attr)->loc, temp, *((yyvsp[-1].expr_attr)->inner));
                                    }
                                    else
                                    {
                                        Q_arr.emit(COPY, (yyval.expr_attr)->loc, (yyvsp[-1].expr_attr)->loc, "");
                                        Q_arr.emit(PLUS, (yyvsp[-1].expr_attr)->loc, (yyvsp[-1].expr_attr)->loc, "1");
                                    }
                                    increase_k();
                                }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 277 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    increase_k();
                                    string s = (yyvsp[-1].expr_attr)->loc;
                                    symtab * f = curr_sym->lookup((yyvsp[-1].expr_attr)->loc);
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(f->type);
                                    if(f->type.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(f->type);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-1].expr_attr)->loc, *((yyvsp[-1].expr_attr)->inner));
                                        Q_arr.emit(COPY, (yyval.expr_attr)->loc, temp, "");
                                        Q_arr.emit(MINUS, temp, temp, "1");
                                        Q_arr.emit(ARRAY_DEREFERENCE, (yyvsp[-1].expr_attr)->loc, temp, *((yyvsp[-1].expr_attr)->inner));
                                    }
                                    else
                                    {
                                        Q_arr.emit(COPY, (yyval.expr_attr)->loc, (yyvsp[-1].expr_attr)->loc, "");
                                        Q_arr.emit(MINUS, (yyvsp[-1].expr_attr)->loc, (yyvsp[-1].expr_attr)->loc, "1");
                                    }
                                    increase_k();
                                }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 299 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 301 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 304 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    func_def *f = new func_def;
                                    increase_k();
                                    f->param_name = (yyvsp[0].expr_attr)->loc;
                                    (yyval.func_list_) = new func_list;
                                    increase_k();
                                    f->type = &(curr_sym->lookup(f->param_name)->type);
                                    (yyval.func_list_)->func_def_list.push_back(f);
                                    increase_k();
                                }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 314 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    func_def *f = new func_def;
                                    f->param_name = (yyvsp[0].expr_attr)->loc;
                                    (yyval.func_list_) = new func_list;
                                    increase_k();
                                    f->type = &(curr_sym->lookup(f->param_name)->type);
                                    (yyval.func_list_)->func_def_list.push_back(f);
                                    increase_k();
                                }
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 325 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 327 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    opcodeType op;
                                    op = PLUS;
                                    increase_k();
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    type = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
                                    if(type.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        Q_arr.emit(PLUS, temp, temp, "1");
                                        Q_arr.emit(ARRAY_DEREFERENCE, (yyvsp[0].expr_attr)->loc, temp, *((yyvsp[0].expr_attr)->inner));
                                    }
                                    else
                                        Q_arr.emit(op, (yyval.expr_attr)->loc, (yyvsp[0].expr_attr)->loc, "1");
                                    type = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    op = COPY;
                                    increase_k();
                                    Q_arr.emit(op, (yyvsp[0].expr_attr)->loc, (yyval.expr_attr)->loc, "");
                                }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 349 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    opcodeType op;
                                    op = MINUS;
                                    increase_k();
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    type = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    if(type.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        Q_arr.emit(MINUS, temp, temp, "1");
                                        Q_arr.emit(ARRAY_DEREFERENCE, (yyvsp[0].expr_attr)->loc, temp, *((yyvsp[0].expr_attr)->inner));
                                    }
                                    else
                                        Q_arr.emit(op, (yyval.expr_attr)->loc, (yyvsp[0].expr_attr)->loc, "1");
                                    type = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    op = COPY;
                                    increase_k();
                                    Q_arr.emit(op, (yyvsp[0].expr_attr)->loc, (yyval.expr_attr)->loc, "");
                                }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 372 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    type.type_name = string("int");
                                    if((yyvsp[-1].charval) == '-')
                                    {
                                        increase_k();
                                        (yyval.expr_attr) = new exp_attr;
                                        (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(UNARY_MINUS,(yyval.expr_attr)->loc,(yyvsp[0].expr_attr)->loc,"");
                                    }
                                    else if((yyvsp[-1].charval) == '&')
                                    {
                                        increase_k();
                                        (yyval.expr_attr) = new exp_attr;
                                	    type.pointer_type = "ptr";
                                	    type.pointer_count = 1;
                                	    type.size = 8;
                                        (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(REFERENCE,(yyval.expr_attr)->loc,(yyvsp[0].expr_attr)->loc,"");
                                    }
                                    else if((yyvsp[-1].charval) == '*')
                                    {
                                        increase_k();
                                        (yyval.expr_attr) = new exp_attr;
                                        (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(DEREFERENCE,(yyval.expr_attr)->loc,(yyvsp[0].expr_attr)->loc,"");
                                    }
                                    else
                                    {
                                        increase_k();
                                        (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                    }
                                }
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 406 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 408 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 411 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.charval) = '&';
                                }
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 414 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.charval) = '*';
                                }
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 417 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.charval) = '+';
                                }
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 420 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.charval) = '-';
                                }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 423 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.charval) = '~';
                                }
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 426 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.charval) = '!';
                                }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 430 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 432 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 435 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    /* $$ = $1; */
                                    increase_k();
                                }
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 439 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    increase_k();
                                    if(type1.type_name == type2.type_name)
                                    {
                                        increase_k();
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convI2F(e,(yyvsp[0].expr_attr));
                                        increase_k();
                                        type.type_name = type1.type_name;
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convI2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2F(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MULT, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    increase_k();
                                }
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 553 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    increase_k();
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convI2F(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        increase_k();
                                        Q_arr.convI2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2F(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(DIVIDE, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 665 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convI2F(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convI2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2F(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MODULO, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 777 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    /* $$ = $1; */
                                }
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 780 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    increase_k();
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convI2F(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        increase_k();
                                        Q_arr.convI2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2F(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    increase_k();
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    increase_k();
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(PLUS, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 891 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    increase_k();
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    increase_k();
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convI2F(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convI2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    increase_k();
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2F(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;
                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MINUS, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1002 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    /* $$ = $1; */
                                }
#line 2927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1005 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    /* type_inf type1;
                                    type1 = curr_sym->lookup($3->loc)->type; */
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }
                                    int flag = 0;
                                    increase_k();
                                    // the amount to be shifted should be an integer
                                    if(type1.type_name.compare("int") == 0)
                                    {
                                    }
                                    else
                                    {
                                        if(type1.type_name.compare("float") == 0)
                                        {
                                            increase_k();
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            increase_k();
                                            e->type.type_name = "int";
                                            Q_arr.convF2I(e,(yyvsp[0].expr_attr));
                                        }
                                        else if(type1.type_name.compare("char") == 0)
                                        {
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            increase_k();
                                            e->type.type_name = "int";
                                            Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        }
                                    }
                                    type1.type_name = "int";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type1);
                                    Q_arr.emit(SHIFT_LEFT, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1064 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    /* type_inf type1;
                                    increase_k();
                                    type1 = curr_sym->lookup($3->loc)->type; */
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }
                                    int flag = 0;
                                    // the amount to be shifted should be an integer
                                    if(type1.type_name.compare("int") == 0)
                                    {
                                    }
                                    else
                                    {
                                        if(type1.type_name.compare("float") == 0)
                                        {
                                            increase_k();
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            e->type.type_name = "int";
                                            increase_k();
                                            Q_arr.convF2I(e,(yyvsp[0].expr_attr));
                                        }
                                        else if(type1.type_name.compare("char") == 0)
                                        {
                                            type1.type_name = "int";
                                            increase_k();
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            increase_k();
                                            e->type.type_name = "int";
                                            Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        }
                                    }
                                    type1.type_name = "int";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type1);
                                    Q_arr.emit(SHIFT_RIGHT, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 3056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1125 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    /* $$ = $1; */
                                }
#line 3064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1128 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    // copy pasted part of the code
                                    // the purpose of the code is to check for array accesses and make temporaries
                                    // for such accesses
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_LESS, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 3102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1161 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    // the copy pasted part of the code
                                    // the purpose of the code is to generate temporaries for array accesses
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_GREATER, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    increase_k();
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1194 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    increase_k();
                                    Q_arr.emit(IF_LESS_EQUAL, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 3176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1225 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    increase_k();
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_GREATER_EQUAL, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 3212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1257 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    /* $$ = $1; */
                                }
#line 3220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1260 "ass6_17CS10059.y" /* yacc.c:1646  */
    {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_IS_EQUAL, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 3256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1291 "ass6_17CS10059.y" /* yacc.c:1646  */
    {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    (yyval.expr_attr) = new exp_attr;
                                    increase_k();
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    increase_k();
                                    Q_arr.emit(IF_NOT_EQUAL, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 3293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1324 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 3300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1326 "ass6_17CS10059.y" /* yacc.c:1646  */
    {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    (yyval.expr_attr) = new exp_attr;
                                    increase_k();
                                    symtab *f = curr_sym->lookup((yyvsp[-2].expr_attr)->loc);//check
                                    type_inf t;
                                    t = f->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(t);
                                    increase_k();
                                    Q_arr.emit(LOGICAL_AND, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 3336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1358 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 3343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1360 "ass6_17CS10059.y" /* yacc.c:1646  */
    {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    (yyval.expr_attr) = new exp_attr;
                                    symtab *f = curr_sym->lookup((yyvsp[-2].expr_attr)->loc);//check
                                    increase_k();
                                    type_inf t;
                                    t = f->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(XOR, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 3378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1391 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 3385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1393 "ass6_17CS10059.y" /* yacc.c:1646  */
    {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-2].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                        (yyvsp[-2].expr_attr)->loc = temp;
                                        (yyvsp[-2].expr_attr)->type.array_type = ""; //check
                                    }

                                    (yyval.expr_attr) = new exp_attr;
                                    increase_k();
                                    symtab *f = curr_sym->lookup((yyvsp[-2].expr_attr)->loc);//check
                                    type_inf t;
                                    increase_k();
                                    t = f->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(OR, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 3421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1425 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 3428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1427 "ass6_17CS10059.y" /* yacc.c:1646  */
    {

                                    type_inf type1, type2;
                                    type1 = curr_sym->lookup((yyvsp[-5].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[-1].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-1].expr_attr)->loc, *((yyvsp[-1].expr_attr)->inner));
                                        (yyvsp[-1].expr_attr)->loc = temp;
                                        (yyvsp[-1].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-5].expr_attr)->loc, *((yyvsp[-5].expr_attr)->inner));
                                        (yyvsp[-5].expr_attr)->loc = temp;
                                        (yyvsp[-5].expr_attr)->type.array_type = ""; //check
                                    }

                                    type_inf type;
                                    increase_k();
                                    type.type_name = "bool";
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type = type;
                                    increase_k();
                                    //N required to prevent fall-through
                                    //backpatching is required to convert $1 to bool
                                    Q_arr.backpatch((yyvsp[-4].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-5].expr_attr));
                                    //N required to prevent fall-through
                                    increase_k();
                                    //backpatching is required to convert $5 to bool
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-1].expr_attr));
                                    increase_k();
                                    //as mentioned in the slide
                                    Q_arr.backpatch((yyvsp[-5].expr_attr)->truelist, (yyvsp[-2].expr_attr)->instr);
                                    (yyval.expr_attr)->truelist = (yyvsp[-1].expr_attr)->truelist;
                                    (yyval.expr_attr)->falselist = merge((yyvsp[-5].expr_attr)->falselist, (yyvsp[-1].expr_attr)->falselist);
                                }
#line 3476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1471 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 3483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1473 "ass6_17CS10059.y" /* yacc.c:1646  */
    {

                                    type_inf type1, type2;
                                    type1 = curr_sym->lookup((yyvsp[-5].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[-1].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-1].expr_attr)->loc, *((yyvsp[-1].expr_attr)->inner));
                                        (yyvsp[-1].expr_attr)->loc = temp;
                                        (yyvsp[-1].expr_attr)->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-5].expr_attr)->loc, *((yyvsp[-5].expr_attr)->inner));
                                        (yyvsp[-5].expr_attr)->loc = temp;
                                        (yyvsp[-5].expr_attr)->type.array_type = ""; //check
                                    }

                                    type_inf type;
                                    type.type_name = "bool";
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type = type;
                                    increase_k();
                                    //N required to prevent fall-through
                                    //backpatching is required to convert $1 to bool
                                    Q_arr.backpatch((yyvsp[-4].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-5].expr_attr));
                                    increase_k();
                                    //N required to prevent fall-through
                                    //backpatching is required to convert $5 to bool
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-1].expr_attr));
                                    increase_k();
                                    //this is standard stuff, as mentioned in the slide
                                    Q_arr.backpatch((yyvsp[-5].expr_attr)->falselist, (yyvsp[-2].expr_attr)->instr);
                                    (yyval.expr_attr)->falselist = (yyvsp[-1].expr_attr)->falselist;
                                    (yyval.expr_attr)->truelist = merge((yyvsp[-5].expr_attr)->truelist, (yyvsp[-1].expr_attr)->truelist);
                                }
#line 3530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1517 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 3537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1519 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    type_inf type1, type2;
                                    type1 = curr_sym->lookup((yyvsp[-4].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                    }
                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[-4].expr_attr)->loc, *((yyvsp[-4].expr_attr)->inner));
                                        (yyvsp[-4].expr_attr)->loc = temp;
                                        (yyvsp[-4].expr_attr)->type.array_type = ""; //check
                                    }
                                    (yyval.expr_attr) = new exp_attr;
                                    list<int> I;
                                    type_inf type;
                                    type = curr_sym->lookup((yyvsp[-4].expr_attr)->loc)->type;
                                    increase_k();
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(COPY, (yyval.expr_attr)->loc, (yyvsp[0].expr_attr)->loc,"");
                                    I = makelist(Q_arr.index);
                                    Q_arr.emit(GOTO,"","","");
                                    increase_k();
                                    // for the second N
                                    Q_arr.backpatch((yyvsp[-3].expr_attr)->nextlist, Q_arr.index);
                                    increase_k();
                                    Q_arr.emit(COPY, (yyval.expr_attr)->loc, (yyvsp[-4].expr_attr)->loc, "");
                                    I = merge(I, makelist(Q_arr.index));
                                    Q_arr.emit(GOTO,"", "", "");
                                    increase_k();
                                    // for the first N
                                    Q_arr.backpatch((yyvsp[-7].expr_attr)->nextlist, Q_arr.index);
                                    increase_k();
                                    Q_arr.convInt2Bool((yyvsp[-8].expr_attr));
                                    increase_k();
                                    // the standard stuff from the slides
                                    Q_arr.backpatch((yyvsp[-8].expr_attr)->truelist, (yyvsp[-5].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-8].expr_attr)->falselist, (yyvsp[-1].expr_attr)->instr);
                                    Q_arr.backpatch(I, Q_arr.index);
                                }
#line 3588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1566 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1569 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1572 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1575 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1578 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1581 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1584 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1587 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1590 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1593 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1596 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1600 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1603 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
                                    increase_k();
                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        increase_k();
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, (yyvsp[0].expr_attr)->loc, *((yyvsp[0].expr_attr)->inner));
                                        (yyvsp[0].expr_attr)->loc = temp;
                                        (yyvsp[0].expr_attr)->type.array_type = ""; //check
                                        increase_k();
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        increase_k();
                                        Q_arr.emit(ARRAY_DEREFERENCE, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc, *((yyvsp[-2].expr_attr)->inner));
                                    }
                                    else
                                        Q_arr.emit(COPY, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc, "");
                                    (yyval.expr_attr) = (yyvsp[-2].expr_attr);
                                    increase_k();
                                }
#line 3714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1630 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1634 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                    increase_k();
                                }
#line 3731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1638 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1643 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1647 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    init_dec_list *new_dec = new init_dec_list;
                                    new_dec = (yyvsp[-1].init_dec_list_);
                                    int size = 0;
                                    increase_k();
                                    type_inf *type = (yyvsp[-2].type_);
                                    if(type->type_name.compare("int")==0) size = 4;
                                    if(type->type_name.compare("float")==0) size = 8;
                                    if(type->type_name.compare("char")==0) size = 1;
                                    increase_k();
                                    list<declaration*>::iterator it;
                                    for(it = (yyvsp[-1].init_dec_list_)->dec_list.begin(); it != (yyvsp[-1].init_dec_list_)->dec_list.end(); it++)
                                    {
                                        increase_k();
                                        declaration *new_dec = *it;
                                        if(new_dec->type!=NULL){
                                        if(new_dec->type->type_name.compare("function")==0)
                                        {
                                            string name = new_dec->dec_name;
                                            //cout<<name<<"\n";
                                            curr_sym = &GT;
                                            Q_arr.emit(_FUNCTION_END,name,"","");
                                            //write an emit
                                            increase_k();
                                        }
                                        increase_k();
                                        symtab *ret, *f;
                                        symboltable *nest;
                                        if(new_dec->type->type_name.compare("function")==0)
                                        {
                                            f = curr_sym->lookup(new_dec->dec_name, type->type_name);
                                            nest = f->nested_table;
                                            ret = nest->lookup("retVal", type->type_name, new_dec->pointer_count);
                                            f->offset = curr_sym->offset;
                                            increase_k();
                                            f->size = size;
                                            f->init_val = NULL;
                                            continue;
                                        }
                                	}
                                        increase_k();

                                        symtab *f1 = curr_sym->lookup(new_dec->dec_name, type->type_name);
                                        increase_k();
                                        f1->nested_table = NULL;
                                        increase_k();
                                        //condition for id
                                        if(new_dec->alist == vector<int>() && new_dec->pointer_count == 0)
                                        {
                                            f1->offset = curr_sym->offset;
                                            increase_k();
                                            //f1->offset = f1->offset + size;
                                            f1->type = *type;
                                            f1 = curr_sym->lookup(new_dec->dec_name, type->type_name);
                                            increase_k();
                                            if(new_dec->init != NULL)
                                            {
                                                increase_k();
                                                string x = new_dec->init->loc;
                                                Q_arr.emit(COPY, new_dec->dec_name, x, "");
                                                f1->init_val = curr_sym->lookup(x,f1->type.type_name)->init_val;
                                            }
                                            else
                                                new_dec->init = NULL;
                                        }

                                        else if(new_dec -> pointer_count > 0)
                                        {
                                            increase_k();
                                            symtab *sp;
                                            for(sp = curr_sym->sym_table; sp < &curr_sym->sym_table[curr_sym->no_of_entries]; sp++)
                                            {
                                                increase_k();
                                                if(!sp->id.empty() && !sp->id.compare(new_dec->dec_name))
                                                {
                                                    increase_k();
                                                    sp->offset = curr_sym->offset-4;
                                                    sp->pointer_count = new_dec->pointer_count;
                                                    sp->type = *type;
                                                    sp->type.pointer_type = "ptr";
                                                    sp->size = 4;
                                                    increase_k();
                                                }
                                            }
                                        }
                                        else if(new_dec->alist!=vector<int>())
                                        {
                                            symtab *sp;
                                            increase_k();
                                            for(sp = curr_sym->sym_table; sp < &curr_sym->sym_table[curr_sym->no_of_entries]; sp++)
                                            {
                                                increase_k();
                                                if(!sp->id.empty() && !sp->id.compare(new_dec->dec_name))
                                                {
                                                    int temp_size = size;
                                                    sp->offset = curr_sym->offset-4;
                                                    sp->type = *type;
                                                    increase_k();
                            			            sp->type.type_name = type->type_name;
                                                    sp->type.array_type = "array";
                                                    increase_k();
                                                    sp->type.pointer_type = "";
                            			            for(int i = 0; i < new_dec->alist.size(); i++)
                                                    {
                                                        increase_k();
                                                        sp->type.array_list.push_back(new_dec->alist[i]);
                                                    }

                                                    for (int i = 0; i < sp->type.array_list.size(); ++i)
                                                    {
                                                        increase_k();
                                                        temp_size = temp_size * sp->type.array_list[i];
                                                    }
                                                    increase_k();
                                                    sp->size = temp_size;
                                                    curr_sym->offset = curr_sym->offset + temp_size;
                                                }
                                            }
                                        }
                                    }
                                }
#line 3874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1770 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1773 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1776 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.type_) = (yyvsp[0].type_);
                                    increase_k();
                                }
#line 3899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1780 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1783 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1786 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1789 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1792 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1801 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.init_dec_list_) = new init_dec_list;
                                    (yyval.init_dec_list_)->dec_list.push_back((yyvsp[0].decclist));
                                }
#line 3949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1806 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].init_dec_list_)->dec_list.push_back((yyvsp[0].decclist));
                                    (yyval.init_dec_list_) = (yyvsp[-2].init_dec_list_);
                                    increase_k();
                                }
#line 3959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1812 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.decclist) = (yyvsp[0].decclist);
                                    (yyval.decclist)->init = NULL;
                                }
#line 3969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1817 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.decclist) = (yyvsp[-2].decclist);
                                    (yyval.decclist)->init = (yyvsp[0].expr_attr);
                                    increase_k();
                                }
#line 3979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1823 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1826 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 3995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1829 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1832 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1836 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("void");
                                    (yyval.type_)->next = NULL;
                                }
#line 4022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1842 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("char");
                                    (yyval.type_)->next = NULL;
                                }
#line 4033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1848 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1851 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("int");
                                    (yyval.type_)->next = NULL;
                                }
#line 4052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1857 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1860 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("float");
                                    (yyval.type_)->next = NULL;
                                }
#line 4071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1866 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1869 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1872 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1875 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1878 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1881 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1884 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1888 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.type_) = (yyvsp[-1].type_);
                                    increase_k();
                                }
#line 4136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1892 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1896 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1899 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1903 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 4167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1905 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 4174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1907 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 4181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1910 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1913 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1917 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1920 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1924 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 4220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1926 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 4227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1929 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1932 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1935 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1939 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1943 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.decclist) = (yyvsp[0].decclist);
                                    increase_k();
                                    (yyval.decclist)->pointer_count = (yyvsp[-1].type_)->pointer_count;
                                }
#line 4269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1948 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.decclist) = (yyvsp[0].decclist);
                                    (yyval.decclist)->pointer_count = 0;
                                    increase_k();
                                }
#line 4279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1961 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.decclist) = new declaration;
                                    (yyval.decclist)->dec_name = *((yyvsp[0].str));
                                }
#line 4289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1967 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.decclist) = (yyvsp[-1].decclist);
                                }
#line 4298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1972 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.decclist) = (yyvsp[-4].decclist);
                            	    int idx = curr_sym->lookup((yyvsp[-1].expr_attr)->loc)->init_val->int_val;
                            	    (yyval.decclist)->alist.push_back(idx);
                            	}
#line 4309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1979 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1983 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1987 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1991 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    list<func_def*> l = (yyvsp[-1].func_list_)->func_def_list;
                                    increase_k();
                                    symboltable *new_sym = new symboltable;
                                    (yyval.decclist) = (yyvsp[-3].decclist);
                                    string name = (yyval.decclist)->dec_name;
                                    increase_k();
                                    (yyval.decclist)->type = new type_inf;
                                    (yyval.decclist)->type->type_name = string("function");
                                    (yyval.decclist)->type->no_of_params = l.size();
                                    symtab *func_lookup = sym->lookup((yyval.decclist)->dec_name, (yyval.decclist)->type->type_name);
                            		for(int i=0; i < sym->no_of_entries; i++)
                                   		{
                                            increase_k();
                            	    	if(sym->sym_table[i].id.compare((yyval.decclist)->dec_name)==0)
                            	    	{
                            				sym->sym_table[i].type.type_name = "function";
                            				sym->sym_table[i].type.no_of_params = l.size();
                            	    	}
                                    }
                                    func_lookup -> nested_table = new_sym;
                                    increase_k();
                                    list<func_def*>::iterator it;
                                    for(it = l.begin(); it != l.end(); it++)
                                    {
                                        func_def *temp = *it;
                                        new_sym -> lookup(temp->param_name, temp->type->type_name);
                            	    for(int i = 0; i<new_sym->no_of_entries; i++)
                            	    {
                            		if(new_sym->sym_table[i].id.compare(temp->param_name)==0)
                            		{
                            			if(temp->type->array_type.compare("array")==0){
                            				new_sym->sym_table[i].type.array_type = "array";
                            				new_sym->sym_table[i].type.idx = temp->type->idx;
                            				}
                            		}
                            	    }
                                    }
                                    increase_k();
                                    symtab *sp;
                                    for(sp = sym->sym_table; sp < &sym->sym_table[sym->no_of_entries]; sp++)
                                    {
                                        if(!sp->id.empty() && !sp->id.compare((yyval.decclist)->dec_name))
                                        {
                                            sp->nested_table = new_sym;
                                        }
                                    }
                                    curr_sym = new_sym;
                                    Q_arr.emit(_FUNCTION_START, name,"","");
                                }
#line 4389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 2042 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 2045 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 2049 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 2054 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("ptr");
                                    (yyval.type_)->next = NULL;
                                    (yyval.type_)->pointer_type = string("ptr");
                                    (yyval.type_)->pointer_count = 1;
                                }
#line 4426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 2062 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 2066 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("ptr");
                                    (yyval.type_)->next = NULL;
                                    (yyval.type_)->pointer_type = string("ptr");
                                    (yyval.type_)->pointer_count = (yyvsp[0].type_)->pointer_count + 1;
                                    increase_k();
                                }
#line 4448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 2076 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 2079 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 2082 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 2086 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.func_list_) = new func_list;
                                }
#line 4481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 2090 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.func_list_) = new func_list;
                                    (yyval.func_list_) = (yyvsp[0].func_list_);
                                }
#line 4491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 2096 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 2100 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.func_list_) = new func_list;
                                    (yyval.func_list_)->func_def_list.push_back((yyvsp[0].func_def_));
                                }
#line 4509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 2106 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyvsp[-2].func_list_)->func_def_list.push_back((yyvsp[0].func_def_));
                                    (yyval.func_list_) = (yyvsp[-2].func_list_);
                                }
#line 4519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 2111 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.func_def_) = new func_def;
                                    (yyval.func_def_)->type = (yyvsp[-1].type_);
                                    increase_k();
                                    if((yyvsp[0].decclist)->alist.size()>0)
                                    {(yyval.func_def_)->type->array_type = "array";(yyval.func_def_)->type->idx = (yyvsp[0].decclist)->alist[0];(yyval.func_def_)->type->type_name = (yyvsp[-1].type_)->type_name;
                                    }
                                    for(int i=0; i<curr_sym->no_of_entries; i++)
                                    {
                                        increase_k();
                                    if(curr_sym->sym_table[i].id.compare((yyvsp[0].decclist)->dec_name)==0)
                                    {
                                    if((yyvsp[0].decclist)->type->array_type.compare("array")==0 || curr_sym->sym_table[i].type.array_type.compare("array")==0)
                                    {
                                    	curr_sym->sym_table[i].type.array_type = "array";
                                    	(yyval.func_def_)->type->array_type = "array";
                                    }
                                    }
                                    }
                                    (yyval.func_def_)->param_name = (yyvsp[0].decclist)->dec_name;
                                    increase_k();
                                }
#line 4546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 2133 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 2137 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 2141 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 2145 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                increase_k();
                                (yyval.type_) = (yyvsp[0].type_);
                            }
#line 4579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 2150 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                increase_k();
                            }
#line 4588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 2155 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                increase_k();
                            }
#line 4596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 2159 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                increase_k();
                            }
#line 4604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 2164 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 2168 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 2172 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 2176 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 2180 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 2184 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 2187 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 2191 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 2194 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 2199 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 2202 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 2205 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 2208 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 2211 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 2214 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 2218 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 2221 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 2224 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 2228 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 2231 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = (yyvsp[-1].expr_attr);
                                    increase_k();
                                }
#line 4765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 2236 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist, Q_arr.index);
                                }
#line 4775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 2241 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->nextlist = (yyvsp[0].expr_attr)->nextlist;
                                    Q_arr.backpatch((yyvsp[-2].expr_attr)->nextlist, (yyvsp[-1].expr_attr)->instr);
                                    increase_k();
                                }
#line 4786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 2248 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.expr_attr) = new exp_attr;
                                }
#line 4795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 2252 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 2256 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = (yyvsp[-1].expr_attr);
                                    increase_k();
                                }
#line 4812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 2261 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                    increase_k();
                                }
#line 4821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 2265 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                }
#line 4829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 2269 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    Q_arr.backpatch((yyvsp[-8].expr_attr)->nextlist , Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-9].expr_attr));
                                    increase_k();
                                    (yyval.expr_attr)->nextlist = merge((yyvsp[-5].expr_attr)->nextlist, (yyvsp[-4].expr_attr)->nextlist);
                                    Q_arr.backpatch((yyvsp[-9].expr_attr)->truelist, (yyvsp[-6].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-9].expr_attr)->falselist, (yyvsp[-2].expr_attr)->instr);
                                    (yyval.expr_attr)->nextlist = merge((yyval.expr_attr)->nextlist, (yyvsp[-1].expr_attr)->nextlist);
                                    (yyval.expr_attr)->nextlist = merge((yyval.expr_attr)->nextlist, (yyvsp[0].expr_attr)->nextlist);
                                    increase_k();
                                }
#line 4846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 2281 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    increase_k();
                                    Q_arr.backpatch((yyvsp[-4].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-5].expr_attr));
                                    increase_k();
                                    Q_arr.backpatch((yyvsp[-5].expr_attr)->truelist, (yyvsp[-2].expr_attr)->instr);
                                    increase_k();
                                    (yyval.expr_attr)->nextlist = merge((yyvsp[0].expr_attr)->nextlist, (yyvsp[-1].expr_attr)->nextlist);
                                    (yyval.expr_attr)->nextlist = merge((yyval.expr_attr)->nextlist, (yyvsp[-5].expr_attr)->falselist);
                                }
#line 4862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 2292 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 2296 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    Q_arr.emit(GOTO,"","","");
                                    Q_arr.backpatch(makelist(Q_arr.index-1),(yyvsp[-6].expr_attr)->instr);
                                    increase_k();
                                    Q_arr.backpatch((yyvsp[-3].expr_attr)->nextlist,Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-4].expr_attr));
                                    increase_k();
                                    (yyval.expr_attr) = new exp_attr;
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist, (yyvsp[-6].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-4].expr_attr)->truelist, (yyvsp[-1].expr_attr)->instr);
                                    (yyval.expr_attr)->nextlist = (yyvsp[-4].expr_attr)->falselist;
                                }
#line 4887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 2308 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    Q_arr.convInt2Bool((yyvsp[-2].expr_attr));
                                    Q_arr.backpatch((yyvsp[-6].expr_attr)->nextlist, (yyvsp[-5].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-2].expr_attr)->truelist, (yyvsp[-7].expr_attr)->instr);
                                    (yyval.expr_attr)->nextlist = (yyvsp[-2].expr_attr)->falselist;
                                    increase_k();
                                }
#line 4900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 2316 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    increase_k();
                                    Q_arr.emit(GOTO,"","","");
                                    Q_arr.backpatch(makelist(Q_arr.index-1),(yyvsp[-5].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-7].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-8].expr_attr));
                                    increase_k();
                                    Q_arr.backpatch((yyvsp[-3].expr_attr)->nextlist,(yyvsp[-9].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-8].expr_attr)->truelist,(yyvsp[-1].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist,(yyvsp[-5].expr_attr)->instr);
                                    increase_k();
                                    (yyval.expr_attr)->nextlist = (yyvsp[-8].expr_attr)->falselist;
                                }
#line 4919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 2330 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    // Not to be produced, as per assignment
                                }
#line 4927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 2334 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 2337 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 2340 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 4951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 2343 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    (yyval.expr_attr) = new exp_attr;
                                    if(curr_sym->lookup("retVal")->type.type_name.compare("void")==0)
                                    {
                                        increase_k();
                                        Q_arr.emit(RETURN_VOID,"","","");
                                    }
                                }
#line 4965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 2352 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    increase_k();
                                    type_inf type1, type2, type3;
                                    type1 = curr_sym->lookup("retVal")->type;
                                    type2 = curr_sym->lookup((yyvsp[-1].expr_attr)->loc)->type;
                                    for(int i=0; i<sym->no_of_entries;i++)
                                	{
                                        increase_k();
                                		if(sym->sym_table[i].id.compare((yyvsp[-1].expr_attr)->loc)==0)
                                			type3 = sym->sym_table[i].type;
                                	}
                                	if(type3.type_name.compare("function")==0)
                                	{
                                        increase_k();
                                		string t = curr_sym->gentemp(type1);
                                		Q_arr.emit(COPY, t, (yyvsp[-1].expr_attr)->loc, "");
                                		Q_arr.emit(RETURN,t,"","");
                                	}
                                	else if(type1.type_name == type2.type_name)
                                    {
                                        increase_k();
                                        Q_arr.emit(RETURN, (yyvsp[-1].expr_attr)->loc, "", "");
                                    }
                                }
#line 4995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 2379 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 5003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 2382 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 5011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 2386 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 5019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 2389 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 5027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 2393 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                }
#line 5035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 2397 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                    increase_k();
                                    declaration *new_dec = (yyvsp[-1].decclist);
                                    int size = 0;
                                    type_inf *type = (yyvsp[-2].type_);
                                    if(type->type_name.compare("int")==0) size = 4;
                                    if(type->type_name.compare("float")==0) size = 8;
                                    if(type->type_name.compare("char")==0) size = 1;
                                    if(type->type_name.compare("void")==0) size = 0;
                                    symboltable *gt = &GT;
                                    Q_arr.emit(_FUNCTION_END,new_dec->dec_name,"","");
                                    symtab *func = gt->lookup((yyvsp[-1].decclist)->dec_name);
                                    if(func->nested_table != NULL)
                                    {
                                        increase_k();
                                        if((yyvsp[-1].decclist)->pointer_count>0)
                                            type->pointer_type = "ptr";
                                        symtab *ret = func->nested_table->lookup("retVal", type->type_name, (yyvsp[-1].decclist)->pointer_count);
                                        increase_k();
                                        if((yyvsp[-1].decclist)->pointer_count>0)
                                        {
                                            increase_k();
                                            ret->pointer_count = (yyvsp[-1].decclist)->pointer_count;
                                            ret->type.pointer_type = "ptr";
                                        }
                                        ret->offset = curr_sym->offset;
                                        ret->size = size;
                                        ret->init_val = NULL;
                                    }
                                    curr_sym = gt;
                                    (yyval.decclist) = (yyvsp[-1].decclist);
                                }
#line 5072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 2430 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 5079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 2432 "ass6_17CS10059.y" /* yacc.c:1646  */
    {
                                }
#line 5086 "y.tab.c" /* yacc.c:1646  */
    break;


#line 5090 "y.tab.c" /* yacc.c:1646  */
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
#line 2435 "ass6_17CS10059.y" /* yacc.c:1906  */


void yyerror(string s){
    cout << "ERROR OCCURED : " << s << endl;
}
