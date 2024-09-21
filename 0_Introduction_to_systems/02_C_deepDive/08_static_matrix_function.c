#include <stdio.h>
// a C constant definition: COLS is defined to be the value 100
#define COLS (100)

void init_matrix(int m[][COLS], int rows)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            m[i][j] = i * j;
        }
    }
}
int main()
{
    int matrix[50][COLS];
    int bigger[90][COLS];
    init_matrix(matrix, 50);
    init_matrix(bigger, 90);
    printf("%d\n", matrix[13][21]); // 13*21 = 273
    printf("%d\n", matrix[49][99]); // 49*99 = 4851
    printf("%d\n", bigger[66][70]); // 66*70  = 4620
    return 0;
}
