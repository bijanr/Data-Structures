#include <stdio.h>
#include <stdlib.h>



int main(){
    int *list, limit, value;
    printf("Enter the limit of list: ");
    scanf("%d", &limit);
    list = (int*)calloc(limit, sizeof(limit));
    printf("Enter the list: \n");
    for(int i = 0; i < limit; i++){
        scanf("%d", list[i]);
    }

    printf("Enter the element to search : \n");
    scanf("%d", &value);
    for(int i = 0; i < limit; i++){
        if(value == list[i]){
            printf("Element found at index %d\n", i);
            break;
        }
    }
    return 0;
}