#include<stdio.h>

int main(){
    int num1, num2;
    int *p1, *p2;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);

    p1 = &num1;
    p2 = &num2;

    if (*p1 > *p2){
        printf("num1 > num2");
    }
    else {
        printf("num1 < num2");
    }

    return 0;
}