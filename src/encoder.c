#include "../inc/encoder.h"

int string_decode( const char *es, char *s ){
    const char * old = & es[0]; 
    char * new = & s[0];
    int length = 0;
    char hex[2]; 
    int check_back_quote = 0;
    //printf("encoder string: %s\n", es);
    if ( * old == '\"') {  //check for starter with double quotes
        old ++;
    } else {
        printf("does not have quotation in the front.\n");
        return 1;
    }

    while ( *old != '\0'){
        if (length > 255){
            printf( "string exceeds the maximum length.\n");
            return 1;
        }
        if ( *old == '\\') {
            //fprintf (stdout, "backslash\n");
            old ++;
            switch ( *old ){
                case 'n' :
                    *new = 10;
                    length ++;
                    break;
                case 'a' :
                    *new = 7;
                    length ++;
                    break;
                case 'b' :
                    *new = 8;
                    length ++;
                    break;
                case 'e' :
                    *new = 27;
                    length ++;
                    break;
                case 'r' :
                    *new = 13;
                    length ++;
                    break;
                case 't' :
                    *new = 9;
                    length ++;
                    break;
                case 'v' :
                    *new = 11;
                    length ++;
                    break;
                case 'f' :
                    *new = 12;
                    length ++;
                    break;
                case '\\' :
                    *new = 92;
                    length ++;
                    break;
                case '\'' :
                    *new = 39;
                    length ++;
                    break;
                case '\"':
                    *new = 34;
                    length ++;
                    break;
                case '0':
                    old ++;
                    if ( *old == 'x'){
                        old++;
                        if ( isalnum (*old) !=0 ){
                            hex[1] = (char) *old;
                            old++;
                            if ( isalnum (*old) !=0 ){
                                hex[0] = (char) *old ; 
                                int i = 0, val, decimal = 0;                               
                                //Iterate over each hex digit                                
                                for(i = 1; i > -1; i--)
                                {                           
                                    // Find the decimal representation of hex[i]
                                    if( hex[i]>='0' && hex[i]<='9'){
                                        val = hex[i] - 48;
                                        }
                                    else if( hex[i]>='a' && hex[i]<='f') {
                                        val = hex[i] - 97 + 10;
                                    }
                                    else if( hex[i]>='A' && hex[i]<='F') {  
                                        val = hex[i] - 65 + 10;
                                    }
                                    else {
                                        //printf("invalid hex\n");
                                        return 1;
                                    }
                                    decimal += val * pow(16, i);
                                } 
                                if (decimal <= 255 && decimal > 0) {
                                        *new =  decimal;
                                        length ++;
                                        //printf("decimal in new string: %u\n", (unsigned char)*new);
                                    } 
                                else if (decimal == 0) {
                                    printf("don't put wrong characters in the strings!\n");
                                    return 1;
                                    }
                                else{
                                    printf("don't put wrong characters in the strings!\n");
                                    return 1;
                                    }
                                }   
                            } 
                        } 
                    break;
                default:
                    printf("there is nothing behind the escape.\n");
                    return 1;
                }
                new ++;
                length ++;
            } 
            else if ( *old >= 0x20 && *old <= 0x7E) {
                if (*old == '\"'){
                    check_back_quote ++;
                }
                *new = *old ;
                new ++; 
                length ++;
        }
        old ++;
    }
    if (check_back_quote >1){
        return 1;
    }
    new --;
    if (* new == '\"'){
        *new = '\0'; 
    } else {
        *new = '\0';
        printf("does not have quotation in the back.\n");
        return 1;
    }

    return 0;
}

int string_encode( const char *s, char *es ){
    const char * input = & s[0];
    char * output = & es [1];
    int hex, firstdigit, secondigit;

    es [0] = '\"';
    while (*input != '\0'){
        switch ( *input ) {
            case '\n' :
                * output = '\\';
                output ++;
                * output = 'n';
                output++;
                break;
            case '\b' :
                * output = '\\';
                output ++;
                * output = 'b';
                output++;
                break;
            case '\e' :
                * output = '\\';
                output ++;
                * output = 'e';
                output++;
                break;
            case '\f' :
                * output = '\\';
                output ++;
                * output = 'f';
                output++;
                break;
            case '\a' :
                * output = '\\';
                output ++;
                * output = 'a';
                output++;
                break;
            case '\r' :
                * output = '\\';
                output ++;
                * output = 'r';
                output++;
                break;
            case '\t' :
                * output = '\\';
                output ++;
                * output = 't';
                output++;
                break;
            case '\v' :
                * output = '\\';
                output ++;
                * output = 'v';
                output++;
                break;
            case '\'' :
                * output = '\\';
                output ++;
                * output = '\'';
                output++;
                break;
            case '\"' :
                * output = '\\';
                output ++;
                * output = '\"';
                output++;
                break;
            default:
                //printf("%u\n", (unsigned char) *input);
                
                if ( *input >= 0x20 && *input <= 0x7E){
                    * output = * input;
                    output ++;
                } else if ( (unsigned char) *input > 0x7E && (unsigned char) *input <= 0xFF){
                    * output = '\\';
                    output ++;
                    * output = '0';
                    output ++;
                    * output = 'x';
                    output ++;
                    hex = (unsigned char) * input ;
                    firstdigit =  hex % 16;
                    secondigit = hex - 16 * firstdigit;
                    if (firstdigit < 10){
                            firstdigit = firstdigit + 48;
                        }
                    else  {
                        firstdigit = firstdigit + 55;
                        }
                    *output = firstdigit;
                    output++;
                    if (secondigit < 10){
                            secondigit = secondigit + 48;
                        }
                    else  {
                        secondigit = secondigit + 55;
                        }
                    *output = secondigit;
                    output++;
                    //printf("1: %d  2: %d\n", firstdigit, secondigit);
                } else if ( (unsigned char) *input > 0x00 && (unsigned char) *input <= 0x1F){
                    * output = '\\';
                    output ++;
                    * output = '0';
                    output ++;
                    * output = 'x';
                    output ++;
                    * output = '0';
                    output ++;
                    hex = (unsigned char) * input;
                    * output = hex + 48;
                    output++;
                } else return 1;
        }
        input ++;
    }
    * output = '\"';
    output ++;
    * output = '\0';
    return 0;
}

int char_decode( const char *es, char *s ){
    const char * old = & es[0]; 
    char * new = s;
    char hex[2]; 
    int length = 0;
    if ( * old == '\'') {  //check for starter with double quotes
        old ++;
    } else {
        printf("does not have single quote in front.\n");
        return 1;
    }
    if ( *old == '\\') {
        old ++;
        switch ( *old ){
            case 'n' :
                *new = 10;
                length ++;
                break;
            case 'a' :
                *new = 7;
                length ++;
                break;
            case 'b' :
                *new = 8;
                length ++;
                break;
            case 'e' :
                *new = 27;
                length ++;
                break;
            case 'r' :
                *new = 13;
                length ++;
                break;
            case 't' :
                *new = 9;
                length ++;
                break;
            case 'v' :
                *new = 11;
                length ++;
                break;
            case '\\' :
                *new = 92;
                length ++;
                break;
            case '\'' :
                *new = 39;
                length ++;
                break;
            case '\"':
                *new = 34;
                length ++;
                break;
            case '0':
                old ++;
                if ( *old == 'x'){
                    old++;
                    if ( isalnum (*old) !=0 ){
                        hex[1] = (char) *old;
                        old++;
                        if ( isalnum (*old) !=0 ){
                            hex[0] = (char) *old ; 
                            int i = 0, val, decimal = 0;                               
                            //Iterate over each hex digit                                
                            for(i = 1; i > -1; i--)
                            {                           
                                // Find the decimal representation of hex[i]
                                if( hex[i]>='0' && hex[i]<='9'){
                                    val = hex[i] - 48;
                                    }
                                else if( hex[i]>='a' && hex[i]<='f') {
                                    val = hex[i] - 97 + 10;
                                }
                                else if( hex[i]>='A' && hex[i]<='F') {  
                                    val = hex[i] - 65 + 10;
                                }
                                else {
                                    return 1;
                                }
                                decimal += val * pow(16, i);
                            } 
                            if (decimal <= 255 && decimal > 0) {
                                    *new =  decimal;
                                    length ++;

                                } 
                            else{
                                printf("don't put wrong characters in the hex!\n");
                                return 1;
                                }
                            }   
                        } 
                    } 
                break;
            default:
                return 1;
            }
    }
    else if ( *old >= 0x20 && *old <= 0x7E) {
        *new = *old;
    }    
    old ++;
    if ( *old != '\''){
        return 1;
    }
    else{
        new ++;
        *new = '\0';
    }     
    return 0;
}


int char_encode( const char *s, char *es ){
    const char * input = & s[0];
    char * output = & es [1];
    int hex, firstdigit, secondigit;
    es [0] = '\'';
    switch (*input ) {
        case '\n' :
            * output = '\\';
            output ++;
            * output = 'n';
            output++;
            break;
        case '\b' :
            * output = '\\';
            output ++;
            * output = 'b';
            output++;
            break;
        case '\e' :
            * output = '\\';
            output ++;
            * output = 'e';
            output++;
            break;
        case '\f' :
            * output = '\\';
            output ++;
            * output = 'f';
            output++;
            break;
        case '\a' :
            * output = '\\';
            output ++;
            * output = 'a';
            output++;
            break;
        case '\r' :
            * output = '\\';
            output ++;
            * output = 'r';
            output++;
            break;
        case '\t' :
            * output = '\\';
            output ++;
            * output = 't';
            output++;
            break;
        case '\v' :
            * output = '\\';
            output ++;
            * output = 'v';
            output++;
            break;
        case '\'' :
            * output = '\\';
            output ++;
            * output = '\'';
            output++;
            break;
        case '\"' :
            * output = '\\';
            output ++;
            * output = '\"';
            output++;
            break;
        default:
            if ( *input >= 0x20 && *input <= 0x7E){
                * output = * input;
                output ++;
            } else if ( (unsigned char) *input > 0x7E && (unsigned char) *input <= 0xFF){
                * output = '\\';
                output ++;
                * output = '0';
                output ++;
                * output = 'x';
                output ++;
                hex = (unsigned char) * input ;
                firstdigit =  hex % 16;
                secondigit = hex - 16 * firstdigit;
                if (firstdigit < 10){
                        firstdigit = firstdigit + 48;
                    }
                else  {
                    firstdigit = firstdigit + 55;
                    }
                *output = firstdigit;
                output++;
                if (secondigit < 10){
                        secondigit = secondigit + 48;
                    }
                else  {
                    secondigit = secondigit + 55;
                    }
                *output = secondigit;
                output++;
            } else if ( (unsigned char) *input > 0x00 && (unsigned char) *input <= 0x1F){
                * output = '\\';
                output ++;
                * output = '0';
                output ++;
                * output = 'x';
                output ++;
                * output = '0';
                output ++;
                hex = (unsigned char) * input;
                * output = hex + 48;
                output++;
            } else return 1;
    }
    * output = '\'';
    output ++;
    * output = '\0';
    return 0;
}