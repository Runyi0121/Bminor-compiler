#include "../inc/expr.h"
#include "../inc/scope.h"
#include <stdlib.h>
extern int resolve_error;
extern int typecheck_error;

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ) {
    struct expr* e = malloc(sizeof(struct expr));
    if (!e)
        return NULL;

    e->kind = kind;
    e->left = left;
    e->right = right;
    return e;
}


struct expr * expr_create_mid( expr_t kind, const char *n, struct expr *mid ) {
    struct expr* e = expr_create(kind, 0, 0);
    e->mid = mid;
    if (n)
        e->name = n;
    return e;
}


struct expr * expr_create_decl( expr_t kind, const char *n, struct expr *mid ) {
    struct expr* e = expr_create(kind, 0,  0);
    e->mid = mid;
    e->name = n;
    return e;
}

struct expr * expr_create_name( const char *n ) {
    struct expr* e = expr_create(EXPR_IDENT, 0, 0);
    e->name = n; 
    return e;
}

struct expr * expr_create_integer_literal( int c ) {
    struct expr* e = expr_create(EXPR_INT, 0, 0);
    e->int_literal = c;
}

struct expr * expr_create_float_literal( float c ) {
    struct expr* e = expr_create(EXPR_FLOAT, 0, 0);
    e->float_literal = c;
}

struct expr * expr_create_boolean_literal( int c ) {
    struct expr* e = expr_create(EXPR_BOOL, 0, 0);
    e->boolean_literal = c;
}

struct expr * expr_create_char_literal( const char *c ) {
    struct expr* e = expr_create(EXPR_CHAR, 0, 0);
    e->char_literal = c;
    return e;
}

struct expr * expr_create_string_literal( const char *str ) {
    struct expr* e = expr_create(EXPR_STRING, 0, 0);
    e->string_literal = str;
    return e;
}

void expr_print( struct expr *e ) {
    if (e == 0) return;
    if(e->left != 0) {
        if(compare_expr(e, e->left, 1) == 0) {
            printf("(");
            expr_print(e->left);
            printf(")");
        } else expr_print(e->left);
    }
    struct expr *t = 0;
    switch (e->kind) {
        case EXPR_ASSIGN:
            printf(" = ");
            break;
        case EXPR_AND:
            printf(" && ");
            break;
        case EXPR_OR:
            printf(" || ");
            break;
        case EXPR_EQ:
            printf(" == ");
            break;
        case EXPR_LE:
            printf(" <= ");
            break;
        case EXPR_GE:
            printf(" >= ");
            break;
        case EXPR_LT:
            printf(" < ");
            break;
        case EXPR_GT:
            printf(" > ");
            break;
        case EXPR_NE:
            printf(" != ");
            break;
        case EXPR_LOGICALNOT:
            printf(" ! ");
            break;
        case EXPR_INCREMENT:
            printf("++");
            break;
        case EXPR_DECREMENT:
            printf("--");
            break;
        case EXPR_ADD:
            printf(" + ");
            break;
        case EXPR_SUB:
            printf(" - ");
            break;
        case EXPR_MUL:
            printf(" * ");
            break;
        case EXPR_REMAIN:
            printf(" %% " );
            break;
        case EXPR_EXPON:
            printf(" ^ ");
            break;
        case EXPR_DIV:
            printf(" / ");
            break;
        case EXPR_INT:
            printf("%d", e->int_literal);
            break;
        case EXPR_FLOAT:
            printf("%f", e->float_literal);
            break;
        case EXPR_BOOL:
            if (e->boolean_literal == 0)   
                printf("true");
            else printf("false");
            break;
        case EXPR_CHAR:
            printf("%s", e->char_literal);
            break;
        case EXPR_STRING:
            printf("%s", e->string_literal);
            break;
        /*
        case EXPR_FUNC_CALL:
            printf("%s(", e->name);
            t = e->mid;
            while(t != 0) {
                expr_print(t);
                if(t->next)
                    printf(", ");
                t = t->next;
            }
            printf(")");
            break;
        */
        case EXPR_ARRAY:
            printf("%s", e->name);
            if (e->mid != 0) {
                printf("[");
                expr_print(e->mid);
                t = e->mid->next;
                while (t) {
                    expr_print(t);
                    t = t->next;
                }
                printf("]");
            }
            break;
        case EXPR_ARR_LITERAL:
            if (e->mid != 0) {
                printf("{");
                expr_print(e->mid);
                t = e->mid->next;
                while(t) {
                    printf(", ");
                    expr_print(t);
                    t = t->next;
                };
                printf("}");
            }
            break;
        case EXPR_ARR_DECL:
            if (e->mid != 0) {
                expr_print(e->mid);
                t = e->mid->next;
                while(t) {
                    printf(", ");
                    expr_print(t);
                    t = t->next;
                };
            }
            break;
        case EXPR_GROUP:
            expr_print(e->mid);
            break;
        case EXPR_IDENT:
            printf("%s", e->name);
            break;
    }
    if(e->right != 0) {
        if(compare_expr(e, e->right, 0) == 0) {
            printf("(");
            expr_print(e->right);
            printf(")");
        } else expr_print(e->right);
    }
}

int compare_expr( struct expr *expr, struct expr *expr_next, int right ) {
    if(expr_next->kind == EXPR_ASSIGN || expr_next->kind == EXPR_EXPON)
        right = !right;
    if(expr_next->kind > expr->kind) return 1;
    if(expr_next->kind == expr->kind) {
        if (expr_next->group && right == 0) return 0;
        else return 1;
    }
    else return 0;
}

void expr_resolve( struct scope *s, struct expr *e) {
    if (e == 0) return;
    if(e->kind == EXPR_IDENT || e->kind == EXPR_FUNC_CALL || e->kind == EXPR_ARRAY) {
        e->symbol = scope_lookup(s, e->name);
        if (e->symbol == 0) {
            resolve_error++;
            printf("resolve error: %s is not defined\n", e->name);
        } else symbol_print(e->symbol);
    } 
    
    expr_resolve(s, e->left);
    expr_resolve(s, e->mid);
    expr_resolve(s, e->right);
    expr_resolve(s, e->next);
}

struct type * expr_typecheck( struct expr *e ) {
    if (e == 0)
        return 0;

    struct type *lt = expr_typecheck(e->left);
    if(e->left) e->left->type_err = type_copy(lt);

    struct type *mt;
    struct type *rt = expr_typecheck(e->right);
    if(e->right) e->right->type_err = type_copy(rt);

    struct type *t;

    switch (e->kind) {
        case EXPR_INT:
            t = type_create(TYPE_INTEGER, 0, 0);
            break;
        case EXPR_FLOAT:
            t = type_create(TYPE_FLOAT, 0, 0);
            break;
        case EXPR_BOOL:
            t = type_create(TYPE_BOOLEAN, 0, 0);
            break;
        case EXPR_IDENT:
            t = type_copy(e->symbol->type);
            break;
        case EXPR_CHAR:
            t = type_create(TYPE_CHARACTER, 0, 0);
            break;
        case EXPR_STRING:
            t = type_create(TYPE_STRING, 0, 0);
            break;
        case EXPR_INCREMENT:
            if(lt->kind != TYPE_INTEGER && e->left->kind != EXPR_IDENT && e->left->kind != EXPR_ARRAY) {
                type_error_print(ERR_DEC, 0, e, 0, 0, 0, 0);
                typecheck_error++;
            }  
            t = type_copy(lt);
            break;
        case EXPR_DECREMENT:
            if(lt->kind != TYPE_INTEGER && e->left->kind != EXPR_IDENT && e->left->kind != EXPR_ARRAY) {
                type_error_print(ERR_DEC, 0, e, 0, 0, 0, 0);
                typecheck_error++;
            }  
            t = type_copy(lt);
            break;
        case EXPR_NEG:
            if(rt->kind != TYPE_INTEGER) {
                type_error_print(ERR_NEG, 0, e, 0, 0, 0, 0);
                typecheck_error++;
            }
            t = type_copy(rt);
            break;

        case EXPR_LOGICALNOT:
            if(rt->kind != TYPE_BOOLEAN) {
                type_error_print(ERR_NOT, 0, e, 0, 0, 0, 0);
                typecheck_error++;
            }
            t = type_copy(rt);
            break;

        // arithmetic operations
        case EXPR_EXPON:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_REMAIN:
        case EXPR_ADD:
        case EXPR_SUB:
            if(!(lt->kind == TYPE_INTEGER && rt->kind == TYPE_INTEGER && type_equals(lt, rt) == 0) &&
               !(lt->kind == TYPE_FLOAT && rt->kind == TYPE_FLOAT && type_equals(lt, rt) == 0)) {
                type_error_print(ERR_MATH, 0, e, 0, 0, 0, 0);
                typecheck_error++;
                t = type_copy(lt);
            }
            t = type_copy(lt);
            break;

        // comparison
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GT:
        case EXPR_GE:
            if(!(lt->kind == TYPE_INTEGER && rt->kind == TYPE_INTEGER && type_equals(lt, rt) == 0)){
                type_error_print(ERR_COMP, 0, e, 0, 0, 0, 0);
                typecheck_error++;
            }
                
            t = type_create(TYPE_BOOLEAN, 0, 0);
            break;

        case EXPR_EQ:
        case EXPR_NE:
            if(lt->kind != TYPE_VOID && lt->kind != TYPE_ARRAY && lt->kind != TYPE_FUNCTION && 
               rt->kind != TYPE_VOID && rt->kind != TYPE_ARRAY && rt->kind != TYPE_FUNCTION) {
                if (type_equals(lt, rt) == 1) {
                    type_error_print(ERR_COMP, 0, e, 0, 0, 0, 0);
                    typecheck_error++;
                }
            } else {
                //printf("type error: cannot compare value type of void, function, or array\n");
                type_error_print(ERR_COMP_INVALID_TYPE, 0, e, 0, 0, 0, 0);
                typecheck_error++;
            }

            t = type_create(TYPE_BOOLEAN, 0, 0);
            break;
        // logical operators
        case EXPR_OR:
        case EXPR_AND:
            if(!(lt->kind == TYPE_BOOLEAN && rt->kind == TYPE_BOOLEAN && type_equals(lt, rt) == 0)) {
                type_error_print(ERR_LOGIC, 0, e, 0, 0, 0, 0);
                typecheck_error++;
            }
            t = type_copy(lt);
            break;

        case EXPR_ASSIGN:
            if (e->left->kind != EXPR_IDENT && e->left->kind != EXPR_ARRAY) {
                type_error_print(ERR_ASSIGN_LEFT, 0, e, 0, 0, 0, 0);
                typecheck_error++;

            } else if (type_equals(lt, rt) == 0) {
                t = type_copy(lt);

            } else {
                type_error_print(ERR_ASSIGN, 0, e, 0, 0, 0, 0);
                typecheck_error++;
                t = type_copy(lt);
            }
            break;
        case EXPR_GROUP:
            t = expr_typecheck(e->mid);
            break;
        // function call
        case EXPR_FUNC_CALL: {
            struct expr *a = e->mid;
            struct param_list *p = e->symbol->type->params;
            while (p != 0) {
                if (a == 0) {
                    type_error_print(ERR_FUNC_MISSING_ARGS, 0, e, 0, e->symbol->type->params, 0, 0);
                    typecheck_error++;
                    break;
                }
                if (type_equals(expr_typecheck(a), p->type) == 1) {
                    p->err = a;
                    type_error_print(ERR_FUNC_PARAM, 0, e, 0, p, 0, 0);
                    typecheck_error++;
                }
                if (a != 0)
                    a = a->next;
                p = p->next;
            }
            if (a != 0) {
                type_error_print(ERR_FUNC_MANY_ARGS, 0, e, 0, e->symbol->type->params, 0, 0);
                typecheck_error++;
            }
            t = type_copy(e->symbol->type->subtype);
            break;
        }

        case EXPR_ARRAY: {
            struct expr *curr = e->mid;
            struct type *subtype = type_copy(e->symbol->type);
            struct type *currtype;

            while (curr) {
                if (subtype->kind != TYPE_ARRAY) {
                    type_error_print(ERR_NON_ARR, 0, e, curr, 0, 0, 0);
                    typecheck_error++;
                    break;
                }

                currtype = expr_typecheck(curr);
                curr->type_err = currtype;
                if (currtype->kind != TYPE_INTEGER) {
                    type_error_print(ERR_ARR_INDEX, 0, e, curr, 0, 0, 0);
                    typecheck_error++;
                }
                subtype = type_copy(subtype->subtype);

                if (subtype->kind == TYPE_VOID || subtype->kind == TYPE_FUNCTION) {
                    type_error_print(ERR_BAD_ARR_TYPE, 0, e, 0, 0, 0, 0);
                    typecheck_error++;
                }
                curr = curr->next;
            }

            t = subtype;
            break;
        }
        case EXPR_ARR_LITERAL:
        case EXPR_ARR_DECL:
            t = type_convert_arr_literal(e);
            break;
    }
    return t;
}

struct expr * expr_copy(struct expr *e) {
    if(e == 0) 
        return 0;

    struct expr *t = expr_create(e->kind, expr_copy(e->left), expr_copy(e->right));
    t->boolean_literal = e->boolean_literal;
    t->char_literal = e->char_literal;
    t->float_literal = e->float_literal;
    t->int_literal = e->int_literal;
    t->string_literal = e->string_literal;

    return t;
}

int expr_value_compare( struct expr *a, struct expr *b ) {
    if (!a && !b) return 0;
    if (!a || !b) return 1;

    if (a->int_literal == b->int_literal && a->float_literal == b->float_literal && a->boolean_literal == b->boolean_literal)
        return 0;
    else 
        return 1;
}