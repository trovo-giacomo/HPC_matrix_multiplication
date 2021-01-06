void matmult_nat(int m, int n,, int k, double **A, double **B, double **C){    
    int i, j, z;

    for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			double sum = 0.0;
			for(z = 0; z<k; z++){
		    	sum += A[i][z]*B[z][j];
			}
			C[i][j] = sum;
		}
	}
}
