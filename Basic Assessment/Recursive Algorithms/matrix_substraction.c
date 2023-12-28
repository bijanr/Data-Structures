#include <stdio.h>

#define MAX_SIZE 10

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols, int i, int j) {
    if (i == rows) {
        return;
    }

    if (j == cols) {
        subtractMatrices(a, b, result, rows, cols, i + 1, 0);
    } else {
        result[i][j] = a[i][j] - b[i][j];
        subtractMatrices(a, b, result, rows, cols, i, j + 1);
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
    int rows, cols;

    // Input dimensions of matrices A and B
    printf("Enter the number of rows and columns for matrices: ");
    scanf("%d %d", &rows, &cols);

    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    // Input elements of matrix A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Input elements of matrix B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Initialize result matrix with zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
        }
    }

    // Subtract matrices using pure recursion
    subtractMatrices(matrixA, matrixB, result, rows, cols, 0, 0);

    // Display the result matrix
    printf("Resultant Matrix:\n");
    displayMatrix(result, rows, cols);

    return 0;
}
