#include "../inc/param_list.h"
#include "../inc/scope.h"
#include <stdlib.h>

extern int resolve_error;
extern int typecheck_error;

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ) {
    struct param_list* p = malloc(sizeof(struct param_list));
    p->name = name;
    p->type = type;
    p->next = next;
    return p;
}

void param_list_print( struct param_list *p ) {
    if (p == 0) return;
    printf("%s: ", p->name);
    type_print(p->type);
    if (p->next != 0)
        printf(", ");
    param_list_print(p->next);
}

void param_list_resolve( struct scope *s, struct param_list *p ) {
    if (p == 0) 
        return;
    struct param_list *t = p;
    while (t != 0) {
        struct symbol *sy = symbol_create(SYMBOL_PARAM, t->type, t->name);
        int bind = scope_bind(s, t->name, sy);
        if (bind == 1) {
            resolve_error++;
            printf("resolve error: %s previously defined\n", p->name);
        }
        sy->which = s->which;
        t = t->next;
    }
}

int param_equals( struct param_list *a, struct param_list *b ) {
    if (!a && !b) return 0;
    if (!a || !b) return 1;
    int err = 0;
    if(type_equals(a->type, b->type) == 1) 
        err++;
    if(param_equals(a->next, b->next) == 1) 
        err++;
    return err;
}

int param_typecheck( struct param_list *a ) {
    struct param_list *t = a;
    while (a != 0) {
        if(a->type->kind == TYPE_AUTO)
            return 0;
        a = a->next;
    } 
    return 1;
}

struct param_list * param_copy( struct param_list *a ) {
    if (a == 0)
        return 0;
    return param_list_create(a->name, a->type, param_copy(a->next));
}
