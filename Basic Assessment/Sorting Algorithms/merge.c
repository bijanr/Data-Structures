#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 100

void mergeSort(int *list, int lowerBound, int upperBound);
void merge(int *list, int lowerBound, int middle, int upperBound);
void input(int *list, int limit);
void display(int *list, int limit);

int main(){
    int limit, *list;
    printf("Enter the limit of array: ");
    scanf("%d", &limit);
    list = (int*)calloc(limit, sizeof(int));
    if(limit <= 0 || limit > MAX_LIMIT || list == NULL){
        printf("Memory buffer exceeded! \n");
        main();
    }
    input(list, limit);
    mergeSort(list, 0, limit - 1);
    
}

void input(int *list, int limit){
    printf("Enter the list: \n");
    for(int i = 0; i < limit; i++)
        scanf("%d", list + i);
}

void mergeSort(int *list, int lowerBound, int upperBound){
    if(lowerBound < upperBound){
        int middle = (lowerBound + upperBound) / 2;
        mergeSort(list, lowerBound, middle);
        mergeSort(list, middle + 1, upperBound);
        merge(list, lowerBound, middle, upperBound);
    }
}


void merge(int *list, int lowerBound, int middle, int upperBound){
    int i = lowerBound, j = middle + 1, k = lowerBound;
    int *sortedList = (int*)calloc(upperBound + 1, sizeof(int));
    while(i <= middle && j <= upperBound){
        if(list[i] <= list[j]){
            sortedList[k] = list[i];
            i++;
        }
        else{
            sortedList[k] = list[j];
            j++;
        }
        k++;
    }
    
    display(sortedList, upperBound + 1);
}

void display(int *list, int limit){
    for(int i = 0; i < limit; i++)
        printf("%d ", *(list + i));
    printf("\n");
}