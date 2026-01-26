#include<stdio.h>
int SumOfNumbers(int);

int SumOfNumbers(int n){
    if (n == 0) return 0;
    return n + SumOfNumbers(n-1);
}
int main(){
    int n = 10;
    printf("The Sum of %d natural numbers is %d", n, SumOfNumbers(n));
}