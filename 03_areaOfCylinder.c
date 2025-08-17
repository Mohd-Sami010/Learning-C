#include <stdio.h>

int main(){
    float cylinderRadius;
    float cylinderHeight;

    printf("Enter Radius: ");
    scanf("%f", &cylinderRadius);

    printf("Enter Height: ");
    scanf("%f",&cylinderHeight);

    float cylinderArea = 3.14 * cylinderRadius * cylinderRadius * cylinderHeight;
    printf("Area of Cylinder: %f",cylinderArea);
}