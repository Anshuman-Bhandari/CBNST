// Aim- To deduce ban error in a given (Absolute, Relative, Problem % errors)
#include<stdio.h>
#include<math.h>

int main() {
    float trueVal = 1.414213562;
    float approxVal = 1.414;
    printf("True Value: %f", trueVal);
    printf("\nApproximate Value: %.3f\n", approxVal);

    float ea = fabs((trueVal - approxVal));
    float er = fabs(ea/trueVal);
    float ep = 100*er;

    printf("\nAbsolute Error: %f\n", ea);
    printf("Relative Error: %f\n", er);
    printf("Percentage Error: %f", ep);
}
