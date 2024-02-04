#include <stdio.h>
#include <stdlib.h>

int** create(int row, int col);
void display(int** , int row, int col);
void free_matrix(int** , int row);

int main(){
    int row, col;
    printf("Enter the rows and columns: ");
    scanf("%d %d", &row, &col);
    int ** matrix= create(row, col);
    display(matrix, row, col);
    return 0;
}

int** create(int row, int col){
    int** matrix = (int**)calloc(row, sizeof(int*));
    for(int i = 0; i < row; i++)
        matrix[i] = (int*)calloc(col, sizeof(int));
    printf("Enter the matrix: \n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("Element %d %d: ", (i+1), (j+1));
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

void display(int** matrix, int row, int col){
    printf("The elements are: \n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d   ", matrix[i][j]);
        }
        putchar('\n');
    }
}

void free_matrix(int** matrix, int row){
    for(int i = 0; i < row; i++){
        free(matrix[i]);
    }
    free(matrix);
}