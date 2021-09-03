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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scopenumber;
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[2000];  // Get current code line from lex
int dump_number;
int attribute_count;
int syntax_flag;
char outbuf[50];
/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char* name,char* type);
void create_symbol();
void insert_symbol(char* name,char* entry_type,char* data_type,int scope_level,int attribute_number);
void check_symbol();
void dump_symbol(int nownumber);
void test();
void create_attribute();
void insert_attribute(char* type,int count);
char* show_attribute(int number);

/* semantic test */
int semantic_happen;
char semantic_name[50];
char semantic_type[50];
char semantic_message[50];
void undeclare_test(char* name,char* type);
void redeclare_test(char* name,char* type);
void semanticerror();

/* .j file generate */

FILE *file;

void gencode_function(char* java_code);
void generate_variable_code(char* type,char* name);
int declarate_has_init;
int constantflag;
int intconstant;
float floatconstant;
void generate_local(char* type,char* name);
void generate_print_function(char* input);
char* remember_function_name;
char* remember_function_type;
char* funcparameterout(char* name);
char parameterreturn[50];
typedef struct heap_s{
	int i;
	float f;
	int flag;
}Heap;
Heap my_heap[10];
void heapipush(int input);
int heapipop();
void heapfpush(float input);
float heapfpop();


typedef struct symbol{
	int index;
	char* name;
	char* entry_type;
	char* data_type;
	int scope_level;
	int attribute_number;
	struct symbol * next;
	struct symbol* prev;
} Symbol_Table;

Symbol_Table* my_symbol_head;

typedef struct attribute{
	int number;
	char* type;
	struct attribute* next;
	struct attribute*prev;
} Attribute_Table;

Attribute_Table* my_attribute_head;





#line 155 "y.tab.c" /* yacc.c:339  */

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
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    MOD = 262,
    INC = 263,
    DEC = 264,
    EQ = 265,
    NE = 266,
    MT = 267,
    LT = 268,
    MTE = 269,
    LTE = 270,
    ASGN = 271,
    ADDASGN = 272,
    SUBASGN = 273,
    MULASGN = 274,
    DIVASGN = 275,
    MODASGN = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    LB = 280,
    RB = 281,
    LCB = 282,
    RCB = 283,
    LSB = 284,
    RSB = 285,
    COMMA = 286,
    PRINT = 287,
    IF = 288,
    ELSE = 289,
    FOR = 290,
    WHILE = 291,
    SEMICOLON = 292,
    VOID = 293,
    INT = 294,
    FLOAT = 295,
    STRING = 296,
    BOOL = 297,
    TRUE = 298,
    FALSE = 299,
    RETURN = 300,
    I_CONST = 301,
    F_CONST = 302,
    STRING_CONST = 303,
    ID = 304
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define MOD 262
#define INC 263
#define DEC 264
#define EQ 265
#define NE 266
#define MT 267
#define LT 268
#define MTE 269
#define LTE 270
#define ASGN 271
#define ADDASGN 272
#define SUBASGN 273
#define MULASGN 274
#define DIVASGN 275
#define MODASGN 276
#define AND 277
#define OR 278
#define NOT 279
#define LB 280
#define RB 281
#define LCB 282
#define RCB 283
#define LSB 284
#define RSB 285
#define COMMA 286
#define PRINT 287
#define IF 288
#define ELSE 289
#define FOR 290
#define WHILE 291
#define SEMICOLON 292
#define VOID 293
#define INT 294
#define FLOAT 295
#define STRING 296
#define BOOL 297
#define TRUE 298
#define FALSE 299
#define RETURN 300
#define I_CONST 301
#define F_CONST 302
#define STRING_CONST 303
#define ID 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 94 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;

#line 299 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 316 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   376

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   142,   146,   147,   151,   152,   156,   173,
     177,   190,   194,   199,   206,   210,   211,   215,   216,   222,
     234,   235,   240,   244,   245,   271,   272,   273,   274,   275,
     276,   280,   281,   282,   283,   287,   288,   292,   297,   298,
     302,   303,   304,   308,   309,   313,   325,   337,   345,   349,
     350,   354,   355,   356,   360,   361,   365,   366,   370,   371,
     375,   376,   380,   381,   382,   386,   387,   388,   389,   390,
     394,   395,   461,   465,   466,   467,   468,   474,   475,   476,
     477,   478,   479,   483,   484,   488,   489,   493,   494,   498,
     505,   591,   592,   593,   594,   595,   599,   600,   608,   609,
     613,   620,   621,   622,   623,   624
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "MOD", "INC",
  "DEC", "EQ", "NE", "MT", "LT", "MTE", "LTE", "ASGN", "ADDASGN",
  "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND", "OR", "NOT", "LB",
  "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "PRINT", "IF", "ELSE", "FOR",
  "WHILE", "SEMICOLON", "VOID", "INT", "FLOAT", "STRING", "BOOL", "TRUE",
  "FALSE", "RETURN", "I_CONST", "F_CONST", "STRING_CONST", "ID", "$accept",
  "program", "ex_declaration", "function_de", "function_forward", "scope",
  "scopestart", "scopeend", "parameter_part", "block_item_list",
  "block_item", "declaration", "init_declarator", "initializer",
  "assignment_expression", "assignment_operator", "unary_expression",
  "postfix_expression", "primary_expression", "argument_expression_list",
  "constant", "boolean", "unary_operator", "cast_expression",
  "specifier_qualifier_list", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "statement",
  "compound_statement", "expression_statement", "selection_statement",
  "iteration_statement", "whileexpression", "whileop", "jump_statement",
  "expression", "print_statement", "type", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-133)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      79,  -133,  -133,  -133,  -133,  -133,     5,  -133,  -133,    79,
    -133,   -42,  -133,  -133,   -20,   -19,     6,    13,   -13,    79,
    -133,    12,  -133,  -133,  -133,  -133,  -133,   197,    14,  -133,
    -133,   327,   327,  -133,   249,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,   139,     9,  -133,  -133,  -133,    12,  -133,
      61,    71,    17,   250,    49,    35,    98,    73,    78,    83,
    -133,   275,   145,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,    -2,  -133,    55,  -133,    12,  -133,  -133,    86,
      38,    79,  -133,  -133,  -133,  -133,  -133,  -133,    12,  -133,
    -133,   301,  -133,  -133,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,  -133,   171,    67,
      12,    67,  -133,    20,  -133,  -133,  -133,    12,  -133,    93,
      12,  -133,  -133,  -133,  -133,  -133,    68,    71,    17,   250,
     250,    49,    49,    49,    49,    35,    35,  -133,  -133,  -133,
    -133,   101,    69,   151,   103,  -133,  -133,  -133,  -133,    12,
      87,   223,  -133,  -133,  -133,  -133,  -133,    67,   223,  -133,
    -133,    99,  -133,  -133,   223,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   105,   101,   102,   104,   103,     0,     3,     4,    14,
       5,     0,     1,     2,     0,     0,    21,     0,     0,     0,
      13,     0,     8,    19,    10,     7,     6,     0,     0,    51,
      52,     0,     0,    53,     0,    49,    50,    45,    46,    47,
      40,    20,    22,    54,    31,    35,    41,    48,     0,    73,
      23,    58,    60,    62,    65,    70,     0,     0,     0,     0,
      85,     0,     0,    15,    17,    98,    18,    77,    78,    79,
      80,    81,     0,    82,     0,    12,     0,    32,    33,     0,
       0,    57,    25,    26,    27,    28,    29,    30,     0,    38,
      39,     0,    54,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    96,     0,    11,     9,    16,     0,    86,    21,
       0,    42,    56,    24,    36,    43,     0,    59,    61,    63,
      64,    66,    67,    68,    69,    71,    72,    74,    75,    76,
      84,     0,     0,     0,     0,    97,    99,    55,    37,     0,
       0,     0,    95,    91,    92,    93,    94,     0,     0,    44,
     100,    88,    90,    89,     0,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,   126,  -133,  -133,  -133,  -133,  -133,  -133,    94,
     -60,    62,  -133,  -133,   -21,  -133,   -23,  -133,  -108,  -133,
    -133,  -133,  -133,   -15,    70,  -133,    58,    72,   -31,   215,
     -16,  -132,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   -22,
    -133,     4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    26,    27,   115,    14,    62,
      63,    64,    17,    41,    65,    88,    43,    44,    45,   126,
      46,    47,    48,    49,    79,    50,    51,    52,    53,    54,
      55,    66,    67,    68,    69,    70,   144,   157,    71,    72,
      73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,   141,   116,   143,    11,    12,    18,    16,    77,    78,
      11,    19,    80,    15,    24,    29,    30,    89,    90,   161,
      31,    32,    21,    28,    25,    92,   163,    96,    97,   117,
      20,    22,   165,    93,    91,   118,    33,    34,    81,   113,
     104,   105,   106,     1,     2,     3,     4,     5,   116,   162,
      23,   117,   102,   103,    80,    35,    36,   145,    37,    38,
      39,    40,    10,    75,   121,   129,   130,   123,    10,   117,
     125,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    94,    81,   135,   136,   142,   137,
     138,   139,    76,    95,   148,   151,   146,    92,   109,   149,
     117,    29,    30,   110,   119,   147,    31,    32,   111,    21,
      35,    36,   120,    37,    38,    39,    40,     1,     2,     3,
       4,     5,    33,    34,   160,    56,   107,   150,   159,   158,
      57,    58,    13,   164,    59,    60,     1,     2,     3,     4,
       5,    35,    36,    61,    37,    38,    39,    40,    29,    30,
     108,   122,   127,    31,    32,    82,    83,    84,    85,    86,
      87,   152,     0,   153,   154,   155,   156,   128,     0,    33,
      34,     0,    56,   114,    29,    30,     0,    57,    58,    31,
      32,    59,    60,     1,     2,     3,     4,     5,    35,    36,
      61,    37,    38,    39,    40,    33,    34,     0,    56,   140,
      29,    30,     0,    57,    58,    31,    32,    59,    60,     1,
       2,     3,     4,     5,    35,    36,    61,    37,    38,    39,
      40,    33,    34,     0,    56,     0,    29,    30,     0,    57,
      58,    31,    32,    59,    60,     1,     2,     3,     4,     5,
      35,    36,    61,    37,    38,    39,    40,    33,    34,     0,
      56,     0,    29,    30,     0,    57,    58,    31,    32,    59,
      60,     0,    98,    99,   100,   101,    35,    36,    61,    37,
      38,    39,    40,    33,    34,     0,     0,     0,    29,    30,
       0,     0,     0,    31,    32,     0,     0,     1,     2,     3,
       4,     5,    35,    36,     0,    37,    38,    39,    40,    33,
      34,     0,     0,     0,    29,    30,     0,     0,     0,    31,
      32,     0,   112,   131,   132,   133,   134,     0,    35,    36,
       0,    37,    38,    39,    40,    33,    34,   124,     0,     0,
      29,    30,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,    35,    36,     0,    37,    38,    39,
      40,    33,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36,     0,    37,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
      21,   109,    62,   111,     0,     0,    26,    49,    31,    32,
       6,    31,    34,     9,    27,     3,     4,     8,     9,   151,
       8,     9,    16,    19,    37,    48,   158,    10,    11,    31,
      49,    25,   164,    48,    25,    37,    24,    25,    34,    61,
       5,     6,     7,    38,    39,    40,    41,    42,   108,   157,
      37,    31,     3,     4,    76,    43,    44,    37,    46,    47,
      48,    49,     0,    49,    26,    96,    97,    88,     6,    31,
      91,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    23,    81,   102,   103,   110,   104,
     105,   106,    25,    22,    26,    26,   117,   120,    25,    31,
      31,     3,     4,    25,    49,   120,     8,     9,    25,    16,
      43,    44,    26,    46,    47,    48,    49,    38,    39,    40,
      41,    42,    24,    25,    37,    27,    28,    26,   149,    26,
      32,    33,     6,    34,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     3,     4,
      56,    81,    94,     8,     9,    16,    17,    18,    19,    20,
      21,    10,    -1,    12,    13,    14,    15,    95,    -1,    24,
      25,    -1,    27,    28,     3,     4,    -1,    32,    33,     8,
       9,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    24,    25,    -1,    27,    28,
       3,     4,    -1,    32,    33,     8,     9,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    24,    25,    -1,    27,    -1,     3,     4,    -1,    32,
      33,     8,     9,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    24,    25,    -1,
      27,    -1,     3,     4,    -1,    32,    33,     8,     9,    36,
      37,    -1,    12,    13,    14,    15,    43,    44,    45,    46,
      47,    48,    49,    24,    25,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,     8,     9,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    46,    47,    48,    49,    24,
      25,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,     8,
       9,    -1,    37,    98,    99,   100,   101,    -1,    43,    44,
      -1,    46,    47,    48,    49,    24,    25,    26,    -1,    -1,
       3,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    46,    47,    48,
      49,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,    40,    41,    42,    51,    52,    53,    54,
      61,    91,     0,    52,    58,    91,    49,    62,    26,    31,
      49,    16,    25,    37,    27,    37,    55,    56,    91,     3,
       4,     8,     9,    24,    25,    43,    44,    46,    47,    48,
      49,    63,    64,    66,    67,    68,    70,    71,    72,    73,
      75,    76,    77,    78,    79,    80,    27,    32,    33,    36,
      37,    45,    59,    60,    61,    64,    81,    82,    83,    84,
      85,    88,    89,    90,    91,    49,    25,    66,    66,    74,
      89,    91,    16,    17,    18,    19,    20,    21,    65,     8,
       9,    25,    66,    73,    23,    22,    10,    11,    12,    13,
      14,    15,     3,     4,     5,     6,     7,    28,    59,    25,
      25,    25,    37,    89,    28,    57,    60,    31,    37,    49,
      26,    26,    74,    64,    26,    64,    69,    76,    77,    78,
      78,    79,    79,    79,    79,    80,    80,    73,    73,    73,
      28,    68,    89,    68,    86,    37,    64,    73,    26,    31,
      26,    26,    10,    12,    13,    14,    15,    87,    26,    64,
      37,    81,    68,    81,    34,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    53,    53,    54,    55,
      56,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      62,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    78,    78,    78,    78,    78,
      79,    79,    79,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      86,    87,    87,    87,    87,    87,    88,    88,    89,    89,
      90,    91,    91,    91,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     4,     4,     3,     3,
       1,     1,     4,     2,     0,     1,     2,     1,     1,     3,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     1,     3,     4,     2,     2,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     2,     1,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     2,     7,     5,     5,
       3,     1,     1,     1,     1,     1,     2,     3,     1,     3,
       5,     1,     1,     1,     1,     1
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
        case 8:
#line 156 "compiler_hw3.y" /* yacc.c:1646  */
    {
	redeclare_test((yyvsp[-1].string),"function");
	attribute_count++; 
	insert_symbol((yyvsp[-1].string),"function",(yyvsp[-2].string),scopenumber,attribute_count);
	remember_function_name=(yyvsp[-1].string);
	if((yyvsp[-2].string)=="int")
		remember_function_type="I";
	else if((yyvsp[-2].string)=="float")
		remember_function_type="F";
	else if((yyvsp[-2].string)=="string")
		remember_function_type="Ljava/lang/String;";
	else if((yyvsp[-2].string)=="void")
		remember_function_type="V";
	}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 177 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		scopenumber++;
		char tmp[50]="";
		gencode_function(".method public static");
		if(strcmp(remember_function_name,"main"))
			sprintf(tmp," %s(%s)%s\n",remember_function_name,funcparameterout(remember_function_name),remember_function_type);
		else
			sprintf(tmp," %s(%s)%s\n",remember_function_name,"[Ljava/lang/String;",remember_function_type);
		gencode_function(tmp);
		gencode_function(".limit stack 50\n. limit locals 50\n");
		}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 190 "compiler_hw3.y" /* yacc.c:1646  */
    {dump_number=scopenumber;scopenumber--;gencode_function(".end method\n");}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 194 "compiler_hw3.y" /* yacc.c:1646  */
    {
		insert_symbol((yyvsp[0].string),"parameter",(yyvsp[-1].string),scopenumber+1,0);
		insert_attribute((yyvsp[-1].string),attribute_count);
		/*check_symbol();*/
		}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 199 "compiler_hw3.y" /* yacc.c:1646  */
    {
		insert_symbol((yyvsp[0].string),"parameter",(yyvsp[-1].string),scopenumber+1,0);
		insert_attribute((yyvsp[-1].string),attribute_count);
		/*check_symbol();*/


		}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "compiler_hw3.y" /* yacc.c:1646  */
    {
		redeclare_test((yyvsp[-1].string),"variable");
		insert_symbol((yyvsp[-1].string),"variable",(yyvsp[-2].string),scopenumber,0);
		if(scopenumber==0)
			generate_variable_code((yyvsp[-2].string),(yyvsp[-1].string));
		else if(scopenumber>0)
			generate_local((yyvsp[-2].string),(yyvsp[-1].string));
		//printf("init\n");
		}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 234 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[-2].string);declarate_has_init=1;}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 235 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 244 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 245 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("%s=%s",(yyvsp[-2].string),(yyvsp[0].string));
		Symbol_Table * seeall;
		char tmp[20];
		for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
		{
			if(strcmp(seeall->name,(yyvsp[-2].string))==0)
				break;
		}
		if(!strcmp(seeall->data_type,"int"))
		{
			sprintf(tmp,"istore %d\n",seeall->index);
		}
		if(!strcmp(seeall->data_type,"float"))
		{
			sprintf(tmp,"fstore %d\n",seeall->index);
		}
		if(!strcmp(seeall->data_type,"string"))
		{
			sprintf(tmp,"astore %d\n",seeall->index);
		}
		gencode_function(tmp);
	}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 271 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is =\n");}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 272 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is +=\n");}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 273 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is -=\n");}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 274 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is *=\n");}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 275 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is /=\n");}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 276 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is %%=\n");}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 280 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 281 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 282 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 283 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="";}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 287 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 288 "compiler_hw3.y" /* yacc.c:1646  */
    {
		undeclare_test((yyvsp[-2].string),"function");
		printf("%sNO input function\n",(yyvsp[-2].string));
		}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 292 "compiler_hw3.y" /* yacc.c:1646  */
    {
		undeclare_test((yyvsp[-3].string),"function");
		printf("%shas input function\n",(yyvsp[-3].string));

		}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 302 "compiler_hw3.y" /* yacc.c:1646  */
    {undeclare_test((yyvsp[0].string),"variable");/*printf("%s v\n",$1);*/}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 303 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);/*printf("constant\n");*/}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 304 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="";}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 313 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.string)="I_CONST";
		printf("I:%d\n",(yyvsp[0].i_val));
		intconstant=(yyvsp[0].i_val);
		constantflag=1;
		heapipush((yyvsp[0].i_val));
		if(scopenumber>0)
		{
			printf("ldc %d\n",(yyvsp[0].i_val));
			//gencode_function("ldc ");
		}
		}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 325 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.string)="F_CONST";
		printf("F:%f\n",(float)(yyvsp[0].f_val));
		floatconstant=(yyvsp[0].f_val);
		constantflag=2;
		heapfpush((yyvsp[0].f_val));
		if(scopenumber>0)
		{
			printf("ldc %f\n",(yyvsp[0].f_val));
			//gencode_function("ldc ");
		}
		}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 337 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.string)="STRING_CONST";
		if(scopenumber>0)
		{
			printf("ldc %s\n",(yyvsp[0].string));
			//gencode_function("ldc ");
		}
	}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 345 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="boolean";}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 361 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="";}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 371 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="";}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 375 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 380 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 386 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 394 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 395 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char tmp[20];
		printf("now is %s+%s\n",(yyvsp[-2].string),(yyvsp[0].string));
		if(!strcmp((yyvsp[-2].string),"I_CONST"))
		{
			sprintf(tmp,"ldc %d\n",yylval.i_val);
			gencode_function(tmp);
		}
		else if(!strcmp((yyvsp[-2].string),"F_CONST"))
		{
			sprintf(tmp,"ldc %f\n",yylval.f_val);
			gencode_function(tmp);
		}
		else
		{
			Symbol_Table * seeall;
			char tmp[20];
			for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
			{
				if(strcmp(seeall->name,(yyvsp[-2].string))==0)
					break;
			}
			if(!strcmp(seeall->data_type,"int"))
			{
				sprintf(tmp,"iload %d\n",seeall->index);
			}
			if(!strcmp(seeall->data_type,"float"))
			{
				sprintf(tmp,"fload %d\n",seeall->index);
			}
			gencode_function(tmp);

		}
		if(!strcmp((yyvsp[0].string),"I_CONST"))
		{
			sprintf(tmp,"ldc %d\n",yylval.i_val);
			gencode_function(tmp);
		}
		else if(!strcmp((yyvsp[0].string),"F_CONST"))
		{
			sprintf(tmp,"ldc %f\n",yylval.f_val);
			gencode_function(tmp);
		}
		else
		{
			Symbol_Table * seeall;
			char tmp[20];
			for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
			{
				if(strcmp(seeall->name,(yyvsp[0].string))==0)
					break;
			}
			if(!strcmp(seeall->data_type,"int"))
			{
				sprintf(tmp,"iload %d\n",seeall->index);
			}
			if(!strcmp(seeall->data_type,"float"))
			{
				sprintf(tmp,"fload %d\n",seeall->index);
			}
			gencode_function(tmp);

		}
		gencode_function("iadd\n");

	}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 461 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is %s-%s\n",(yyvsp[-2].string),(yyvsp[0].string));}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 465 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 466 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is %s*%s\n",(yyvsp[-2].string),(yyvsp[0].string));}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 467 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is %s/%s\n",(yyvsp[-2].string),(yyvsp[0].string));}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 468 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is %s%% %s\n",(yyvsp[-2].string),(yyvsp[0].string));}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 493 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("ifandelse\n");}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 494 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("if\n");}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 498 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("while\n");
		gencode_function("goto LABEL_BEGIN\nLABEL_FALSE:\ngoto EXIT_0\nEXIT_0:\n");
		}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 505 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("whileexpression\n");
		gencode_function("LABEL_BEGIN:\n");
		char tmp[50];
		int choise=0;
		if(!strcmp((yyvsp[-2].string),"I_CONST"))
		{
			sprintf(tmp,"ldc %d\n",heapipop());
			gencode_function(tmp);
			choise=1;
		}
		else if(!strcmp((yyvsp[-2].string),"F_CONST"))
		{
			sprintf(tmp,"ldc %f\n",heapfpop());
			gencode_function(tmp);
		}
		else
		{
			Symbol_Table * seeall;
			for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
			{
				if(strcmp(seeall->name,(yyvsp[-2].string))==0)
					break;
			}
			if(seeall->data_type=="int")
				choise=1;
			else
				choise=2;
			sprintf(tmp,"iload %d\n",seeall->index);
			gencode_function(tmp);
		}
		if(!strcmp((yyvsp[0].string),"I_CONST"))
		{
			sprintf(tmp,"ldc %d\n",heapipop());
			gencode_function(tmp);
			choise=1;
		}
		else if(!strcmp((yyvsp[0].string),"F_CONST"))
		{
			sprintf(tmp,"ldc %f\n",heapfpop());
			gencode_function(tmp);
		}
		else
		{
			Symbol_Table * seeall;
			for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
			{
				if(strcmp(seeall->name,(yyvsp[-2].string))==0)
					break;
			}
			if(seeall->data_type=="int")
				choise=1;
			else
				choise=2;
			sprintf(tmp,"iload %d\n",seeall->index);
			gencode_function(tmp);
		}
		if(choise==1)
			gencode_function("isub\n");
		else
			gencode_function("fsub\n");
		switch ((yyvsp[-1].i_val))
		{
			case 1:
				gencode_function("ifgt LABEL_TRUE\n");
				break;
			case 2:
				gencode_function("iflt LABEL_TRUE\n");
				break;
			case 3:
				gencode_function("ifge LABEL_TRUE\n");
				break;
			case 4:
				gencode_function("ifle LABEL_TRUE\n");
				break;
			case 5:
				gencode_function("ifne LABEL_TRUE\n");
				break;
			default:
			break;
		}
		gencode_function("goto LABEL_FALSE\n");
		printf("end\n");
	}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 591 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is >\n");(yyval.i_val)=1;}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 592 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is <\n");(yyval.i_val)=2;}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 593 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is >=\n");(yyval.i_val)=3;}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 594 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("now is <=\n");(yyval.i_val)=4;}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 595 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=5;}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 599 "compiler_hw3.y" /* yacc.c:1646  */
    {gencode_function("return\n");}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 600 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(remember_function_type=="I")
			gencode_function("ireturn\n");
		if(remember_function_type=="F")
			gencode_function("freturn\n");}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 613 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("%s\n",(yyvsp[-2].string));generate_print_function((yyvsp[-2].string));}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 620 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = "int"; }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 621 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = "float"; }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 622 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = "bool"; }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 623 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = "string"; }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 624 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = "void"; }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2178 "y.tab.c" /* yacc.c:1646  */
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
#line 627 "compiler_hw3.y" /* yacc.c:1906  */




/* C code section */
int main(int argc, char** argv)
{
	memset(my_heap,0,sizeof(my_heap));
	file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
    scopenumber=0;
	attribute_count=0;
    yylineno = 0;
	semantic_happen=0;
	syntax_flag=0;
	create_symbol();
	create_attribute();
	
    yyparse();
	if(!syntax_flag)
		dump_symbol(scopenumber);
		printf("\nTotal lines: %d \n",yylineno);
	//test();
	fclose(file);
    return 0;
}

void semanticerror()
{
	printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s %s %s",semantic_message,semantic_type,semantic_name);
    printf("\n|-----------------------------------------------|\n\n");
}

void yyerror(char *s)
{
	if(semantic_happen==1)
	{
		semanticerror();
	}
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	syntax_flag=1;
}

void create_symbol() {
	my_symbol_head=(Symbol_Table*)malloc(sizeof(Symbol_Table));
	my_symbol_head->next=my_symbol_head;
	my_symbol_head->prev=my_symbol_head;
	my_symbol_head->index=-1;
	my_symbol_head->name=NULL;
	my_symbol_head->entry_type=NULL;
	my_symbol_head->data_type=NULL;
	my_symbol_head->scope_level=-1;
	my_symbol_head->attribute_number=-1;
}
void insert_symbol(char* name,char* entry_type,char* data_type,int scope_level,int attribute_number) {
	int index=0;
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		if(seeall->scope_level==scope_level)
		{
			index++;
		}
	}
	Symbol_Table* tmp=(Symbol_Table*)malloc(sizeof(Symbol_Table));
	tmp->index=index;
	tmp->name=name;
	tmp->entry_type=entry_type;
	tmp->data_type=data_type;
	tmp->scope_level=scope_level;
	tmp->attribute_number=attribute_number;


	my_symbol_head->prev->next=tmp;
	tmp->next=my_symbol_head;
	tmp->prev=my_symbol_head->prev;
	my_symbol_head->prev=tmp;
}
void check_symbol() 
{
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		printf("\n%-10d%-10s%-12s%-10s%-10d%-10d\n",seeall->index, seeall->name, seeall->entry_type, seeall->data_type, seeall->scope_level, seeall->attribute_number);
	}
	//printf("\n|-----------------------------------------------|\n");
}
int lookup_symbol(char* name,char* type) 
{
	
}
void dump_symbol(int nownumber) 
{
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n","Index", "Name", "Kind", "Type", "Scope", "Attribute");
	Symbol_Table * out;
	for(out=my_symbol_head->next;out!=my_symbol_head;out=out->next)
	{
		if(out->scope_level==nownumber)
		{
			printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",out->index,out->name,out->entry_type,out->data_type,out->scope_level,show_attribute(out->attribute_number));
			out->prev->next=out->next;
			out->next->prev=out->prev;
		}
	}
	printf("\n");
	
}

void test()
{
	insert_symbol("a","v","int",scopenumber,0);
	insert_symbol("s","v","int",scopenumber,0);
	scopenumber++;
	insert_symbol("d","v","int",scopenumber,0);
	insert_symbol("b","v","int",scopenumber,0);
	insert_symbol("x","v","int",scopenumber,0);
	check_symbol();
	dump_symbol(scopenumber);
	scopenumber--;
	check_symbol();
	scopenumber++;
	insert_symbol("cf","v","int",scopenumber,0);
	insert_symbol("q","v","int",scopenumber,0);
	insert_symbol("y","v","int",scopenumber,0);
	check_symbol();
}


void create_attribute()
{
	my_attribute_head=(Attribute_Table*)malloc(sizeof(Attribute_Table));
	my_attribute_head->number=-1;
	my_attribute_head->type=NULL;
	my_attribute_head->next=my_attribute_head;
	my_attribute_head->prev=my_attribute_head;
}
void insert_attribute(char* type,int count)
{
	Attribute_Table* tmp=(Attribute_Table*)malloc(sizeof(Attribute_Table));
	tmp->type=type;
	tmp->number=count;

	my_attribute_head->prev->next=tmp;
	tmp->next=my_attribute_head;
	tmp->prev=my_attribute_head->prev;
	my_attribute_head->prev=tmp;
}
char* show_attribute(int number)
{
	
	outbuf[0]='\0' ;
	Attribute_Table * seeall;
	if(number>0)
	{
		for(seeall=my_attribute_head->next;seeall!=my_attribute_head;seeall=seeall->next)
		{
			if(seeall->number==number)
			{
				if(outbuf[0]=='\0')
				{
					strncat(outbuf,seeall->type,strlen(seeall->type));
				}
				else
				{
					strncat(outbuf,",",1);
					strncat(outbuf,seeall->type,strlen(seeall->type));
				}
			}
		}
	}
	return outbuf;
}

void undeclare_test(char* name,char* type)
{
	int check=0;
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		if(strcmp(seeall->name,name)==0)
		{
			//printf("%sexist!!!\n",type);
			check=1;
			break;
		}
	}
	if(check==0)
	{
		//printf("%sno exist!!\n",type);
		strcpy(semantic_name,name);
		strcpy(semantic_type,type);
		strcpy(semantic_message,"Undeclared");
		semantic_happen=1;

	}
}
void redeclare_test(char* name,char* type)
{
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		if(strcmp(seeall->name,name)==0)
		{
			if(seeall->scope_level>0)
			//printf("%s %s redeclare!!!\n",name,type);
			strcpy(semantic_name,name);
			strcpy(semantic_type,type);
			strcpy(semantic_message,"Redeclared");
			semantic_happen=1;
		}
	}
}


/* homework 3 added  */

void gencode_function(char* java_code) {
    if(!syntax_flag)
		fprintf(file, "%s", java_code);  
}
void generate_variable_code(char* type,char* name)
{
	char tmp[256];
	//printf("%s %s",type,name);
	
	if(!strcmp(type, "int"))
	{
		if(declarate_has_init)
		{
			if(constantflag==1)
				sprintf(tmp,".field public static %s %s = %d\n", name, "I", intconstant);
			if(constantflag==2)
				sprintf(tmp,".field public static %s %s = %d\n", name, "I", (int)floatconstant);
		}
		else
			sprintf(tmp,".field public static %s %s = %d\n", name, "I",0);
	}
	else if(!strcmp(type, "float"))
	{
		if(declarate_has_init)
		{
			if(constantflag==1)
			sprintf(tmp,".field public static %s %s = %f\n", name, "F", (float)intconstant);
			if(constantflag==2)
			sprintf(tmp,".field public static %s %s = %f\n", name, "F", floatconstant);

		}
		else
			sprintf(tmp,".field public static %s %s = %f\n", name, "F",0);
	}
	else if(!strcmp(type, "string"))
	{
		sprintf(tmp, ".field public static %s %s = \"%s\"\n", name, "Ljava/lang/String;", yylval.string);
		
	}
	else if(!strcmp(type, "bool"))
	{
		if(declarate_has_init)
			sprintf(tmp,".field public static %s %s = %d\n", name, "B", yylval.i_val);
		else
			sprintf(tmp,".field public static %s %s = %d\n", name, "B", 0);
	}
	
	
	if(strcmp(tmp, ""))
            gencode_function(tmp);
	declarate_has_init=0;
	constantflag=0;
	heapipop();
}

void generate_local(char*type,char* name){
	char tmp[256];
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		if(strcmp(seeall->name,name)==0)
			break;
	}
	if(!strcmp(type, "int"))
	{
		if(declarate_has_init)
		{
			if(constantflag==1)
			{
				gencode_function("ldc ");
				sprintf(tmp,"%d\nistore %d\n",intconstant,seeall->index);
			}
			if(constantflag==2)
			{
				gencode_function("ldc ");
				sprintf(tmp,"%d\nistore %d\n",(int)floatconstant,seeall->index);
			}
		}
		else 
		{
			gencode_function("ldc ");
			sprintf(tmp,"%d\nistore %d\n",0,seeall->index);
		}
	}
	if(!strcmp(type, "float"))
	{
		if(declarate_has_init)
		{
			if(constantflag==1)
			{
				gencode_function("ldc ");
				sprintf(tmp,"%f\nfstore %d\n",(float)intconstant,seeall->index);
			}
			if(constantflag==2)
			{
				gencode_function("ldc ");
				sprintf(tmp,"%f\nfstore %d\n",floatconstant,seeall->index);
			}
		}
		else 
		{
			gencode_function("ldc ");
			sprintf(tmp,"%d\nfstore %d\n",0,seeall->index);
		}
	}
	if(!strcmp(type, "string"))
	{
		if(declarate_has_init)
		{
			gencode_function("ldc ");
			sprintf(tmp,"%s\nastore %d\n",yylval.string,seeall->index);
		}
	}
	if(strcmp(tmp, ""))
        gencode_function(tmp);
	declarate_has_init=0;
	constantflag=0;
	heapipop();
}

void generate_print_function(char* input){
	
	char tmp[256];
	if(!strcmp(input, "I_CONST"))
	{	
		sprintf(tmp,"ldc %d\n",(int)yylval.f_val);
		gencode_function(tmp);
		gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		
	}
	else if(!strcmp(input, "F_CONST"))
	{	
		sprintf(tmp,"ldc %f\n",yylval.f_val);
		gencode_function(tmp);
		gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(F)V\n");
		
	}
	else if(!strcmp(input, "STRING_CONST"))
	{	
		sprintf(tmp,"ldc %s\n",yylval.string);
		gencode_function(tmp);
		gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
		
	}
	else 
	{
		Symbol_Table * seeall;
		for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
		{
			if(strcmp(seeall->name,input)==0)
				break;
		}
		if(!strcmp(seeall->data_type,"int"))
		{
			sprintf(tmp,"iload %d\n",seeall->index);
			gencode_function(tmp);
			gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		}
		if(!strcmp(seeall->data_type,"float"))
		{
			sprintf(tmp,"fload %d\n",seeall->index);
			gencode_function(tmp);
			gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		}
		if(!strcmp(seeall->data_type,"string"))
		{
			sprintf(tmp,"aload %d\n",seeall->index);
			gencode_function(tmp);
			gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		}
	}
}

char* funcparameterout(char* name)
{
	Symbol_Table * seeall;
		for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
		{
			if(strcmp(seeall->name,name)==0)
				break;
		}
	parameterreturn[0]='\0';
	Attribute_Table* search;
	for (search=my_attribute_head->next;search!=my_attribute_head;search=search->next)
	{
		if(search->number==seeall->attribute_number)
		{
			if(search->type=="int")
			{
				strncat(parameterreturn,"I",1);
			}
			else if(search->type=="float")
			{
				strncat(parameterreturn,"F",1);
			}
			else if(search->type=="string")
			{
				strcat(parameterreturn,"Ljava/lang/String;");
			}
		}

	}
	//printf("%s\n",parameterreturn);
	return parameterreturn;
}


void heapipush(int input){
	int i=0;
	for(i;i<10;i++)
	{
		if(my_heap[i].flag==0)
		{
			my_heap[i].i=input;
			my_heap[i].flag=1;
			break;
		}
	}
}
void heapfpush(float input){
	int i=0;
	for(i;i<10;i++)
	{
		if(my_heap[i].flag==0)
		{
			my_heap[i].f=input;
			my_heap[i].flag=2;
			break;
		}
	}
}
int heapipop(){
	int tmp=my_heap[0].i;
	int i;
	for(i=1;i<10;i++)
	{
		my_heap[i-1].i=my_heap[i].i;
		my_heap[i-1].f=my_heap[i].f;
		my_heap[i-1].flag=my_heap[i].flag;
	}
	return tmp;
}
float heapfpop(){
	float tmp=my_heap[0].f;
	int i;
	for(i=1;i<10;i++)
	{
		my_heap[i-1].i=my_heap[i].i;
		my_heap[i-1].f=my_heap[i].f;
		my_heap[i-1].flag=my_heap[i].flag;
	}
	return tmp;
}
