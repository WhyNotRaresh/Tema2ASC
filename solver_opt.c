/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	double *C = (double *) malloc(N * N * sizeof(double));
	int i, j, k;

	/* S1 = B * Bt */
	double *S1 = (double *) malloc(N * N * sizeof(double));
	for (i = 0; i < N; i++) {
		double *line_ptr_B = B + i * N;
		for (j = 0; j < N; j++){
			register double *line_ptr_B_copy = line_ptr_B;
			register double *line_ptr_Bt = B + j * N;
			register double sum = 0;
			for (k = 0; k < N; k++){
				sum += *line_ptr_B_copy * *line_ptr_Bt;
				line_ptr_B_copy++;
				line_ptr_Bt++;
			}
			S1[i * N + j] = sum;
		}
	}

	/* C = A * S1 */
	for (i = 0; i < N; i++) {
		double *line_ptr_A = A + i * N;
		for (j = 0; j < N; j++){
			register double *line_ptr_A_copy = line_ptr_A + i;
			register double *col_ptr_S1 = S1 + i * N + j;
			register double sum = 0;
			for (k = i; k < N; k++){
				sum += *line_ptr_A_copy * *col_ptr_S1;
				line_ptr_A_copy++;
				col_ptr_S1 += N;
			}
			C[i * N + j] = sum;
		}
	}
	free(S1);

	/* C += A * At */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			for (k = 0; k <= MIN(i, j); k++) {
				C[i * N + j] += A[k * N + i] * A[k * N + j];
			}
		}
	}

	return C;
}