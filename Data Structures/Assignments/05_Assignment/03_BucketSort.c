#include <stdio.h>

void PrintArray(int array[]){
    for (int i = 0; i < 10; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void InsertionSort(int bucket[], int n){
    for(int i = 1; i < n; i++){
        int key = bucket[i];
        int j = i - 1;

        while(j >= 0 && bucket[j] > key){
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void BucketSort(int array[], int n){
    int bucket[10][10];
    int count[10] = {0};

    // Put elements into buckets
    for(int i = 0; i < n; i++){
        int index = array[i] / 10;   // Range 0–99 assumed
        bucket[index][count[index]++] = array[i];
    }

    // Sort individual buckets
    for(int i = 0; i < 10; i++){
        if(count[i] > 0)
            InsertionSort(bucket[i], count[i]);
    }

    // Merge buckets
    int k = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < count[i]; j++){
            array[k++] = bucket[i][j];
        }
    }
}

int main(){
    int array[] = {29,25,3,49,9,37,21,43,8,15};

    printf("Original Array: ");
    PrintArray(array);

    BucketSort(array, 10);

    printf("Sorted Array: ");
    PrintArray(array);

    return 0;
}