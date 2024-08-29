#include <stdio.h>
#include <stdlib.h>

void input(int* list, int size);
void mergeSort(int* list, int left, int right);
void merge(int* list, int left, int middle, int right);
void display(int* list, int size);

int main(){
    int* list, size;
    printf("Enter the size of list: ");
    scanf("%d", &size);
    list = calloc(size, sizeof(int));
    input(list, size);
    mergeSort(list, 0, size - 1);
    display(list, size);

}

void input(int* list, int size){
    printf("Enter the list: ");
    for(int i = 0; i < size; i++)
        scanf("%d", list + i);
}

void mergeSort(int* list, int left, int right){
    if(left < right){
        int middle = (left + right) / 2;
        mergeSort(list, left, middle);
        mergeSort(list, middle + 1, right);
        merge(list, left, middle, right);
    }
}

void merge(int* list, int left, int middle, int right){
    int i = 0, j = 0, k = 0;
    int sizeA = middle - left + 1;
    int sizeB = right - middle;
    //allocating two new lists for merging
    int *listA = calloc(sizeA, sizeof(int));
    int *listB = calloc(sizeB, sizeof(int));
    //filling up the two lists with existing values from list
    for(int i = 0; i < sizeA; i++)
        *(listA + i) = *(list + (left + i));
    for(int j = 0; j < sizeB; j++)
        *(listB + j) = *(list + (middle + 1 + j));
    i = 0, j = 0, k = left;
    //comparing and merging sorted arrays
    while(i < sizeA && j < sizeB){
        if(*(listA + i) < *(listB + j))
            list[k++] = listA[i++];
        else
            list[k++] = listB[j++];
    }
    //remaining elements filled uo
    while(i < sizeA)
        list[k++] = listA[i++];
    while(j < sizeB)
        list[k++] = listB[j++];
}

void display(int* list, int size){
    printf("The sorted list is: ");
    for(int i = 0; i < size; i++)
        printf("%d ", *(list + i));
}