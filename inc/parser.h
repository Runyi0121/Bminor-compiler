/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 75 "src/parser.bison" /* yacc.c:1909  */

    struct decl *decl;
    struct expr *expr;
    struct stmt *stmt;
    struct symbol *symbol;
    struct type *type;
    struct param_list *param_list;
    char *name;

#line 123 "inc/parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_PARSER_H_INCLUDED  */
