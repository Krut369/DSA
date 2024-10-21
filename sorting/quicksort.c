/*

Choose a Pivot: Pick an element from the array as the pivot. There are different strategies for selecting the pivot, like choosing the first, last, middle, or a random element.

Partition the Array: Rearrange the array such that:

All elements less than the pivot are on the left side of the pivot.
All elements greater than the pivot are on the right side of the pivot.
Recursively Apply: Apply the same process (choose pivot and partition) recursively to the sub-arrays on the left and right of the pivot.
Base Case: The recursion stops when the sub-array has one or zero elements, which means it is already sorted.

Algorithm:
Pick a pivot element.
Partition the array into two parts based on the pivot.
Recursively apply Quick Sort to the left and right parts.
Combine the results

Quick Sort can run in O(n log n) time, which is much faster than algorithms like Bubble Sort or Insertion Sort for large arrays.
*/
#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element is chosen as the last element
    int i = (low - 1);      // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);  // Swap elements if smaller than pivot
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Place the pivot in its correct position
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index

        quickSort(arr, low, pi - 1);  // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
