#include "../inc/encoder.h"
#include "../inc/parser.h"
#include "../inc/token.h"
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext; 
extern int yyparse();
extern int yydebug;

void usage(int num)
{
    switch (num){
        case 0:
            printf("Wrong!\n");
            break;
        case 1:
            printf("Could not open file.\n");
            break;
    }
}
int main (int argc, char *argv[]){
    bool check_encode = false;
    bool check_scan = false; 
    bool check_parse = false;

    if (argc == 3){
        printf("%s %s\n", argv[1], argv[2]);
        if (strcmp(argv[1], "--encode") == 0){
            check_encode = true;
        }
        else if (strcmp(argv[1], "--scan") == 0){
            check_scan = true;
        }
        else if (strcmp(argv[1], "--parse") == 0){
            check_parse = true;
        }
        else{    
            printf("Do not have the right command arguments.\n");
            return 1;
        }
    } 
    else {
        printf("Do not have enough command arguments.\n");
        return 1;
    }

    if (check_parse == true){
        char * file = argv[2];
        yyin = fopen (file, "r");
        if (! yyin){
            usage(1);
        }
        yydebug = 0;
        int y = yyparse();
        if ( y == 0 ){
                printf("Parse successful!\n");
                return 0;
        } else {
                printf("Parse failed.\n");
                return 1;
            }
    }
    else if (check_scan == true){
        char * file = argv[2];
        yyin = fopen (file, "r");
        if (! yyin){
            usage(1);
        }
        while(1) {
            int sentinel = 0;
            int t = yylex();
            switch (t){
                case TOKEN_CCOMMENT:
                    printf("%-20s %20s\n", "TOKEN_CCOMMENT", yytext);
                    break;
                case TOKEN_CPLUSCOMMENT:
                    printf("%-20s %20s", "TOKEN_CPLUSPlUSCOMMENT", yytext);
                    break;
                case TOKEN_ARRAY:
                    printf("%-20s %20s\n", "TOKEN_ARRAY", yytext);
                    break;
                case TOKEN_AUTO:
                    printf("%-20s %20s\n", "TOKEN_AUTO", yytext);
                    break;
                case TOKEN_BOOLEAN:
                    printf("%-20s %20s\n", "TOKEN_BOOLEAN", yytext);
                    break;
                case TOKEN_CHAR:
                    printf("%-20s %20s\n", "TOKEN_CHAR", yytext);
                    break;
                case TOKEN_ELSE:
                    printf("%-20s %20s\n", "TOKEN_ELSE", yytext);
                    break;
                case TOKEN_FALSE:
                    printf("%-20s %20s\n", "TOKEN_FALSE", yytext);
                    break;
                case TOKEN_FLOAT:
                    printf("%-20s %20s\n", "TOKEN_FLOAT", yytext);
                    break;
                case TOKEN_FOR:
                    printf("%-20s %20s\n", "TOKEN_FOR", yytext);
                    break;
                case TOKEN_FUNCTION:
                    printf("%-20s %20s\n", "TOKEN_FUNCTION", yytext);
                    break;
                case TOKEN_IF:
                    printf("%-20s %20s\n", "TOKEN_IF", yytext);
                    break;
                case TOKEN_INTEGER:
                    printf("%-20s %20s\n", "TOKEN_INTEGER", yytext);
                    break;
                case TOKEN_PRINT:
                    printf("%-20s %20s\n", "TOKEN_PRINT", yytext);
                    break;
                case TOKEN_RETURN:
                    printf("%-20s %20s\n", "TOKEN_RETURN", yytext);
                    break;
                case TOKEN_STRING:
                    printf("%-20s %20s\n", "TOKEN_STRING", yytext);
                    break;
                case TOKEN_TRUE:
                    printf("%-20s %20s\n", "TOKEN_TRUE", yytext);
                    break;
                case TOKEN_VOID:
                    printf("%-20s %20s\n", "TOKEN_VOID", yytext);
                    break;
                case TOKEN_WHILE:
                    printf("%-20s %20s\n", "TOKEN_WHILE", yytext);
                    break;
                    case TOKEN_SPECIALCHAR:
                    printf("%-20s %20s\n", "TOKEN_SPECIALCHAR", yytext);
                    break;
                case TOKEN_ADD:
                    printf("%-20s %20s\n", "TOKEN_ADD", yytext);
                    break;
                case TOKEN_SUBTRACT:
                    printf("%-20s %20s\n", "TOKEN_SUBTRACT", yytext);
                    break;
                case TOKEN_INCREMENT:
                    printf("%-20s %20s\n", "TOKEN_INCREMENT", yytext);
                    break;
                case TOKEN_DECREMENT:
                    printf("%-20s %20s\n", "TOKEN_DECREMENT", yytext);
                    break;
                case TOKEN_FRONTPARENTHESE:
                    printf("%-20s %20s\n", "TOKEN_FRONTPARENTHESE", yytext);
                    break;
                case TOKEN_BACKPARENTHESE:
                    printf("%-20s %20s\n", "TOKEN_BACKPARENTHESE", yytext);
                    break;
                case TOKEN_FRONTSQUAREBRACKET:
                    printf("%-20s %20s\n", "TOKEN_FRONTSQUAREBRACKET", yytext);
                    break;
                case TOKEN_BACKSQUAREBRACKET:
                    printf("%-20s %20s\n", "TOKEN_BACKSQUAREBRACKET", yytext);
                    break;
                case TOKEN_FRONTCURLYBRACKET:
                    printf("%-20s %20s\n", "TOKEN_FRONTCURLYBRACKET", yytext);
                    break;
                case TOKEN_BACKCURLYBRACKET:
                    printf("%-20s %20s\n", "TOKEN_BACKCURLYBRACKET", yytext);
                    break;
                case TOKEN_LOGICALNOT:
                    printf("%-20s %20s\n", "TOKEN_LOGICALNOT", yytext);
                    break;
                case TOKEN_EXPONENTIAL:
                    printf("%-20s %20s\n", "TOKEN_EXPONENTIAL", yytext);
                    break;
                case TOKEN_MULTIPLY:
                    printf("%-20s %20s\n", "TOKEN_MULTIPLY", yytext);
                    break;
                case TOKEN_DIVIDE:
                    printf("%-20s %20s\n", "TOKEN_DIVIDE", yytext);
                    break;
                case TOKEN_REMAIN:
                    printf("%-20s %20s\n", "TOKEN_REMAIN", yytext);
                    break;  
                case TOKEN_LESSTHAN:
                    printf("%-20s %20s\n", "TOKEN_LESSTHAN", yytext);
                    break;
                case TOKEN_LESSEQUAL:
                    printf("%-20s %20s\n", "TOKEN_LESSEQUAL", yytext);
                    break;
                case TOKEN_GREATERTHAN:
                    printf("%-20s %20s\n", "TOKEN_GREATERTHAN", yytext);
                    break;
                case TOKEN_GREATEREQUAL:
                    printf("%-20s %20s\n", "TOKEN_GREATEREQUAL", yytext);
                    break;
                case TOKEN_EQUAL:
                    printf("%-20s %20s\n", "TOKEN_EQUAL", yytext);
                    break;
                case TOKEN_NOTEQUAL:
                    printf("%-20s %20s\n", "TOKEN_NOTEQUAL", yytext);
                    break;
                case TOKEN_AND:
                    printf("%-20s %20s\n", "TOKEN_AND", yytext);
                    break;
                case TOKEN_OR:
                    printf("%-20s %20s\n", "TOKEN_OR", yytext);
                    break;
                case TOKEN_ASSIGN:
                    printf("%-20s %20s\n", "TOKEN_ASSIGN", yytext);
                    break;
                case TOKEN_COLON:
                    printf("%-20s %20s\n", "TOKEN_COLON", yytext);
                    break;
                case TOKEN_SEMICOLON:
                    printf("%-20s %20s\n", "TOKEN_SEMICOLON", yytext);
                    break;
                case TOKEN_COMMA:
                    printf("%-20s %20s\n", "TOKEN_COMMA", yytext);
                    break;
                case TOKEN_TYPE_CHAR:
                    printf("%-20s %20s\n", "TOKEN_TYPE_CHAR", yytext);
                    break;
                case TOKEN_TYPE_INT:
                    printf("%-20s %20s\n", "TOKEN_TYPE_INT", yytext);
                    break;
                case TOKEN_TYPE_FLOAT:
                    printf("%-20s %20s\n", "TOKEN_TYPE_FLOAT", yytext);
                    break;
                case TOKEN_TYPE_IDENT:
                    printf("%-20s %20s\n", "TOKEN_TYPE_IDENT", yytext);
                    break;
                case TOKEN_TYPE_STRING:
                    printf("%-20s %20s\n", "TOKEN_TYPE_STRING", yytext);
                    break;
                case TOKEN_ERROR:
                    printf("Invalid Token!\n", yytext);
                    return 1;
                    break;
                case 0:
                case TOKEN_EOF:
                    sentinel = -1;
                    return 0;
                    break;
                default:
                    sentinel = 1; 
                    printf("bad case:!%s!%d!\n", yytext, t);
                    return 1;
            }
            if (sentinel == -1) break;
            else if (sentinel == 1) return 1;
        }
    }
    else if (check_encode = true) {
        FILE *file = fopen( argv[2], "r"); // open code
            if (file == NULL) {
                perror("Cannot open file.\n");
                return 1;  // Exit with an error code
            }
        char line [1280] = ""; // initialize for decode es
        char new [256] = ""; // initialize for encode s
        char printstring [1280] = ""; // initialize for output
        int return_code1 = fgets(line, sizeof(line), file) != NULL;
        if (return_code1 == 0) {
            printf("Cannot read in content of file.\n");
            return 1;
        }
        int return_code2 = string_decode(line, new);
        if (return_code2 != 0) {
            printf("There is an error in the original string.\n");
            return 1;
        }
        int return_code3 = string_encode(new, printstring);
        if (return_code3 != 0) {
            printf("There is an error in the new string.\n");
            return 1;
        }
        if (return_code3 == 0) {
            int i = 0;
            while ( printstring[i] != '\0'){
                printf( "%c", printstring[i]);
                i++;
            }
            printf("\n");
            } 
    }
    return 0;
}