#include <stdio.h>

void PrintArray(int arr[]){
    for (int i = 0; i <10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    
    int data[] = {2, 1, 6, 8, 21, 4, 6, 53, 3, 54};
    PrintArray(data);
    
    for (int i = 1; i< 10; i++){
        int temp = data[i];

        int positionAt = i;
        for (int j = i-1; data[j] > temp && j >=0; j--){
            data[j+1] = data[j];
            positionAt = j;
        }
        data[positionAt] = temp;
    }

    PrintArray(data);

    return 0;
}