#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void ConvertToSparse(int rows, int cols, int matrix[rows][cols], int sparse[MAX][3]) {
    int k = 1;
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;
}

void DisplaySparse(int sparse[MAX][3]) {
    int n = sparse[0][2] + 1;
    for(int i = 0; i < n; i++)
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}

void Transpose(int sparse[MAX][3], int result[MAX][3]) {
    int n = sparse[0][2];

    result[0][0] = sparse[0][1];
    result[0][1] = sparse[0][0];
    result[0][2] = n;

    int k = 1;

    for(int col = 0; col < sparse[0][1]; col++) {
        for(int i = 1; i <= n; i++) {
            if(sparse[i][1] == col) {
                result[k][0] = sparse[i][1];
                result[k][1] = sparse[i][0];
                result[k][2] = sparse[i][2];
                k++;
            }
        }
    }
}

void AddSparse(int A[MAX][3], int B[MAX][3], int result[MAX][3]) {

    int i = 1, j = 1, k = 1;
    result[0][0] = A[0][0];
    result[0][1] = A[0][1];

    while(i <= A[0][2] && j <= B[0][2]) {
        if(A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if(A[i][0] < B[j][0] || 
               (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++; k++;
        }
        else {
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++; k++;
        }
    }

    while(i <= A[0][2]) {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++; k++;
    }

    while(j <= B[0][2]) {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++; k++;
    }

    result[0][2] = k - 1;
}

void MultiplySparse(int A[MAX][3], int B[MAX][3], int result[MAX][3]) {
    int temp[MAX][MAX] = {0};

    for(int i = 1; i <= A[0][2]; i++) {
        for(int j = 1; j <= B[0][2]; j++) {
            if(A[i][1] == B[j][0]) {
                temp[A[i][0]][B[j][1]] += A[i][2] * B[j][2];
            }
        }
    }

    int k = 1;
    result[0][0] = A[0][0];
    result[0][1] = B[0][1];

    for(int i = 0; i < result[0][0]; i++) {
        for(int j = 0; j < result[0][1]; j++) {
            if(temp[i][j] != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = temp[i][j];
                k++;
            }
        }
    }

    result[0][2] = k - 1;
}

int main() {

    int matrixA[3][3] = {
        {0, 0, 3},
        {4, 0, 0},
        {0, 5, 0}
    };

    int matrixB[3][3] = {
        {0, 2, 0},
        {0, 0, 6},
        {7, 0, 0}
    };

    int sparseA[MAX][3], sparseB[MAX][3];
    int transposeA[MAX][3], sum[MAX][3], product[MAX][3];

    ConvertToSparse(3, 3, matrixA, sparseA);
    ConvertToSparse(3, 3, matrixB, sparseB);

    printf("Sparse Matrix A:\n");
    DisplaySparse(sparseA);

    printf("\nSparse Matrix B:\n");
    DisplaySparse(sparseB);

    Transpose(sparseA, transposeA);
    printf("\nTranspose of A:\n");
    DisplaySparse(transposeA);

    AddSparse(sparseA, sparseB, sum);
    printf("\nAddition (A + B):\n");
    DisplaySparse(sum);

    MultiplySparse(sparseA, sparseB, product);
    printf("\nMultiplication (A x B):\n");
    DisplaySparse(product);

    return 0;
}
