#include<stdio.h>

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0) {
        printf("Yes it is Natural number");
    }
    else {
        printf("No it is not Natural number");
    }
    return 0;
}