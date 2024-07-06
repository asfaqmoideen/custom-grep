# custom-grep
This is the repository which contains a C program implemented for the functionalities of `grep` in Linux. It may not contain all functions but  the basic functonalities and implemented file handling in my knowlwdge. 


### Methods 

    void searchMatchingPattern(FILE *file, char *pattern)
    void searchCaseInsensitivePattern(FILE *file, char *pattern)
    void findMatchedLineNumber(FILE *file, char *pattern)
    void printNonMatchingPattern(FILE *file, char *pattern)
    void printNumberOfOccurences(FILE *file, char *pattern)
    void printGrepMenu()
    char* toLower(char *stringToLowerCase)

### enum
    typedef enum{
    defaultSearch,
    caseInsensitiveSearch,
    invertMatching,
    lineNumber,
    matchingWordCount,
    }grepOperations;

Enumerable of function names is defined which improves code readability and ease of edit in future. 

### Function pointers and method call decision in runtime
    void (*ptr2func[MethodCount])(FILE*, char*) = {
    searchMatchingPattern,
    searchCaseInsensitivePattern,
    printNonMatchingPattern,
    findMatchedLineNumber,
    printNumberOfOccurences
    };

instead of using switch or multi if else to call the function this enum type casted and call with arry f funcion pointers which have the aaddress of the funtions. 

        ptr2func[userOption](file,pattern);

### toLowe(char*) 
Uses tolower() function defined in ctype.h library and iterative loop to lower entire line and pattern for case insensitive pattern matching. 

