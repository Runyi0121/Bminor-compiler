#include "../inc/param_list.h"
#include "../inc/scope.h"
#include <stdlib.h>

extern int resolve_error;

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
            printf("resolve error: %s is already defined\n", p->name);
        }
        sy->which = s->which;
        t = t->next;
    }
}
