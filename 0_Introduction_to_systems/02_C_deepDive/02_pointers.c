#include <stdio.h>

int main()
{
    int *ptr;
    char *cptr;

    int x;
    char ch;

    ptr = &x;
    cptr = &ch;

    if (ptr == NULL && cptr == NULL)
        printf("ptr is null");
    else
    {
        printf("ptr is %p\n", ptr);   // ptr is 0x7ffd0ed7bf54
        printf("cptr is %p\n", cptr); // cptr is 0x7ffd0ed7bf53
    }

    // de-reference operator
    x = 2;
    printf("x is %d\n", x); // 2
    *ptr = 9;
    printf("x is now %d\n", x); // 9
    return 0;
}