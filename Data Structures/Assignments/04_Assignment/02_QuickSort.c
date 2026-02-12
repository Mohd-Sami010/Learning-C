#include <stdio.h>

void PrintArray(int array[]){
    for (int i = 0; i < 10; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int Partition(int array[], int low, int high){
    int pivot = array[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (1){
        while (i <= high && array[i] <= pivot)
            i++;

        while (array[j] > pivot)
            j--;

        if (i < j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        else{
            temp = array[low];
            array[low] = array[j];
            array[j] = temp;
            return j;
        }
    }
}

void QuickSort(int array[], int low, int high){
    int partitionIndex;
    if (low < high){
        partitionIndex = Partition(array, low, high);
        QuickSort(array, low, partitionIndex - 1);
        QuickSort(array, partitionIndex + 1, high);
    }
}

int main(){
    int array[] = {5,78,3,10,7,21,6,89,3,2};
    printf("Original Array: "); 
    PrintArray(array);

    QuickSort(array, 0, 9);

    printf("Sorted Array: "); 
    PrintArray(array);

    return 0;
}