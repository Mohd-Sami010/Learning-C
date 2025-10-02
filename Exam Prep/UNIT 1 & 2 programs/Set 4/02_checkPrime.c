#include<stdio.h>

int main(){
    int num;
    int isPrime = 1;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 2; i < num; i++){
        if (num % i == 0){
            isPrime = 0;
            break;
        }
    }
    if (isPrime){
        printf("Yes it is Prime number");
    }
    else{
        printf("Not a Prime number");
    }
    return 0;
}