#include <stdio.h>
#include <string.h>


void searchForPattern(FILE *, char*);

int main(int args, char *argv[]){
    FILE *file;

    file = fopen(argv[2], "r");
    if(file == NULL){
        printf("Error opening the file\n");
        return 1;
    }    

    searchForPattern(file, argv[1]);
    fclose(file);
    return 0;

}

void searchForPattern(FILE *file, char* pattern){

    char line[256];
    while (fgets(line, sizeof(line), file)){

        line[strcspn(line, "\n")] = '\0';

        if(strstr(line, pattern) != NULL){
            printf("%s\n", line);
        }
    }

}