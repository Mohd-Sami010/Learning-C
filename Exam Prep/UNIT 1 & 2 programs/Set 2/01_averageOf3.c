#include<stdio.h>

int main(){
    int num1 = 5, num2 = 7, num3 = 12;

    float average = (num1 + num2 + num3)/3.0;
    printf("Average of %d, %d and %d is %0.3f", num1, num2, num3, average);
    return 0;
}