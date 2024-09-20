#include <stdio.h>

int main()
{
    int x = 2;
    int y;
    int a, b, c;

    char letter;

    float winpct;
    double pi;

    a = 5;
    a += x;    // a is 7
    b = a / x; // b is 3
    c = a % x;

    letter = 97;
    // a single quote is used for single character value
    printf("letter is %c\n", letter);
    letter = letter + 1; // letter stores 'B' (ASCII value one more than 'A')
    printf("letter+1 is %c\n", letter);

    pi = 3.1415926;
    winpct = 11 / 2.0;

    printf("x is %d\n", x);
    printf("a is %d\n", a);
    printf("b is %d\n", b);
    printf("c is %d\n", c);

    printf("winpct is %f\n", winpct);
    printf("pi is %1f\n", pi);

    // size of 64-bit system
    printf("number of bytes in an int: %lu\n", sizeof(int));
    printf("number of bytes in a short: %lu\n", sizeof(short));

    // post-pre incre/decrement
    x = 6;
    y = ++x + 2;            // y is assigned 9: increment x first, then evaluate x + 2 (9)
    printf("y is %d\n", y); // 9
    x = 6;
    y = x++ + 2;            // y is assigned 8: evaluate x + 2 first (8), then increment x
    printf("y is %d\n", y); // 8

    return 0;
}