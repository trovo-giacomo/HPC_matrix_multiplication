#include <math.h>
void matmult_blk(int m, int n, int k, double **A, double **B, double **C, int bs){ 
    int i1, i2,j,z;
    
    for(i1 = 0; i1<m; i1+=bs){
        for(j=0; j<n; j++){
            for(i2=0; i2 < fmin(m-i1,bs); i2++){
                double sum = 0;
                for(z=0; z<k; z++){
                    sum += A[i1+i2][z]*B[z][j];
                }
                C[i1+i2][j] = sum;
            }
        }
    }
}   