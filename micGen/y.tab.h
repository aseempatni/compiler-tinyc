/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 16 "ass4_12CS10008.y" /* yacc.c:1909  */

	int intval;
	char c;
	float floatval;

	struct sym* symp;

#line 200 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
