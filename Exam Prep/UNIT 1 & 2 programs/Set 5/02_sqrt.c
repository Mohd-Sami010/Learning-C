#include<stdio.h>
#include<math.h>

int main(){
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    float sqrt = pow(num, 0.5);
    printf("Sqrt is %0.2f", sqrt);
    return 0;
}