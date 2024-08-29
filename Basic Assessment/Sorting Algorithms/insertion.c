#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 100

void input(int *list, int limit);
void insertionSort(int* list, int limit);
void display(int *list, int limit);

int main()	{
    int limit, *list;
    printf("Enter the limit of list: ");
    scanf("%d", &limit);
    list = (int*)calloc(limit, sizeof(int));
    if(limit <= 0 || limit > MAX_LIMIT || list == NULL){
        printf("Memory buffer exceeded! \n");
        main();
    }
    input(list, limit);
    insertionSort(list, limit);
    display(list, limit);
    return 0;

}

void input(int *list, int limit){
    printf("Enter the list: ");
    for(int i = 0; i < limit; i++)
        scanf("%d", list + i);
}

void insertionSort(int* list, int limit){
    int j;
    for(int i = 0; i < limit; i++){
        int key = *(list + i);
        j = i - 1;
        while(j >= 0 && *(list + j) >= key){    //for ascending order
            *(list + (j+1)) = *(list + j);
            j = j - 1;
        }
        *(list + (j+1)) = key;
    }
}

void display(int* list, int limit){
    printf("The list is: \n");
    for(int i = 0; i < limit; i++)
        printf("%d ", *(list + i));
    printf("\n");
}

