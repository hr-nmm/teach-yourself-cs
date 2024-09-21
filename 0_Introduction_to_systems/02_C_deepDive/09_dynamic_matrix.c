#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4
void init2D(int *arr, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            arr[i * cols + j] = 0;
        }
    }
}
int main()
{
    int *two_d_array;
    // the type is a pointer to an int (the element type)
    // allocate in a single malloc of N x M int-sized elements:
    two_d_array = malloc(sizeof(int) * N * M);
    if (two_d_array == NULL)
    {
        printf("ERROR: malloc failed!\n");
        exit(1);
    }
    init2D(two_d_array, N, M);
    free(two_d_array);
    two_d_array = NULL;

    // the 2D array variable is declared to be `int **` (a pointer to an int *)
    // a dynamically allocated array of dynamically allocated int arrays
    // (a pointer to pointers to ints)
    int **two_d_array1;
    int i;
    // allocate an array of N pointers to ints
    // malloc returns the address of this array (a pointer to (int *)'s)
    two_d_array1 = malloc(sizeof(int *) * N);
    // for each row, malloc space for its column elements and add it to
    // the array of arrays
    for (i = 0; i < N; i++)
    {
        // malloc space for row i's M column elements
        two_d_array1[i] = malloc(sizeof(int) * M);
    }
    printf("%p\n", &two_d_array1[0][0]);
    printf("%p\n", &two_d_array1[0][1]);
    printf("%p\n", &two_d_array1[0][2]);
    printf("%p\n", &two_d_array1[0][3]);
    printf("%p\n", &two_d_array1[1][0]);
    printf("%p\n", &two_d_array1[1][1]);
    printf("%p\n", &two_d_array1[1][2]);
    printf("%p\n", &two_d_array1[1][3]);
    printf("%p\n", &two_d_array1[2][0]);
    printf("%p\n", &two_d_array1[2][1]);
    printf("%p\n", &two_d_array1[2][2]);
    printf("%p\n", &two_d_array1[2][3]);
    printf("%p\n", two_d_array1); // same as &two_d_array1[0]
    printf("%p\n", &two_d_array1[0]);
    printf("%p\n", &two_d_array1[1]);
    printf("%p\n", &two_d_array1[2]);

    return 0;
}
