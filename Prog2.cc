#include <stdio.h>
#include <math.h>

float f(float x) {
    return (x * x * x - x - 1);
}

int main() {
    float x, x1, x2, aerr;
    int fg = 0, itr = 0;

    printf("Equation : x^3 - x - 1\n");

    do {
        printf("\nEnter value of x1 & x2: ");
        scanf("%f %f", &x1, &x2);

        if (f(x1) * f(x2) < 0) {
            fg = 1;
            printf("Roots lie between %.1f and %.1f\n", x1, x2);
        } 
        else {
            printf("No root exists in the given interval\n");
        }
    } while (fg == 0);

    printf("\nEnter the accuracy : ");
    scanf("%f", &aerr);

    while (fg == 1) {
        itr++;
        x = (x1 + x2) / 2;
        printf("\n%d iteration value of x is %f, value of (%f) is %f", itr, x, x, f(x));

        if (fabs(f(x)) <= aerr) {
            fg = 0;
            printf("\n\nRoot found at x = %f in %d iterations\n", x, itr);
        } else if (f(x) * f(x1) < 0) {
            x2 = x;
        } else {
            x1 = x;
        }
    }

    return 0;
}
