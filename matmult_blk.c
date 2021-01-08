#include <math.h>
// mnk blk implementation - nat
/*void matmult_blk(int m, int n, int k, double **A, double **B, double **C, int bs){ 
    int i1, i2,j1, j2,z1,z2;
    //init blocks
    for(i1 = 0; i1<m; i1+=bs){
        for(j1=0; j1<n; j1+=bs){
            for(i2=0; i2 < fmin(m-i1,bs); i2++){
                for(j2 =0; j2 < fmin(n-j1,bs); j2++){
                    C[i1+i2][j1+j2] = 0;
                }
            }
        }
    }

    for(i1 = 0; i1<m; i1+=bs){
        for(j1=0; j1<n; j1+=bs){
            for(z1=0; z1<k; z1+=bs){
                for(i2=0; i2 < fmin(m-i1,bs); i2++){
                    for(j2 =0; j2 < fmin(n-j1,bs); j2++){
                        for(z2=0; z2<fmin(k-z1,bs); z2++){
                            C[i1+i2][j1+j2] += A[i1+i2][z1+z2]*B[z1+z2][j1+j2];
                        }
                    }
                }
            }
        }
    }
}*/

// nkm

void matmult_blk(int m, int n, int k, double **A, double **B, double **C, int bs){
    int i1, i2,j1, j2,z1, z2;
    //init blocks
    for(i1 = 0; i1<m; i1++){
        for(j1=0; j1<n; j1++){
            C[i1][j1]= 0;
        }
    }

    for(j1=0; j1<n; j1+=bs){
        for(z1=0; z1<k; z1+=bs){
			for(i1 = 0; i1<m; i1+=bs){
                for(j2 =0; j2 < fmin(n-j1,bs); j2++){
                    for(z2=0; z2<fmin(k-z1,bs); z2++){
                        for(i2=0; i2 < fmin(m-i1,bs); i2++){
		    	            C[i1+i2][j1+j2] += A[i1+i2][z1+z2]*B[z1+z2][j1+j2];
                        }
                    }
                }
			}
		} 
	}
}