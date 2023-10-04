#include <stdio.h>

int main()
{
    int limit,temp;
    printf("Enter the limit of array : ");
    scanf("%d",&limit);
    int ascending[limit];
    int descending[limit];
    printf("Enter Elements: ");
    for(int i = 0;i<limit; i++)
    {
        scanf("%d",&ascending[i]);
        descending[i] = ascending[i];
    }

    for(int i = 0;i<limit-1; i++)
    {
        for(int j = 0; j<limit-i-1; j++)
        {
            if(ascending[j]>ascending[j+1])
            {
                temp = ascending[j];
                ascending[j] = ascending[j+1];
                ascending[j+1] = temp;
            }

            if(descending[j]<descending[j+1])
            {
                temp = descending[j];
                descending[j] = descending[j+1];
                descending[j+1] = temp;
            }
        }
    } //sorting
    printf("The array in ascending order: \n");
    for(int i = 0;i<limit; i++)
    {
        printf("%d ",ascending[i]);
    }
    printf("\nThe array in descending order: \n");
    for(int i = 0;i<limit; i++)
    {
        printf("%d ",descending[i]);
    }
    return 0;
}