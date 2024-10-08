#include<stdio.h>
float fact(int n){
    if (n==1 || n==0) return 1;
    float ans=1;
    for(int i=1; i<=n ;i++){
        ans*=i;
    }
    return ans;
}
float u_cal(float u, int i){
    if(i==0) return 1;
    if(i==1) return u;
    float ans=1;
    for(int j=0; j<i; j++){
        ans*=u+j;
    }
    return ans;
}
int main() {
    int n;
    printf("Enter size of x: ");
    scanf("%d", &n);
    int m=n-1;
    float x[n],y[n][n];
    printf("Enter values of x: ");
    for(int i=0; i<n; i++){
        scanf("%f", &x[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            y[i][j]=0;
        }
    }
    printf("Enter values of y: ");
    for(int i=0; i<n; i++){
        scanf("%f", &y[i][0]);
    }
    printf("Initial Table:   \n");
    for(int i=0; i<n; i++){
        printf("%.2f ",x[i]);
        for(int j=0; j < n ; j++){
            printf("%.2f ",y[i][j]);
        }
        printf("\n");
    }
    int s=0,d=1,temp=m;
    for(int i=0; i<m; i++ ){
        for(int j=0; j<temp; j++){
            y[j][d]=y[j+1][s]-y[j][s];
        }
        temp--;
        d++;
        s++;
    }
    printf("Difference Table:   \n");
    for(int i=0; i<n; i++){
        printf("%.2f\t",x[i]);
        for(int j=0; j < n ; j++){
            printf("%.2f\t",y[i][j]);
        }
        printf("\n");
    }
    float x0,y0=0;
    printf("Enter the value of x to find: ");
    scanf("%f", &x0);
    float h=x[1]-x[0];
    float u=(x0-x[n-1])/h;
    printf("h= %f\nu= %f\n",h,u);
    for(int i=0; i<n; i++){
        y0+=(y[n-i-1][i] * u_cal(u,i))/fact(i);
    }
    printf("\nf(x)= %.2f",y0);
    return 0;
}
