/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "parser.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "hash.h"
  #include "ast.h"
  #include "semantic.h"

  int getLineNumber (void);
  int yylex(void);
  int yyerror();

  AST *root;
  int errorCounter;


#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    KW_CHAR = 258,
    KW_INT = 259,
    KW_FLOAT = 260,
    KW_CODE = 261,
    KW_IF = 262,
    KW_ELSE = 263,
    KW_WHILE = 264,
    KW_INPUT = 265,
    KW_PRINT = 266,
    KW_RETURN = 267,
    OPERATOR_LE = 268,
    OPERATOR_GE = 269,
    OPERATOR_EQ = 270,
    OPERATOR_DIF = 271,
    TK_IDENTIFIER = 272,
    LIT_INT = 273,
    LIT_REAL = 274,
    LIT_CHAR = 275,
    LIT_STRING = 276,
    TOKEN_ERROR = 277
  };
#endif
/* Tokens.  */
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_CODE 261
#define KW_IF 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_INPUT 265
#define KW_PRINT 266
#define KW_RETURN 267
#define OPERATOR_LE 268
#define OPERATOR_GE 269
#define OPERATOR_EQ 270
#define OPERATOR_DIF 271
#define TK_IDENTIFIER 272
#define LIT_INT 273
#define LIT_REAL 274
#define LIT_CHAR 275
#define LIT_STRING 276
#define TOKEN_ERROR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

  HASH_NODE *symbol;
  AST *ast;

#line 187 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

#define YYUNDEFTOK  2
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,     2,
      36,    37,    30,    28,    38,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      23,    32,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    26,    40,    27,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    88,    88,    91,    94,    95,    96,    97,   100,   103,
     106,   109,   110,   113,   114,   117,   118,   121,   124,   125,
     128,   131,   132,   133,   134,   135,   136,   139,   140,   143,
     145,   146,   149,   152,   153,   156,   159,   160,   163,   166,
     167,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   193,   194,   197,   198,   201,   202,   203,   206,
     207,   208,   209
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_CHAR", "KW_INT", "KW_FLOAT",
  "KW_CODE", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_INPUT", "KW_PRINT",
  "KW_RETURN", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ", "OPERATOR_DIF",
  "TK_IDENTIFIER", "LIT_INT", "LIT_REAL", "LIT_CHAR", "LIT_STRING",
  "TOKEN_ERROR", "'<'", "'>'", "'&'", "'|'", "'~'", "'+'", "'-'", "'*'",
  "'/'", "'='", "';'", "'['", "']'", "'('", "')'", "','", "'{'", "'}'",
  "$accept", "programa", "ldecl_globais", "lista_decl", "decl_var",
  "decl_vetor", "decl_proto", "opcional", "lparam", "fim_param", "param",
  "lista_code", "decl_func", "cmd", "cmd_atribuicao", "cmd_print",
  "aux_print", "cmd_return", "cmd_ctrl_fluxo", "cmd_if", "tail", "bloco",
  "lista_cmd", "expr", "lista_args", "lista_args_fim", "tipo", "literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    60,    62,    38,   124,   126,    43,    45,
      42,    47,    61,    59,    91,    93,    40,    41,    44,   123,
     125
};
# endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,   -29,   -29,   -29,     2,   -29,    22,    14,    14,    14,
     -14,   -29,    15,   -29,    22,   -29,   -29,   -29,     4,    -2,
     -29,    46,    17,    14,    33,    34,     6,    -6,     7,   -29,
      -2,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,    57,    56,    55,    59,    76,    -6,    -6,    62,
     -28,   -29,   -29,   -29,   -29,    -6,    61,   258,   195,    -6,
      -6,    -2,    60,   -29,    46,    66,    14,   -29,   -29,    92,
     111,    14,    -6,    -6,   130,   -29,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,   -29,
     216,   149,   -29,   -29,    69,    46,   -29,    59,    -2,    -2,
      72,   172,    58,    73,   -29,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    18,    18,   -29,   -29,   -29,    63,
     -29,   -29,   -29,    95,   -29,   -29,   -29,    -6,   -29,   -29,
      -6,    -2,   -29,    58,   237,   -29,   -29,   -29
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,    66,    67,    68,     0,     2,    19,     7,     7,     7,
       0,     1,     0,     3,    19,     4,     5,     6,     0,     0,
      18,     0,     0,    14,     0,     0,     0,     0,     0,    26,
      40,    20,    21,    22,    23,    24,    33,    25,    70,    71,
      69,    72,     0,     0,     0,    16,     0,     0,     0,     0,
      55,    59,    60,    58,    30,     0,     0,    31,     0,     0,
       0,    40,     0,     8,    12,     0,     0,    13,    17,     0,
       0,     0,     0,    63,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,    39,    38,     0,    12,    10,    16,     0,     0,
       0,     0,    65,     0,    61,    53,    52,    51,    50,    45,
      46,    47,    48,    49,    41,    42,    44,    43,    27,     0,
       9,    11,    15,    37,    34,    54,    57,     0,    62,    56,
       0,     0,    35,    65,     0,    36,    64,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,    36,   -29,   -29,   -29,    16,   -29,    31,
      48,    99,   -29,   -19,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,    70,   -26,   -29,    -1,    -3,   109
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    94,    44,    67,
      45,    13,    14,    61,    32,    33,    56,    34,    35,    36,
     132,    37,    62,    57,   103,   128,    10,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    58,    11,    18,    49,    24,    72,    25,    73,    26,
      27,    50,    51,    52,    53,    28,    49,     1,     2,     3,
      46,    69,    70,    50,    51,    52,    53,    54,    12,    74,
      55,    29,    19,    90,    91,    43,    21,    30,    22,    59,
      23,    60,    55,    15,    16,    17,   101,   102,    87,    88,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    46,    38,    39,    40,    41,   100,    47,
      48,    76,    77,    78,    79,    85,    86,    87,    88,   123,
     124,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      63,    64,    65,    68,    75,   130,   127,    66,    71,    96,
      93,   133,   120,   131,   134,    76,    77,    78,    79,   125,
     129,   121,   135,    20,    97,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    76,    77,    78,    79,   122,    98,
      42,    92,   136,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    76,    77,    78,    79,     0,    99,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    76,    77,    78,    79,     0,   104,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,   119,    76,    77,    78,    79,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,   126,    76,    77,
      78,    79,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,    76,
      77,    78,    79,     0,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,   118,
      76,    77,    78,    79,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
     137,    76,    77,    78,    79,     0,     0,     0,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      19,    27,     0,    17,    10,     7,    34,     9,    36,    11,
      12,    17,    18,    19,    20,    17,    10,     3,     4,     5,
      23,    47,    48,    17,    18,    19,    20,    21,     6,    55,
      36,    33,    17,    59,    60,    18,    32,    39,    34,    32,
      36,    34,    36,     7,     8,     9,    72,    73,    30,    31,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    66,    18,    19,    20,    21,    71,    36,
      36,    13,    14,    15,    16,    28,    29,    30,    31,    98,
      99,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      33,    35,    37,    17,    33,    32,    38,    38,    36,    33,
      40,   127,    33,     8,   130,    13,    14,    15,    16,    37,
      37,    95,   131,    14,    66,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    13,    14,    15,    16,    97,    37,
      21,    61,   133,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    13,    14,    15,    16,    -1,    37,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    13,    14,    15,    16,    -1,    37,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    35,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    35,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    42,    43,    44,    45,    46,    47,
      67,     0,     6,    52,    53,    44,    44,    44,    17,    17,
      52,    32,    34,    36,     7,     9,    11,    12,    17,    33,
      39,    54,    55,    56,    58,    59,    60,    62,    18,    19,
      20,    21,    68,    18,    49,    51,    67,    36,    36,    10,
      17,    18,    19,    20,    21,    36,    57,    64,    64,    32,
      34,    54,    63,    33,    35,    37,    38,    50,    17,    64,
      64,    36,    34,    36,    64,    33,    13,    14,    15,    16,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    33,
      64,    64,    63,    40,    48,    68,    33,    51,    37,    37,
      67,    64,    64,    65,    37,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    33,    35,
      33,    48,    50,    54,    54,    37,    35,    38,    66,    37,
      32,     8,    61,    64,    64,    54,    66,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    44,    44,    45,    46,
      47,    48,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    54,    54,    54,    54,    54,    54,    55,    55,    56,
      57,    57,    58,    59,    59,    60,    61,    61,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    68,
      68,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     0,     5,     7,
       6,     2,     0,     2,     0,     3,     0,     2,     2,     0,
       3,     1,     1,     1,     1,     1,     1,     4,     7,     3,
       1,     1,     3,     1,     5,     6,     2,     0,     3,     2,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     1,     4,     4,     1,     1,
       1,     3,     2,     0,     3,     0,     1,     1,     1,     1,
       1,     1,     1
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 88 "parser.y"
                                                                  {root=(yyval.ast); astPrint(root, 0); errorCounter = semanticVerification(root);}
#line 1484 "y.tab.c"
    break;

  case 3:
#line 91 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_LSTDECGLOB, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1490 "y.tab.c"
    break;

  case 4:
#line 94 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_LSTDEC, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1496 "y.tab.c"
    break;

  case 5:
#line 95 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_LSTDEC, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1502 "y.tab.c"
    break;

  case 6:
#line 96 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_LSTDEC, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1508 "y.tab.c"
    break;

  case 7:
#line 97 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1514 "y.tab.c"
    break;

  case 8:
#line 100 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_DECVAR, (yyvsp[-3].symbol), (yyvsp[-4].ast), (yyvsp[-1].ast), 0, 0, getLineNumber());}
#line 1520 "y.tab.c"
    break;

  case 9:
#line 103 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_DECVEC, (yyvsp[-5].symbol), (yyvsp[-6].ast), astCreate(AST_SYMBOL, (yyvsp[-3].symbol), 0, 0, 0, 0, getLineNumber()), (yyvsp[-1].ast), 0, getLineNumber());}
#line 1526 "y.tab.c"
    break;

  case 10:
#line 106 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_DECPROTO, (yyvsp[-4].symbol), (yyvsp[-5].ast), (yyvsp[-2].ast), 0, 0, getLineNumber());}
#line 1532 "y.tab.c"
    break;

  case 11:
#line 109 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_OPT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1538 "y.tab.c"
    break;

  case 12:
#line 110 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1544 "y.tab.c"
    break;

  case 13:
#line 113 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_LSTPARAMINIT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1550 "y.tab.c"
    break;

  case 14:
#line 114 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1556 "y.tab.c"
    break;

  case 15:
#line 117 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_LSTPARAM, 0, (yyvsp[-1].ast), (yyvsp[0].ast),0 , 0, getLineNumber());}
#line 1562 "y.tab.c"
    break;

  case 16:
#line 118 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1568 "y.tab.c"
    break;

  case 17:
#line 121 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_PARAM, (yyvsp[0].symbol), (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1574 "y.tab.c"
    break;

  case 18:
#line 124 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_LSTCODE, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1580 "y.tab.c"
    break;

  case 19:
#line 125 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1586 "y.tab.c"
    break;

  case 20:
#line 128 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_CODE, (yyvsp[-1].symbol), (yyvsp[0].ast), 0, 0, 0, getLineNumber());}
#line 1592 "y.tab.c"
    break;

  case 21:
#line 131 "parser.y"
                                                                  {(yyval.ast)=(yyvsp[0].ast);}
#line 1598 "y.tab.c"
    break;

  case 22:
#line 132 "parser.y"
                                                                  {(yyval.ast)=(yyvsp[0].ast);}
#line 1604 "y.tab.c"
    break;

  case 23:
#line 133 "parser.y"
                                                                  {(yyval.ast)=(yyvsp[0].ast);}
#line 1610 "y.tab.c"
    break;

  case 24:
#line 134 "parser.y"
                                                                  {(yyval.ast)=(yyvsp[0].ast);}
#line 1616 "y.tab.c"
    break;

  case 25:
#line 135 "parser.y"
                                                                  {(yyval.ast)=(yyvsp[0].ast);}
#line 1622 "y.tab.c"
    break;

  case 26:
#line 136 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1628 "y.tab.c"
    break;

  case 27:
#line 139 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_ATTR, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1634 "y.tab.c"
    break;

  case 28:
#line 140 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_VECATTR, (yyvsp[-6].symbol), (yyvsp[-4].ast), (yyvsp[-1].ast), 0, 0, getLineNumber());}
#line 1640 "y.tab.c"
    break;

  case 29:
#line 143 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_PRINT, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1646 "y.tab.c"
    break;

  case 30:
#line 145 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1652 "y.tab.c"
    break;

  case 31:
#line 146 "parser.y"
                                                                  {(yyval.ast)=(yyvsp[0].ast);}
#line 1658 "y.tab.c"
    break;

  case 32:
#line 149 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_RETURN, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1664 "y.tab.c"
    break;

  case 33:
#line 152 "parser.y"
                                                                  {(yyval.ast)=(yyvsp[0].ast);}
#line 1670 "y.tab.c"
    break;

  case 34:
#line 153 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_WHILE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1676 "y.tab.c"
    break;

  case 35:
#line 156 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_IF, 0, (yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast), 0, getLineNumber());}
#line 1682 "y.tab.c"
    break;

  case 36:
#line 159 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_ELSE, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber());}
#line 1688 "y.tab.c"
    break;

  case 37:
#line 160 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1694 "y.tab.c"
    break;

  case 38:
#line 163 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_BLOCK, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1700 "y.tab.c"
    break;

  case 39:
#line 166 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_CMDLST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1706 "y.tab.c"
    break;

  case 40:
#line 167 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1712 "y.tab.c"
    break;

  case 41:
#line 170 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_ADD, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1718 "y.tab.c"
    break;

  case 42:
#line 171 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1724 "y.tab.c"
    break;

  case 43:
#line 172 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_DIV, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1730 "y.tab.c"
    break;

  case 44:
#line 173 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_MUL, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1736 "y.tab.c"
    break;

  case 45:
#line 174 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_LT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1742 "y.tab.c"
    break;

  case 46:
#line 175 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_GT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1748 "y.tab.c"
    break;

  case 47:
#line 176 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_AND, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1754 "y.tab.c"
    break;

  case 48:
#line 177 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_OR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1760 "y.tab.c"
    break;

  case 49:
#line 178 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_NOT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1766 "y.tab.c"
    break;

  case 50:
#line 179 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_DIF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1772 "y.tab.c"
    break;

  case 51:
#line 180 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_EQ, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1778 "y.tab.c"
    break;

  case 52:
#line 181 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_GE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1784 "y.tab.c"
    break;

  case 53:
#line 182 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_LE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1790 "y.tab.c"
    break;

  case 54:
#line 183 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_INPUT, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1796 "y.tab.c"
    break;

  case 55:
#line 184 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1802 "y.tab.c"
    break;

  case 56:
#line 185 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_FUN, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1808 "y.tab.c"
    break;

  case 57:
#line 186 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_VEC, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1814 "y.tab.c"
    break;

  case 58:
#line 187 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1820 "y.tab.c"
    break;

  case 59:
#line 188 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1826 "y.tab.c"
    break;

  case 60:
#line 189 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1832 "y.tab.c"
    break;

  case 61:
#line 190 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_PAREN, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1838 "y.tab.c"
    break;

  case 62:
#line 193 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_ARGLSTINIT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1844 "y.tab.c"
    break;

  case 63:
#line 194 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1850 "y.tab.c"
    break;

  case 64:
#line 197 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_ARGLST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1856 "y.tab.c"
    break;

  case 65:
#line 198 "parser.y"
                                                                  {(yyval.ast)=0;}
#line 1862 "y.tab.c"
    break;

  case 66:
#line 201 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_CHAR, 0, 0, 0, 0, 0, getLineNumber());}
#line 1868 "y.tab.c"
    break;

  case 67:
#line 202 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_INT, 0, 0, 0, 0, 0, getLineNumber());}
#line 1874 "y.tab.c"
    break;

  case 68:
#line 203 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_FLOAT, 0, 0, 0, 0, 0, getLineNumber());}
#line 1880 "y.tab.c"
    break;

  case 69:
#line 206 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1886 "y.tab.c"
    break;

  case 70:
#line 207 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1892 "y.tab.c"
    break;

  case 71:
#line 208 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1898 "y.tab.c"
    break;

  case 72:
#line 209 "parser.y"
                                                                  {(yyval.ast)=astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber() );}
#line 1904 "y.tab.c"
    break;


#line 1908 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 213 "parser.y"


void checkSemantic() {
  if(errorCounter > 0){
    fprintf(stderr, "%d Semantic Errors in Total.\n", errorCounter);
    exit(4);
  }
}

int yyerror() {
  printf("Erro sintatico na linha %d\n", getLineNumber());
  exit(3);
}

AST * getAST() {
  return root;
}
