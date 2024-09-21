#include <stdio.h>
void arr_is_actually(void)
{
    int arr[3] = {1, 2, 3};
    printf("arr is actually %p\n", arr); // arr is actually 0x7ffec915165c
}
void change_me(int *ptr_x)
{
    printf("ptr_x is actually %p\n", ptr_x);
    printf("x before changing is %d\n", *ptr_x);
    *ptr_x = 11;
}
int main()
{
    arr_is_actually(); // arr is actually a pointer
    int x = 2;
    change_me(&x);
    printf("x is now %d\n", x);
    return 0;
}