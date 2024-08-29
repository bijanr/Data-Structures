#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 100

int* alloc(int limit);  // used for allocating memory for the list 
int* input(int limit);  // used for taking input from the user
void sort(int *list, int limit);    // selection sort method
void swap(int *a, int *b);      // used for swapping two elements
int search(int* list, int key, int limit);  // binary serach method
void display(int* list, int limit);     // optional method for displaying 

int main(){
    int* list, limit, key ;
    char check;
    printf("Enter the limit of array: ");
    scanf("%d", &limit);
    if(limit <= 0 || limit > MAX_LIMIT) {   // exception for incorrect input
        printf("Maximum size exceeded. \n");
        return 1;
    }
    list = alloc(limit);
    if(list == NULL)   {
        printf("Memory allocation failed.\n");
        return 0;
    }
 
    list = input(limit);    //taking input
    printf("Enter the value to find: \n");
    scanf("%d", &key);
    sort(list, limit);
    printf("Want to display the list: \n");
    scanf("%d", )
    display(list, limit);
    int keySearch = search(list, key, limit);   //storing the status of finding the element inside the list
    (keySearch == -1)? printf("Element not found.\n") : printf("ELement %d is located at %d\n", key, keySearch+1);
    return 0;
}

int* alloc(int limit)   {   
    return (int*)calloc(limit, sizeof(int));
}


int* input(int limit){
    int* array = alloc(limit);
    printf("Enter the elements of list: \n");
    for(int i = 0; i < limit; i++)
        scanf("%d", &array[i]);
    return array;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *list, int limit){
    int min;
    for(int i = 0; i < limit - 1; i++)  {
        min = i;
        for(int j = i+1; j < limit; j++){
            if(list[j] < list[min])
                min = j;
        }
        if(min != i)
            swap(&list[min], &list[i]);
    }
}


int search(int* list, int key, int limit) {
    int lowerBound  = 0, upperBound = limit - 1;
    while(lowerBound <= upperBound){
        int middle = (lowerBound + upperBound) / 2;
        if(list[middle] == key)
            return middle;
        else if(list[middle] < key)
            lowerBound = middle + 1;
        else if(list[middle] > key)
            upperBound =middle - 1;
        else
            return -1;

    } 
}

void display(int *list, int limit)   {
    printf("The sorted array is: \n");
    for(int i = 0; i < limit; i++)
        printf("%d ", list[i]);
    putchar('\n');
}