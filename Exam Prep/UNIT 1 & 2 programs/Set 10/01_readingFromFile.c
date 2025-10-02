#include <stdio.h>

int main() {
    FILE *file;
    char str[100];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (fgets(str, sizeof(str), file) != NULL) {
        printf("Read from file: %s", str);
    } else {
        printf("No data read from file.\n");
    }

    fclose(file);
    return 0;
}