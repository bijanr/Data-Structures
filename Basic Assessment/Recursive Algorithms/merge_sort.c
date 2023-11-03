// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int A[], int size);

int main()
{

    int limit;
    printf("Enter the limit of array: ");
    scanf("%d", &limit);
    int arr[limit];
    printf("Enter the elements of array: \n");
    for(int i = 0; i<limit; i++)
        scanf("%d",&arr[i]);
	printf("Given array is \n");
	printArray(arr, limit);

	mergeSort(arr, 0, limit - 1);

	printf("\nSorted array is \n");
	printArray(arr, limit);
	return 0;
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;


	int left[n1], right[n2];

	for (i = 0; i < n1; i++)
		left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		right[j] = arr[m + 1 + j];      

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	
	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right) {
		int m = left + (right - left) / 2;

		mergeSort(arr, left, m);
		mergeSort(arr, m + 1, right);

		merge(arr, left, m, right);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}