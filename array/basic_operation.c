#include <stdio.h>

// Function to traverse an array
void traverseArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
void insertElement(int arr[], int *size, int element, int position) {
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

// Function to delete an element at a specific position
void deleteElement(int arr[], int *size, int position) {
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

// Function to search for an element in an array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}

// Sliding window maximum sum
int slidingWindowMaxSum(int arr[], int size, int k) {
    int maxSum = 0, windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    maxSum = windowSum;
    
    for (int i = k; i < size; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }
    
    return maxSum;
}

// Row-major order to get an element at a specific position
int getRowMajor(int arr[], int rows, int cols, int row, int col) {
    return arr[row * cols + col];
}

// Column-major order to get an element at a specific position
int getColumnMajor(int arr[], int rows, int cols, int row, int col) {
    return arr[col * rows + row];
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Array before insertion: ");
    traverseArray(arr, size);

    // Insertion
    insertElement(arr, &size, 10, 2);
    printf("Array after insertion: ");
    traverseArray(arr, size);

    // Deletion
    deleteElement(arr, &size, 3);
    printf("Array after deletion: ");
    traverseArray(arr, size);

    // Searching
    int index = searchElement(arr, size, 10);
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }

    // Sliding window maximum sum
    int maxSum = slidingWindowMaxSum(arr, size, 3);
    printf("Maximum sum of sliding window of size 3: %d\n", maxSum);

    // Row-major and column-major order access
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Element at (2, 3) in row-major: %d\n", getRowMajor((int *)matrix, 4, 4, 2, 3));
    printf("Element at (2, 3) in column-major: %d\n", getColumnMajor((int *)matrix, 4, 4, 2, 3));

    return 0;
}
