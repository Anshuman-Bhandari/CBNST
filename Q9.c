#include <stdio.h>

float factorial(int n) {
    float result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

float uTerm(float u, int n) {
    float result = 1;
    for (int i = 0; i < n; i++) result *= (u - i);
    return result;
}

void inputValues(int n, float x[], float y[][n]) {
    printf("Enter values of x: ");
    for (int i = 0; i < n; i++) scanf("%f", &x[i]);

    printf("Enter values of y: ");
    for (int i = 0; i < n; i++) scanf("%f", &y[i][0]);
}

void constructDifferenceTable(int n, float y[][n]) {
    for (int col = 1; col < n; col++) {
        for (int row = 0; row < n - col; row++) {
            y[row][col] = y[row + 1][col - 1] - y[row][col - 1];
        }
    }
}

void printTable(int n, float x[], float y[][n]) {
    printf("\nDifference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
        for (int j = 0; j < n - i; j++) printf("%.2f\t", y[i][j]);
        printf("\n");
    }
}

float newtonForwardInterpolation(int n, float x[], float y[][n], float x0) {
    float h = x[1] - x[0];
    float u = (x0 - x[0]) / h;
    float result = y[0][0];

    for (int i = 1; i < n; i++) {
        result += (uTerm(u, i) * y[0][i]) / factorial(i);
    }
    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n][n];
    inputValues(n, x, y);

    constructDifferenceTable(n, y);
    printTable(n, x, y);

    float x0;
    printf("\nEnter the value of x to find: ");
    scanf("%f", &x0);

    float result = newtonForwardInterpolation(n, x, y, x0);
    printf("\nf(x) = %.2f\n", result);

    return 0;
}
