#include <stdio.h>

void PrintArray(int array[]){
    for (int i = 0; i < 10; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int GetMax(int array[], int n){
    int max = array[0];
    for(int i = 1; i < n; i++){
        if(array[i] > max)
            max = array[i];
    }
    return max;
}

void CountSort(int array[], int n, int exp){
    int output[10];
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(array[i]/exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for(int i = n-1; i >= 0; i--){
        output[count[(array[i]/exp) % 10] - 1] = array[i];
        count[(array[i]/exp) % 10]--;
    }

    for(int i = 0; i < n; i++)
        array[i] = output[i];
}

void RadixSort(int array[], int n){
    int max = GetMax(array, n);

    for(int exp = 1; max/exp > 0; exp *= 10)
        CountSort(array, n, exp);
}

int main(){
    int array[] = {170,45,75,90,802,24,2,66,501,33};

    printf("Original Array: ");
    PrintArray(array);

    RadixSort(array, 10);

    printf("Sorted Array: ");
    PrintArray(array);

    return 0;
}