#include<stdio.h>
#include<math.h>
float f(float x) {
	return fabs(cosf(x) - (3*x) + 1);
}
float g(float x) {
	return fabs((cosf(x)+1)/3);
}
float dg(float x) {
	return fabs(sinf(x)/3);
}
int main() {
	printf("Equation: cos(x) - 3*x + 1\n");
	float x0, aerr;
	do {
		printf("\nEnter x0: ");
		scanf("%f", &x0);
		if(dg(x0) < 1) {
			printf("\nYou can proceed\n");
			break;
		}
		else printf("Try Again\n");
	}while(1);
	x0 = g(x0);
	printf("\nEnter allowed error: ");
	scanf("%f", &aerr);
	int itr = 0;
	do {
		itr++;
		printf("\n%d iteration | Value of x0 is %f | value of f(x0) is %f", itr, x0, f(x0));
		if(f(x0) < aerr) {
			printf("\n\nRoot found in the %d iteration and value of x0 is %f\n", itr, x0);
			break;
		}
		x0 = g(x0);
	}while(1);
	return 0;
}
