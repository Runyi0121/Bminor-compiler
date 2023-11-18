#include "../inc/decl.h"
#include <stdlib.h>
#include <string.h>


extern int resolve_error;
extern int typecheck_error;

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ){
    struct decl *dec = malloc(sizeof(struct decl));
    dec -> name = name;
    dec -> type = type;
    dec -> value = value;
    dec -> code = code;
    dec -> symbol = 0;
    dec -> next = next;
    return dec;
}

void decl_print( struct decl *d, int indent ){
    if (d == 0) return;
    indent_print(indent);
    printf("%s:", d->name);
    type_print(d->type);
    if (d->value) {
        printf (" = ");
        if (d -> value -> kind == EXPR_ARR_DECL) {
            printf("{");
        }
        expr_print(d ->value);
        if (d -> value -> kind == EXPR_ARR_DECL) {
            printf("}");
        }
        printf(";\n");
    } 
    else if (d -> code) {
        printf (" = ");
        stmt_print(d ->code, indent);
    } 
    else {
        printf(";\n");  
    }
    if (d -> next){
        decl_print( d->next , 0);
    }
}

void indent_print( int indent) {
    for (int i = 0; i < indent; i++) {
        printf( "\t");
    }
}

void decl_resolve ( struct scope * s, struct decl *d ) {
    if (d == 0) return;
    if (s == 0) return;
    symbol_t kind = scope_level(s) ? SYMBOL_LOCAL : SYMBOL_GLOBAL;
    
    d->symbol = symbol_create(kind, d->type, d->name);
    
    // resolve expression
    expr_resolve(s, d->value);
    int bind = scope_bind(s, d->name, d->symbol);

    // symbol is already in the symbol table
    if (bind == 1)
        resolve_error++;
    d->symbol->which = s->which;
    // enter a scope
    // resolve parameters and code
    if (d->code != 0) {
        s = scope_enter(s);
        param_list_resolve(s, d->type->params);
        d->param_count = s->which;

        stmt_resolve(s, d->code->body);
        d->var_count = d->param_count + (s->which - d->param_count);
        d->local_count = d->var_count - d->param_count;

        s = scope_exit(s);
    }
    decl_resolve(s, d->next);
}


void decl_typecheck ( struct decl *d ) {
    if (d == 0)
        return;

    struct type *t, *l;

    if (d->value != 0) {
        if (d->symbol->kind == SYMBOL_GLOBAL) {
            switch (d->value->kind) {
                case EXPR_INT:
                case EXPR_FLOAT:
                case EXPR_STRING:
                case EXPR_CHAR:
                case EXPR_BOOL:
                case EXPR_ARR_DECL:
                case EXPR_ARR_LITERAL:
                    break;
                default:
                    /*printf("type error: cannot declare non-literal value in global scope\n");
                    decl_print(d, 1);*/
                    type_error_print(ERR_CONST, d, 0, 0, 0, 0, 0);
                    typecheck_error++;

            }
        }

        // check if array being declared with a positive integer length
        if (d->value->kind == EXPR_ARR_LITERAL) {
            d->symbol->type->arr_expr = expr_copy(d->type->arr_expr);
            struct type *literal = type_convert_arr_literal(d->value);
            if (literal != 0) {
                t = d->symbol->type;
                l = literal;
                // check for subtype
                while(t->subtype && l->subtype) {
                    if(t->subtype->kind == TYPE_AUTO) {
                        t->subtype = type_copy(l->subtype);
                        printf("type notice: type of %s is now ", d->name);
                        type_print(d->symbol->type);
                        printf("\n");
                        return;
                    }
                    t = t->subtype;
                    l = l->subtype;
                }

                d->value->type_err = type_copy(literal);

                if(type_equals(d->symbol->type, literal) == 1) {
                    type_error_print(ERR_DECL_VAL, d, 0, 0, 0, 0, 0);
                    typecheck_error++;
                }
            }
        }
        else {
            t = expr_typecheck(d->value);
            if(d->symbol->type->kind == TYPE_AUTO) {
                if(t->kind == TYPE_AUTO) {
                    type_error_print(ERR_AUTO, d, 0, 0, 0, 0, 0);
                    typecheck_error++;
                }

                d->symbol->type = type_copy(t);
                printf("type notice: type of %s is now ", d->name);
                type_print(t); 
                printf("\n");
            }

            d->value->type_err = type_copy(t);

            if (d->symbol->type->kind == TYPE_AUTO) {
                if(t->kind == TYPE_AUTO) {
                    /*printf("type error: cannot infer auto\n");
                    decl_print(d, 1);*/
                    type_error_print(ERR_AUTO, d, 0, 0, 0, 0, 0);
                    typecheck_error++;
                }
                d->symbol->type = type_copy(t);
                printf("type notice: type of %s is now ", d->name);
                type_print(d->symbol->type);
                printf("\n");
            }

            if(t->kind != d->symbol->type->kind) {
                type_error_print(ERR_DECL_VAL, d, 0, 0, 0, 0, 0);
                typecheck_error++;
            }
        }
        
    }
    
    if(d->type->kind == TYPE_VOID && d->code == 0) {
        //printf("type error: cannot declare void type\n");
        type_error_print(ERR_VOID, 0, d->value, 0, 0, 0, 0);
        typecheck_error++;
    }

    if(d->code != 0) {
        stmt_typecheck(d->code, d);

        // change return type of function if auto
        if(d->symbol->type->subtype->kind == TYPE_AUTO) {
            d->symbol->type->subtype = type_create(TYPE_VOID, 0, 0);
            printf("type notice: return type of function %s is now ", d->name);
            type_print(d->symbol->type->subtype);
            printf("\n");
        }
    }

    // check for a return if non-void
    if(d->symbol->type->kind == TYPE_FUNCTION 
        && d->symbol->type->subtype->kind != TYPE_VOID 
        && d->returned == 1
        && d->code
        && strcmp(d->name, "main")) {

        //printf("type error: non-void function %s missing return value\n", d->name);
        type_error_print(ERR_NO_RETURN, d, 0, 0, 0, 0, 0);        
        typecheck_error++;
    }
 
    // check next
    decl_typecheck(d->next);

    return;
}
