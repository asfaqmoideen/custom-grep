#include <stdio.h>
#include <string.h>
#include <ctype.h>


void toLower(char *pattern)
{
    for (int i = 0; pattern[i]; i++)
    {
        pattern[i] = tolower(pattern[i]);
    }
}

void searchPattern(FILE *file, char *pattern)
{

    printf("Matching Case Pattern\n");
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%s", line);
        }
    }
}

void searchCaseInsensitivePattern(FILE *file, char *pattern)
{

    printf("Matching Case Insensitive Pattern\n");
    char line[256];
    toLower(pattern);
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%s", line);
        }
    }
}

void findMatchedLineNumber(FILE *file, char *pattern)
{
    printf("Matching Line NUmber\n");
    int lineNumber = 0;
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%d", lineNumber++);
        }
    }
}

void printNonMatchingPattern(FILE *file, char *pattern)
{

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) == NULL)
        {
            printf("%s", line);
        }
    }
    printf("Non - Matching Case Patter\n");
}

void printNumberOfOccurences(FILE *file, char *pattern)
{
    char line[256];
    int count =0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) == NULL) count++;
    }
    printf("No Of Occurences is %d", count);
}
int main(int args, char *argv[])
{
    FILE *file;

    file = fopen(argv[2], "r");
    if (file == NULL)
    {
        printf("Error opening the file\n");
        return 1;
    }

    searchPattern(file, argv[1]);
    rewind(file);

    searchCaseInsensitivePattern(file, argv[1]);
    rewind(file);

    findMatchedLineNumber(file, argv[1]);
    rewind(file);
    
    printNonMatchingPattern(file, argv[1]);
    rewind(file);
    
    printNumberOfOccurences(file, argv[1]);
    fclose(file);
    return 0;
}