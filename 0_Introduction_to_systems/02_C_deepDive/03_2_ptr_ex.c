#include <stdio.h>
int main()
{
    int *ptr1, *ptr2, x, y;
    x = 8;
    ptr2 = &x;
    ptr1 = NULL;
    // ptr2 is assigned the address of x
    *ptr2 = 10;
    // the memory location ptr2 points to is assigned 10
    y = *ptr2 + 3; // y is assigned what ptr2 points to plus 3
    *ptr2 = 10;
    // the memory location ptr2 points to is assigned 10
    y = *ptr2 + 3; // y is assigned what ptr2 points to plus 3

    *ptr1 = 100;
    ptr1 = &y; // change ptr1's value (change what it points to)
    *ptr1 = 80;

    return 0;
}