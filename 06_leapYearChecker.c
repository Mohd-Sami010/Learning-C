#include<stdio.h>

int main(){

    int yearEntered;

    printf("Enter year: ");
    scanf("%d", &yearEntered);

    if ((yearEntered % 4 == 0 && yearEntered % 100 != 0) || yearEntered % 400 == 0){
        printf("Year %d is a leap year ;)",yearEntered);
    }
    else {
        printf("Year %d is not a leap year :(", yearEntered);
    }

    return 0;
}