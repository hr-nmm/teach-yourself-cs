#include <stdio.h>

int main()
{
    int num, val;
    scanf("%d", &num);
    if (num < 0)
        num = -num;
    val = 1;
    printf("num is %d & val is %d\n", num, val);
    while (val < num)
    {
        printf("%d\n", val);
        val = val * 2;
    }

    // for loop
    int i, x = 2;
    printf("num is %d\n", x);
    for (i = 0; i < num; i++)
    {
        printf("%d\n", i);
    }

    // indefinate loop => while (guess != num)
    int guess;
    for (guess = 0; guess != num;)
    {
        printf("%d is not the right number\n", guess);
        printf("Enter another guess: ");
        scanf("%d", &guess);
    }
    return 0;
}