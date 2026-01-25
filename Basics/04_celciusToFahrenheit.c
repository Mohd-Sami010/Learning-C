#include<stdio.h>

int main(){
    int tempretureInCelcius;

    printf("Enter Tempreture in celcius: ");
    scanf("%d", &tempretureInCelcius);

    float tempretureInFahrenheit = 9.0/5 * tempretureInCelcius +32;
    printf("%d Celcius in Fahrenheit is %f", tempretureInCelcius, tempretureInFahrenheit);
}