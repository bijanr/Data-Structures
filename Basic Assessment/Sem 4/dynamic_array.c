#include <stdio.h>
#include <stdlib.h>

int* alloc(int limit);
void input(int* array, int limit);
void display(int* array, int limit);
int main(){
    int *array, limit;
    printf("Enter the limit of array: ");
    scanf("%d", &limit);
    array = alloc(limit);
    input(array, limit);
    display(array, limit);
    free(array);
    return 0;
}

int* alloc(int limit){
    return (int*)calloc(limit, sizeof(int));
}
void input(int* array, int limit){
    printf("Enter the elements: ");
    for(int i = 0; i < limit; i++)
        scanf("%d", &(*(array + i)));
}
void display(int* array, int limit){
    for(int i = 0; i < limit; i++)
        printf("%d ", *(array + i));
    putchar('\n');
}
