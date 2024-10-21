/*
Example of Radix Sort
Let’s consider an example to illustrate how Radix Sort works.

Input Array: [170, 45, 75, 90, 802, 24, 2, 66]

Step 1: Find the Maximum Number

The maximum number is 802, which has 3 digits.
Step 2: Sort by Each Digit (Using Counting Sort)

1st Pass (Least Significant Digit - LSD):

Sort by the units place (0, 5, 5, 0, 2, 4, 2, 6)
Sorted array: [170, 90, 802, 2, 24, 45, 75, 66]
2nd Pass (Tens Place):

Sort by the tens place (7, 9, 0, 0, 2, 4, 7, 6)
Sorted array: [802, 2, 24, 45, 66, 75, 90, 170]
3rd Pass (Hundreds Place):

Sort by the hundreds place (1, 0, 0, 0, 0, 0, 0, 1)
Sorted array: [2, 24, 45, 66, 75, 90, 170, 802]
Final Sorted Array: [2, 24, 45, 66, 75, 90, 170, 802]
time complexity is the O(n)
*/
#include <stdio.h>

#define RANGE 10 // Range of the digits (0 to 9)

// Function to perform counting sort on the specified digit
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[RANGE] = {0}; // Initialize count array to 0

    // Store the count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % RANGE; // Get the digit at the current exponent
        count[index]++;
    }

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < RANGE; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % RANGE;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to implement radix sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int maxNum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }

    // Apply counting sort to sort elements based on each digit
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
