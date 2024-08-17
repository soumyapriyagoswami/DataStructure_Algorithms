#include <Stdio.h>
#include <Stdlib.h>
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
// creating an array
void createArray(struct myArray *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}
// setting value

void set_value(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d:\n", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}
// showing value
void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("values are %d\n", a->ptr[i]);
    }
}
// array traversal
void Traversal(struct myArray *a)
{
    
}
int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    set_value(&marks);
    show(&marks);

    return 0;
}