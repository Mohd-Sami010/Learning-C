#include<stdio.h>

int main(){
    // Declaring variables
    float side1, side2;

    // Taking Inputs
    printf("----------------------------------------------");
    printf("\nEnter length of Side 1: ");
    scanf("%f", &side1);

    printf("Enter length of Side 2: ");
    scanf("%f", &side2);

    // Calculating and printing the answer
    float parameter = 0.5 * side1 * side2;
    printf("\nParamter is %0.2f", parameter);
    return 0;
}