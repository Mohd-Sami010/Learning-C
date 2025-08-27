#include<stdio.h>

int main(){
    int pyramidHeight;
    int isValidInput = 1;
    do {
        printf("Enter pyramid Height (int only): ");

        if (scanf("%d", &pyramidHeight) != 1) {
            // Invalid input -> clear buffer
            char c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            isValidInput = 0;
        }
        else if (pyramidHeight < 1) {
            isValidInput = 0;
        }
        else {
            isValidInput = 1;
        }
    } while (!isValidInput);

    for (int line=1; line <= pyramidHeight; line++){
        // Handle Spacing
        for (int spaces = 0; spaces < pyramidHeight - line; spaces++){
            printf(" ");
        }
        // Handle # printing
        for (int hash = 0; hash < line; hash++){
            printf("#");
        }
        printf("\n");
    }
    
    return 0;
}