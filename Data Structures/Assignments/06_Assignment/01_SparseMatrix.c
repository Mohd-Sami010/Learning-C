#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_ROWS 3
#define NUM_OF_COLUMNS 4
#define NUM_OF_NON_ZERO_ELEMENTS 4

int main(){
    int matrixA[NUM_OF_ROWS][NUM_OF_COLUMNS] = {{0, 0, 1, 0}, {0, 2, 0, 9}, {0, 0, 0, 4}};

    printf("Normal Form:\n");
    for (int i = 0; i < NUM_OF_ROWS; i++){
        for (int j = 0; j < NUM_OF_COLUMNS; j++){
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    // ---------- Convert to Sparse -------------------

    int sparseOfA[NUM_OF_NON_ZERO_ELEMENTS][3];
    int i = 0;
    // int i = 1;
    // sparseOfA[0][0] = NUM_OF_ROWS;
    // sparseOfA[0][1] = NUM_OF_COLUMNS;
    // sparseOfA[0][2] = NUM_OF_NON_ZERO_ELEMENTS;

    for (int j =0; j < NUM_OF_ROWS; j++){
        for (int k = 0; k < NUM_OF_COLUMNS; k++){
            if (matrixA[j][k] != 0){

                sparseOfA[i][0] = j;
                sparseOfA[i][1] = k;
                sparseOfA[i][2] = matrixA[j][k];
                i++;
            }
        }
    }

    printf("Sparse Form:\n");
    for (int i = 0; i < NUM_OF_NON_ZERO_ELEMENTS; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", sparseOfA[i][j]);
        }
        printf("\n");
    }
    

    // ---------------- Transpose -----------------
    int transposeOfSparseA[NUM_OF_NON_ZERO_ELEMENTS][3];
    for (int i = 0; i < NUM_OF_NON_ZERO_ELEMENTS; i++){
        transposeOfSparseA[i][0] = sparseOfA[i][1];
        transposeOfSparseA[i][1] = sparseOfA[i][0];
        transposeOfSparseA[i][2] = sparseOfA[i][2];

        for (int j = i; j > 0; j--){
            if (transposeOfSparseA[j][0] < transposeOfSparseA[j-1][0]){
                int temp[3];
                for (int k = 0; k < 3; k++){
                    temp[k] = transposeOfSparseA[j][k];
                    transposeOfSparseA[j][k] = transposeOfSparseA[j-1][k];
                    transposeOfSparseA[j-1][k] = temp[k];
                }
            }
        }
    }
    
    printf("Transpose of Sparse Form:\n");
    for (int i = 0; i < NUM_OF_NON_ZERO_ELEMENTS; i++){ 
        for (int j = 0; j < 3; j++){
            printf("%d ", transposeOfSparseA[i][j]);
        }
        printf("\n");
    }
}