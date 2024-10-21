/*

Each phase requires time proportional to O(n log n). Therefore, the running time to sort an array of n elements in the worst case is proportional to O(n log n).
*/

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at node i
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]); // Swap root with largest

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); // Move current root to the end
        heapify(arr, i, 0); // Call max heapify on the reduced heap
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

/*
How Heap Sort Works
Building a Max Heap:

A heap is a complete binary tree where the value of each node is greater than or equal to the values of its children (in a max heap).
The first step is to convert the unsorted array into a max heap. This is done by starting from the last non-leaf node and calling the heapify function on each node going up to the root.
Extracting Elements:

Once the max heap is built, the largest element (the root of the heap) is at the top.
Swap the root with the last element of the heap (the last element of the array) and reduce the size of the heap by one.
Call the heapify function on the new root to maintain the heap property.
Repeat this process until all elements are sorted.
Detailed Steps of Heap Sort
Here’s a breakdown of the steps involved in Heap Sort:

Build a Max Heap:

Start with an unsorted array.
For an array of size  𝑛 , the last non-leaf node is at index 𝑛/2−1
Call heapify on each node from this index down to 0 to build a max heap.

Sort the Array:

Swap the first element (max element) with the last element of the current heap (the end of the array).

Decrease the heap size by 1 (ignore the last element which is now in its sorted position).

Call heapify on the root to maintain the max heap property.

Repeat the above two steps until the heap size is reduced to 1.
*/