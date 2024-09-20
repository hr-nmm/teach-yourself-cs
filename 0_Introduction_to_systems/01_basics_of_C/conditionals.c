#include <stdio.h>
int main()
{
    int num1, num2;
    printf("Enter the 1st number: ");
    scanf("%d", &num1);
    printf("Enter the 2nd number: ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        printf("%d is biggest\n", num1);
    }
    else if (num1 == num2)
    {
        printf("both are equal\n");
    }
    else
    {
        printf("%d is biggest\n", num2);
    }

    return 0;
}