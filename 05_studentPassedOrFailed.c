#include<stdio.h>



int main(){

    const int NUM_OF_SUBJECTS = 3;
    const int MAX_MARKS = 100;
    const float TOTAL_PASS_PERCENTAGE = 40.0;
    const int PASS_PERCENTAGE = 33;

    int marksInSubject1;
    int marksInSubject2;
    int marksInSubject3;

    printf("Enter marks of Subject 1: ");
    scanf("%d", &marksInSubject1);

    printf("Enter marks of Subject 2: ");
    scanf("%d",&marksInSubject2);

    printf("Enter marks of Subject 3: ");
    scanf("%d", &marksInSubject3);


    float totalPercentage = (marksInSubject1 + marksInSubject2 + marksInSubject3)/NUM_OF_SUBJECTS *100;
    if (totalPercentage < TOTAL_PASS_PERCENTAGE){
        printf("Your total percantage is %f, YOU FAILED THE EXAM!", totalPercentage);
    }
    else if (marksInSubject1 < PASS_PERCENTAGE || marksInSubject2 < PASS_PERCENTAGE || marksInSubject3 <PASS_PERCENTAGE){
        printf("YOU FAILED THE EXAM");
    }
    else{
        printf("YOU PASSED THE EXAM");
    }
}