#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"
#include "scope.h"
#include "decl.h"

struct decl;

typedef enum {
	EXPR_ASSIGN ,
	EXPR_OR ,
	EXPR_AND ,
	EXPR_LT ,
	EXPR_LE,
	EXPR_GT,
	EXPR_GE,
	EXPR_EQ ,
	EXPR_NE,
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_REMAIN ,
	EXPR_EXPON,
	EXPR_LOGICALNOT ,
	EXPR_INCREMENT ,
	EXPR_DECREMENT,
	EXPR_INT ,
	EXPR_FLOAT,
	EXPR_BOOL,
	EXPR_CHAR,
	EXPR_STRING,
	EXPR_ARRAY,
	EXPR_ARR_LITERAL,
	EXPR_GROUP,
	EXPR_IDENT,
	EXPR_ARR_DECL,
	EXPR_NEG,
	EXPR_FUNC_CALL

	/* many more kinds of exprs to add here */
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;
	struct expr *next;
	struct expr *mid;

	/* used by various leaf exprs */
	const char *name;
	int int_literal;
	float float_literal;
	int boolean_literal;
	const char * string_literal;
	const char * char_literal;
	struct symbol *symbol;
	int group;
	int cond_expr;
	struct type * type_err;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right);
struct expr * expr_create_mid (expr_t kind, const char *n, struct expr *mid );
struct expr * expr_create_decl( expr_t kind, const char *n, struct expr *mid );


struct expr * expr_create_name( const char *n );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_float_literal( float c );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_char_literal( const char *c );
struct expr * expr_create_string_literal( const char *str );

void expr_print( struct expr *e );
int compare_expr( struct expr *expr, struct expr * expr_next, int right);
void expr_resolve( struct scope *s, struct expr *e);
struct type * expr_typecheck( struct expr *e );
struct expr * expr_copy( struct expr *e );
int expr_value_compare( struct expr *e1, struct expr *e2 );

#endif
