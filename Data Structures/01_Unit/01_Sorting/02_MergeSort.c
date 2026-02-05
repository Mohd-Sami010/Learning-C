#include <stdio.h>
void PrintArray(int[]);
void PrintArray(int array[]){
    for (int i = 0; i<10; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}
void Merge(int array1[], int mid, int low, int high){
    int i, j, k, array2[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high){
        if (array1[i] < array1[j]){
            array2[k] = array1[i];
            i++; k++;
        }
        else{
            array2[k] = array1[j];
            j++; k++;
        }
    }
    while (i<=mid){
        array2[k] = array1[i];
        i++; k++;
    }
    while (j<=high){
        array2[k] = array1[j];
        j++; k++;
    }
    for (int i = low; i<= high; i++){
        array1[i] = array2[i];
    }
    PrintArray(array1);
}
void MergeSort(int array[], int low, int high){
    int mid;
    if (low < high){
        mid = (low + high)/2;
        MergeSort(array, low, mid);
        MergeSort(array, mid+1, high);
        Merge(array, mid, low, high);
    }
}

void main(){
    int array[] = {5,78,3,10,7,21,6,89,3,2};
    printf("Original Array: "); PrintArray(array);

    printf("\nSorting Array:\n");
    MergeSort(array, 0, 9);

    printf("\nSorted Array: "); PrintArray(array);
}
