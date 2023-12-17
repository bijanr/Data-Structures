#include <stdio.h>


int gcd(int i, int x, int y, int n, int *a);

int main()
{
    int limit, largest;
    printf("Enter the limit of array: ");
    scanf("%d", &limit);
    int array[limit];
    printf("Enter the elements of array: ");
    for(int i = 0; i<limit; i++)
        scanf("%d", &array[i]);
    largest = gcd(1,array[0], array[1], limit, array);
    
    printf("The gcd is %d",largest);
    return 0;
}
/*  i = position of array
    x and y = two numbers which are to be checked for gcd
    */
int gcd(int i, int x, int y, int n, int *a)  {  
    int r = x%y;                    // if 6 and 3 r == 0
    if(r == 0 && i == n-1)          //here r = 0 and 1 = 2-1 return y or 3
        return y;
    else if(r == 0)
        return gcd(i+1, a[i+1], y, n, a);
    return gcd(i,y,r,n,a);      //divisor becomes dividend and remainder becomes divisor

}



