#include <stdio.h>

// void init_matrix()

int main()
{
    int matrix[50][100];
    printf("%p || %p || %d\n", &matrix[0][0], matrix, &matrix[0][0] == matrix); // true
    // initialize matrix
    int i, j;
    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 100; j++)
            matrix[i][j] = i + j;
    }

    int val_at_row3_col7, val_at_row8_col4, val_at_row49_col99;

    val_at_row3_col7 = matrix[3][7];     // get int value in row 3, column 7 of matrix
    val_at_row8_col4 = matrix[8][4];     // get int value in row 8, column 4 of matrix
    val_at_row49_col99 = matrix[49][99]; // get int value in row 49, column 99 of matrix

    printf("%d\n", val_at_row3_col7);   // 10
    printf("%d\n", val_at_row8_col4);   // 12
    printf("%d\n", val_at_row49_col99); // 148

    return 0;
}