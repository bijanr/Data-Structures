#include <stdio.h>

int gcd(int num1, int num2);

int main()
{
    int limit, largest;
    printf("Enter the limit of array: ");
    scanf("%d", &limit);
    int array[limit];
    printf("Enter the elements of array: ");
    for(int i = 0; i<limit; i++)
        scanf("%d", &array[i]);
    for(int i = 0; i<limit-1; i++)
        largest = gcd(array[i], array[i+1]);
    
    printf("The gcd is %d",largest);
    return 0;
}

int gcd(int num1, int num2)
{
    if(num2 != 0)
        return gcd(num2, num1 % num2);
    else
        return num1;
}


