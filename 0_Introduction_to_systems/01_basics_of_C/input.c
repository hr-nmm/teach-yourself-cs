#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter numbers: ");
    scanf("%d  %d", &num1, &num2);
    // printf("Enter another number: ");
    // scanf("%d", &num2);
    printf("sum of %d + %d is %d\n", num1, num2, num1 + num2);
    return 0;
}