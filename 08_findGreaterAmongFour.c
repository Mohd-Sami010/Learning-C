#include<stdio.h>

int main(){
    int num1, num2, num3, num4;

    printf("Enter 1st number: ");
    scanf("%d", &num1);
    
    printf("Enter 2nd number: ");
    scanf("%d", &num2);

    printf("Enter 3rd number: ");
    scanf("%d", &num3);

    printf("Enter 4th number: ");
    scanf("%d", &num4);

    if (num1 > num2 && num1 > num3 && num1 > num4){
        printf("%d is greatest among other numbers", num1);
    }
    else if ( num2 > num3 && num3 > num4){
        printf("%d is greatest among other numbers", num2);
    }
    else if (num3 > num4){
        printf("%d is greatest among other numbers", num3);
    }
    else {
        printf("%d is greatest among other numbers", num4);
    }

    return 0;
}