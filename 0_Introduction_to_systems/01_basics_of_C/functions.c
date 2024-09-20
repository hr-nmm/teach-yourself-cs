#include <stdio.h>
void foo(void); // prototype

int factorial(int num)
{
    if (num < 2)
        return 1;
    return num * factorial(num - 1);
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void print_table(int num)
{
    int i;
    for (i = 1; i < 11; i++)
        printf("%d X %d = %d\n", num, i, num * i);
}

int main()
{
    int ans, num;
    scanf("%d", &num);
    ans = factorial(num);
    printf("factorial of %d is %d\n", num, ans);
    printf("max of %d & %d is %d\n", num, ans, max(num, ans));
    print_table(13);
    foo();
    return 0;
}

void foo(void) // prototype
{
    printf("foo!!!\n");
}
