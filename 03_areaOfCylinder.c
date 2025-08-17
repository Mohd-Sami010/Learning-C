#include <stdio.h>

int main(){
    int cylinderRadius;
    int cylinderHeight;

    printf("Enter Radius: ");
    scanf("%d", &cylinderRadius);

    printf("Enter Height: ");
    scanf("%d",&cylinderHeight);

    float cylinderArea = 3.14 * cylinderRadius * cylinderRadius * cylinderHeight;
    printf("Area of Cylinder with radius %d and height %d is %f",cylinderRadius,cylinderHeight,cylinderArea);
}