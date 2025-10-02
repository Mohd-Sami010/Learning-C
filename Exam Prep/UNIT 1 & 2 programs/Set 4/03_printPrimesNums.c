#include<stdio.h>
int IsPrimeNumber(int);
int main(){
    int range;
    printf("Enter range 2 to ");
    scanf("%d", &range);
    for (int i = 2; i <= range; i++){
        if (IsPrimeNumber(i)){
            printf("%d\n", i);
        }
    }
    return 0;
}
int IsPrimeNumber(int num){
    for (int i = 2; i < num; i++){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}