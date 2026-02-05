#include <stdio.h>
void PrintArray(int[]);
void main(){
    int array[] = {5,78,3,10,7,21,6,89,3,2};
    printf("Original Array: ");
    PrintArray(array);

    // Insertion Sort
    printf("\nSorting:\n");
    for (int i = 0; i<10; i++){
        int temp = array[i];
        int j = i -1;

        while (j>=0 && array[j] > temp){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;

        PrintArray(array);
    }

    printf("\nSorted: "); PrintArray(array);

}
void PrintArray(int array[]){
    printf("{");
    for (int i = 0; i<10; i++){
        printf("%d, ", array[i]);
    }
    printf("}\n");
}