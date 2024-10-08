// Gauss Seidal
#include<stdio.h>
#include<math.h>
float f1(float x,float y,float z){
    return (44-y-2*z)/10;
}
float f2(float x,float y,float z){
    return (51-2*x-z)/10;
}
float f3(float x,float y,float z){
    return (61-x-2*y)/10;
}
int main() {
    float x0=0,y0=0,z0=0,x1=0,y1=0,z1=0;
    int n,itr=1;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    int flag=1;
    float mat[n][n+1];
    while(flag!=0){
        flag=0;
        for (int i = 0; i< n; i++) {
            printf("\nEnter elements in row %d: ", i + 1);
            for (int j = 0; j < n + 1; j++) {
                scanf("%f", &mat[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            float sum=0;
            for(int j=0;j<n;j++){
                if(i!=j){
                    sum+=fabs(mat[i][j]);
                }
            }
            if(fabs(mat[i][i])<=sum){
                flag=1;
            }
        }
        if(flag==1){
            printf("\nThis is not a diagonal dominant matrix. Try again.\n");
        }
    }
    printf("\nMatrix: \n");
    for (int i = 0; i< n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.3f\t", mat[i][j]);
        }
        printf("\n");
    }
    float e,e1=1,e2=1,e3=1;
    printf("Enter allowed error: ");
    scanf("%f", &e);
    while(e1>e && e2>e && e3>e){
        printf("\n%d iteration:\nx = %f\ny = %f\nz= %f\n", itr++,x0,y0,z0);
        x1=f1(x0,y0,z0);
        y1=f2(x1,y0,z0);
        z1=f3(x1,y1,z0);
        e1=fabs(x0-x1);
        e2=fabs(y0-y1);
        e3=fabs(z0-z1);
        x0=x1;
        y0=y1;
        z0=z1;
    }
    printf("\nFinal root: \nx = %f\ny = %f\nz = %f\n", x0, y0, z0);
    return 0;
}

