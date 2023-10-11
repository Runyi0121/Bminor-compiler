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
    TOKEN_EOF = 258,
    TOKEN_CCOMMENT = 259,
    TOKEN_CPLUSCOMMENT = 260,
    TOKEN_ARRAY = 261,
    TOKEN_AUTO = 262,
    TOKEN_BOOLEAN = 263,
    TOKEN_CHAR = 264,
    TOKEN_ELSE = 265,
    TOKEN_FALSE = 266,
    TOKEN_FLOAT = 267,
    TOKEN_FOR = 268,
    TOKEN_FUNCTION = 269,
    TOKEN_IF = 270,
    TOKEN_INTEGER = 271,
    TOKEN_PRINT = 272,
    TOKEN_RETURN = 273,
    TOKEN_STRING = 274,
    TOKEN_TRUE = 275,
    TOKEN_VOID = 276,
    TOKEN_WHILE = 277,
    TOKEN_SPECIALCHAR = 278,
    TOKEN_ADD = 279,
    TOKEN_SUBTRACT = 280,
    TOKEN_INCREMENT = 281,
    TOKEN_DECREMENT = 282,
    TOKEN_FRONTPARENTHESE = 283,
    TOKEN_BACKPARENTHESE = 284,
    TOKEN_FRONTSQUAREBRACKET = 285,
    TOKEN_BACKSQUAREBRACKET = 286,
    TOKEN_FRONTCURLYBRACKET = 287,
    TOKEN_BACKCURLYBRACKET = 288,
    TOKEN_NEGATIVE = 289,
    TOKEN_LOGICALNOT = 290,
    TOKEN_EXPONENTIAL = 291,
    TOKEN_MULTIPLY = 292,
    TOKEN_DIVIDE = 293,
    TOKEN_REMAIN = 294,
    TOKEN_LESSTHAN = 295,
    TOKEN_LESSEQUAL = 296,
    TOKEN_GREATERTHAN = 297,
    TOKEN_GREATEREQUAL = 298,
    TOKEN_EQUAL = 299,
    TOKEN_NOTEQUAL = 300,
    TOKEN_AND = 301,
    TOKEN_OR = 302,
    TOKEN_ASSIGN = 303,
    TOKEN_COLON = 304,
    TOKEN_SEMICOLON = 305,
    TOKEN_COMMA = 306,
    TOKEN_PERCENT = 307,
    TOKEN_TYPE_CHAR = 308,
    TOKEN_TYPE_INT = 309,
    TOKEN_TYPE_FLOAT = 310,
    TOKEN_TYPE_IDENT = 311,
    TOKEN_TYPE_STRING = 312,
    TOKEN_ERROR = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_PARSER_H_INCLUDED  */
