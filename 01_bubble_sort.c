#include <stdio.h>
#include <stdbool.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    bool swapped;
    
    // Outer loop for the number of passes
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Inner loop to compare adjacent elements
        // The last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true; // Mark that a swap occurred
            }
        }
        
        // If no two elements were swapped in the inner loop, the array is sorted
        if (swapped == false) {
            break;
        }
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array:\n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array in ascending order:\n");
    printArray(arr, n);
    
    return 0;
}
