// this is a generalised insertion sort where the gap is (size/2)
//here the [i = 0] is compared with [i = i+4] elements for every element until i<=gap
// [15, 19, 20, 38, 24, 41, 30, 31, 32] here 15[i =0] is compared with 24[i = 4] until 24[ i = 4] with 12[i = 8]

// Shell Sort in C programming

#include <stdio.h>

void inputArray(int arr[], int n);
void shellSort(int array[], int n);
void printArray(int array[], int size);

int main() {
    int limit;
	printf("Enter the limit: ");
	scanf("%d", &limit);
    int arr[limit];
    inputArray(arr, limit);
    shellSort(arr, limit);
    printArray(arr, limit);
    return 0;
}

void inputArray(int arr[], int n)
{
	printf("Enter the array: ");
		for(int i = 0; i<n; i++)
			scanf("%d", &arr[i]);
}

void shellSort(int array[], int n) {
  for (int interval = n/2; interval > 0; interval /= 2)  
    {  
        for (int i = interval; i < n; i += 1)  
        {  
            int temp = array[i];  
            int j;        
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)  
                array[j] = array[j - interval];  
              
            array[j] = temp;  
        }  
    } 
}

void printArray(int array[], int size) 
{
    printf("Sorted array: \n");
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


