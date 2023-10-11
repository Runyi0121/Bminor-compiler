#include "../inc/expr.h"

#include <stdio.h>
#include <stdlib.h>

/*
Create one node in an expression tree and return the structure.
*/

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right)
{
	/* Shortcut: sizeof(*e) means "the size of what e points to" */
	struct expr *e = malloc(sizeof(*e));
	e->kind = kind;
	e->left = left;
	e->right = right;

	return e;
}

struct expr * expr_create_value( int value )
{
	struct expr *e = expr_create(EXPR_VALUE,0,0);
	e->literal_value = value;
	return e;
}