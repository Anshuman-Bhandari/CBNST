#include <stdio.h>

void printmatrix(int n, float mat[][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%8.3f ", mat[i][j]);
        }
        printf("\n");
    }
}
void gaussJordanElimination(int n, float mat[][n + 1], float x[]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        if (mat[i][i] == 0) {
            printf("Mathematical Error: Division by zero or pivot element is zero.\n");
            return;
        }
        float pivot = mat[i][i];
        for (j = 0; j <= n; j++)
            mat[i][j] /= pivot;
        for (k = 0; k < n; k++) {
            if (k != i) {
                float factor = mat[k][i];
                for (j = 0; j <= n; j++) 
                    mat[k][j] -= factor * mat[i][j];
            }
        }
    }
    for (i = 0; i < n; i++) 
        x[i] = mat[i][n];
}

int main()
{
    int n;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    float mat[n][n + 1], x[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter elements in row %d: ", i + 1);
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }
    printf("\nInitial Augmented Matrix:\n");
    printmatrix(n, mat);
    gaussJordanElimination(n, mat, x);
    printf("\nMatrix after Gauss-Jordan Elimination:\n");
    printmatrix(n, mat);
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %8.3f\n", i + 1, x[i]);
    }
    return 0;
}