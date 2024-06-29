#include <stdio.h>
#include <string.h>

int main(){
    FILE *file;

    file = fopen("linux.txt", "r");
    if(file == NULL){
        printf("Error opening the file\n");
        return 1;
    }
    
    char line[256];

    while (fgets(line, sizeof(line), file)){

        line[strcspn(line, "\n")] = '\0';

        if(strstr(line, "linux") != NULL){
            printf("%s\n", line);
        }
    }

    fclose(file);

    return 0;

}