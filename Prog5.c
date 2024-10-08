#include <stdio.h>
#include <math.h>

float f(float x) {
    return (x*x - 12);
}
float df(float x) {
    return (2*x);
}
int main() {
    float x0, x1, fg = 0;
    printf("f(x) = x^2 - 12\n");
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
    x0 = (x0 + x1)/2;
    float aerr;
    printf("\nEnter the required accuracy: ");
    scanf("%f", &aerr);
    int itr = 0;
    float x, fx, dfx;
    while (1) {
        itr++;
        fx = f(x0);
        dfx = df(x0);
        x = x0 - (fx/dfx);
        printf("\n%d iteration | Value of x%d is %f", itr, itr, x);
        if (fabs(x - x0) < aerr) {
            printf("\n\nRoot for the given equation is %f found in %d iterations\n", x, itr);
            break;
        }
        x0 = x;
    }
    return 0;
}
