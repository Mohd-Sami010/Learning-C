#include<stdio.h>

int main(){
    int arr[10];

    // Writing
    for (int i = 0; i < 10; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // Reading
    for (int i = 0; i < 10; i++){
        printf("%d, ", arr[i]);
    }

    printf("\n\n");
    // Maximum, Minimum and Average
    int maxValue = arr[0];
    int minValue = arr[0];

    float average;
    int sumOfElements = 0;

    for (int i = 0; i < 10; i++){
        sumOfElements += arr[i];
        if (arr[i] > maxValue){
            maxValue = arr[i];
        }
        if (arr[i] < minValue){
            minValue = arr[i];
        }
    }
    average = sumOfElements / 10.0;
    
    printf("Maximum value is %d\n",maxValue);
    printf("Minimum value is %d\n",minValue);
    printf("Average is %f",average);
    
    return 0;
}