void matmult_mnk(int m, int n, int k, double **A, double **B, double **C){    
    matmult_nat(m,n,k,A,B,C);
}

void matmult_mkn(int m, int n, int k, double **A, double **B, double **C){    
    int i, j, z;

    for(j = 0; j < n; j++){
        for(i = 0; i < m; i++){
            C[i][j] = 0;
        }
    }

    for(i = 0; i < m; i++){
        for(z = 0; z < k; z++){
			for(j = 0; j < n; j++){
		    	C[i][j] += A[i][z]*B[z][j];
			}
		}
	}
}
    
void matmult_nmk(int m, int n, int k, double **A, double **B, double **C){    
    int i, j, z;

    for(j = 0; j < n; j++){
		for(i = 0; i < m; i++){
			double sum = 0.0;
			for(z = 0; z<k; z++){
		    	sum += A[i][z]*B[z][j];
			}
			C[i][j] = sum;
		}
	}
}

void matmult_nkm(int m, int n, int k, double **A, double **B, double **C){    
    int i, j, z;

    for(j = 0; j < n; j++){
        for(i = 0; i < m; i++){
            C[i][j] = 0;
        }
    }

    for(j = 0; j < n; j++){
        for(z = 0; z < k; z++){
			for(i = 0; i < m; i++){
		    	C[i][j] += A[i][z]*B[z][j];
			}
		}
	}
}

void matmult_kmn(int m, int n, int k, double **A, double **B, double **C){    
    int i, j, z;

    for(j = 0; j < n; j++){
        for(i = 0; i < m; i++){
            C[i][j] = 0;
        }
    }

    for(z = 0; z < k; z++){
        for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
		    	C[i][j] += A[i][z]*B[z][j];
			}
		}
	}
}

void matmult_knm(int m, int n, int k, double **A, double **B, double **C){    
    int i, j, z;

    for(j = 0; j < n; j++){
        for(i = 0; i < m; i++){
            C[i][j] = 0;
        }
    }

    for(z = 0; z < k; z++){
        for(j = 0; j < n; j++){
            for(i = 0; i < m; i++){
		    	C[i][j] += A[i][z]*B[z][j];
			}
		}
	}
}