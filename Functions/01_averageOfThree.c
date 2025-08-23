#include<stdio.h>
float CalculateAverage(int, int, int);

float CalculateAverage(int num1, int num2, int num3){
    float average = (num1 + num2 + num3)/3.0;
    return average;
}
int main(){
    int a = 2, b = 4, c = 5;
    printf("Average is %f", CalculateAverage(a,b,c));
}