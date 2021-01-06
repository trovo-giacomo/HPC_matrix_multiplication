#include <math.h>
void matmult_blk(int m, int n, int k, double **A, double **B, double **C, int bs){ 
    int i1, i2,j1, j2,z;

    for(i1 = 0; i1<m; i1+=bs){
        for(j1=0; j1<n; j1+=bs){
            for(i2=0; i2 < fmin(m-i1,bs); i2++){
                for(j2 =0; j2 < fmin(n-i2,bs); j2++){
                    double sum = 0;
                    for(z=0; z<k; z++){
                        sum += A[i1+i2][z]*B[z][j1+j2];
                    }
                    C[i1+i2][j1+j2] = sum;
                }
            }
        }
    }
}   