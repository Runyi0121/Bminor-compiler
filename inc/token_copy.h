#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
     TOKEN_EOF=0,
     TOKEN_CCOMMENT,
     TOKEN_CPLUSCOMMENT,
     TOKEN_ARRAY,
     TOKEN_AUTO,
     TOKEN_BOOLEAN,
     TOKEN_CHAR,
     TOKEN_ELSE,
     TOKEN_FALSE,
     TOKEN_FLOAT,
     TOKEN_FOR,
     TOKEN_FUNCTION,
     TOKEN_IF,
     TOKEN_INTEGER,
     TOKEN_PRINT,
     TOKEN_RETURN,
     TOKEN_STRING,
     TOKEN_TRUE,
     TOKEN_VOID,
     TOKEN_WHILE,
     TOKEN_SPECIALCHAR,
     TOKEN_ADD,
     TOKEN_SUBTRACT,
     TOKEN_INCREMENT,
     TOKEN_DECREMENT,
     TOKEN_FRONTPARENTHESE,
     TOKEN_BACKPARENTHESE,
     TOKEN_FRONTSQUAREBRACKET,
     TOKEN_BACKSQUAREBRACKET,
     TOKEN_FRONTCURLYBRACKET,
     TOKEN_BACKCURLYBRACKET,
     TOKEN_NEGATIVE,
     TOKEN_LOGICALNOT,
     TOKEN_EXPONENTIAL,
     TOKEN_MULTIPLY,
     TOKEN_DIVIDE,
     TOKEN_REMAIN,
     TOKEN_LESSTHAN,
     TOKEN_LESSEQUAL,
     TOKEN_GREATERTHAN,
     TOKEN_GREATEREQUAL,
     TOKEN_EQUAL,
     TOKEN_NOTEQUAL,
     TOKEN_AND,
     TOKEN_OR,
     TOKEN_ASSIGN,
     TOKEN_COLON,
     TOKEN_SEMICOLON,
     TOKEN_COMMA,
     TOKEN_PERCENT,
     TOKEN_TYPE_CHAR,
     TOKEN_TYPE_INT,
     TOKEN_TYPE_FLOAT,
     TOKEN_TYPE_IDENT,
     TOKEN_TYPE_STRING,
     TOKEN_ERROR
 } token_t;

token_t checkstring (char *yytext);
token_t checkchar (char *yytext);

 #endif