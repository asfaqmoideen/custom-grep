#include <stdio.h>
#include <string.h>
#include <ctype.h>


#if defined(_WIN32) || defined(__APPLE__)
#error "This program is only compatible with Linux"
#endif
char line[256];

void printGrepMenu(){
    printf(" Custom grep using C");
    printf("\n provide appropriate input to excute grep - Input pattern is as follows");
    printf("\n `grep` `option` `pattern` `filepath`" );
    printf("\n deafult (without option) search for pattern in case sensitive mannner ");
    printf("\n -i, --ignore-case: Ignores case distinctions in patterns and input data.");
    printf("\n -v, --invert-match: Selects the non-matching lines of the provided input pattern.");
    printf("\n -n, --line-number: Prefix each line of the matching output with the line number in the input file.");
    printf("\n -w: Find the exact matching word from the input file or string.");
    printf("\n -c: Count the number of occurrences of the provided pattern.\n");
}

char* toLower(char *stringToLowerCase)
{
    for (int i = 0; stringToLowerCase[i]; i++)
    {
        stringToLowerCase[i] = tolower(stringToLowerCase[i]);
    }

    return stringToLowerCase;
}

void searchPattern(FILE *file, char *pattern)
{
    printf("Matching Case Pattern\n");
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

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(toLower(line), toLower(pattern)) != NULL)
        {
            printf("%s", line);
        }
    }
}

void findMatchedLineNumber(FILE *file, char *pattern)
{
    printf("Matching Line Number\n");
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%d\n", lineNumber++);
        }
    }
}

void printNonMatchingPattern(FILE *file, char *pattern)
{

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
    int count =0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) != NULL) count++;
    }
    printf("No Of Occurences is %d", count);
}

int main(int args, char *argv[])
{   
    if(args < 3){
        printGrepMenu();
        return 1;
    }
    
    FILE *file;
    file = fopen(argv[args-1], "r");

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