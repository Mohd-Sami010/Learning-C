#include<stdio.h>
float Pow(float, int);
int main(){
    float num = 4;
    int power = 3;

    printf("%f^%d: %0.2f", num, power, Pow(num, power));
    return 0;
}
float Pow(float num, int power){
    float result = 1;
    for (int i = 0; i < power; i++){
        result *= num;
    }
    return result;
}