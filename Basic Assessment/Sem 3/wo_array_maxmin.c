#include <stdio.h>

int main()
{
    int a, max = 0, min;
    int limit;
    printf("Enter the limit of element : ");
    scanf("%d", &limit);
    int i=1;
    printf("Enter Element 1: ");
    scanf("%d",&max);
    min = max;
    while(i<limit)
    {
        printf("Enter Element %d: ", i+1);
        scanf("%d", &a);
        if(a>max)
        max = a;
        else if(a<min)
        min = a;
        i++;
    }
    printf("%d %d",max,min);

    return 0;
}