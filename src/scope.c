#include "../inc/scope.h"
#include "../inc/hash_table.h"
#include <stdlib.h>

struct scope *scope_create( int level, struct hash_table *hash_table, struct scope *prev, struct scope *next ) {
    struct scope *s = malloc(sizeof(struct scope));
    s->level = level;
    s->hash_table = hash_table;
    s->prev = prev;
    s->next = next;
    s->which = 0;
    return s;
}

// push new scope
struct scope * scope_enter( struct scope *s ) {

    struct hash_table *h = hash_table_create(0, 0);
    struct scope *new_scope = scope_create(s->level + 1, h, s, 0);
    s->next = new_scope;
    return new_scope;
}

struct scope * scope_exit( struct scope *s ) {
    struct scope *head = s->next;
    hash_table_delete(s->hash_table);
    //free(s);
    return head;
}

// count scopes
int scope_level( struct scope *s ) {
    return s->level;

}

// write in scope
int scope_bind( struct scope *s, const char *name, struct symbol *sym ) {
    int bind = hash_table_insert(s->hash_table, name, sym);
    if (bind == 1) {
        //printf("%d\n", s->which);
        s->which++;
        return 0;
    }
    return 1;
}

// lookup in scopes in precedence
struct symbol *scope_lookup( struct scope *s, const char *name ) {
    if (s == 0) return 0;
    if (!name) return 0;
    if (s->hash_table && name){
        struct symbol *sym = hash_table_lookup(s->hash_table, name);
        if (sym == 0)
            sym = scope_lookup(s->prev, name);
            return sym;
    }
}

// search the current scope
struct symbol *scope_lookup_current( struct scope *s, const char *name ) {
    if (!s) return 0;
    struct symbol *sym = hash_table_lookup(s->hash_table, name);
    return sym;
}

