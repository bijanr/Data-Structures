#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 100

int *alloc(int limit);
void inputArray(int* array, int limit);
void sort(int* array, int limit);
void swap(int *num1, int *num2);
void displayArray(int* array, int limit);
void freeArray(int* array);

int main(){
    int limit, *array;
    printf("Enter the limit of array (up to %d): ", MAX_LIMIT);
    scanf("%d", &limit);
    if(limit <= 0 || limit > 100){
        printf("Maximum size exceeded!\n");
        return 1;
    }
    array = alloc(limit);
    if(array == NULL){
        printf("Allocation failed!\n");
        return 1;
    }
    inputArray(array, limit);
    sort(array, limit);
    displayArray(array, limit);
    freeArray(array);
    return 0;
}

int *alloc(int limit){
    return (int*)calloc(limit, sizeof(int));
}

void inputArray(int* array, int limit){
    printf("Enter the array: \n");
    for(int i = 0; i < limit; i++){
        scanf("%d", &array[i]);
    }
}

void sort(int* array, int limit){
    for(int i = 0; i < limit - 1; i++){
        for(int j = 0; j < (limit - i - 1); j++){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void swap(int *num1, int *num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void displayArray(int* array, int limit){
    printf("The sorted array is: \n");
    for(int i = 0; i < limit; i++){
        printf("%d ", array[i]);
    }
    putchar('\n');
}

void freeArray(int* array){
    free(array);
}