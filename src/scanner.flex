%{
#include "../inc/token.h"
#include "../inc/encoder.h"
%}

C_COMMENT       \/\*[^*]*\*+([^*\/][^*]*\*+)*\/
CPLUS_COMMENT   \/\/[^\n]*\n
INT             [+-]?[0-9]+
IDENT           ([a-zA-Z]|_)+([a-zA-Z]|[0-9]|_)*
STRING          \"([^\"\0\n\t]|(\\.))*\"
CHAR            \'(\\[abefnrtv\'"0-9]|\\0x[0-9a-fA-F][0-9a-fA-F]|.)\'
FLOAT           [-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?
%%

{C_COMMENT}     {;}
{CPLUS_COMMENT} {;}
(" "|\t|\n)     {;}

array           {return TOKEN_ARRAY;}
auto            {return TOKEN_AUTO;}
boolean         {return TOKEN_BOOLEAN;}
char            {return TOKEN_CHAR;}
else            {return TOKEN_ELSE;}
false           {return TOKEN_FALSE;}
float           {return TOKEN_FLOAT;}
for             {return TOKEN_FOR;}
function        {return TOKEN_FUNCTION;}
if              {return TOKEN_IF;}
integer         {return TOKEN_INTEGER;}
print           {return TOKEN_PRINT;}
return          {return TOKEN_RETURN;}
string          {return TOKEN_STRING;}
true            {return TOKEN_TRUE;}
void            {return TOKEN_VOID;}
while           {return TOKEN_WHILE;}
\+              {return TOKEN_ADD;}
\-              {return TOKEN_SUBTRACT;}
\+\+            {return TOKEN_INCREMENT;}
\-\-            {return TOKEN_DECREMENT;}
\(              {return TOKEN_FRONTPARENTHESE;}
\)              {return TOKEN_BACKPARENTHESE;}
\[              {return TOKEN_FRONTSQUAREBRACKET;}
\]              {return TOKEN_BACKSQUAREBRACKET;}
\{              {return TOKEN_FRONTCURLYBRACKET;}
\}              {return TOKEN_BACKCURLYBRACKET;}
\!              {return TOKEN_LOGICALNOT;}
\^              {return TOKEN_EXPONENTIAL;}
\*              {return TOKEN_MULTIPLY;}
\/              {return TOKEN_DIVIDE;}
\%              {return TOKEN_REMAIN;}
\<              {return TOKEN_LESSTHAN;}
\<\=            {return TOKEN_LESSEQUAL;}
\>              {return TOKEN_GREATERTHAN;}
\>\=            {return TOKEN_GREATEREQUAL;}
\=\=            {return TOKEN_EQUAL;}
\!\=            {return TOKEN_NOTEQUAL;}
\&\&            {return TOKEN_AND;}
\|\|            {return TOKEN_OR;}
\=              {return TOKEN_ASSIGN;}
:               {return TOKEN_COLON;}
;               {return TOKEN_SEMICOLON;}
,               {return TOKEN_COMMA;}

{CHAR}          {return checkchar(yytext);}                                    
{INT}           {return TOKEN_TYPE_INT;}
{FLOAT}         {return TOKEN_TYPE_FLOAT;}
{IDENT}         {return TOKEN_TYPE_IDENT;}
{STRING}        {return checkstring(yytext);}
.               {return TOKEN_ERROR;}

%%
int yywrap()    { return 1; }

token_t checkstring (char * yytext) {
    //printf("%s\n", yytext);
    char buffer [256] = ""; // initialize for encode s
    int return_check_encode;
    int return_check_decode;
    return_check_decode = string_decode(yytext, buffer);
    if (return_check_decode != 0) {
        return TOKEN_ERROR;
    }
    if (strlen(buffer) > 256){
        return TOKEN_ERROR; 
    }
    return_check_encode = string_encode (buffer, yytext);
    if (return_check_encode != 0) {
        return TOKEN_ERROR;
    }
    return TOKEN_TYPE_STRING;
}

token_t checkchar (char * yytext) {
    char buffer [256] = ""; // initialize for encode s
    //printf("%s\n", yytext);
    int return_check_encode;
    int return_check_decode;
    return_check_decode = char_decode(yytext, buffer);
    if (return_check_decode != 0) {
        //printf("1\n");
        return TOKEN_ERROR;
        }
    //printf("%s\n", buffer);

    if (strlen(buffer) > 1 ){
        //printf("2\n");
        return TOKEN_ERROR; 
    } 
    return_check_encode = char_encode (buffer, yytext);
    //printf("return_check_encode:%d\n", return_check_encode);
    if (return_check_encode != 0) {
        //printf("3\n");
        return TOKEN_ERROR;
    }

    return TOKEN_TYPE_CHAR;
}