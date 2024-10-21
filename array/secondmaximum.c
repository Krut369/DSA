#include <stdio.h>
#include <limits.h> // For INT_MIN

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of the array
    int max = INT_MIN;      // Initialize to minimum possible value
    int secondmax = INT_MIN; // Initialize to minimum possible value

    // Find the maximum value
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Find the second maximum value
    for (int i = 0; i < size; i++) {
        if (arr[i] > secondmax && arr[i] != max) {
            secondmax = arr[i];
        }
    }

    // Check if we found a valid second maximum
    if (secondmax == INT_MIN) {
        printf("No second maximum element found (all elements might be equal)\n");
    } else {
        printf("The second maximum element is %d\n", secondmax);
    }

    return 0;
}
