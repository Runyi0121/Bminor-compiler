#include "../inc/decl.h"
#include <stdlib.h>

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