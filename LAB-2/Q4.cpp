#include <stdio.h>

// Function to remove all occurrences of a character using pointers
char* removeChar(char *str, char ch) {
    char *src = str;   // source pointer
    char *dst = str;   // destination pointer

    while (*src) { // until null terminator
        if (*src != ch) {
            *dst = *src;  // copy if not the character to remove
            dst++;
        }
        src++;
    }
    *dst = '\0'; // null-terminate the new string
    return str;
}

int main() {
    char str[100], ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter character to delete: ");
    scanf("%c", &ch);

    printf("Corrected string: %s\n", removeChar(str, ch));

    return 0;
}
