/*1. Start
2. input(list)
3. for(i = 1 to n - 1; step by 1)
    min = i
    for(j = i+1 to n; step by 1)
        if(list[j] < list[min])
            min = j
    if(min != i)
        swap(list[min], list[i])
4. Stop */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void input(int *list, int limit);

void display(int *list, int limit);

int main(){
    int *list, limit;
    printf("Enter the limit of list : ");
    scanf("%d", &limit);
    list = (int*)calloc(limit , sizeof(int));
    input(list, limit);
    sort(list, limit);
    display(list, limit);
    return 0;
}

void input(int *list, int limit){
    printf("Enter the elements : \n");
    for(int i = 0; i < limit; i++)
        scanf("%d", &(list[i]));
}



void display(int *list, int limit)   {
    printf("The sorted array is: \n");
    for(int i = 0; i < limit; i++)
        printf("%d ", list[i]);
    putchar('\n');
}