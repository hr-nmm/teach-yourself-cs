// This prog. compiles successfully

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, x;
    ptr = malloc(sizeof(int) * 10);
    x = ptr[3]; // reading from uninitialized memory

    ptr[11] = 100; // writing to unallocated memory (no 11th element)
    x = ptr[11];   // reading from unallocated memory

    free(ptr);
    free(ptr); // freeing the same pointer a second time

    int *ptr1;
    ptr1 = malloc(sizeof(int) * 10);
    ptr1 = malloc(sizeof(int) * 5); // memory leak of first malloc of // 10 ints

    return 0;
}