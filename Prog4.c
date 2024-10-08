#include <stdio.h>
#include <math.h>

float f(float x) {
    return ((x*x*x) - 5*x + 1);
}

int main() {
    float x1, x0, fg = 0;
    printf("f(x) = x^3 - 5x + 1\n");
    do {
        printf("\nEnter the initial guess (x0) & (x1): ");
        scanf("%f %f", &x0, &x1);
        if (f(x0) * f(x1) < 0) {
            fg = 1;
            printf("\nRoot lies between %.1f & %.1f", x0, x1);
        } else {
            printf("\nInitial guesses do not bracket a root. Try again.\n");
        }
    } while (!fg);
    float aerr;
    printf("\nEnter the required accuracy: ");
    scanf("%f", &aerr);
    int itr = 0;
    float x, fx0, fx1;
    while (1) {
        itr++;
        fx0 = f(x0);
        fx1 = f(x1);
        x = x1 - ((x1 - x0) / (fx1 - fx0)) * fx1;
        printf("\n%d iteration | Value of x%d is %f", itr, itr + 1, x);
        if (fabs(x - x1) < aerr) {
            printf("\n\nRoot for the given equation is %f found in %d iterations\n", x, itr);
            break;
        }
        x0 = x1;
        x1 = x;
    }
    return 0;
}
