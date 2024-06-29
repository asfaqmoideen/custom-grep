#include <stdio.h>
#include <string.h>


void searchPattern(FILE *, char*);
void searchCaseInsensitivePattern(FILE* , char*);
void findMatchedLineNumber(FILE*, char*);
void printNonMatchingPattern(FILE*, char*);

char* toLower(char*);

int main(int args, char *argv[]){
    FILE *file;

    file = fopen(argv[2], "r");
    if(file == NULL){
        printf("Error opening the file\n");
        return 1;
    }    

    searchPattern(file, argv[1]);
    searchCaseInsensitivePattern(file, argv[1]);
    findMatchedLineNumber(file,argv[1]);
    printNonMatchingPattern(file, argv[1]);

    fclose(file);
    return 0;

}

void searchPattern(FILE *file, char* pattern){

    char line[256];
    while (fgets(line, sizeof(line), file)){

        line[strcspn(line, "\n")] = '\0';

        if(strstr(line, pattern) != NULL){
            printf("%s\n", line);
        }
    }
}

void searchCaseInsensitivePattern(FILE *file, char* pattern){

    char line[256];
    while (fgets(line, sizeof(line), file)){

        line[strcspn(line, "\n")] = '\0';

        if(strstr(line, pattern) != NULL){
            printf("%s\n", line);
        }
    }
}

void findMatchedLineNumber(FILE *file, char* pattern){
    int lineNumber =0;
    char line[256];
    while (fgets(line, sizeof(line), file)){

        line[strcspn(line, "\n")] = '\0';

        if(strstr(line, pattern) != NULL){
            printf("%d",lineNumber++);
        }
    }
}

void printNonMatchingPattern(FILE *file, char* pattern){

    char line[256];
    while (fgets(line, sizeof(line), file)){

        line[strcspn(line, "\n")] = '\0';

        if(strstr(line, pattern) == NULL){
            printf("%s\n", line);
        }
    }
}

char* toLower(char* pattern){
    char* loweredChar; 
    for(int i=0; i<sizeof(pattern); i++){
        if (pattern[i] < 125 )
        return NULL;
    }
}