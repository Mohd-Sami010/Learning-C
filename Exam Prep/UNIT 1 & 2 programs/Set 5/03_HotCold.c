#include<stdio.h>

int main(){
    const float MIN_HOT_TEMPRETURE = 20.0;
    float tempreture;
    printf("Enter tempreture in Celcius: ");
    scanf("%f", &tempreture);

    if (tempreture > MIN_HOT_TEMPRETURE){
        printf("Thats HOT!");
    }
    else{
        printf("Thats COLD!");
    }
    return 0;
}