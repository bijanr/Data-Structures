#include <stdio.h>
#include <stdlib.h>

void input(int *list, int size);
void merge(int *listA, int* listB, int sizeA, int sizeB, int* result);
void display(int *result, int size);
int main (){
    int *listA, *listB, *result, sizeA, sizeB;
    printf("Enter the size of list A: ");
    scanf("%d", &sizeA);
    printf("Enter the size of list B: ");
    scanf("%d", &sizeB);
    listA = (int*)calloc(sizeA, sizeof(int));
    printf("Enter list A: \n");
    input(listA, sizeA);
    listB = (int*)calloc(sizeB, sizeof(int));
    printf("Enter list B: \n");
    input(listB, sizeB);
    result = (int*)calloc(sizeA + sizeB, sizeof(int));
    merge(listA, listB, sizeA, sizeB, result);
    display(result, sizeA+sizeB);
    return 0;
}


void input(int *list, int size){
    for(int i = 0; i < size; i++)
        scanf("%d", list + i);
}

void merge(int *listA, int* listB, int sizeA, int sizeB, int* result){
    int i = 0, j = 0, k = 0;
    while(i < sizeA && j < sizeB){
        if(listA[i] <= listB[j])
            result[k++] = listA[i++];
        else
            result[k++] = listB[j++];
    }
    while(i < sizeA){
        result[k++] = listA[i++];
    }
    while(j < sizeB){
        result[k++] = listB[j++];
    }
}

void display(int *result, int size){
    printf("The merged array is: \n");
    for(int i = 0; i < size; i++)
        printf("%d ", *(result + i));
    printf("\n");
}