    #include <stdlib.h>
    #include <stdio.h>

    int main() {
        int *ptr = (int *)malloc(sizeof(int));
        *ptr = 10;
        printf("Value before free: %d\n", *ptr);
        free(ptr); // Memory is freed, ptr is now dangling
        // Attempting to access *ptr here would result in undefined behavior
        // printf("Value after free: %d\n", *ptr); // Dangerous!
        return 0;
    }