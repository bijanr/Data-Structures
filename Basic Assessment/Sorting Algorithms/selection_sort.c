// in Selection sort we select an element from the INDEX and compare it with the next Least element (m,inimum element )
// suppose we have [9,2,5,6,7,1,10] here we have to compare 9[i=0 index] with least element [min ] compared to 9

#include <stdio.h>

void inputArray(int arr[], int n);
void swap(int *xp, int *yp); 
void selectionSort(int arr[], int n);
void printArray(int arr[], int size);

int main()
{
	int limit;
	printf("Enter the limit: ");
	scanf("%d", &limit);
	int arr[limit];

    inputArray(arr, limit);
	selectionSort(arr, limit);
	printArray(arr, limit);
	return 0;
}


void inputArray(int arr[], int n){
    printf("Enter the array: ");
		for(int i = 0; i<n; i++)
			scanf("%d", &arr[i]);
}
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min;

	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min])
			min = j;
		if(min != i)
			swap(&arr[min], &arr[i]);
	}
}

void printArray(int arr[], int size)
{
    printf("Sorted array: \n");
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}




