/**
 * Author: Devendra Naga <devendra.aaru@gmail.com
 * 
 * Copyright Apache License
 */
#include <stdio.h>

/**
 * @brief - adds two matrices and places them in 3rd matrix
 */
static int mat_add(int mat1[3][3], int mat2[3][3], int mat3[3][3])
{
        int i;
        int j;

        for (i = 0; i < 3; i ++) {
                for (j = 0; j < 3; j ++) {
                        mat3[i][j] = mat1[i][j] + mat2[i][j];
                }
        }

        return 0;
}

int main()
{
        int mat1[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9},
        };

        int mat2[3][3] = {
                {2, 4, 6},
                {8, 10, 12},
                {14, 16, 18},
        };

        int mat3[3][3];
        int ret;

        ret = mat_add(mat1, mat2, mat3);
        if (ret < 0) {
                return -1;
        }

        int i;
        int j;

        for (i = 0; i < 3; i ++) {
                for (j = 0; j < 3; j ++) {
                        printf("%d ", mat3[i][j]);
                }
                printf("\n");
        }
}
