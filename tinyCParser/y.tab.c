/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ass3_12CS10008.y" /* yacc.c:339  */
 /* C Declarations and Definitions */
	#include <string.h>
	#include <stdio.h>

	extern int yylex();
	void yyerror(char *s);

#line 74 "y.tab.c" /* yacc.c:339  */

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
    TYPEDEF = 258,
    EXTERN = 259,
    STATIC = 260,
    AUTO = 261,
    REGISTER = 262,
    INLINE = 263,
    RESTRICT = 264,
    CHAR = 265,
    SHORT = 266,
    INT = 267,
    LONG = 268,
    SIGNED = 269,
    UNSIGNED = 270,
    FLOAT = 271,
    DOUBLE = 272,
    CONST = 273,
    VOLATILE = 274,
    VOID = 275,
    BOOL = 276,
    COMPLEX = 277,
    IMAGINARY = 278,
    STRUCT = 279,
    UNION = 280,
    ENUM = 281,
    BREAK = 282,
    CASE = 283,
    CONTINUE = 284,
    DEFAULT = 285,
    DO = 286,
    IF = 287,
    ELSE = 288,
    FOR = 289,
    GOTO = 290,
    WHILE = 291,
    SWITCH = 292,
    SIZEOF = 293,
    RETURN = 294,
    ELLIPSIS = 295,
    RIGHT_ASSIGN = 296,
    LEFT_ASSIGN = 297,
    ADD_ASSIGN = 298,
    SUB_ASSIGN = 299,
    MUL_ASSIGN = 300,
    DIV_ASSIGN = 301,
    MOD_ASSIGN = 302,
    AND_ASSIGN = 303,
    XOR_ASSIGN = 304,
    OR_ASSIGN = 305,
    RIGHT_OP = 306,
    LEFT_OP = 307,
    INC_OP = 308,
    DEC_OP = 309,
    PTR_OP = 310,
    AND_OP = 311,
    OR_OP = 312,
    LE_OP = 313,
    GE_OP = 314,
    EQ_OP = 315,
    NE_OP = 316,
    IDENTIFIER = 317,
    STRING_LITERAL = 318,
    PUNCTUATORS = 319,
    COMMENT = 320,
    INT_CONSTANT = 321,
    FLOAT_CONSTANT = 322,
    ENU_CONSTANT = 323,
    CHAR_CONSTANT = 324
  };
#endif
/* Tokens.  */
#define TYPEDEF 258
#define EXTERN 259
#define STATIC 260
#define AUTO 261
#define REGISTER 262
#define INLINE 263
#define RESTRICT 264
#define CHAR 265
#define SHORT 266
#define INT 267
#define LONG 268
#define SIGNED 269
#define UNSIGNED 270
#define FLOAT 271
#define DOUBLE 272
#define CONST 273
#define VOLATILE 274
#define VOID 275
#define BOOL 276
#define COMPLEX 277
#define IMAGINARY 278
#define STRUCT 279
#define UNION 280
#define ENUM 281
#define BREAK 282
#define CASE 283
#define CONTINUE 284
#define DEFAULT 285
#define DO 286
#define IF 287
#define ELSE 288
#define FOR 289
#define GOTO 290
#define WHILE 291
#define SWITCH 292
#define SIZEOF 293
#define RETURN 294
#define ELLIPSIS 295
#define RIGHT_ASSIGN 296
#define LEFT_ASSIGN 297
#define ADD_ASSIGN 298
#define SUB_ASSIGN 299
#define MUL_ASSIGN 300
#define DIV_ASSIGN 301
#define MOD_ASSIGN 302
#define AND_ASSIGN 303
#define XOR_ASSIGN 304
#define OR_ASSIGN 305
#define RIGHT_OP 306
#define LEFT_OP 307
#define INC_OP 308
#define DEC_OP 309
#define PTR_OP 310
#define AND_OP 311
#define OR_OP 312
#define LE_OP 313
#define GE_OP 314
#define EQ_OP 315
#define NE_OP 316
#define IDENTIFIER 317
#define STRING_LITERAL 318
#define PUNCTUATORS 319
#define COMMENT 320
#define INT_CONSTANT 321
#define FLOAT_CONSTANT 322
#define ENU_CONSTANT 323
#define CHAR_CONSTANT 324

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 9 "ass3_12CS10008.y" /* yacc.c:355  */

int intval;

#line 256 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 271 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

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
       0,    32,    32,    33,    34,    35,    40,    41,    42,    43,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      61,    62,    67,    68,    69,    70,    71,    72,    77,    78,
      79,    80,    81,    82,    87,    88,    93,    94,    95,    96,
     101,   102,   103,   108,   109,   110,   115,   116,   117,   118,
     119,   124,   125,   126,   131,   132,   137,   138,   143,   144,
     149,   150,   155,   156,   161,   162,   167,   168,   173,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   189,
     190,   195,   200,   201,   206,   207,   208,   209,   210,   211,
     212,   213,   218,   219,   224,   225,   230,   231,   232,   233,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   257,   258,   259,   260,   266,   267,   268,
     269,   270,   275,   276,   281,   282,   287,   288,   289,   293,
     297,   298,   303,   304,   305,   306,   307,   308,   309,   310,
     315,   316,   320,   321,   326,   327,   328,   329,   334,   335,
     341,   342,   347,   348,   353,   354,   359,   360,   365,   373,
     374,   375,   380,   381,   382,   383,   388,   393,   394,   399,
     400,   405,   406,   407,   408,   409,   410,   415,   416,   417,
     422,   423,   428,   429,   434,   435,   441,   442,   447,   448,
     449,   454,   455,   456,   457,   462,   463,   464,   465,   466,
     472,   473,   478,   479,   484,   485,   486,   487,   491,   492
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "RESTRICT", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID",
  "BOOL", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "BREAK",
  "CASE", "CONTINUE", "DEFAULT", "DO", "IF", "ELSE", "FOR", "GOTO",
  "WHILE", "SWITCH", "SIZEOF", "RETURN", "ELLIPSIS", "RIGHT_ASSIGN",
  "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP",
  "LEFT_OP", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "IDENTIFIER", "STRING_LITERAL", "PUNCTUATORS",
  "COMMENT", "INT_CONSTANT", "FLOAT_CONSTANT", "ENU_CONSTANT",
  "CHAR_CONSTANT", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "$accept",
  "primary_expression", "constant", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "enum_specifier", "enumerator_list", "enumerator", "type_qualifier",
  "function_specifier", "declarator", "direct_declarator",
  "type_qualifier_list_opt", "assignment_expression_opt", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", YY_NULLPTR
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

#define YYPACT_NINF -280

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-280)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     489,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,     3,  -280,    -8,    10,  -280,    -3,  1135,  1135,  -280,
    1135,  1135,   640,    60,     4,   466,  -280,  -280,   -54,    41,
      -2,  -280,  -280,    10,  -280,   -47,  -280,   442,  -280,  -280,
    -280,  -280,   262,  -280,    -3,  -280,   640,   663,   100,    60,
    -280,  -280,    41,    18,    65,  -280,  -280,  -280,  -280,    -8,
    -280,   857,  -280,   640,    28,   949,    73,    38,   669,   136,
     147,   157,   153,   154,   972,   702,   995,   995,   144,  -280,
    -280,  -280,  -280,  -280,   560,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,    61,   150,   949,  -280,    59,
      70,   111,   -36,   148,   158,   140,   149,   183,   -42,  -280,
    -280,   -25,  -280,  -280,  -280,  -280,   352,  -280,  -280,  -280,
    -280,  -280,   151,  -280,  -280,  -280,  -280,    -8,   170,   168,
    -280,   -51,   118,  1018,   118,    95,   949,  -280,    11,  -280,
    -280,   834,  -280,  -280,  -280,  -280,  -280,  -280,   159,  -280,
     669,   213,   949,   735,   160,   949,   949,   560,  -280,  -280,
      -7,   560,  -280,  -280,   669,    36,  1153,  -280,  1153,   180,
    -280,  -280,   190,   880,   949,   192,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,   949,  -280,   949,
     949,   949,   949,   949,   949,   949,   949,   949,   949,   949,
     949,   949,   949,   949,   949,   949,   949,   949,   949,  -280,
    -280,  -280,  -280,  -280,  1098,  -280,   194,   949,   185,  -280,
     186,  -280,    32,  -280,  -280,  -280,   949,   198,  -280,   135,
     857,   -29,  -280,   669,  -280,   191,    40,   735,  -280,    51,
      68,   215,  -280,   224,  -280,  -280,  -280,  -280,   903,  -280,
    -280,    69,  -280,    76,  -280,  -280,  -280,  -280,  -280,    59,
      59,    70,    70,   111,   111,   111,   111,   -36,   -36,   148,
     158,   140,   149,   183,   -44,  -280,  -280,  -280,  -280,   189,
    -280,  -280,  -280,   229,  -280,  -280,   768,  -280,  -280,  -280,
    -280,   949,   669,   926,   669,   669,   228,   228,   834,  -280,
    -280,   949,  -280,   949,  -280,  -280,  -280,  -280,   857,    83,
     232,   669,    87,  -280,  -280,   137,  -280,  -280,  -280,   211,
     669,  -280,   669,  -280,   801,  -280,  -280,  -280,  -280
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    96,    97,    98,    99,   129,   128,   101,   102,   103,
     104,   107,   108,   105,   106,   126,   127,   100,   109,   110,
     111,     0,   132,     0,   144,   203,     0,    84,    86,   112,
      88,    90,     0,   131,     0,     0,   200,   202,   121,     0,
       0,   148,   146,   145,    82,     0,    92,    94,    85,    87,
      89,    91,     0,   208,     0,   207,     0,     0,   140,   130,
       1,   201,     0,   124,     0,   122,   133,   149,   147,     0,
      83,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       6,     7,     8,     9,     0,   180,    28,    29,    30,    31,
      32,    33,   186,    10,     3,    22,    34,     0,    36,    40,
      43,    46,    51,    54,    56,    58,    60,    62,    64,    66,
      79,     0,   184,   185,   171,   172,     0,   182,   173,   174,
     175,   176,    94,   209,   206,   156,   139,   155,     0,   150,
     152,     0,   140,   142,   141,     0,     0,   117,     0,    93,
       2,     0,   159,    95,   204,   197,    34,    81,     0,   196,
       0,     0,     0,     0,     0,     0,     0,     0,    26,   198,
       0,     0,    23,    24,     0,     0,   114,   158,   116,     0,
      16,    17,     0,     0,     0,     0,    75,    74,    72,    73,
      69,    70,    71,    76,    77,    78,    68,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
     181,   183,   154,   137,     0,   138,     0,     0,    29,   143,
       0,   118,     0,   125,   119,   123,     0,     0,   162,     0,
       0,     0,   167,     0,   179,     0,     0,     0,   195,     0,
       0,     0,   199,     0,   177,     5,   113,   115,     0,    15,
      12,     0,    20,     0,    14,    67,    37,    38,    39,    41,
      42,    45,    44,    49,    50,    47,    48,    52,    53,    55,
      57,    59,    61,    63,     0,    80,   151,   153,   157,     0,
     136,   134,   120,     0,   170,   160,     0,   163,   166,   168,
     178,     0,     0,     0,     0,     0,    27,     0,     0,    35,
      13,     0,    11,     0,   135,   169,   161,   164,     0,     0,
     188,     0,     0,   191,   190,     0,    21,    65,   165,     0,
       0,   193,     0,    18,     0,   192,   189,   194,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -280,  -280,  -280,  -280,   -26,  -280,  -103,    13,    17,
      -5,    23,    93,    94,    92,    96,    97,  -280,   -69,   -71,
    -280,   -83,  -132,   -20,     7,  -280,   239,  -280,   -76,    29,
    -280,   247,  -140,   -19,  -280,   -13,   276,   172,  -280,     1,
     288,  -280,  -280,    98,  -280,    -6,   -70,     9,  -279,  -280,
      77,   -75,  -280,   -16,  -280,   193,  -154,  -280,  -280,  -280,
    -280,   285,  -280,   274
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   103,   104,   105,   261,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     197,   121,   158,    25,    54,    45,    46,    27,    28,   177,
      29,    64,    65,    30,    31,    32,    33,   143,   230,    34,
     144,   138,   139,   140,   141,   179,   238,   239,   240,   241,
     242,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      35,    36,    37,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     152,   153,   170,   161,   198,    41,   157,    26,   235,   247,
      40,   175,    53,    47,   233,   216,    55,   318,   176,     6,
     225,    62,   206,   207,    67,    42,   226,    53,    15,    16,
      69,    72,   122,   218,    48,    49,   133,    50,    51,    41,
     134,   132,    26,   236,    68,   237,    70,   313,   217,   156,
     208,   209,   218,   133,    22,   318,   132,   154,   168,    22,
     172,   173,    23,   298,   137,    38,    22,    23,   219,    66,
     218,    24,   229,    63,    23,   178,    24,   157,    39,   246,
     152,   156,   249,   250,   175,   244,   252,   234,   175,    24,
      44,   176,   235,   303,    63,   176,   266,   267,   268,   254,
     176,   263,   176,    63,   293,   142,   122,   255,   292,     6,
     146,   302,   262,   218,   180,   181,   182,   218,    15,    16,
     156,   155,   304,    41,   222,    67,   265,     6,   218,   160,
      57,   183,    58,   184,   284,   185,    15,    16,   199,   305,
     310,   147,   148,   200,   201,   218,   311,   285,   178,   312,
     202,   203,   178,   218,   329,   309,   289,   178,   332,   178,
     218,   251,   204,   205,   218,   253,   159,   157,   300,   152,
     297,   231,   232,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   273,   274,   275,   276,   256,   162,   257,   210,   211,
     156,   295,   296,   333,   334,   269,   270,   163,   319,   164,
     322,   271,   272,   165,   166,   152,   317,   320,   213,   323,
     324,   137,   156,   277,   278,   174,   212,   152,   214,   215,
     326,   223,   196,    71,   327,   224,   331,   152,   328,   245,
     243,   258,   259,   248,   264,   336,   288,   337,   290,   291,
     294,   301,   314,   152,   317,   330,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   306,   156,    21,    74,
      75,    76,    77,    78,    79,   307,    80,    81,    82,    83,
      84,    85,   315,   308,   335,   279,   281,   280,   149,   145,
      59,   282,    43,   283,   227,    86,    87,   325,   299,   221,
      61,    73,   287,     0,    88,    89,     0,     0,    90,    91,
      92,    93,    94,     0,     0,     0,     0,    52,    95,     0,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,    21,    74,
      75,    76,    77,    78,    79,     0,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,    88,    89,     0,     0,    90,    91,
      92,    93,    94,     0,     0,     0,     0,    52,   220,     0,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    60,     0,    21,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,    21,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,    21,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,    71,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,     0,   150,    89,     0,     0,    90,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,    21,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,    86,    87,     0,   135,     0,     0,     0,     0,
       0,    88,    89,     0,   136,    90,    91,    92,    93,    94,
      84,     0,     0,     0,    52,     0,     0,    96,    97,    98,
      99,   100,   101,     0,     0,    86,    87,     0,     0,     0,
       0,     0,   102,     0,   150,    89,     0,     0,    90,    91,
      92,    93,    94,    84,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,     0,     0,    86,    87,
       0,     0,     0,     0,     0,   169,     0,   150,    89,     0,
       0,    90,    91,    92,    93,    94,    84,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,     0,
       0,    86,    87,     0,     0,     0,     0,     0,   102,     0,
     150,    89,     0,     0,    90,    91,    92,    93,    94,    84,
     236,     0,   237,   151,   316,     0,    96,    97,    98,    99,
     100,   101,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,     0,   150,    89,     0,     0,    90,    91,    92,
      93,    94,    84,   236,     0,   237,   151,   338,     0,    96,
      97,    98,    99,   100,   101,     0,     0,    86,    87,     0,
       0,     0,     0,     0,     0,    84,   150,    89,     0,     0,
      90,    91,    92,    93,    94,     0,   236,     0,   237,   151,
      86,    87,    96,    97,    98,    99,   100,   101,    84,   150,
      89,     0,     0,    90,    91,    92,    93,    94,     0,     0,
       0,     0,   151,    86,    87,    96,    97,    98,    99,   100,
     101,    84,   150,    89,     0,     0,    90,    91,    92,    93,
      94,   260,     0,     0,     0,     0,    86,    87,    96,    97,
      98,    99,   100,   101,    84,   150,    89,     0,     0,    90,
      91,    92,    93,    94,     0,     0,     0,     0,   308,    86,
      87,    96,    97,    98,    99,   100,   101,    84,   150,    89,
       0,     0,    90,    91,    92,    93,    94,   321,     0,     0,
       0,     0,    86,    87,    96,    97,    98,    99,   100,   101,
      84,   150,    89,     0,     0,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,    86,    87,    96,    97,    98,
      99,   100,   101,    84,   150,    89,     0,     0,    90,    91,
      92,    93,   167,     0,     0,     0,     0,     0,    86,    87,
      96,    97,    98,    99,   100,   101,    84,   150,    89,     0,
       0,    90,    91,    92,    93,   171,     0,     0,     0,     0,
       0,    86,    87,    96,    97,    98,    99,   100,   101,     0,
     150,    89,     0,     0,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,    96,   228,    98,    99,
     100,   101,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,    21,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,    21
};

static const yytype_int16 yycheck[] =
{
      71,    71,    85,    78,   107,    24,    75,     0,   148,   163,
      23,    94,    32,    26,   146,    57,    32,   296,    94,     9,
      71,    75,    58,    59,    43,    24,    77,    47,    18,    19,
      77,    47,    52,    77,    27,    28,    56,    30,    31,    58,
      56,    54,    35,    72,    43,    74,    93,    91,    90,    75,
      86,    87,    77,    73,    62,   334,    69,    73,    84,    62,
      86,    87,    70,    92,    57,    62,    62,    70,    93,    71,
      77,    79,   143,    62,    70,    94,    79,   146,    75,   162,
     151,   107,   165,   166,   167,   160,    93,    76,   171,    79,
      93,   167,   232,   247,    62,   171,   199,   200,   201,   174,
     176,   184,   178,    62,   236,     5,   126,    71,    76,     9,
      92,    71,   183,    77,    53,    54,    55,    77,    18,    19,
     146,    93,    71,   142,   137,   144,   197,     9,    77,    91,
      70,    70,    72,    72,   217,    74,    18,    19,    79,    71,
      71,    76,    77,    84,    85,    77,    77,   218,   167,    73,
      80,    81,   171,    77,    71,   258,   227,   176,    71,   178,
      77,   167,    51,    52,    77,   171,    93,   236,   243,   240,
     240,    76,    77,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,   206,   207,   208,   209,   176,    70,   178,    60,    61,
     236,    76,    77,    76,    77,   202,   203,    70,   301,    62,
     303,   204,   205,    70,    70,   296,   296,   302,    88,   304,
     305,   224,   258,   210,   211,    91,    78,   308,    89,    56,
     311,    71,    92,    92,   313,    77,   321,   318,   318,    36,
      91,    71,    62,    93,    62,   330,    62,   332,    73,    73,
      62,    70,    73,   334,   334,    33,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    71,   313,    26,    27,
      28,    29,    30,    31,    32,    71,    34,    35,    36,    37,
      38,    39,    73,    75,    93,   212,   214,   213,    69,    62,
      34,   215,    24,   216,   142,    53,    54,   308,   241,   126,
      35,    47,   224,    -1,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,    -1,    26,    -1,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    71,    66,    67,    68,    69,    70,
      38,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    38,
      72,    -1,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    38,    72,    -1,    74,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    -1,    72,    -1,    74,    75,
      53,    54,    78,    79,    80,    81,    82,    83,    38,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    75,    53,    54,    78,    79,    80,    81,    82,
      83,    38,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    53,    54,    78,    79,
      80,    81,    82,    83,    38,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    75,    53,
      54,    78,    79,    80,    81,    82,    83,    38,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    53,    54,    78,    79,    80,    81,    82,    83,
      38,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    53,    54,    78,    79,    80,
      81,    82,    83,    38,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    53,    54,
      78,    79,    80,    81,    82,    83,    38,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    53,    54,    78,    79,    80,    81,    82,    83,    -1,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    26,    62,    70,    79,   117,   118,   121,   122,   124,
     127,   128,   129,   130,   133,   154,   155,   156,    62,    75,
     129,   127,   133,   134,    93,   119,   120,   129,   118,   118,
     118,   118,    75,   117,   118,   147,   157,    70,    72,   130,
       0,   155,    75,    62,   125,   126,    71,   127,   133,    77,
      93,    92,   147,   157,    27,    28,    29,    30,    31,    32,
      34,    35,    36,    37,    38,    39,    53,    54,    62,    63,
      66,    67,    68,    69,    70,    76,    78,    79,    80,    81,
      82,    83,    93,    95,    96,    97,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   115,   117,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   129,   117,   147,    62,    71,   118,   135,   136,
     137,   138,     5,   131,   134,   125,    92,    76,    77,   120,
      62,    75,   113,   140,   147,    93,    99,   112,   116,    93,
      91,   145,    70,    70,    62,    70,    70,    70,    99,    93,
     115,    70,    99,    99,    91,   115,   122,   123,   127,   139,
      53,    54,    55,    70,    72,    74,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    92,   114,   101,    79,
      84,    85,    80,    81,    51,    52,    58,    59,    86,    87,
      60,    61,    78,    88,    89,    56,    57,    90,    77,    93,
      76,   149,   129,    71,    77,    71,    77,   131,    79,   113,
     132,    76,    77,   116,    76,   126,    72,    74,   140,   141,
     142,   143,   144,    91,   145,    36,   115,   150,    93,   115,
     115,   139,    93,   139,   145,    71,   123,   123,    71,    62,
      71,    98,   113,   115,    62,   113,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   104,   105,   105,   106,
     107,   108,   109,   110,   115,   113,    40,   137,    62,   113,
      73,    73,    76,   116,    62,    76,    77,   140,    92,   144,
     145,    70,    71,   150,    71,    71,    71,    71,    75,   101,
      71,    77,    73,    91,    73,    73,    76,   140,   142,   115,
     145,    71,   115,   145,   145,   141,   113,   112,   140,    71,
      33,   145,    71,    76,    77,    93,   145,   145,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,   100,   100,
     100,   100,   100,   100,   101,   101,   102,   102,   102,   102,
     103,   103,   103,   104,   104,   104,   105,   105,   105,   105,
     105,   106,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   123,   123,   123,   124,   124,   124,
     124,   124,   125,   125,   126,   126,   127,   127,   127,   128,
     129,   129,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   132,   132,   133,   133,   133,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   139,   140,
     140,   140,   141,   141,   141,   141,   142,   143,   143,   144,
     144,   145,   145,   145,   145,   145,   145,   146,   146,   146,
     147,   147,   148,   148,   149,   149,   150,   150,   151,   151,
     151,   152,   152,   152,   152,   153,   153,   153,   153,   153,
     154,   154,   155,   155,   156,   156,   156,   156,   157,   157
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     4,     5,     5,
       6,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     1,     1,     3,     5,     6,     5,     4,     4,     3,
       0,     1,     0,     1,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     1,
       3,     4,     1,     2,     3,     4,     2,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     2,     1,     1,     1,     2,     5,     7,
       5,     5,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     3,     3,     2,     1,     2
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
        case 5:
#line 36 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("primary_expression\n");}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 57 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("postfix_expression\n");}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 63 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("argument_expression_list\n");}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 73 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("unary_expression\n");}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 83 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("unary_operator\n");}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 89 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("cast_expression\n");}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 97 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("multiplicative_expression\n");}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 104 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("additive_expression\n");}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 111 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("shift_expression\n");}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 120 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("relational_expression\n");}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 127 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("equality_expression\n");}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 133 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("and_expression\n");}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 139 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("exclusive_or_expression\n");}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 145 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("inclusive_or_expression\n");}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 151 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("logical_and_expression\n");}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 157 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("logical_or_expression\n");}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 163 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("conditional_expression\n");}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 169 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("assignment_expression\n");}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 174 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("assignment_operator\n");}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 185 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("assignment_operator\n");}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 191 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("expression\n");}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 196 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("constant_expression\n");}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 202 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("declaration\n");}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 214 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("declaration_specifiers\n");}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 220 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("init_declarator_list\n");}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 226 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("init_declarator\n");}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 234 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("storage_class_specifier\n");}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 251 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("type_specifier\n");}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 261 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("specifier_qualifier_list\n");}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 271 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("enum_specifier\n");}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 277 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("enumerator_list\n");}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 283 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("enumerator\n");}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 290 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("type_qualifier\n");}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 294 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("function_specifier\n");}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 299 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("declarator\n");}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 311 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("direct_declarator\n");}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 317 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("type_qualifier_list_opt\n");}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 322 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("assignment_expression_opt\n");}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 330 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("pointer\n");}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 336 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("type_qualifier_list\n");}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 343 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("parameter_type_list\n");}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 349 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("parameter_list\n");}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 355 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("parameter_declaration\n");}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 361 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("identifier_list\n");}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 366 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("type_name\n");}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 376 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("initializer\n");}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 384 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("initializer_list\n");}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 389 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("designation\n");}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 395 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("designator_list\n");}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 401 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("designator\n");}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 411 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("statement\n");}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 418 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("labeled_statement\n");}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 424 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("compound_statement\n");}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 430 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("block_item_list\n");}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 436 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("block_item\n");}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 443 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("expression_statement\n");}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 450 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("selection_statement\n");}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 458 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("iteration_statement\n");}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 468 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("jump_statement\n");}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 474 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("translation_unit\n");}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 480 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("external_declaration\n");}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 488 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("function_definition\n");}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 493 "ass3_12CS10008.y" /* yacc.c:1646  */
    {printf("declaration_list\n");}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2166 "y.tab.c" /* yacc.c:1646  */
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
#line 496 "ass3_12CS10008.y" /* yacc.c:1906  */

void yyerror(char *s) {
	printf ("ERROR: %s",s);
}
