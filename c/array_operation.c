#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int insertion(int arr[], int size, int number, int index, int capacity)
{
    if (size >= capacity)
    {
        printf("Insertion not possible.\n");
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = number;
    return 1;
}
// deletion
void Deletion(int arr[], int size, int index, int capacity)
{
    if (index > capacity - 1)
    {
        printf("Deletion not possible.");
    }
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[10] = {2, 3, 4, 5};
    int number = 10, index = 3, capacity = 10;
    int size = 4;
    display(arr, size);
    printf("------------------------------------------------\n");
    insertion(arr, size, number, index, capacity);
    size = size + 1;
    display(arr, size);
    printf("------------------------------------------------\n");
    Deletion(arr, size, index, capacity);
    size = size - 1;
    display(arr, size);

    return 0;
}