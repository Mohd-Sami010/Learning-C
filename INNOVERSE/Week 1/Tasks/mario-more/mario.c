#include<stdio.h>

int main(){
    int pyramidHeight;
    printf("Enter pyramid Height (int only): ");

    if (scanf("%d", &pyramidHeight) != 1) {
        printf("Characters Not Allowed");
        return 0;
    }
    else if (pyramidHeight < 1 || pyramidHeight > 8){
        printf("Enter a number between 1 to 8 only!!");
        return 0;
    }

    for (int line=1; line <= pyramidHeight; line++){
        // Handle Spacing
        for (int spaces = 0; spaces < pyramidHeight - line; spaces++){
            printf(" ");
        }
        // Handle # printing
        for (int hash = 0; hash < line; hash++){
            printf("#");
        }
        printf("  ");

        // Handle second # pattern
        for (int hash = 0; hash < line; hash++){
            printf("#");
        }
        printf("\n");
    }
    
    return 0;
}