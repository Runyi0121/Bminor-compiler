#ifndef STMT_H
#define STMT_H

#include "decl.h"

struct decl;

typedef enum {
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK
} stmt_t;

struct stmt {
	stmt_t kind;
	struct decl *decl;
	struct expr *init_expr;
	struct expr *expr;
	struct expr *next_expr;
	struct stmt *body;
	struct stmt *else_body;
	struct stmt *next;
	int else_if;
	int indent;
	int in_func;
	char *func_return; 
};

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next );
void stmt_print( struct stmt *s, int indent);
void stmt_resolve( struct scope *sc, struct stmt *st);
struct type * stmt_typecheck( struct stmt *s, struct decl *return_type );
void stmt_codegen( struct stmt *s );
void stmt_codegen_print( struct stmt *s );
#endif
