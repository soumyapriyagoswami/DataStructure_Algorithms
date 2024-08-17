public class ArrayOperations {

    // Function to traverse an array
    public static void traverseArray(int[] arr, int size) {
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // Function to insert an element at a specific position
    public static void insertElement(int[] arr, int size, int element, int position) {
        if (size >= arr.length) {
            System.out.println("Array is full, cannot insert element.");
            return;
        }
        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
    }

    // Function to delete an element at a specific position
    public static void deleteElement(int[] arr, int size, int position) {
        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = 0; // Clear the last element
    }

    // Function to search for an element in an array
    public static int searchElement(int[] arr, int size, int element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                return i; // Element found, return its index
            }
        }
        return -1; // Element not found
    }

    // Sliding window maximum sum
    public static int slidingWindowMaxSum(int[] arr, int size, int k) {
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
    public static int getRowMajor(int[][] arr, int rows, int cols, int row, int col) {
        return arr[row][col];
    }

    // Column-major order to get an element at a specific position
    public static int getColumnMajor(int[][] arr, int rows, int cols, int row, int col) {
        return arr[col][row];
    }

    public static void main(String[] args) {
        int[] arr = new int[100];
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        arr[4] = 5;
        int size = 5;

        System.out.println("Array before insertion:");
        traverseArray(arr, size);

        // Insertion
        insertElement(arr, size, 10, 2);
        size++;
        System.out.println("Array after insertion:");
        traverseArray(arr, size);

        // Deletion
        deleteElement(arr, size, 3);
        size--;
        System.out.println("Array after deletion:");
        traverseArray(arr, size);

        // Searching
        int index = searchElement(arr, size, 10);
        if (index != -1) {
            System.out.println("Element found at index: " + index);
        } else {
            System.out.println("Element not found");
        }

        // Sliding window maximum sum
        int maxSum = slidingWindowMaxSum(arr, size, 3);
        System.out.println("Maximum sum of sliding window of size 3: " + maxSum);

        // Row-major and column-major order access
        int[][] matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };

        System.out.println("Element at (2, 3) in row-major: " + getRowMajor(matrix, 4, 4, 2, 3));
        System.out.println("Element at (2, 3) in column-major: " + getColumnMajor(matrix, 4, 4, 2, 3));
    }
}
