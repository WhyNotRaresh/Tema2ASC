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
			for (j = 0; j < N; j++) {
				double b = line_ptr_B[k];
				S1[i * N + j] += b * b;
			}
		}
	}

	/* C = A * S1 */
	for (i = 0; i < N; i++) {
		double *line_ptr_A = A + i * N;
		for (k = i; k < N; k++){
			for (j = 0; j < N; j++){
				C[i * N + j] += line_ptr_A[k] * S1[k * N + j];
			}
		}
	}
	free(S1);

	/* C += A * At */
	for (i = 0; i < N; i++) {
		double *line_ptr_A = A + i * N;
		for (k = i; k < N; k++){
			for (j = 0; j < N; j++){
				double a = line_ptr_A[k];
				C[i * N + j] += a * a;
			}
		}
	}

	return C;
}
