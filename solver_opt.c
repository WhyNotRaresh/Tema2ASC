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
		for (j = 0; j < N; j++){
			double *line_ptr = B + j * N;
			for (k = 0; k < N; k++){
				double b = line_ptr[k];
				S1[i * N + j] += b * b;
			}
		}
	}

	/* C = A * S1 */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			double *line_ptr_A = A + j * N;
			for (k = j; k < N; k++){
				C[i * N + j] += line_ptr_A[k] * S1[k * N + j];
			}
		}
	}
	free(S1);

	/* C += A * At */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			double *line_ptr = A + j * N;
			for (k = j; k < N; k++){
				double a = line_ptr[k];
				C[i * N + j] += a * a;
			}
		}
	}

	return C;
}
