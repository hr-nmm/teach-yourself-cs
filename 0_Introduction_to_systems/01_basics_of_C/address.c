#include <stdio.h>

int main()
{
    int var = 23232;
    void *address = &var;
    char var2 = 'T';
    float var3 = 3.141;
    float *address_var3 = &var3;

    printf("Address of int var whose value is %d is %p\n", var, address);
    printf("Address of char var2 whose value is %c is %p\n", var2, (void *)&var2);
    printf("Address of float var3 whose value is %f is %p\n", var3, address_var3);

    /*Address of int var whose value is 23232 is 0x7ffc627897e0
    Address of char var2 whose value is T is 0x7ffc627897df
    Address of int var3 whose value is 3.141000 is 0x7ffc627897e4*/
}