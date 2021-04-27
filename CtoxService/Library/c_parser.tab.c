/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 23 "c_parser.y" /* yacc.c:337  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

extern int yylineno;

int yylex();
void yyerror(char *);

char *concatn(int n, ...);
void freen(int n, ...);
char *createfunc(char *, char *, char *);
void addfunccall(char *, char *);
char *createexp(char *);
char *createdecl(char *);
char *createifelse(char *, char *, char *);
char *createswitch(char *, char *);
char *createcycle(int, char *, char *);

char *currentcalls = NULL;

int ignorecall = 0;

#define EXPS "<expression"
#define EXPE "</expression>"
#define HASC "hascalls = \"true\">"
#define DHAC "hascalls = \"false\">"
#define TEXS "<text>"
#define TEXE "</text>"

#define DECS "<declaration"
#define DECE "</declaration>"

#define FUNS "<function>"
#define FUNE "</function>"
#define PROS "<prototype>"
#define PROE "</prototype>"
#define BODS "<body>"
#define BODE "</body>"
#define NBOD "<body/>"

#define CALS "<funccall>"
#define CALE "</funccall>"
#define NAMS "<name>"
#define NAME "</name>"
#define ARGS "<arguments>"
#define ARGE "</arguments>"
#define NARG "<arguments/>"

#define IFSS "<if>"
#define IFSE "</if>"
#define CONS "<condition>"
#define CONE "</condition>"
#define IFBS "<ifbody>"
#define IFBE "</ifbody>"
#define NIFB "<ifbody/>"
#define ELBS "<elsebody>"
#define ELBE "</elsebody>"
#define NELB "<elsebody/>"

#define SWIS "<switch>"
#define SWIE "</switch>"
#define LABS "<labelstatement>"
#define LABE "</labelstatement>"

#define GOTS "<goto>"
#define GOTE "</gote>"
#define CONT "<continue/>"
#define BREA "<break/>"
#define RETS "<return>"
#define RETE "</return>"
#define NRET "<return/>"

#define CYCS "<cycle"
#define PREC "pre = \"true\">"
#define POSC "pre = \"false\">"
#define CYCE "</cycle>"

#line 151 "c_parser.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
   by #include "c_parser.tab.h".  */
#ifndef YY_YY_C_PARSER_TAB_H_INCLUDED
# define YY_YY_C_PARSER_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    I_CONSTANT = 259,
    F_CONSTANT = 260,
    STRING_LITERAL = 261,
    FUNC_NAME = 262,
    SIZEOF = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPEDEF = 285,
    EXTERN = 286,
    STATIC = 287,
    AUTO = 288,
    REGISTER = 289,
    INLINE = 290,
    CONST = 291,
    RESTRICT = 292,
    VOLATILE = 293,
    BOOL = 294,
    CHAR = 295,
    SHORT = 296,
    INT = 297,
    LONG = 298,
    SIGNED = 299,
    UNSIGNED = 300,
    FLOAT = 301,
    DOUBLE = 302,
    VOID = 303,
    COMPLEX = 304,
    IMAGINARY = 305,
    STRUCT = 306,
    UNION = 307,
    ENUM = 308,
    ELLIPSIS = 309,
    CASE = 310,
    DEFAULT = 311,
    IF = 312,
    ELSE = 313,
    SWITCH = 314,
    WHILE = 315,
    DO = 316,
    FOR = 317,
    GOTO = 318,
    CONTINUE = 319,
    BREAK = 320,
    RETURN = 321,
    ALIGNAS = 322,
    ALIGNOF = 323,
    ATOMIC = 324,
    GENERIC = 325,
    NORETURN = 326,
    STATIC_ASSERT = 327,
    THREAD_LOCAL = 328
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef char * YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_C_PARSER_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  273
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  478

#define YYUNDEFTOK  2
#define YYMAXUTOK   328

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,     2,     2,     2,    90,    83,     2,
      74,    75,    84,    85,    76,    86,    80,    89,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    77,    97,
      91,    96,    92,    95,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    78,     2,    79,    93,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,    94,    82,    87,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   110,   111,   112,   113,   117,   118,   122,
     123,   127,   131,   132,   136,   137,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   154,   155,   159,   160,
     161,   162,   163,   164,   165,   169,   170,   171,   172,   173,
     174,   178,   179,   183,   184,   185,   186,   190,   191,   192,
     196,   197,   198,   202,   203,   204,   205,   206,   210,   211,
     212,   216,   217,   221,   222,   226,   227,   231,   232,   236,
     237,   241,   242,   246,   247,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   265,   266,   270,   274,
     275,   276,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   293,   294,   298,   299,   303,   304,   305,   306,
     307,   308,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   330,   331,   332,
     336,   337,   341,   342,   346,   347,   348,   352,   353,   354,
     355,   359,   360,   364,   365,   366,   370,   371,   372,   373,
     374,   378,   379,   383,   384,   388,   392,   393,   394,   395,
     399,   400,   404,   405,   409,   410,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     432,   433,   434,   435,   439,   440,   445,   446,   450,   451,
     455,   456,   457,   461,   462,   466,   467,   471,   472,   473,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   501,   502,   503,   507,   508,   509,   510,   514,   518,
     519,   523,   524,   528,   532,   533,   534,   535,   536,   537,
     541,   542,   543,   547,   548,   552,   553,   557,   558,   562,
     563,   567,   568,   569,   573,   574,   575,   576,   577,   578,
     582,   583,   584,   585,   586,   590,   594,   595,   599,   600,
     604,   605,   609,   610
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "FUNC_NAME", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "INLINE",
  "CONST", "RESTRICT", "VOLATILE", "BOOL", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID", "COMPLEX", "IMAGINARY",
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT",
  "THREAD_LOCAL", "'('", "')'", "','", "':'", "'['", "']'", "'.'", "'{'",
  "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept",
  "primary_expression", "constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program_unit", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
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
     325,   326,   327,   328,    40,    41,    44,    58,    91,    93,
      46,   123,   125,    38,    42,    43,    45,   126,    33,    47,
      37,    60,    62,    94,   124,    63,    61,    59
};
# endif

#define YYPACT_NINF -363

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-363)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2121,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,    25,   -35,    -9,  -363,    49,  -363,
    -363,    57,  2209,  2209,  -363,    47,  -363,  -363,  2209,  2209,
    2209,  -363,    20,  2121,  -363,  -363,    -3,   132,   862,  2284,
    1595,  -363,    85,   236,  -363,   -44,  -363,  1807,   -11,    26,
    -363,  -363,    67,  2247,  -363,  -363,  -363,  -363,  -363,   132,
      65,    61,  -363,  -363,  -363,  -363,  -363,  -363,  1616,  1702,
    1702,    79,   108,   862,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,   157,  -363,  1595,  -363,   112,   -30,
     160,   125,   196,   117,   113,   136,   220,    -1,  -363,   167,
    2284,   -26,  2284,   172,   175,   156,   180,  -363,  -363,  -363,
     236,    85,  -363,   428,  1360,  -363,    57,  -363,  1929,  1761,
     884,   -11,  2247,  1975,  -363,    48,  -363,    75,  1595,    14,
    -363,   862,  -363,   862,  -363,  -363,  2284,  1595,   200,  -363,
    -363,   158,   188,   249,  -363,  -363,  1446,  1595,   266,  -363,
    1595,  1595,  1595,  1595,  1595,  1595,  1595,  1595,  1595,  1595,
    1595,  1595,  1595,  1595,  1595,  1595,  1595,  1595,  1595,  -363,
    -363,  1874,   970,     1,  -363,   131,  -363,  -363,  -363,   272,
    -363,  -363,  -363,  -363,   191,   212,  1595,   227,   217,   228,
     235,   686,   237,   312,   222,   230,   723,  -363,  -363,   -43,
    -363,  -363,  -363,  -363,   547,  -363,  -363,  -363,  -363,  -363,
    1339,  -363,  -363,  -363,  -363,  -363,  -363,    78,   242,   253,
    -363,   182,  1211,  -363,   262,   267,   993,  2022,  -363,  -363,
    1595,  -363,   -38,  -363,   248,    27,  -363,  -363,  -363,  -363,
     257,   274,   278,   271,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  1595,  -363,  1595,  1467,  -363,
    -363,   185,  -363,   104,  -363,  -363,  -363,  -363,   112,   112,
     -30,   -30,   160,   160,   160,   160,   125,   125,   196,   117,
     113,   136,   220,   189,  -363,   281,   282,  1211,  -363,   279,
     280,  1079,   131,  2075,  1102,   285,   686,   284,   686,  1595,
    1595,  1595,   305,   635,   269,  -363,  -363,  -363,    68,  -363,
    -363,  -363,  1595,   364,  -363,   105,  1360,   114,  -363,  1684,
    -363,   100,  -363,  -363,  2165,  -363,   365,   290,  1211,  -363,
    -363,  1595,  -363,   291,   292,  -363,  -363,   102,  -363,  1595,
    -363,   311,   311,  -363,   785,  -363,  -363,  1339,  -363,  -363,
    1595,  -363,  1595,  -363,  -363,   293,  1211,  -363,  -363,  1595,
    -363,   314,  -363,   319,  1211,  -363,   317,   318,  1188,   306,
    -363,   686,  -363,   207,   210,   223,   328,   774,   774,  -363,
    -363,   325,  -363,  1232,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,   326,   327,  -363,  -363,  -363,  -363,   330,   225,
    -363,   331,   121,  -363,  -363,  -363,   332,   333,  -363,  -363,
     334,  1211,  -363,  -363,  1595,  -363,   335,  -363,  -363,   686,
     686,   686,  1595,  1488,  1574,  -363,  -363,  -363,  1360,  -363,
    -363,  1595,  -363,   785,  1595,  1318,  -363,  -363,  -363,  -363,
     336,   337,  -363,   351,  -363,  -363,   238,   686,   246,   686,
     260,  -363,  -363,  -363,  -363,  -363,  -363,  -363,   686,   320,
    -363,   686,  -363,   686,  -363,  -363,  -363,  -363
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   106,   107,   108,   110,   111,   160,   156,   157,   158,
     121,   113,   114,   115,   116,   119,   120,   117,   118,   112,
     122,   123,   130,   131,     0,     0,   159,   161,     0,   109,
     269,     0,    93,    95,   125,     0,   126,   124,    97,    99,
     101,    91,     0,   265,   266,   268,   150,     0,     0,     0,
       0,   166,     0,   183,    89,     0,   102,   105,   165,     0,
      92,    94,   129,     0,    96,    98,   100,     1,   267,     0,
     154,     0,   151,     2,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,    35,    36,    37,    38,    39,    40,
      16,     3,     4,     6,    28,    41,     0,    43,    47,    50,
      53,    58,    61,    63,    65,    67,    69,    71,    88,     0,
     138,   196,   140,     0,     0,     0,     0,   159,   184,   182,
     181,     0,    90,     0,     0,   272,     0,   271,     0,     0,
       0,   164,     0,     0,   132,     0,   136,     0,     0,     0,
     146,     0,    32,     0,    29,    30,     0,     0,    41,    73,
      86,     0,     0,     0,    22,    23,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
     137,     0,     0,   198,   195,   199,   139,   162,   155,     0,
     167,   185,   180,   103,   105,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,   249,     0,
     247,   248,   234,   235,     0,   245,   236,   237,   238,   239,
       0,   223,   104,   273,   270,   193,   178,   192,     0,   187,
     188,     0,     0,   168,    36,     0,     0,     0,   127,   133,
       0,   134,     0,   141,   145,     0,   148,   153,   147,   152,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    75,     0,     5,     0,     0,    21,
      18,     0,    26,     0,    20,    44,    45,    46,    48,    49,
      51,    52,    56,    57,    54,    55,    59,    60,    62,    64,
      66,    68,    70,     0,   217,     0,     0,     0,   201,    36,
       0,     0,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   262,   263,     0,   250,
     244,   246,     0,     0,   225,     0,     0,     0,   229,     0,
     190,   198,   191,   177,     0,   179,     0,     0,     0,   169,
     176,     0,   175,    36,     0,   128,   143,     0,   135,     0,
     149,    33,     0,    34,     0,    74,    87,     0,    42,    19,
       0,    17,     0,   218,   200,     0,     0,   202,   208,     0,
     207,     0,   219,     0,     0,   209,    36,     0,     0,     0,
     240,     0,   242,     0,     0,     0,     0,     0,     0,   260,
     264,     0,   232,     0,   221,   224,   228,   230,   186,   189,
     194,   171,     0,     0,   172,   174,   142,   144,     0,     0,
      12,     0,     0,    27,    72,   204,     0,     0,   206,   220,
       0,     0,   210,   216,     0,   215,     0,   233,   241,     0,
       0,     0,     0,     0,     0,   231,   222,   227,     0,   170,
     173,     0,    11,     0,     0,     0,    24,   203,   205,   212,
       0,     0,   213,   252,   253,   254,     0,     0,     0,     0,
       0,   226,    15,    13,    14,    25,   211,   214,     0,     0,
     258,     0,   256,     0,   251,   255,   259,   257
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -363,  -363,  -363,  -363,  -363,  -363,   -24,  -363,  -363,   214,
    -363,   -50,   176,   177,    76,   173,   245,   247,   250,   244,
     252,  -363,   -25,   -90,  -363,   -70,   -41,   -54,     4,  -363,
     301,  -363,   -42,  -363,  -363,   295,  -119,    17,  -363,    77,
    -363,   354,  -128,  -363,   -48,  -363,  -363,   -19,   -51,   -34,
    -106,  -113,  -363,    96,  -363,   -22,   -89,  -173,  -122,    84,
    -362,  -363,   116,   -18,   -31,  -363,    -8,  -363,   231,  -224,
    -363,  -363,  -363,  -363,  -363,   401,  -363,  -363
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    90,    91,    92,    93,   409,   410,    94,   271,   148,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   149,   150,   265,   209,   109,    30,   126,    55,
      56,    32,    33,    34,    35,   133,   134,   111,   242,   243,
      36,    71,    72,    37,    38,    39,    40,   116,    58,    59,
     120,   295,   229,   230,   231,   411,   296,   185,   324,   325,
     326,   327,   328,    41,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    42,    43,    44,    45,   128
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     112,   112,   222,   125,    31,   118,   110,   110,   131,   115,
     302,   249,    57,   151,   239,   112,   228,    70,   177,   119,
      67,   110,   184,   108,   236,   108,   113,   114,    46,    51,
      70,   438,   121,   267,   221,   112,    60,    61,   347,    48,
     235,   110,    64,    65,    66,   136,   159,    31,   181,   127,
      62,    51,   182,   122,   319,   163,   164,   253,    53,   348,
      51,   152,   112,   129,   112,    49,   272,   130,   110,   210,
     110,   151,   191,   151,   223,   181,   301,   183,    69,   182,
     135,    51,   118,   438,   112,   112,   192,   273,    51,   388,
     110,   110,   300,   112,   178,   112,   248,   247,   112,   110,
      52,   110,   194,    51,   110,    51,    47,   194,   293,   350,
     275,   276,   277,   108,   136,   136,   244,   249,   239,   250,
     224,   251,    52,    50,   252,   240,   338,   180,    63,   186,
     221,    52,    53,   227,   118,    70,   318,   139,   332,   167,
     168,    53,   337,   140,   267,   241,   344,   183,   132,   135,
     135,   245,   329,   146,    54,   307,   182,   246,   302,    52,
     210,   138,    53,   433,   434,   390,   153,   154,   155,    53,
     312,   108,   165,   166,   329,   355,    52,   356,   182,   240,
     267,   393,   147,   361,   118,   227,    53,   394,   191,   112,
     373,   366,   322,   331,   323,   110,   160,   445,   378,   346,
     173,   161,   162,   446,   395,   303,   174,   365,   330,   304,
     396,   371,   171,   172,   377,   108,   169,   170,   358,   136,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     175,   156,   189,   266,   267,   157,   221,   158,   176,   383,
     384,   385,   179,   282,   283,   284,   285,   187,   402,   118,
     188,   403,   269,   191,   135,   190,   118,   335,   336,   387,
     359,   360,    95,   268,    95,   267,   362,   221,   421,   274,
     413,   437,     7,     8,     9,   380,   416,   382,   305,   417,
     131,   391,   429,   267,   420,   430,   267,   124,   426,   306,
     191,   309,   142,   144,   145,   331,   264,   108,   431,   267,
     442,   443,   310,   221,   308,   117,   112,   227,   407,   311,
      95,   313,   110,   469,   267,   314,   461,   333,   191,   315,
      53,   471,   267,   437,   108,   349,   118,   316,   244,   334,
     191,   450,   351,   227,   451,   473,   267,   414,   227,   278,
     279,   339,   280,   281,   286,   287,   340,   354,   221,   352,
     428,   462,    95,   353,   464,   221,   363,   364,   367,   368,
     379,   381,   456,   458,   460,   386,   389,   392,   400,   401,
     404,   405,   415,   191,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,   357,   418,   419,   112,   422,   423,   453,   454,
     455,   110,   432,   427,   435,   439,   440,   441,   444,   468,
      95,   447,   448,   449,   452,   466,   467,   475,   288,   463,
     291,   289,   193,   137,   406,   290,   470,   237,   472,   292,
     399,   195,    74,    75,    76,    77,    78,   474,    79,    80,
     476,   412,   477,   397,    68,   321,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    95,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,    25,    81,    26,    82,    27,
      28,    29,    83,     0,     0,     0,     0,     0,     0,   123,
     207,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     195,    74,    75,    76,    77,    78,     0,    79,    80,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,    25,    81,    26,    82,    27,    28,
      29,    83,     0,     0,     0,     0,     0,     0,   123,   320,
      84,    85,    86,    87,    88,    89,     0,     0,    73,    74,
      75,    76,    77,    78,   208,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   195,
      74,    75,    76,    77,    78,     0,    79,    80,     0,     0,
       0,     0,    25,    81,    26,    82,    27,    28,    29,    83,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,     0,     0,    73,    74,    75,    76,
      77,    78,   208,    79,    80,     0,     0,     0,     0,     0,
       0,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,     0,    81,     0,    82,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,   123,     0,    84,
      85,    86,    87,    88,    89,     0,     0,    73,    74,    75,
      76,    77,    78,   208,    79,    80,     0,     0,     0,     0,
       0,    81,     0,    82,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
     317,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,   408,    81,     0,    82,     0,     0,     0,    83,     0,
       0,     0,     0,     0,    26,     0,     0,    84,    85,    86,
      87,    88,    89,     0,     0,    73,    74,    75,    76,    77,
      78,   208,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    77,    78,     0,    79,    80,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   232,     0,     0,     0,
       7,     8,     9,     0,     0,     0,     0,     0,     0,     0,
      81,    26,    82,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,     0,    81,   117,    82,     0,     0,     0,    83,     0,
       0,     0,     0,   233,     0,     0,     0,    84,   234,    86,
      87,    88,    89,    73,    74,    75,    76,    77,    78,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    78,   297,    79,    80,     0,     7,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   341,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,     0,     0,    81,   117,
      82,     0,     0,     0,    83,     0,     0,     0,     0,   298,
       0,     0,     0,    84,   299,    86,    87,    88,    89,     0,
       0,    81,   117,    82,     0,     0,     0,    83,     0,     0,
       0,     0,   342,     0,     0,     0,    84,   343,    86,    87,
      88,    89,    73,    74,    75,    76,    77,    78,     0,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,   369,    79,    80,     0,     7,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,     0,     0,     0,     7,     8,
       9,     0,     0,     0,     0,     0,     0,    81,   117,    82,
       0,     0,     0,    83,     0,     0,     0,     0,   370,     0,
       0,     0,    84,    85,    86,    87,    88,    89,     0,     0,
      81,   117,    82,     0,     0,     0,    83,     0,     0,     0,
       0,   375,     0,     0,     0,    84,   376,    86,    87,    88,
      89,    73,    74,    75,    76,    77,    78,     0,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,    78,
     424,    79,    80,     0,     7,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,     0,    79,    80,     0,     0,     0,     7,     8,     9,
       0,     0,     0,     0,     0,     0,    81,   117,    82,     0,
       0,     0,    83,     0,     0,     0,     0,   425,     0,     0,
       0,    84,    85,    86,    87,    88,    89,     0,     0,    81,
     117,    82,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88,    89,
      81,     0,    82,     0,     0,     0,    83,     0,     0,     0,
     322,     0,   323,   220,   436,    84,    85,    86,    87,    88,
      89,    73,    74,    75,    76,    77,    78,     0,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    78,     0,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,    82,     0,
       0,     0,    83,     0,     0,     0,   322,     0,   323,   220,
     465,    84,    85,    86,    87,    88,    89,    81,     0,    82,
       0,     0,     0,    83,     0,     0,     0,   322,     0,   323,
     220,     0,    84,    85,    86,    87,    88,    89,    81,     0,
      82,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,   220,     0,    84,    85,    86,    87,    88,    89,    73,
      74,    75,    76,    77,    78,     0,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,     0,    79,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,     0,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,    82,     0,     0,     0,
      83,   270,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    81,     0,    82,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,   357,     0,
      84,    85,    86,    87,    88,    89,    81,     0,    82,     0,
       0,     0,    83,   457,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    73,    74,    75,
      76,    77,    78,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    77,    78,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,     0,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,    82,     0,     0,     0,    83,   459,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    81,     0,    82,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,    81,     0,    82,    51,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    73,    74,    75,    76,    77,
      78,     0,    79,    80,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    26,     0,    27,     0,    29,   329,   294,
       0,     0,   182,     0,   225,     0,     0,     0,    53,     0,
      81,     0,    82,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
      26,     0,    27,     0,    29,     0,   226,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,    26,     0,    27,    28,
      29,     0,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    26,     0,    27,     0,    29,   181,   294,
       0,     0,   182,     0,     0,     0,     0,     0,    53,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,    26,     0,
      27,    28,    29,     0,     0,     0,     0,     0,     0,     0,
     123,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,    26,     0,    27,     0,    29,     0,
     372,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
      26,     0,    27,    28,    29,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   398,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,    26,     0,    27,     0,    29,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,    26,     0,
      27,     0,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,    28,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26
};

static const yytype_int16 yycheck[] =
{
      48,    49,   124,    57,     0,    53,    48,    49,    59,    50,
     183,   139,    31,    83,   133,    63,   129,     3,    19,    53,
       0,    63,   111,    48,   130,    50,    48,    49,     3,     3,
       3,   393,    76,    76,   124,    83,    32,    33,    76,    74,
     130,    83,    38,    39,    40,    63,    96,    43,    74,    57,
       3,     3,    78,    97,    97,    85,    86,   147,    84,    97,
       3,    83,   110,    74,   112,    74,   156,    78,   110,   123,
     112,   141,   120,   143,   128,    74,   182,   111,    81,    78,
      63,     3,   130,   445,   132,   133,   120,   157,     3,   313,
     132,   133,   182,   141,    95,   143,    82,   138,   146,   141,
      74,   143,   121,     3,   146,     3,    81,   126,   178,    82,
     160,   161,   162,   138,   132,   133,   135,   245,   237,   141,
     128,   143,    74,    74,   146,    77,   232,   110,    81,   112,
     220,    74,    84,   129,   182,     3,   206,    76,   227,    14,
      15,    84,   232,    82,    76,    97,   236,   181,    81,   132,
     133,    76,    74,    74,    97,   196,    78,    82,   331,    74,
     214,    96,    84,   387,   388,    97,     9,    10,    11,    84,
     201,   196,    12,    13,    74,   265,    74,   267,    78,    77,
      76,    76,    74,    79,   232,   181,    84,    82,   236,   237,
     303,   297,    78,   227,    80,   237,    84,    76,   304,   240,
      83,    89,    90,    82,   326,    74,    93,   297,   227,    78,
      96,   301,    16,    17,   304,   240,    91,    92,   268,   237,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      94,    74,    76,    75,    76,    78,   326,    80,    18,   309,
     310,   311,    75,   167,   168,   169,   170,    75,   338,   297,
      75,   341,     3,   301,   237,    75,   304,    75,    76,   313,
      75,    76,    48,    75,    50,    76,    77,   357,   374,     3,
     360,   393,    36,    37,    38,   306,   366,   308,     6,   369,
     331,   322,    75,    76,   374,    75,    76,    96,   378,    77,
     338,    74,    78,    79,    80,   329,    96,   322,    75,    76,
      75,    76,    74,   393,    77,    69,   354,   303,   349,    74,
      96,    74,   354,    75,    76,     3,   438,    75,   366,    97,
      84,    75,    76,   445,   349,    77,   374,    97,   347,    76,
     378,   421,    75,   329,   424,    75,    76,   362,   334,   163,
     164,    79,   165,   166,   171,   172,    79,    76,   438,    75,
     381,   441,   138,    75,   444,   445,    75,    75,    79,    79,
      75,    77,   432,   433,   434,    60,    97,     3,     3,    79,
      79,    79,    79,   421,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    81,    79,    75,   443,    79,    79,   429,   430,
     431,   443,    74,    97,    79,    79,    79,    77,    77,    58,
     196,    79,    79,    79,    79,    79,    79,    97,   173,   443,
     176,   174,   121,    69,   347,   175,   457,   132,   459,   177,
     334,     3,     4,     5,     6,     7,     8,   468,    10,    11,
     471,   357,   473,   327,    43,   214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   268,    55,    56,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   362,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,     3,     4,
       5,     6,     7,     8,    97,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    88,    -1,    -1,     3,     4,     5,     6,
       7,     8,    97,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    -1,    70,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    83,
      84,    85,    86,    87,    88,    -1,    -1,     3,     4,     5,
       6,     7,     8,    97,    10,    11,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    83,    84,    85,
      86,    87,    88,    -1,    -1,     3,     4,     5,     6,     7,
       8,    97,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    32,    -1,    -1,    -1,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      88,    -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    88,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    32,    10,    11,    -1,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    88,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    88,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    32,    10,    11,    -1,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    88,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      88,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      32,    10,    11,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    88,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,    88,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    83,    84,    85,    86,    87,    88,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    88,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      83,    84,    85,    86,    87,    88,    68,    -1,    70,    -1,
      -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    88,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    88,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    88,    68,    -1,    70,     3,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    88,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    71,    -1,    73,    74,    75,
      -1,    -1,    78,    -1,     3,    -1,    -1,    -1,    84,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      88,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    73,    -1,    75,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    71,    -1,    73,    74,    75,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    84,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    72,    73,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    73,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    73,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    72,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    67,    69,    71,    72,    73,
     125,   126,   129,   130,   131,   132,   138,   141,   142,   143,
     144,   161,   171,   172,   173,   174,     3,    81,    74,    74,
      74,     3,    74,    84,    97,   127,   128,   145,   146,   147,
     126,   126,     3,    81,   126,   126,   126,     0,   173,    81,
       3,   139,   140,     3,     4,     5,     6,     7,     8,    10,
      11,    68,    70,    74,    83,    84,    85,    86,    87,    88,
      99,   100,   101,   102,   105,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   124,
     130,   135,   142,   153,   153,   124,   145,    69,   142,   147,
     148,    76,    97,    81,    96,   125,   126,   164,   175,    74,
      78,   146,    81,   133,   134,   135,   161,   139,    96,    76,
      82,    74,   107,    74,   107,   107,    74,    74,   107,   120,
     121,   123,   153,     9,    10,    11,    74,    78,    80,   109,
      84,    89,    90,    85,    86,    12,    13,    14,    15,    91,
      92,    16,    17,    83,    93,    94,    18,    19,    95,    75,
     135,    74,    78,   147,   154,   155,   135,    75,    75,    76,
      75,   142,   147,   128,   145,     3,    55,    56,    57,    59,
      60,    61,    62,    63,    64,    65,    66,    82,    97,   123,
     125,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      81,   121,   156,   125,   164,     3,    75,   126,   149,   150,
     151,   152,    32,    79,    84,   121,   148,   133,    82,   134,
      77,    97,   136,   137,   145,    76,    82,   124,    82,   140,
     153,   153,   153,   121,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    96,   122,    75,    76,    75,     3,
      75,   106,   121,   123,     3,   109,   109,   109,   110,   110,
     111,   111,   112,   112,   112,   112,   113,   113,   114,   115,
     116,   117,   118,   123,    75,   149,   154,    32,    79,    84,
     121,   148,   155,    74,    78,     6,    77,   124,    77,    74,
      74,    74,   162,    74,     3,    97,    97,    97,   123,    97,
      82,   166,    78,    80,   156,   157,   158,   159,   160,    74,
     145,   147,   154,    75,    76,    75,    76,   121,   148,    79,
      79,    32,    79,    84,   121,    82,   124,    76,    97,    77,
      82,    75,    75,    75,    76,   121,   121,    81,   109,    75,
      76,    79,    77,    75,    75,   121,   148,    79,    79,    32,
      79,   121,    75,   149,    32,    79,    84,   121,   148,    75,
     162,    77,   162,   123,   123,   123,    60,   125,   167,    97,
      97,   124,     3,    76,    82,   156,    96,   160,    54,   151,
       3,    79,   121,   121,    79,    79,   137,   124,    56,   103,
     104,   153,   157,   121,   120,    79,   121,   121,    79,    75,
     121,   148,    79,    79,    32,    79,   121,    97,   162,    75,
      75,    75,    74,   167,   167,    79,    82,   156,   158,    79,
      79,    77,    75,    76,    77,    76,    82,    79,    79,    79,
     121,   121,    79,   162,   162,   162,   123,    75,   123,    75,
     123,   156,   121,   104,   121,    82,    79,    79,    58,    75,
     162,    75,   162,    75,   162,    97,   162,   162
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    98,    99,    99,    99,    99,    99,   100,   100,   101,
     101,   102,   103,   103,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   110,   110,   110,   111,   111,   111,
     112,   112,   112,   113,   113,   113,   113,   113,   114,   114,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   123,   123,   124,   125,
     125,   125,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   129,
     129,   129,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   131,
     132,   132,   133,   133,   134,   134,   134,   135,   135,   135,
     135,   136,   136,   137,   137,   137,   138,   138,   138,   138,
     138,   139,   139,   140,   140,   141,   142,   142,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     147,   147,   147,   147,   148,   148,   149,   149,   150,   150,
     151,   151,   151,   152,   152,   153,   153,   154,   154,   154,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   156,   156,   156,   157,   157,   157,   157,   158,   159,
     159,   160,   160,   161,   162,   162,   162,   162,   162,   162,
     163,   163,   163,   164,   164,   165,   165,   166,   166,   167,
     167,   168,   168,   168,   169,   169,   169,   169,   169,   169,
     170,   170,   170,   170,   170,   171,   172,   172,   173,   173,
     174,   174,   175,   175
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     6,     1,     3,     3,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     2,
       1,     1,     1,     2,     2,     3,     1,     2,     1,     2,
       1,     1,     3,     2,     3,     1,     4,     5,     5,     6,
       2,     1,     3,     3,     1,     4,     1,     1,     1,     1,
       1,     1,     4,     4,     2,     1,     1,     3,     3,     4,
       6,     5,     5,     6,     5,     4,     4,     4,     3,     4,
       3,     2,     2,     1,     1,     2,     3,     1,     1,     3,
       2,     2,     1,     1,     3,     2,     1,     2,     1,     1,
       3,     2,     3,     5,     4,     5,     4,     3,     3,     3,
       4,     6,     5,     5,     6,     4,     4,     2,     3,     3,
       4,     3,     4,     1,     2,     1,     4,     3,     2,     1,
       2,     3,     2,     7,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     1,     2,     1,     1,     1,
       2,     7,     5,     5,     5,     7,     6,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     1,     2,     1,     1,
       4,     3,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  *++yylsp = yylloc;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 109 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2211 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 110 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2217 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 111 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2223 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 112 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2229 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 113 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2235 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 117 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2241 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 118 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2247 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 122 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2253 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 123 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2259 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 127 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2265 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 131 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2271 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 132 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2277 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 136 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2283 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 137 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2289 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 141 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2295 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 142 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2301 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 143 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); addfunccall(yyvsp[-2], NULL); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2307 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 144 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); addfunccall(yyvsp[-3], yyvsp[-1]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2313 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 145 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2319 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 146 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2325 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 147 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2331 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 148 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2337 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 149 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2343 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 150 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(7, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(7, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2349 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 154 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2355 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 155 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2361 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 159 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2367 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 160 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2373 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 161 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2379 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 162 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2385 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 163 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2391 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 164 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2397 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 165 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2403 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 169 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2409 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 170 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2415 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 171 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2421 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 172 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2427 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 173 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2433 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 174 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2439 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 178 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2445 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 179 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2451 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 183 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2457 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 184 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2463 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 185 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2469 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 186 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2475 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 190 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2481 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 191 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2487 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 192 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2493 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 196 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2499 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 197 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2505 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 198 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2511 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 202 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2517 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 203 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2523 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 204 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2529 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 205 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2535 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 206 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2541 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 210 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2547 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 211 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2553 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 212 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2559 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 216 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2565 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 217 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2571 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 221 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2577 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 222 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2583 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 226 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2589 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 227 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2595 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 231 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2601 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 232 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2607 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 236 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2613 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 237 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2619 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 241 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2625 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 242 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2631 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 246 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2637 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 247 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2643 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 251 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2649 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 252 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2655 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 253 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2661 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 254 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2667 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 255 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2673 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 256 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2679 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 257 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2685 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 258 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2691 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 259 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2697 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 260 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2703 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 261 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2709 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 265 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2715 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 266 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2721 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 270 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2727 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 274 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[-1]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2733 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 275 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-2], yyvsp[-1]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2739 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 276 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2745 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 280 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2751 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 281 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2757 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 282 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2763 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 283 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2769 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 284 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2775 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 285 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2781 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 286 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2787 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 287 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2793 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 288 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2799 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 289 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2805 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 293 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2811 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 294 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2817 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 298 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2823 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 299 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2829 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 303 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2835 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 107:
#line 304 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2841 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 305 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2847 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 306 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2853 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 307 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2859 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 111:
#line 308 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2865 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 112:
#line 312 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2871 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 113:
#line 313 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2877 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 114:
#line 314 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2883 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 115:
#line 315 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2889 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 116:
#line 316 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2895 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 117:
#line 317 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2901 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 118:
#line 318 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2907 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 119:
#line 319 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2913 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 120:
#line 320 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2919 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 121:
#line 321 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2925 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 122:
#line 322 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2931 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 123:
#line 323 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2937 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 124:
#line 324 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2943 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 125:
#line 325 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2949 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 126:
#line 326 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2955 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 127:
#line 330 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2961 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 128:
#line 331 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 2967 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 129:
#line 332 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2973 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 130:
#line 336 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2979 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 131:
#line 337 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2985 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 132:
#line 341 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 2991 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 133:
#line 342 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 2997 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 134:
#line 346 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[-1]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3003 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 135:
#line 347 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-2], yyvsp[-1]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3009 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 136:
#line 348 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3015 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 137:
#line 352 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3021 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 138:
#line 353 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3027 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 139:
#line 354 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3033 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 140:
#line 355 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3039 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 141:
#line 359 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3045 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 142:
#line 360 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3051 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 143:
#line 364 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3057 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 144:
#line 365 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3063 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 145:
#line 366 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3069 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 146:
#line 370 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3075 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 147:
#line 371 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3081 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 148:
#line 372 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3087 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 149:
#line 373 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3093 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 150:
#line 374 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3099 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 151:
#line 378 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3105 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 152:
#line 379 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3111 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 153:
#line 383 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3117 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 154:
#line 384 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3123 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 155:
#line 388 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3129 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 156:
#line 392 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3135 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 157:
#line 393 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3141 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 158:
#line 394 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3147 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 159:
#line 395 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3153 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 160:
#line 399 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3159 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 161:
#line 400 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3165 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 162:
#line 404 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3171 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 163:
#line 405 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3177 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 164:
#line 409 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3183 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 165:
#line 410 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3189 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 166:
#line 415 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3195 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 167:
#line 416 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3201 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 168:
#line 417 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3207 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 169:
#line 418 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3213 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 170:
#line 419 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3219 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 171:
#line 420 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3225 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 172:
#line 421 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3231 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 173:
#line 422 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3237 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 174:
#line 423 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3243 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 175:
#line 424 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3249 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 176:
#line 425 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3255 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 177:
#line 426 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3261 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 178:
#line 427 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3267 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 179:
#line 428 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3273 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 180:
#line 432 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3279 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 181:
#line 433 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3285 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 182:
#line 434 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3291 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 183:
#line 435 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3297 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 184:
#line 439 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3303 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 185:
#line 440 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3309 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 186:
#line 445 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3315 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 187:
#line 446 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3321 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 188:
#line 450 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3327 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 189:
#line 451 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3333 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 190:
#line 455 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3339 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 191:
#line 456 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3345 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 192:
#line 457 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3351 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 193:
#line 461 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3357 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 194:
#line 462 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3363 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 195:
#line 466 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3369 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 196:
#line 467 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3375 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 197:
#line 471 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3381 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 198:
#line 472 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3387 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 199:
#line 473 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3393 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 200:
#line 477 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3399 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 201:
#line 478 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3405 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 202:
#line 479 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3411 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 203:
#line 480 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3417 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 204:
#line 481 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3423 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 205:
#line 482 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3429 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 206:
#line 483 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3435 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 207:
#line 484 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3441 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 208:
#line 485 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3447 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 209:
#line 486 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3453 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 210:
#line 487 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3459 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 211:
#line 488 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3465 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 212:
#line 489 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3471 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 213:
#line 490 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3477 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 214:
#line 491 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3483 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 215:
#line 492 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3489 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 216:
#line 493 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3495 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 217:
#line 494 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3501 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 218:
#line 495 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3507 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 219:
#line 496 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3513 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 220:
#line 497 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3519 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 221:
#line 501 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3525 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 222:
#line 502 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3531 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 223:
#line 503 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]);free(yyvsp[0]);}
#line 3537 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 224:
#line 507 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3543 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 225:
#line 508 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3549 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 226:
#line 509 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3555 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 227:
#line 510 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3561 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 228:
#line 514 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3567 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 229:
#line 518 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3573 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 230:
#line 519 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3579 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 231:
#line 523 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3585 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 232:
#line 524 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3591 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 233:
#line 528 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(6, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1]);freen(7, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3597 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 234:
#line 532 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3603 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 235:
#line 533 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3609 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 236:
#line 534 "c_parser.y" /* yacc.c:1652  */
    {yyval = createexp(yyvsp[0]); free(yyvsp[0]);}
#line 3615 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 237:
#line 535 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3621 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 238:
#line 536 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3627 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 239:
#line 537 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3633 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 240:
#line 541 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, LABS, yyvsp[-2], LABE, yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3639 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 241:
#line 542 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, LABS, yyvsp[-2], LABE, yyvsp[0]); freen(4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3645 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 242:
#line 543 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, LABS, yyvsp[-2], LABE, yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3651 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 243:
#line 547 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, ""); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3657 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 244:
#line 548 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[-1]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3663 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 245:
#line 552 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3669 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 246:
#line 553 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3675 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 247:
#line 557 "c_parser.y" /* yacc.c:1652  */
    { yyval = createdecl(yyvsp[0]); free(yyvsp[0]);}
#line 3681 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 248:
#line 558 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3687 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 249:
#line 562 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, ""); free(yyvsp[0]);}
#line 3693 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 250:
#line 563 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[-1]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3699 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 251:
#line 567 "c_parser.y" /* yacc.c:1652  */
    {yyval = createifelse(yyvsp[-4], yyvsp[-2], yyvsp[0]); freen(7, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3705 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 252:
#line 568 "c_parser.y" /* yacc.c:1652  */
    {yyval = createifelse(yyvsp[-2], yyvsp[0], NULL); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3711 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 253:
#line 569 "c_parser.y" /* yacc.c:1652  */
    {yyval = createswitch(yyvsp[-2], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3717 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 254:
#line 573 "c_parser.y" /* yacc.c:1652  */
    {yyval = createcycle(1, yyvsp[-2], yyvsp[0]); freen(5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3723 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 255:
#line 574 "c_parser.y" /* yacc.c:1652  */
    {yyval = createcycle(0, yyvsp[-2], yyvsp[-5]); freen(7, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3729 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 256:
#line 575 "c_parser.y" /* yacc.c:1652  */
    {char *cond = concatn(4, yyvsp[-3], ";", yyvsp[-2], ";"); yyval = createcycle(1, cond, yyvsp[0]); freen(7, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], cond);}
#line 3735 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 257:
#line 576 "c_parser.y" /* yacc.c:1652  */
    {char *cond = concatn(5, yyvsp[-4], ";", yyvsp[-3], ";", yyvsp[-2]); yyval = createcycle(1, cond, yyvsp[0]); freen(8, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], cond);}
#line 3741 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 258:
#line 577 "c_parser.y" /* yacc.c:1652  */
    {char *cond = concatn(4, yyvsp[-3], ";", yyvsp[-2], ";"); yyval = createcycle(1, cond, yyvsp[0]); freen(7, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], cond);}
#line 3747 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 259:
#line 578 "c_parser.y" /* yacc.c:1652  */
    {char *cond = concatn(5, yyvsp[-4], ";", yyvsp[-3], ";", yyvsp[-2]); yyval = createcycle(1, cond, yyvsp[0]); freen(8, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], cond);}
#line 3753 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 260:
#line 582 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, GOTS, yyvsp[-1], GOTE); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3759 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 261:
#line 583 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, CONT); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3765 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 262:
#line 584 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, BREA); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3771 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 263:
#line 585 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, NRET); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3777 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 264:
#line 586 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, RETS, yyvsp[-1], RETE); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3783 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 265:
#line 590 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(3, "<program>", yyvsp[0], "</program>");printf("%s", yyval); freen(2, yyvsp[0], yyval);}
#line 3789 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 266:
#line 594 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3795 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 267:
#line 595 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(2, yyvsp[-1], yyvsp[0]); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3801 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 268:
#line 599 "c_parser.y" /* yacc.c:1652  */
    { yyval = concatn(1, yyvsp[0]); free(yyvsp[0]);}
#line 3807 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 269:
#line 600 "c_parser.y" /* yacc.c:1652  */
    { yyval = createdecl(yyvsp[0]); free(yyvsp[0]);}
#line 3813 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 271:
#line 605 "c_parser.y" /* yacc.c:1652  */
    {yyval = createfunc(yyvsp[-2], yyvsp[-1], yyvsp[0]); freen(3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 3819 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 272:
#line 609 "c_parser.y" /* yacc.c:1652  */
    {yyval = createdecl(yyvsp[0]);free(yyvsp[0]);}
#line 3825 "c_parser.tab.c" /* yacc.c:1652  */
    break;

  case 273:
#line 610 "c_parser.y" /* yacc.c:1652  */
    {yyval = concatn(4, yyvsp[-1], DECS, yyvsp[0], DECE); freen(2, yyvsp[-1], yyvsp[0]);}
#line 3831 "c_parser.tab.c" /* yacc.c:1652  */
    break;


#line 3835 "c_parser.tab.c" /* yacc.c:1652  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 613 "c_parser.y" /* yacc.c:1918  */


char *createcycle(int precondition, char *condition, char *body) {
	char *toreturn;
	if(strlen(body) > 0) {
		if(precondition)
			toreturn = concatn(9, CYCS, PREC, CONS, condition, CONE, BODS, body, BODE, CYCE);
		else
			toreturn = concatn(9, CYCS, POSC, CONS, condition, CONE, BODS, body, BODE, CYCE);
	} else {
		if(precondition)
			toreturn = concatn(7, CYCS, PREC, CONS, condition, CONE, NBOD, CYCE);
		else
			toreturn = concatn(7, CYCS, POSC, CONS, condition, CONE, NBOD, CYCE);
	}
	return toreturn;
}

char *createswitch(char *condition, char *body) {
	return concatn(6, SWIS, CONS, condition, CONE, body, SWIE);
}

char *createifelse(char *condition, char *ifbody, char *elsebody) {
	char *toreturn;
	if(elsebody && strlen(elsebody) > 0) {
		if(strlen(ifbody) > 0)
			toreturn = concatn(11, IFSS, CONS, condition, CONE, IFBS, ifbody, IFBE, ELBS, elsebody, ELBE, IFSE);
		else
			toreturn = concatn(9, IFSS, CONS, condition, CONE, NIFB, ELBS, elsebody, ELBE, IFSE);
	} else {
		if(strlen(ifbody) > 0)
			toreturn = concatn(9, IFSS, CONS, condition, CONE, IFBS, ifbody, IFBE, NELB, IFSE);
		else
			toreturn = concatn(7, IFSS, CONS, condition, CONE, NIFB, NELB, IFSE);
	}
	return toreturn;
}

char *createdecl(char *decl) {
	char *toreturn = NULL;
	if(currentcalls) {
		toreturn = concatn(7, DECS, HASC, currentcalls, TEXS, decl, TEXE, DECE);
		free(currentcalls);
		currentcalls = NULL;
	} else {
		toreturn = concatn(6, DECS, DHAC, TEXS, decl, TEXE, DECE);
	}
	return toreturn;
}

char *createexp(char *exp) {
	char *toreturn = NULL;
	if(strlen(exp) > 0) {
		if(currentcalls) {
			toreturn = concatn(7, EXPS, HASC, currentcalls, TEXS, exp, TEXE, EXPE);
			free(currentcalls);
			currentcalls = NULL;
		} else {
			toreturn = concatn(6, EXPS, DHAC, TEXS, exp, TEXE, EXPE);
		}
	} else {
		toreturn = concatn(1, "");
	}
	return toreturn;
}

void addfunccall(char *funcname, char *args) {
	if(currentcalls) {
		if(args)
			currentcalls = concatn(9, currentcalls, CALS, NAMS, funcname, NAME, ARGS,  args, ARGE, CALE);
		else
			currentcalls = concatn(7, currentcalls, CALS, NAME, funcname, NAME, NARG, CALE);
	} else {
		if(args)
			currentcalls = concatn(8, CALS, NAMS, funcname, NAME, ARGS, args, ARGE, CALE);
		else
			currentcalls = concatn(6, CALS, NAMS, funcname, NAME, NARG, CALE);
	}
}

char *createfunc(char *specifiers, char *prototype, char *body) {
	char *toreturn;
	if(strlen(body) > 0)
		toreturn = concatn(9, FUNS, PROS, specifiers, prototype, PROE, BODS, body, BODE, FUNE);
	else
		toreturn = concatn(7, FUNS, PROS, specifiers, prototype, PROE, NBOD, FUNE);
	return toreturn;
}

char *concatn(int n, ...) {
    size_t flen = 0;
    va_list ap;
    va_start(ap, n);
    int i;
    for(i = 0; i < n; i++) {
        flen += strlen(va_arg(ap, char *));
    }
    va_end(ap);
    char *dest = (char *)calloc(flen + n, sizeof(char));
	if(!dest) {
		fflush(stdout);
    	fprintf(stderr, "%s\n", "an error occurred, while trying to allocate memory");
    	exit(1);
	}
    flen = 0;
    va_start(ap, n);
    for(i = 0; i < n; i++) {
        char *tmp = va_arg(ap, char *);
        strcpy(dest + flen, tmp);
        flen += strlen(tmp);
        if(i != n - 1) {
            dest[flen] = ' ';
            flen++;
        }
    }
    va_end(ap);
    return dest;
}

void freen(int n, ...) {
    va_list ap;
    va_start(ap, n);
    for(int i = 0; i < n; i++) {
        char *tmp = va_arg(ap, char *);
        free(tmp);
    }
    va_end(ap);
}

void yyerror(char *str) {
	fflush(stdout);
    printf("<error>%s on line %d</error>", str, yylineno);
    exit(1);
}

int main() {
    return yyparse();
}
