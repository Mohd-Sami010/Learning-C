#include <stdio.h>

int main() {
    char ch = 'A';
    char *p = &ch;

    printf("Uppercase letters:\n");
    for (*p = 'A'; *p <= 'Z'; (*p)++)
        printf("%c ", *p);

    printf("\nLowercase letters:\n");
    for (*p = 'a'; *p <= 'z'; (*p)++)
        printf("%c ", *p);

    return 0;
}