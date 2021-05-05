/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	double *C = (double *) calloc(N * N, sizeof(double));
	int i, j, k;

	/* S1 = B * Bt */
	double *S1 = (double *) calloc(N * N, sizeof(double));
	for (i = 0; i < N; i++) {
		double *line_ptr_B = B + i * N;
		for (k = 0; k < N; k++) {
			double b = line_ptr_B[k];
			double elem = b * b;
			for (j = 0; j < N; j++) {
				S1[i * N + j] += elem;
			}
		}
	}

	/* C = A * S1 */
	for (i = 0; i < N; i++) {
		double *line_ptr_A = A + i * N;
		for (j = 0; j < N; j++){
			double *line_ptr_A_copy = line_ptr_A + i;
			double *col_ptr_S1 = S1 + j;
			register double sum = 0;
			for (k = i; k < N; k++){
				sum += *line_ptr_A_copy * *col_ptr_S1;
				line_ptr_A_copy++;
				col_ptr_S1 += N;
			}
			C[i * N + j] += sum;
		}
	}
	free(S1);

	/* C += A * At */
	for (i = 0; i < N; i++) {
		double *line_ptr_A = A + i * N;
		for (k = i; k < N; k++){
			double a = line_ptr_A[k];
			double elem = a * a;
			for (j = 0; j < N; j++){
				C[i * N + j] += elem;
			}
		}
	}

	return C;
}
