#include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowA, int colA, int rowB, int colB, int i, int j, int k) {
    if (i >= rowA) {
        return;
    }

    if (j < colB) {
        if (k < colA) {
            result[i][j] += a[i][k] * b[k][j];
            multiplyMatrices(a, b, result, rowA, colA, rowB, colB, i, j, k + 1);
        } else {
            multiplyMatrices(a, b, result, rowA, colA, rowB, colB, i, j + 1, 0);
        }
    } else {
        multiplyMatrices(a, b, result, rowA, colA, rowB, colB, i + 1, 0, 0);
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowA, colA, rowB, colB;

    // Input dimensions of matrices A and B
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowA, &colA);

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowB, &colB);

    if (colA != rowB) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    // Input elements of matrix A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Input elements of matrix B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Initialize result matrix with zeros
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            result[i][j] = 0;
        }
    }

    // Multiply matrices using pure recursion
    multiplyMatrices(matrixA, matrixB, result, rowA, colA, rowB, colB, 0, 0, 0);

    // Display the result matrix
    printf("Resultant Matrix:\n");
    displayMatrix(result, rowA, colB);

    return 0;
}
