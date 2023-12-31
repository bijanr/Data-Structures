// in Insertion sort, the current element is compared with the last element(s) until 0 th location
#include <stdio.h>

void inputArray(int arr[], int n);
void insertionSortAsc(int arr[], int n);	// function for ascending order
void insertionSortDesc(int arr[], int n);  // function for descending order
void printArray(int arr[], int n);

int main()
{
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    int arr[limit];
    inputArray(arr, limit);

    // Sorting in ascending order
    insertionSortAsc(arr, limit);
    printf("Ascending Order: ");
    printArray(arr, limit);

    // Sorting in descending order
    insertionSortDesc(arr, limit);
    printf("Descending Order: ");
    printArray(arr, limit);

    return 0;
}

void inputArray(int arr[], int n)
{
    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void insertionSortAsc(int arr[], int n)
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

void insertionSortDesc(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)  // Change the condition for descending order
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
