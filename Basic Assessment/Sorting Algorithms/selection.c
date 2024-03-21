#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 100

void input(int *list, int limit);
void selection_sort(int *list, int limit);
void swap(int *a, int *b);
void display(int *list, int limit);


int main(){
    int *list, limit;
    printf("Enter the limit of array: ");
    scanf("%d", &limit);
    list = (int*)calloc(limit, sizeof(int));
    if(limit < 0 || limit > MAX_LIMIT){
        printf("Out of Bound Error.\n");
        return 1;
    }
    input(list, limit);
    display(list, limit);
    return 0;    
}

void input(int *list, int limit){
    printf("Enter the array: ");
    for(int i = 0; i < limit; i++){
        scanf("%d", &list[i]);
    }
}

void selection_sort(int *list, int limit){

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *list, int limit){
    for(int i = 0; i < limit; i++){
        printf("%d ", list[i]);
    }
}