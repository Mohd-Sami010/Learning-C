#include<stdio.h>

int main(){
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int tempNum = num;
    int sumOfDigits = 0;
    while (tempNum > 0){
        sumOfDigits+= tempNum % 10;
        tempNum /= 10;
    }

    printf("Sum of digits of %d is %d", num, sumOfDigits);
    return 0;
}