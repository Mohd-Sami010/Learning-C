#include <stdio.h>

int main(){
    float rectLenth = 5;
    float rectBredth = 6;

    printf("Enter rectangle lenth:");
    scanf("%f", &rectLenth);

    printf("Enter rectangle bredth: ");
    scanf("%f", &rectBredth);

    float rectArea = rectLenth * rectBredth;
    printf("Area of rectangle is %f", rectArea);
}