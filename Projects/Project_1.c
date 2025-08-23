#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Initialize randomizer
    srand(time(0));

    int randomNumber =(rand() % 100) + 1;
    int numOfAttempts = 0;
    int enteredNumber;

    while (enteredNumber != randomNumber){
        printf("Guess the number: ");
        scanf("%d", &enteredNumber);

        if (enteredNumber < randomNumber){
            printf("Think Bigger\n");
        }
        else if (enteredNumber > randomNumber){
            printf("Think Smaller\n");
        }
        numOfAttempts++;
    }
    printf("YOU GUESSED THE NUMBER in %d Attempts, XD", numOfAttempts);

    return 0;
}