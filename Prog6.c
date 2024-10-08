#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    float mat[10][10], x[10];
    for (int i = 0; i < n; i++) // Enter the Equation matrix : 3 x 4
    {
        printf("\nEnter elements in row %d: ", i + 1);
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }
    printf("\nMatrix: \n");
    for (int i = 0; i < n; i++) // Print the matrix
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%.3f\t", mat[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) // Check the Diagonal Element with the other element of the column 
    {
        for (int k = i + 1; k < n; k++) // And if the diagonal element is smaller swap the whole row with the other column
        {
            if (fabs(mat[i][i]) < fabs(mat[k][i]))
            {
                for (int j = 0; j <= n; j++)
                {
                    float temp = mat[i][j];
                    mat[i][j] = mat[k][j];
                    mat[k][j] = temp;
                }
            }
        }
        for (int j = i + 1; j < n; j++) // Make upper triangular matrix 
        {
            float ratio = mat[j][i] / mat[i][i]; // Apply row operation to 0 the elements
            for (int k = 0; k <= n; k++)
            {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
    }
    printf("\nUpper Triangular matrix: \n");
    for (int i = 0; i < n; i++) // Print the upper triangular matrix
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%.3f\t", mat[i][j]);
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 0; i--) // Finding the solution for the equation 
    {
        x[i] = mat[i][n]; // initialize x[i] with the solution
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= mat[i][j] * x[j]; // 0x1 + 3x2 + 4x3 = 5, => 3x2 = 5 - 4(value of x3 that has already calculated earlier).
        }
        x[i] /= mat[i][i]; // Equate by dividing the solution with coeffiient : 3x = 1 , =>  x = 1/3
    }
    printf("\nSolution: \n");
    for (int i = 0; i < n; i++) // Printing the Solution for the equation
    {
        printf("x%d = %.3f\n", i + 1, x[i]);
    }
    return 0;
}