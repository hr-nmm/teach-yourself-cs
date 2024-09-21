#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t x;
    x = sizeof(int);
    printf("%zu\n", x);        // 4
    printf("%p\n", malloc(4)); // address of 4 bytes that malloc has allocated

    //
    int *p;
    p = malloc(sizeof(int)); // allocate heap memory for storing an int
    if (p != NULL)
    {
        *p = 6;
        // the heap memory p points to gets the value 6
    }
    free(p);
    p = NULL;
    printf("%d\n", p == NULL); // 1
}