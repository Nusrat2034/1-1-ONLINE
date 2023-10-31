#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int check_lowercase(char c) {
    return islower(c) == 0 ? 0 : 1;
}

int check_uppercase(char c) {
    return isupper(c) == 0 ? 0 : 1;
}

int count_case_letters(char *str, int (*fp)(char)) {
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        int ret = fp(str[i]);
        count += ret;
        i++;
    }
    return count;
}

int main() {
    char *str = (char *)calloc(100, sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    
    printf("Enter a string: ");
    scanf(" %[^\n]", str);  // Removed 's' from the format specifier

    int count_lower = count_case_letters(str, check_lowercase);
    int count_upper = count_case_letters(str, check_uppercase);

    printf("Number of lowercase letters: %d\n", count_lower);
    printf("Number of uppercase letters: %d\n", count_upper);

    free(str);
    return 0;
}
