#include "../inc/stmt.h"
#include <stdlib.h>

extern int resolve_error;
extern int typecheck_error;
extern int codegen_error;
extern FILE *fp;

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next ) {
    struct stmt * s = malloc(sizeof(struct stmt));
    s->kind = kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->expr = expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;
    s->else_if = 1;
    s->indent = 1;
    s->in_func = 1;
    return s; 
}

void stmt_print( struct stmt *s, int indent ) {
    if (s == 0) return;
    switch (s->kind) {
        
        case STMT_IF_ELSE:
            if (s->else_if == 1) 
                indent_print(indent);
            printf("if (");
            expr_print(s->expr);
            printf(") ");

            if (s->body->kind == STMT_BLOCK) stmt_print(s->body, indent);
            else {
                printf("{\n");
                stmt_print(s->body, indent + 1);
                indent_print(indent);
                printf("}\n");
            }
                  
            if (s->else_body != 0) {
                indent_print(indent);
                printf("else ");
                if (s->else_body->kind == STMT_BLOCK) stmt_print(s->else_body, indent);
                else {
                    if (s->else_body->kind == STMT_IF_ELSE) stmt_print(s->else_body, indent);
                    else {
                        printf("{\n");
                        stmt_print(s->else_body, indent + 1);
                        indent_print(indent);
                        printf("}\n");
                    }
                }
            }
            stmt_print(s->next, indent);
            break;

        case STMT_FOR:
            indent_print(indent);
            printf("for ("); 
            if (s->init_expr != 0) expr_print(s->init_expr);
            printf(";");
            if (s->expr != 0) {
                printf(" ");
                expr_print(s->expr);
            }
            printf(";");
            if (s->next_expr != 0) {
                printf(" ");
                expr_print(s->next_expr);
            }
            printf(") ");
            if(s->body) {
                if (s->body->kind == STMT_BLOCK) stmt_print(s->body, indent);
                else {
                    printf("{\n");
                    stmt_print(s->body, indent + 1);
                    indent_print(indent);
                    printf("}\n");
                }
            }
            stmt_print(s->next, indent);
            break;
        case STMT_DECL:
            decl_print(s->decl, indent);
            stmt_print(s->next, indent);
            break;
        case STMT_PRINT:
            indent_print(indent);
            printf("print ");
            struct expr *t = s->expr;
            while(t) {
                expr_print(t);
                if(t->next)
                    printf(", ");
                t = t->next;
            }
            printf(";\n");
            stmt_print(s->next, indent);
            break;
        case STMT_RETURN:
            indent_print(indent);
            printf("return ");
            expr_print(s->expr);
            printf(";\n");
            stmt_print(s->next, indent);
            break;
        
        case STMT_BLOCK:
            if(s->else_if == 0 || s->indent == 0); 
            else indent_print(indent);
            printf("{\n");
            stmt_print(s->body, indent + 1);
            indent_print(indent);
            printf("}\n");
            stmt_print(s->next, indent);
            break;

    }
}

void stmt_resolve( struct scope *sco, struct stmt *stmt) {
    if (stmt == 0) return;
    int which;
    switch (stmt->kind) {

        case STMT_EXPR:
        case STMT_PRINT:
        case STMT_RETURN:
            expr_resolve(sco, stmt->expr);
            break;

        case STMT_DECL:
            decl_resolve(sco, stmt->decl);
            break;

        case STMT_IF_ELSE:
            expr_resolve(sco, stmt->expr);
            stmt_resolve(sco, stmt->body);
            stmt_resolve(sco, stmt->else_body);
            break;

        case STMT_FOR:
            expr_resolve(sco, stmt->init_expr);
            expr_resolve(sco, stmt->expr);
            expr_resolve(sco, stmt->next_expr);
            stmt_resolve(sco, stmt->body);
            break;

        case STMT_BLOCK:
            which = sco->which;
            if (stmt->in_func == 0)
                stmt_resolve(sco, stmt->body);
            else {
                scope_enter(sco);
                sco->next->which = which;
                stmt_resolve(sco->next, stmt->body);
                sco->which = sco->next->which;
                scope_exit(sco->next);
            }
            break;
    }

    stmt_resolve(sco, stmt->next);
}

struct type * stmt_typecheck(struct stmt *s, struct decl *return_type) {
    if(s == 0) 
        return 0;
    
    struct type *t;
    switch(s->kind) {
        case STMT_BLOCK:
            stmt_typecheck(s->body, return_type); 
            break;
        case STMT_EXPR:
            expr_typecheck(s->expr);
            break;    
        case STMT_RETURN:
            t = expr_typecheck(s->expr);
            if(return_type->symbol->type->subtype->kind == TYPE_AUTO) {
                if(t != 0 && t->kind == TYPE_AUTO) {
                    type_error_print(ERR_AUTO, 0, 0, 0, 0, 0, 0);
                    typecheck_error++;
                }            
                if (t != 0) 
                    return_type->symbol->type->subtype = type_copy(t);
                else 
                    return_type->symbol->type->subtype = type_create(TYPE_VOID, 0, 0);

                t->kind = return_type->symbol->type->subtype->kind;
                printf("type notice: return type of function %s is now ", return_type->name);
                type_print(return_type->symbol->type->subtype);
                printf("\n");
            }
    
            if(!(t == 0 && return_type->symbol->type->subtype->kind == TYPE_VOID) 
                     && (t == 0 || t->kind != return_type->symbol->type->subtype->kind)) {
                type_error_print(ERR_FUNC_TYPE, return_type, 0, 0, 0, 0, t);
                typecheck_error++;
            }
        
            s->func_return = return_type->name;
            return_type->returned = 0;
            break;

        case STMT_DECL:
            decl_typecheck(s->decl);
            break;
        case STMT_IF_ELSE:
            t = expr_typecheck(s->expr);
            s->expr->cond_expr = 0;
            if(t->kind != TYPE_BOOLEAN) {
                type_error_print(ERR_IF_COND, 0, s->expr, 0, 0, 0, t);
                typecheck_error++;
            }
            stmt_typecheck(s->body, return_type);
            stmt_typecheck(s->else_body, return_type);
            break;

        case STMT_PRINT:
            expr_typecheck(s->expr);
            break;

        case STMT_FOR:
            t = expr_typecheck(s->init_expr);
            t = expr_typecheck(s->expr);
            if(s->expr && t->kind != TYPE_BOOLEAN) {
                type_error_print(ERR_FOR_COND, 0, 0, 0, 0, s, t);
                typecheck_error++;
            }
            if  (s->expr != 0) 
                s->expr->cond_expr = 0;
            t = expr_typecheck(s->next_expr);
            t = stmt_typecheck(s->body, return_type);
            break;
        default:
            break;
    }

    return stmt_typecheck(s->next, return_type);
}
void stmt_codegen( struct stmt *s ) {
    if (s == 0)
        return;

    fprintf(fp, "# STMT\n");
    int l1, l2;

    switch(s->kind) {
        case STMT_DECL:
            decl_codegen(s->decl);
            break;
        case STMT_EXPR:
            expr_codegen(s->expr);
            scratch_free(s->expr->reg);
            break;
        case STMT_IF_ELSE:
            fprintf(fp, "# start of if stmt\n");
            l1 = label_create(); // else label
            l2 = label_create(); // done label

            fprintf(fp, "# condition expr\n");
            expr_codegen(s->expr);
            
            fprintf(fp, "\tcmpq $0, %s\n",scratch_name(s->expr->reg));
            fprintf(fp, "\tje %s\n",label_name(l1)); // else label

            fprintf(fp, "# if body\n");
            stmt_codegen(s->body);
            fprintf(fp, "\tjmp %s\n",label_name(l2)); //done label

            fprintf(fp, "# false label\n");
            fprintf(fp, "%s:\n", label_name(l1));

            fprintf(fp, "# else body\n");
            stmt_codegen(s->else_body);

            fprintf(fp, "%s:\n",label_name(l2)); //done label

            scratch_free(s->expr->reg);
            fprintf(fp, "# end of if stmt\n");
            break;
        case STMT_FOR:
            fprintf(fp, "# start of for loop\n");

            fprintf(fp, "# init expr\n");
            if (s->init_expr) {
                expr_codegen(s->init_expr);
                scratch_free(s->init_expr->reg);
            }

            l1 = label_create(); // top label
            l2 = label_create(); // done label
            fprintf(fp, "%s:\n", label_name(l1)); // top label

            // expr
            fprintf(fp, "# condition expr\n");
            if (s->expr) {
                expr_codegen(s->expr);
                fprintf(fp, "\tcmpq $0, %s\n", scratch_name(s->expr->reg));
                scratch_free(s->expr->reg);
                fprintf(fp, "\tje %s\n", label_name(l2)); // done label
            }

            fprintf(fp, "# loop body\n");
            stmt_codegen(s->body);

            // next expr
            fprintf(fp, "# next expr\n");
            if (s->next_expr) {
                expr_codegen(s->next_expr);
                scratch_free(s->next_expr->reg);
            }

            fprintf(fp, "\tjmp %s\n", label_name(l1));
            fprintf(fp, "%s:\n", label_name(l2));

            fprintf(fp, "# end of for loop\n");
            break;
        
        case STMT_PRINT:
            fprintf(fp, "# printing exprs\n");
            stmt_codegen_print(s);
            break;
        case STMT_RETURN:
            fprintf(fp, "# return stmt\n");
            expr_codegen(s->expr);
            fprintf(fp, "\tmovq %s, %%rax\n", scratch_name(s->expr->reg));
            fprintf(fp, "\tjmp .%s_epilogue\n", s->func_return); 
            scratch_free(s->expr->reg);
            break;
        case STMT_BLOCK:
            stmt_codegen(s->body);
            break;
    }

    stmt_codegen(s->next);
}

void stmt_codegen_print( struct stmt *s ) {
    struct expr *e = s->expr;
    struct type *t;
    while (e) {
        t = expr_typecheck(e);

        // save r10 r11, store left into rdi
        fprintf(fp, "\tpushq %%r10\n");
        fprintf(fp, "\tpushq %%r11\n");

        expr_codegen(e);
        fprintf(fp, "\tmovq %s, %%rdi\n", scratch_name(e->reg));
        switch (t->kind) {
            case TYPE_BOOLEAN:
            fprintf(fp, "\tcall print_boolean\n");
            break;
            case TYPE_STRING:
                fprintf(fp, "\tcall print_string\n");
                break;
            case TYPE_CHARACTER:
                fprintf(fp, "\tcall print_character\n");
                break;
            case TYPE_INTEGER:
                fprintf(fp, "\tcall print_integer\n");
                break;
            case TYPE_FLOAT:
                fprintf(fp, "\tcall print_float\n");
                break;
        }
        // restore r10, r11
        fprintf(fp, "\tpopq %%r11\n");
        fprintf(fp, "\tpopq %%r10\n");

        scratch_free(e->reg);
        e = e->next;
    }
}