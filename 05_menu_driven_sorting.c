#include <stdio.h>

// Function prototypes
void displayArray(int arr[], int size);
void copyArray(int source[], int target[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

int main() {
    int size, choice;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int originalArray[size];
    int workingArray[size];

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &originalArray[i]);
    }

    // Menu loop
    do {
        // Reset working copy to original array before every sort iteration
        copyArray(originalArray, workingArray, size);

        printf("\n=================== SORTING MENU ===================\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Display Original Array\n");
        printf("5. Exit\n");
        printf("====================================================\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nRunning Bubble Sort...\n");
                bubbleSort(workingArray, size);
                printf("Sorted Array: ");
                displayArray(workingArray, size);
                break;
            case 2:
                printf("\nRunning Selection Sort...\n");
                selectionSort(workingArray, size);
                printf("Sorted Array: ");
                displayArray(workingArray, size);
                break;
            case 3:
                printf("\nRunning Insertion Sort...\n");
                insertionSort(workingArray, size);
                printf("Sorted Array: ");
                displayArray(workingArray, size);
                break;
            case 4:
                printf("\nOriginal Array: ");
                displayArray(originalArray, size);
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid selection! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to print the array elements
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to clone original inputs so we can reuse them across different sorts
void copyArray(int source[], int target[], int size) {
    for (int i = 0; i < size; i++) {
        target[i] = source[i];
    }
}

// Bubble Sort Implementation
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort Implementation
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort Implementation
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
