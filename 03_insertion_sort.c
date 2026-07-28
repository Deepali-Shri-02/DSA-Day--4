#include <stdio.h>

// Function to sort an array using insertion sort
void insertionSort(int arr[], int size) {
    // Start from the second element (index 1)
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insert the key into its correct sorted position
        arr[j + 1] = key;
    }
}

// Function to print the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {12, 11, 13, 5, 6};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: \n");
    printArray(data, size);

    insertionSort(data, size);

    printf("Sorted array in ascending order: \n");
    printArray(data, size);

    return 0;
}
