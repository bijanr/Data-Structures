// in Insertion sort, the current element is compared with the last element(s) until 0 th location
#include <stdio.h>

void inputArray(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
	int limit;
	printf("Enter the limit: ");
	scanf("%d", &limit);
	int arr[limit];
    inputArray(arr, limit);
	insertionSort(arr, limit);
	printArray(arr, limit);

	return 0;
} 

void inputArray(int arr[], int n)
{
	printf("Enter the array: ");
		for(int i = 0; i<n; i++)
			scanf("%d", &arr[i]);
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}




