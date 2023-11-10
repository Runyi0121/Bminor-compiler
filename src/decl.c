#include "../inc/decl.h"
#include <stdlib.h>

extern int resolve_error;

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

void decl_resolve ( struct scope *s, struct decl *d ) {
    if (d == 0 || s == 0) return;
    symbol_t kind = scope_level(s) > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;
    
    d->symbol = symbol_create(kind, d->type, d->name);
    expr_resolve(s, d->value);
    int bind = scope_bind(s, d->name, d->symbol);
    // symbol is already in the symbol table
    if (bind == 1) {
        if (d->type->kind == TYPE_FUNCTION) {
            struct symbol *sy = scope_lookup(s, d->name);
            if (sy->defined == 0 && d->code != 0) {
                resolve_error++;
                printf("resolve error: function %s is already defined\n", d->name);
            }
        } else {
            resolve_error++;
            printf("resolve error: %s is already defined\n", d->name);
        }
    }
    d->symbol->which = s->which;
    // enter a scope
    if (d->code != 0) {
        d->code->in_func = 0;
        d->symbol->defined = 0;

        scope_enter(s);
        param_list_resolve(s->next, d->type->params);
        d->param_count = s->next->which;

        stmt_resolve(s->next, d->code);
        d->var_count = d->param_count + (s->next->which - d->param_count);
        d->local_count = d->var_count - d->param_count;

        scope_exit(s->next);
    }
    decl_resolve(s, d->next);
}