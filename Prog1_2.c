// Aim- To deduce ban error in a given (Absolute, Relative, Problem % errors)
#include<stdio.h>
#include<math.h>

int main() {
    float val = 1.0/3.0;
    float approxVal1 = 0.30;
    float approxVal2 = 0.33;
    float approxVal3 = 0.34;
    printf("Approximate value of 1/3 is: %.2f, %.2f, %.2f\n", approxVal1, approxVal2, approxVal3);

    float ea1 = fabs(val - approxVal1);
    float ea2 = fabs(val - approxVal2);
    float ea3 = fabs(val - approxVal3);

    printf("\n1 Absolute error of 1/3: %f\n", ea1);
    printf("2 Absolute error of 1/3: %f\n", ea2);
    printf("3 Absolute error of 1/3: %f\n", ea3);

    float bestApprox;
    if(ea1 < ea2) {
    	if(ea1 < ea3) 
    		bestApprox = approxVal1;
    	else
    		bestApprox = approxVal3;
	}
	else {
		if(ea2 < ea3) 
    		bestApprox = approxVal2;
    	else
    		bestApprox = approxVal3;
	}

    printf("\nBest Approximation of 1/3 is: %.2f\n", bestApprox);
}
