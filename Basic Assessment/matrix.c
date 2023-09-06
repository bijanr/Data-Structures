#include <stdio.h>
#include <stdlib.h>

int** AllocMatrix(int row, int col);

void InputMatrix(int** matrix, int row, int col);

void PrintMatrix(int** matrix, int row, int col);

void AddMatrix(int** matrixA, int** matrixB, int** MatrixC, int rowA, int colA);

int main()
{
    int** matrixB;
    int** matrixC;
    int rowA, rowB, colA, colB;
    printf("Enter the dimensions of Matrix A: ");
    scanf("%d %d", &rowA, &colA);
    int **matrixA = AllocMatrix(rowA, colA);
    InputMatrix(matrixA, rowA, colA);
    PrintMatrix(matrixA, rowA, colA);
    return 0;
}

int** AllocMatrix(int row, int col) {
    int **matrix = (int**)calloc(row, sizeof(int*));
    for(int i = 0; i<row; i++)
        for(int j = 0; j<col; j++)
            matrix[i] = (int*)calloc(col, sizeof(int));
    
}

void InputMatrix(int** matrix, int row, int col) {
    printf("Enter the elements of array: \n");
    for(int i = 0; i<row; i++)
        for(int j = 0; j<col; j++)
            scanf("%d", &matrix[i][j]);
}

void PrintMatrix(int** matrix, int row, int col)    {
    for(int i = 0; i<row; i++)  {
        for(int j = 0;j <col; j++)
            printf("%d", &matrix[i][j]);
        putchar('\n');
    }
}