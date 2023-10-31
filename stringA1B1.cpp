/*Take a number of lines as input and discard the leading and trailing blank spaces from each line
and output. Also, output the longest line and its number of characters. It is recommended to use
pointer to solve the problem. 30% number will be deducted if you do not use pointer*/
#include <stdio.h>
#include <string.h>

void trimLeadingTrailingSpaces(char *line) {
    // Trim leading spaces
    while (*line == ' ' || *line == '\t') {
        line++;
    }

    // Trim trailing spaces
    char *end = line + strlen(line) - 1;
    while (end >= line && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) {
        *end = '\0';
        end--;
    }
}

int main() {
    char line[1000];
    char longestLine[1000];
    int longestLineLength = 0;
    int lineNumber = 0;

    printf("Enter lines of text:\n");

    while (fgets(line, sizeof(line), stdin) != NULL && lineNumber !=3) {
        lineNumber++;

        trimLeadingTrailingSpaces(line);

        int lineLength = strlen(line);

        if (lineLength > longestLineLength) {
            longestLineLength = lineLength;
            strcpy(longestLine, line);
        }

        printf("Line %d (Length: %d): %s\n", lineNumber, lineLength, line);
    }

    printf("\nLongest Line (Length: %d): %s\n", longestLineLength, longestLine);

    return 0;
}
