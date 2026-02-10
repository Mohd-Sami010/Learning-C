#include <stdio.h>

void PrintArray(int arr[]){
    for (int i = 0; i <10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){

    int data[] = {32, 56, 21, 4, 1, 56, 2, 5, 3, 21};
    PrintArray(data);

    for (int i = 0; i<9; i++){
        int minValueAt= i;
        for (int j = i+1; j < 10; j++){
            if (data[j] < data[minValueAt]){
                minValueAt = j;
            }
        }
        int temp = data[i];
        data[i] = data[minValueAt];
        data[minValueAt] = temp;
    }
    PrintArray(data);

    return 0;
}