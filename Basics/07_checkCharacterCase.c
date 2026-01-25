#include<stdio.h>

int main(){

    const int LOWER_A_ASCII_VALUE = 97;
    const int LOWER_Z_ASCII_VALUE = 122;

    char characterEntered;
    printf("Enter a character: ");
    scanf("%c", &characterEntered);

    if (characterEntered >= LOWER_A_ASCII_VALUE && characterEntered <= LOWER_Z_ASCII_VALUE){
        printf("The entered Character %c is in Lower Case", characterEntered);
    }
    else {
        printf("The entered Character %c is in Upper Case", characterEntered);
    }

    return 0;
}