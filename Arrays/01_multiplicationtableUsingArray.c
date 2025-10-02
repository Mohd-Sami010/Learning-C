#include<stdio.h>

int main(){
    int arr[10];
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    for (int i = 0; i < 10; i++){
        arr[i] = number * (i+1);
    }
    for (int i = 0; i <10; i++){
        printf("%d * %d = %d\n",number, i +1, arr[i]);
    }
    return 0;
}