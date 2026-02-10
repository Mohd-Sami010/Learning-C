#include <stdio.h>

void PrintArray(int arr[]){
    for (int i = 0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){

    int data[] = {2, 45, 12, 3, 4, 5, 63, 21, 22, 33};
    PrintArray(data);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10- i -1; j++){
            if (data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    PrintArray(data);
    return 0;
}