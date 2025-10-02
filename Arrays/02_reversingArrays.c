#include<stdio.h>
void reverse(int arr[], int n){
    int temp;
    for (int i = 0;i < n/2; i++){
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n -i -1] = temp;
    }
}
int main(){
    int arr1[] = {1 , 4, 6, 7, 8, 10, 12};
    int reverseArr[7];

    reverse(arr1, 7);

    for (int i = 0; i < 7; i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}