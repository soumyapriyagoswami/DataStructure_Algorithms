#include <stdio.h>

// traversiing an array
void Traverse_Array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// insertion element
void insertElement(int arr[], int *size, int element, int position)
{
    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

// deleting element
void delete(int arr[], int *size, int position]){
    for(int i = position; i < *size - 1; i++){
        arr[i] = arr[i+1];
    }
    return (*size)--;
}

// search element
int searchElement(int arr[[], int size, int element]){
    for(int i = 0; i < size; i++){
        if(arr[i] == element) return i;
    }
    return -1;
}

int slidingWindow(int arr[], int size, int k)
{
    int maxsum = 0; int windowsum = 0;
    
}