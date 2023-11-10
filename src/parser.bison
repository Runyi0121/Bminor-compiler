%token TOKEN_EOF 0
%token TOKEN_CCOMMENT
%token TOKEN_CPLUSCOMMENT
%token TOKEN_ARRAY
%token TOKEN_AUTO
%token TOKEN_BOOLEAN
%token TOKEN_CHAR
%token TOKEN_ELSE
%token TOKEN_FALSE
%token TOKEN_FLOAT
%token TOKEN_FOR
%token TOKEN_FUNCTION
%token TOKEN_IF
%token TOKEN_INTEGER
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_STRING
%token TOKEN_TRUE
%token TOKEN_VOID
%token TOKEN_WHILE
%token TOKEN_SPECIALCHAR
%token TOKEN_ADD
%token TOKEN_SUBTRACT
%token TOKEN_INCREMENT
%token TOKEN_DECREMENT
%token TOKEN_FRONTPARENTHESE
%token TOKEN_BACKPARENTHESE
%token TOKEN_FRONTSQUAREBRACKET
%token TOKEN_BACKSQUAREBRACKET
%token TOKEN_FRONTCURLYBRACKET
%token TOKEN_BACKCURLYBRACKET
%token TOKEN_NEGATIVE
%token TOKEN_LOGICALNOT
%token TOKEN_EXPONENTIAL
%token TOKEN_MULTIPLY
%token TOKEN_DIVIDE
%token TOKEN_REMAIN
%token TOKEN_LESSTHAN
%token TOKEN_LESSEQUAL
%token TOKEN_GREATERTHAN
%token TOKEN_GREATEREQUAL
%token TOKEN_EQUAL
%token TOKEN_NOTEQUAL
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_ASSIGN
%token TOKEN_COLON
%token TOKEN_SEMICOLON
%token TOKEN_COMMA
%token TOKEN_PERCENT
%token TOKEN_TYPE_CHAR
%token TOKEN_TYPE_INT
%token TOKEN_TYPE_FLOAT
%token TOKEN_TYPE_IDENT
%token TOKEN_TYPE_STRING
%token TOKEN_ERROR


%{
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
%}

%union {
    struct decl *decl;
    struct expr *expr;
    struct stmt *stmt;
    struct symbol *symbol;
    struct type *type;
    struct param_list *param_list;
    char *name;
};

%type <decl> program decl_list decl
%type <expr> optional_stmt expr_list expr expr_or expr_and expr_comp expr_arith1 expr_arith2 expr_expo expr_not expr_crement expr_group expr_base others array_content
%type <stmt> stmt_array stmt_list stmt stmt_recursive stmt_closed stmt_base
%type <type> type
%type <param_list> arg_lists arg_list arg
%type <name> ident

%%

program : decl_list TOKEN_EOF 
	{ $$ = $1; parser_result = $$; }
	;

decl_list: decl decl_list
	{ $1 -> next = $2; $$ = $1; }
	| 
	{ $$ = 0; }
	;

decl: ident TOKEN_COLON type TOKEN_SEMICOLON
	{ $$ = decl_create($1, $3, 0, 0, 0);}
	| ident TOKEN_COLON type TOKEN_ASSIGN expr_list TOKEN_SEMICOLON
	{ $$ = decl_create($1, $3, $5, 0, 0);}
	| ident TOKEN_COLON type TOKEN_ASSIGN TOKEN_FRONTCURLYBRACKET stmt_array TOKEN_BACKCURLYBRACKET
	{ $$ = decl_create($1, $3, 0, stmt_create(STMT_BLOCK, 0, 0, 0, 0, $6, 0, 0), 0); }
	| ident TOKEN_COLON type TOKEN_ASSIGN TOKEN_FRONTCURLYBRACKET array_content TOKEN_BACKCURLYBRACKET TOKEN_SEMICOLON
	{ $$ = decl_create($1, $3, $6 , 0, 0);  }
	;

stmt_array: stmt_list
	{ $$ = $1; }
	|
	{ $$ = 0;}
	;

array_content: expr TOKEN_COMMA array_content 
	{$$ = expr_create_decl(EXPR_ARR_DECL, $1); $1 -> next = $3; }
	| expr_base
	{ $$ = $1;}
	;

ident: TOKEN_TYPE_IDENT
	{$$ = strdup(yytext); }

type: TOKEN_INTEGER
	{ $$ = type_create(TYPE_INTEGER, 0, 0); }
	| TOKEN_BOOLEAN
	{ $$ = type_create(TYPE_BOOLEAN, 0, 0);}
	| TOKEN_ARRAY TOKEN_FRONTSQUAREBRACKET optional_stmt TOKEN_BACKSQUAREBRACKET type
	{ $$ = type_create(TYPE_ARRAY, $5, 0); $$ -> arr_expr = $3;}
	| TOKEN_CHAR
	{ $$ = type_create(TYPE_CHARACTER, 0, 0);}
	| TOKEN_FLOAT
	{ $$ = type_create(TYPE_FLOAT, 0, 0);}
	| TOKEN_STRING
	{ $$ = type_create(TYPE_STRING, 0, 0);}
	| TOKEN_VOID
	{ $$ = type_create(TYPE_VOID, 0, 0);}
	| TOKEN_AUTO
	{ $$ = type_create(TYPE_AUTO, 0, 0);}
	| TOKEN_FUNCTION type TOKEN_FRONTPARENTHESE arg_lists TOKEN_BACKPARENTHESE
	{ $$ = type_create(TYPE_FUNCTION, $2, $4);}

arg_lists: arg_list
	{ $$ = $1; }
	|
	{ $$ = 0;}
	;

arg_list: arg TOKEN_COMMA arg_list
	{ $1 ->next = $3; $$ = $1;}
	| arg
	{$$ = $1;}
	;

arg: ident TOKEN_COLON type
	{ $$ = param_list_create( $1, $3, 0); }
	;

stmt_list: stmt stmt_list
	{ $1 -> next = $2; $$ = $1; }
	| stmt
	{ $$ = $1; }
	;

stmt: stmt_recursive
	{ $$ = $1; }
	| stmt_closed
	{ $$ = $1; }
	;

stmt_recursive: TOKEN_FOR TOKEN_FRONTPARENTHESE optional_stmt TOKEN_SEMICOLON optional_stmt TOKEN_SEMICOLON optional_stmt TOKEN_BACKPARENTHESE stmt_recursive
	{ $9 -> indent = 0; $$ = stmt_create( STMT_FOR, 0, $3, $5, $7, $9, 0, 0);}
	| TOKEN_IF TOKEN_FRONTPARENTHESE expr TOKEN_BACKPARENTHESE stmt_closed TOKEN_ELSE stmt_recursive
	{ $5 -> indent = 0; $7 -> else_if = 0; $$ = stmt_create( STMT_IF_ELSE, 0, 0, $3, 0, $5, $7, 0);}
	| TOKEN_IF TOKEN_FRONTPARENTHESE expr TOKEN_BACKPARENTHESE stmt
	{ $5 -> indent = 0; $$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, 0, 0);}
	;

stmt_closed: TOKEN_FOR TOKEN_FRONTPARENTHESE optional_stmt TOKEN_SEMICOLON optional_stmt TOKEN_SEMICOLON optional_stmt TOKEN_BACKPARENTHESE stmt_closed
	{ $9 -> indent = 0; $$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0 ,0); }
	| TOKEN_IF TOKEN_FRONTPARENTHESE expr TOKEN_BACKPARENTHESE stmt_closed TOKEN_ELSE stmt_closed 
	{ $5 -> indent = 0; $7 -> else_if = 0; $$ = stmt_create( STMT_IF_ELSE, 0, 0, $3, 0, $5, $7, 0); }
	| stmt_base
	{ $$ = $1; }
	;


stmt_base: expr TOKEN_SEMICOLON
	{ $$ = stmt_create( STMT_EXPR, 0, 0, $1, 0, 0, 0, 0); }
	| TOKEN_RETURN expr TOKEN_SEMICOLON
	{ $$ = stmt_create( STMT_RETURN, 0, 0, $2, 0, 0, 0, 0);}
	| TOKEN_PRINT expr_list TOKEN_SEMICOLON
	{ $$ = stmt_create( STMT_PRINT, 0, 0, $2, 0, 0, 0, 0);}
	| TOKEN_FRONTCURLYBRACKET stmt_list TOKEN_BACKCURLYBRACKET
	{ $$ = stmt_create( STMT_BLOCK, 0, 0, 0, 0, $2, 0, 0);}
	| decl
	{ $$ = stmt_create( STMT_DECL, $1, 0, 0, 0, 0, 0, 0); }
	;

optional_stmt: expr
	{ $$ = $1; }
	|
	{ $$ = 0; }
	;

expr_list: expr TOKEN_COMMA expr_list
	{ $1 -> next = $3; $$ = $1; }
	| expr
	{ $$ = $1; }
	;

expr: expr TOKEN_ASSIGN expr_or
	{ $$ = expr_create (EXPR_ASSIGN, $1, $3); }
	| expr_or
	{ $$ = $1; }
	;

expr_or	: expr_or TOKEN_OR expr_and 
	{ $$ = expr_create(EXPR_OR, $1, $3); }
	| expr_and 
	{ $$ = $1; }
	;

expr_and : expr_and TOKEN_AND expr_comp
	{ $$ = expr_create(EXPR_AND, $1, $3); }
	| expr_comp
	{ $$ = $1; }
	;

expr_comp :  expr_comp TOKEN_LESSTHAN expr_arith1
	{ $$ = expr_create(EXPR_LT,$1,$3); }
	| expr_comp TOKEN_LESSEQUAL expr_arith1
	{ $$ = expr_create(EXPR_LE,$1,$3); }
	| expr_comp TOKEN_GREATERTHAN expr_arith1
	{ $$ = expr_create(EXPR_GT,$1,$3); }
	| expr_comp TOKEN_GREATEREQUAL expr_arith1
	{ $$ = expr_create(EXPR_GE,$1,$3); }
	| expr_comp TOKEN_EQUAL expr_arith1
	{ $$ = expr_create(EXPR_EQ,$1,$3); }
	| expr_comp TOKEN_NOTEQUAL expr_arith1
	{ $$ = expr_create(EXPR_NE,$1,$3); }
	| expr_arith1
	{ $$ = $1; } 
	;

expr_arith1: expr_arith1 TOKEN_ADD expr_arith2
	{ $$ = expr_create(EXPR_ADD,$1,$3); }
	| expr_arith1 TOKEN_SUBTRACT expr_arith2
	{ $$ = expr_create(EXPR_SUB,$1,$3); }
	| expr_arith2
	{ $$ = $1; }
	;

expr_arith2: expr_arith2 TOKEN_MULTIPLY expr_expo
	{ $$ = expr_create(EXPR_MUL,$1,$3); }
	| expr_arith2 TOKEN_DIVIDE expr_expo
	{ $$ = expr_create(EXPR_DIV, $1, $3); if ($3 == 0) {printf("cannot divide by zero!\n");} }
	| expr_arith2 TOKEN_REMAIN expr_expo
	{ $$ = expr_create(EXPR_REMAIN,$1,$3); }
	| expr_expo
	{ $$ = $1; } 
	;

expr_expo: expr_expo TOKEN_EXPONENTIAL expr_not
	{ $$ = expr_create(EXPR_EXPON, $1, $3); }
	| expr_not
	{ $$ = $1; } 
	;

expr_not: TOKEN_SUBTRACT expr_not
	{ $$ = expr_create(EXPR_SUB, 0, $2); }
	| TOKEN_LOGICALNOT expr_not
	{ $$ = expr_create(EXPR_LOGICALNOT, 0, $2); }
	| expr_crement
	{ $$ = $1; }
	;

expr_crement: expr_crement TOKEN_INCREMENT
	{ $$ = expr_create(EXPR_INCREMENT, $1, 0); }
	| expr_crement TOKEN_DECREMENT
	{ $$ = expr_create(EXPR_DECREMENT, $1, 0); }
	| expr_group
	{ $$ = $1; }
	;

expr_group: TOKEN_FRONTPARENTHESE expr TOKEN_BACKPARENTHESE
	{ $2 -> group = 1; $$ = $2; }
	| expr_base
	{ $$ = $1; }
	;

expr_base: TOKEN_TYPE_CHAR
	{ $$ = expr_create_char_literal(strdup(yytext));}
	| TOKEN_TYPE_INT
	{ $$ = expr_create_integer_literal(atoi(yytext));}
	| TOKEN_TRUE
	{ $$ = expr_create_boolean_literal(0);}
	| TOKEN_FALSE
	{ $$ = expr_create_boolean_literal(1);}
	| TOKEN_TYPE_FLOAT
	{ $$ = expr_create_float_literal(atof(yytext));}
	| TOKEN_TYPE_STRING
	{ $$ = expr_create_string_literal(strdup(yytext));}
	| ident others
	{ $$  = expr_create_mid(EXPR_ARRAY, $1, $2);}
	;

others: TOKEN_FRONTSQUAREBRACKET expr TOKEN_BACKSQUAREBRACKET others
	{ $2->next = $4; $$ = $2; }
	| TOKEN_FRONTPARENTHESE expr_list TOKEN_BACKPARENTHESE
	{ $$ = $2; }
	| 
	{ $$ = 0; }
	;	
%%

int yyerror(char* str) {
    printf("parse error: %s\n", str);
    return 1;
}