#include <stdio.h>
#include <stdlib.h>

void PrintArray(int array[]){
    for (int i = 0; i < 10; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void CountingSort(int array[], int n){
    int max = array[0];

    // Find maximum element
    for(int i = 1; i < n; i++){
        if(array[i] > max)
            max = array[i];
    }

    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initialize count array
    for(int i = 0; i <= max; i++)
        count[i] = 0;

    // Store frequency
    for(int i = 0; i < n; i++)
        count[array[i]]++;

    // Reconstruct sorted array
    int index = 0;
    for(int i = 0; i <= max; i++){
        while(count[i] > 0){
            array[index++] = i;
            count[i]--;
        }
    }

    free(count);
}

int main(){
    int array[] = {5,7,3,1,4,2,6,9,8,0};

    printf("Original Array: ");
    PrintArray(array);

    CountingSort(array, 10);

    printf("Sorted Array: ");
    PrintArray(array);

    return 0;
}