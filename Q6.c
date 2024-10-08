#include <stdio.h>
#include <math.h>

void inputMatrix(int n, float mat[10][10]) {
    for (int i = 0; i < n; i++) {
        printf("Enter elements for row %d: ", i + 1);
        for (int j = 0; j <= n; j++) {
            scanf("%f", &mat[i][j]);
        }
    }
}

void printMatrix(int n, float mat[10][10], char *title) {
    printf("\n%s:\n", title);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.3f\t", mat[i][j]);
        }
        printf("\n");
    }
}

void gaussElimination(int n, float mat[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (fabs(mat[i][i]) < fabs(mat[k][i])) {
                for (int j = 0; j <= n; j++) {
                    float temp = mat[i][j];
                    mat[i][j] = mat[k][j];
                    mat[k][j] = temp;
                }
            }
        }

        for (int j = i + 1; j < n; j++) {
            float ratio = mat[j][i] / mat[i][i];
            for (int k = 0; k <= n; k++) {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
    }
}

void backSubstitution(int n, float mat[10][10], float x[10]) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }
}

void printSolution(int n, float x[10]) {
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.3f\n", i + 1, x[i]);
    }
}

int main() {
    int n;
    float mat[10][10], x[10];

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    inputMatrix(n, mat);
    printMatrix(n, mat, "Matrix");

    gaussElimination(n, mat);
    printMatrix(n, mat, "Upper Triangular Matrix");

    backSubstitution(n, mat, x);
    printSolution(n, x);

    return 0;
}
