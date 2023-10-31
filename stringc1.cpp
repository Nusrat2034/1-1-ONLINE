/*Take a string as input and give the number of words in the string as output. Assume the words
are separated by spaces. Do not use any function, rather use a loop. It is recommended to use
pointer to solve the problem. 30% number will be deducted if you do not use pointer*/

#include <stdio.h>

int countWords(const char *str) {
    int count = 0;
    int inWord = 0;  // Flag to track whether we are inside a word

    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            // If we encounter a space, tab, or newline character, we are not in a word
            inWord = 0;
        } else if (inWord == 0) {
            // If we were not in a word before and found a non-space character, we're in a new word
            inWord = 1;
            count++;
        }
        str++;
    }

    return count;
}

int main() {
    char str[1000];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int wordCount = countWords(str);

    printf("Number of words in the string: %d\n", wordCount);

    return 0;
}
