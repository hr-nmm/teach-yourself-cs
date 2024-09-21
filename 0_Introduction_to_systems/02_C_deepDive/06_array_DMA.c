#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[])
{
    int i;
    for (i = 0; i < 3; i++)
        printf("value of %d index %d\n", i, arr[i]);
}

int main()
{
    int *arr;
    arr = malloc(sizeof(int) * 3);
    if (arr == NULL)
    {
        printf("Error: malloc failed\n");
        exit(1);
    }

    printf("address of 0 index %p\n", arr);
    printf("address of 0 index %p\n", &arr[0]);
    printf("address of 0 index %d\n", arr == &arr[0]); // true
    arr[0] = 23;
    arr[1] = 33;
    arr[2] = 44;
    print_array(arr);
    free(arr);

    printf("%d is not equal to 33 after freeing \n", arr[1]); // not 33
    arr = NULL;

    return 0;
}