#include <stdio.h>

void PrintArray(int array[]){
    for (int i = 0; i < 10; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void Heapify(int array[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    int temp;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i){
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        Heapify(array, n, largest);
    }
}

void HeapSort(int array[], int n){
    int temp;

    // Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--)
        Heapify(array, n, i);

    // Extract elements
    for (int i = n-1; i >= 0; i--){
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        Heapify(array, i, 0);
    }
}

int main(){
    int array[] = {5,78,3,10,7,21,6,89,3,2};
    printf("Original Array: "); 
    PrintArray(array);

    HeapSort(array, 10);

    printf("Sorted Array: "); 
    PrintArray(array);

    return 0;
}