# Custom grep using C

### Problem: 
    Implement grep without recursive Linux Command

### Solution:

This Functionality can be acheived by implementing file operation in C without custom linux libraries. 

### Design 
    
    A general C program Main function which should accept file path and -x command in the command line and should return the appropriate soltion for this. 
    
(x represents diiferent char elements to implement different function)

### Base Function
    grep searches for PATTERNS in each FILE. Grep finds each line that matched the provided PATTERN.
    
### Functionalities
    
    -i, --ignore-case: Ignores case distinctions in patterns and input data.
    -v, --invert-match: Selects the non-matching lines of the provided input pattern.
    -n, --line-number: Prefix each line of the matching output with the line number in the input file.
    -w: Find the exact matching word from the input file or string.
    -c: Count the number of occurrences of the provided pattern.