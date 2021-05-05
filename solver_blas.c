/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"
#include "cblas.h"
/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	double *C = calloc(N * N, sizeof(double));

	/* C = B * Bt */
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N, 1.0, B, N,
		B, N, 1.0, C, N);
	
	/* C = A * C */
	cblas_dtrmm(CblasRowMajor,CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
		N, N, 1.0, A, N, C, N);

	/* C += At * A */
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, A, N,
		A, N, 1.0, C, N);
	
	return C;
}
