#include <stdio.h>

// Function to copy array data for fair comparison testing
void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 1. Bubble Sort: Repeatedly compares and swaps adjacent elements
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; // Optimization flag
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break; // Stop if already sorted
    }
}

// 2. Selection Sort: Finds the minimum element and places it at the front
void selectionSort(int arr[], int n) {
    int min_idx, temp;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// 3. Insertion Sort: Inserts elements into their correct position one by one
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int original[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(original) / sizeof(original[0]);
    int testArr[7]; // Array buffer for testing

    printf("Original Unsorted Array: ");
    printArray(original, n);
    printf("-------------------------------------------\n");

    // Test Bubble Sort
    copyArray(original, testArr, n);
    bubbleSort(testArr, n);
    printf("Result of Bubble Sort:    ");
    printArray(testArr, n);

    // Test Selection Sort
    copyArray(original, testArr, n);
    selectionSort(testArr, n);
    printf("Result of Selection Sort: ");
    printArray(testArr, n);

    // Test Insertion Sort
    copyArray(original, testArr, n);
    insertionSort(testArr, n);
    printf("Result of Insertion Sort: ");
    printArray(testArr, n);

    return 0;
}
