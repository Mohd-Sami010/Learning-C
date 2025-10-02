#include<stdio.h>
#include <stdlib.h>

int main(){
    int *ptr = (int *)calloc(500, sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < 500; i++) {
        ptr[i] = i + 1;
    }

    for (int i = 0; i < 500; i++) {
        printf("%d ", ptr[i]);
    }
    free(ptr);
    return 0;
}