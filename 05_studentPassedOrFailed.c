#include<stdio.h>

int main(){
    int marksInSubject1;
    int marksInSubject2;
    int marksInSubject3;

    printf("Enter marks of Subject 1: ");
    scanf("%d", &marksInSubject1);

    printf("Enter marks of Subject 2: ");
    scanf("%d",&marksInSubject2);

    printf("Enter marks of Subject 2: ");
    scanf("%d", &marksInSubject3);


    float totalPercentage = (marksInSubject1 + marksInSubject2 + marksInSubject3)/300.0 *100;
    if (totalPercentage < 40.0){
        printf("Your total percantage is %f, YOU FAILED THE EXAM!", totalPercentage);
    }
    else if (marksInSubject1 < 33 || marksInSubject2 < 33 || marksInSubject3 < 33){
        printf("YOU FAILED THE EXAM");
    }
    else{
        printf("YOU PASSED THE EXAM");
    }
}