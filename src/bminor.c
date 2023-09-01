#include "encoder.h"

int main (int argc, char *argv[]){
    if (argc == 3){
        if (strcmp(argv[1], "--encode") != 0){
            printf("Do not have the right command arguments.\n");
            return 1;
        }
    } else {
        printf("Do not have enough command arguments.\n");
        return 1;
    }
    
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