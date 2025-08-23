#include<stdio.h>
float ConvertCelciusToFahrenheit(int); // This line is Function prototype.

float ConvertCelciusToFahrenheit(int tempretureInCelcius){
    float tempretureInFahrenheit = 9.0/5*tempretureInCelcius +32.0;
    return tempretureInFahrenheit;
}
int main(){
    int tempInCelcius = 10;

    printf("%dC in Fahrenhiet is %fF", tempInCelcius, ConvertCelciusToFahrenheit(tempInCelcius));
    
}