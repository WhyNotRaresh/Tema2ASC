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
	double *C = (double *) calloc(N * N, sizeof(double));
	int i, j, k;

	/* S1 = B * Bt */
	double *S1 = (double *) calloc(N * N, sizeof(double));
	for (i = 0; i < N; i++) {
		double *line_ptr_B = B + i * N;
		for (j = 0; j < N; j++){
			double *line_ptr_Bt = B + j * N;
			for (k = 0; k < N; k++){
				S1[i * N + j] += line_ptr_B[k] * line_ptr_Bt[k];
			}
		}
	}

	/* C = A * S1 */
	for (i = 0; i < N; i++) {
		double *line_ptr_A = A + i * N;
		for (j = 0; j < N; j++){
			for (k = i; k < N; k++){
				C[i * N + j] += line_ptr_A[k] * S1[k * N + j];
			}
		}
	}
	free(S1);

	/* C += A * At */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			for (k = 0; k <= MIN(i, j); k++){
				C[i * N + j] += A[k * N + i] * A[k * N + j];
			}
		}
	}

	return C;
}
