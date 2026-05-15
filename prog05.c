#include <stdio.h>

// Function to perform modified binary search on a rotated sorted array
int search_rotated_array(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        // Calculate mid to avoid overflow with large arrays
        int mid = low + (high - low) / 2;

        // If the key is found at the middle, return the index
        if (arr[mid] == key) {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if the key lies within the sorted left half
            if (key >= arr[low] && key < arr[mid]) {
                high = mid - 1; // Search in the left half
            } else {
                low = mid + 1; // Search in the right half
            }
        }
        // If the left half is not sorted, the right half must be sorted
        else {
            // Check if the key lies within the sorted right half
            if (key > arr[mid] && key <= arr[high]) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
    }

    // Key not found in the array
    return -1;
}

// Driver program to test the function
int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 0;
    int index = search_rotated_array(arr, n, key);

    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found in the array\n", key);
    }

    // Example with another key
    key = 3;
    index = search_rotated_array(arr, n, key);

    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found in the array\n", key);
    }

    return 0;
}