#include<stdio.h>

// Pointer Arithmetic
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("Pointer points to: %d\n", *ptr);

    // Increment
    ptr++;
    printf("Pointer after ptr++ points to: %d\n", *ptr);

    // Addition
    ptr = ptr + 3;
    printf("Pointer after ptr+2: %d\n", *ptr);

    // Subtraction
    int *startPtr = &arr[0];
    int distance = ptr - startPtr;
    printf("Distance from start: %ld elements\n", distance);

    // Comparision
    int *endPtr = &arr[4];
    if (ptr == endPtr) {
        printf("The pointer is now at the last element.\n");
    }

    return 0;
}