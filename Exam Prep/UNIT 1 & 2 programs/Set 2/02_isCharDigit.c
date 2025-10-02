#include<stdio.h>

int main(){
    char c;

    printf("Enter a char: ");
    scanf("%c", &c);

    int charAscii = c;
    if (charAscii >= 48 && charAscii <= 57){
        printf("%c is a Digit",c);
    }
    else {
        printf("%c is not a Digit", c);
    }
    return 0;
}