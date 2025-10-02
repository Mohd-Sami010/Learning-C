#include<stdio.h>

int main(){
    // Decalring Variables
    int num;

    // Taking Inputs
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculation and output
    int cube = num * num * num;
    printf("Cube of %d is %d", num, cube);

    return 0;
}