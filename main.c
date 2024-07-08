#include <stdio.h>
#include <string.h>
#include <ctype.h>

#if defined(_WIN32) || defined(__APPLE__)
#error "This program is only compatible with Linux"
#endif
# define MethodCount 5 

char line[256];

typedef enum{
    defaultSearch,
    caseInsensitiveSearch,
    invertMatching,
    lineNumber,
    matchingWordCount,
}grepOperations;


void printGrepMenu()
{
    printf(" Custom grep using C");
    printf("\n provide appropriate input to excute grep - Input pattern is as follows");
    printf("\n `grep` `option` `pattern` `filepath`");
    printf("\n deafult (without option) search and prints pattern in case sensitive mannner ");
    printf("\n -i, --ignore-case: Ignores case distinctions in patterns and input data.");
    printf("\n -v, --invert-match: Selects the non-matching lines of the provided input pattern.");
    printf("\n -n, --line-number: Prefix each line of the matching output with the line number in the input file.");
    printf("\n -c: Count the number of occurrences of the provided pattern.\n");
    printf("\n --help prints grep Menu\n");

}
 

char* toLower(char *stringToLowerCase)
{
    for (int i = 0; stringToLowerCase[i]; i++)
    {
        stringToLowerCase[i] = tolower(stringToLowerCase[i]);
    }

    return stringToLowerCase;
}

void searchMatchingPattern(FILE *file, char *pattern)
{
    printf("Matching Case   Sensitive Pattern\n");
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
    printf("Matching Line Numbers are\n");
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file))
    {   
        lineNumber++;
        if (strstr(line, pattern) != NULL)
        {
            printf("%d\n",lineNumber );
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
    int count = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) != NULL)
            count++;
    }
    printf("No Of Occurences is %d", count);
}

void (*ptr2func[MethodCount])(FILE*, char*) = {
    searchMatchingPattern,
    searchCaseInsensitivePattern,
    printNonMatchingPattern,
    findMatchedLineNumber,
    printNumberOfOccurences
};

int main(int args, char *argv[])
{
    if (args < 3)
    {
        printGrepMenu();
        return 1;
    }

    FILE *file;
    file = fopen(argv[args - 1], "r");

    if (file == NULL)
    {
        printf("Error opening the file\n");
        return 1;
    }

    grepOperations userOption;

    if (strcmp(argv[1], "-i") == 0) 
        userOption = caseInsensitiveSearch;
    else if (strcmp(argv[1], "-v") == 0) 
        userOption = invertMatching;
    else if (strcmp(argv[1], "-n")== 0 ) 
        userOption = lineNumber;
    else if (strcmp(argv[1], "-c") == 0) 
        userOption = matchingWordCount;
    else if (strcmp(argv[1], "--help") == 0) 
        printGrepMenu();
    else 
        userOption = defaultSearch;

    char *pattern = argv[args-2];

    ptr2func[userOption](file,pattern);

    return 0;
}