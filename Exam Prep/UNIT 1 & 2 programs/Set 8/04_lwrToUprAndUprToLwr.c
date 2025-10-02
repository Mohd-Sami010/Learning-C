#include<stdio.h>

int main(){
    char string[20];

    printf("Enter a text: ");
    fgets(string, sizeof(string), stdin);

    for (int i = 0; string[i] != '\0'; i++){
        char alpha = string[i];
        if ((int)alpha >= 97 && (int)alpha <= 122){
            string[i] = alpha - 32;
        }
        else if ((int)alpha >= 55 && (int)alpha <= 90){
            string[i] = alpha+ 32;
        }
    }
    printf("%s", string);
    return 0;
}