//works until the elements are smaller in the left and greater in the right
// put a pivot at the end of array and use i and j element and works only if j< pivot then compares i+1 with j; runs until j<pivot
//pivot is now set to i+1 element and the same run is done for all the partitions made [ using divide and conquer]

#include <stdio.h>  

void inputArray(int arr[], int n);
int partition (int a[], int start, int end);
void quick(int a[], int start, int end);
void printArr(int a[], int n);

int main()  
{  
    int limit;
	printf("Enter the limit: ");
	scanf("%d", &limit);
	int arr[limit];
    inputArray(arr, limit); 
    printArr(arr, limit);  
    quick(arr, 0, limit - 1); 
    printArr(arr, limit);  
      
    return 0;  
} 

void inputArray(int arr[], int n)
{
	printf("Enter the array: ");
		for(int i = 0; i<n; i++)
			scanf("%d", &arr[i]);
}

int partition (int a[], int start, int end)  {  
    int pivot = a[end]; 
    int i = (start - 1);  
    for (int j = start; j <= end - 1; j++)  {  
        if (a[j] < pivot)  {  
            i++; 
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  

void quick(int a[], int start, int end) {  
    if (start < end)  {  
        int p = partition(a, start, end);  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  
  
void printArr(int a[], int n)  {  
    printf("\n Sorted array - \n");  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
