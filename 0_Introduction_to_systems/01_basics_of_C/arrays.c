#include <stdio.h>
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%dth element is: %d\n", i, arr[i]);
    }
}

int main()
{
    int i, size = 0;
    int my_arr[10];

    for (i = 0; i < 9; i++)
    {
        my_arr[i] = i;
        size++;
    }
    printf("total elements in the array is %d\n", size);
    my_arr[3] = 100;

    print_array(my_arr, size);
}