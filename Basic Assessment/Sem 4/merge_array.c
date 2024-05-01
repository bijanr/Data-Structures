#include <stdio.h>
#include <stdlib.h>

int merge(int *listA, int* listB, int sizeA, int sizeB, int* result);

int main (){
    int *listA, *listB, *result, sizeA, sizeB;
    printf("Enter the size of list A: ");
    scanf("%d", &sizeA);
    printf("Enter the size of list B: ");
    scanf("%d", &sizeB);
    listA = (int*)calloc(sizeA, sizeof(int));
    listB = (int*)calloc(sizeB, sizeof(int));
    result = (int*)calloc(sizeA + sizeB, sizeof(int));
    merge(listA, listB, sizeA, sizeB, result);
    

    return 0;
}