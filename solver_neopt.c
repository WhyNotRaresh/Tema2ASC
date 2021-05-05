/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	double *C = (double *) malloc(N * N * sizeof(double));
	int i, j, k;

	double *At = (double *) malloc(N * N * sizeof(double));
	double *Bt = (double *) malloc(N * N * sizeof(double));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			At[j * N + i] = A[i * N + j];
			Bt[j * N + i] = B[i * N + j];
		}
	}

	/* S1 = B * Bt */
	double *S1 = (double *) calloc(N * N, sizeof(double));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			for (k = 0; k < N; k++){
				S1[i * N + j] += B[i * N + k] * Bt[k * N + j];
			}
		}
	}

	/* C = A * S1 */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			for (k = i; k < N; k++){
				C[i * N + j] = A[i * N + k] * S1[k * N + j];
			}
		}
	}
	free(S1);

	/* C += A * At */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			for (k = i; k < N; k++){
				C[i * N + j] += A[i * N + k] * At[k * N + j];
			}
		}
	}

	free(At);
	free(Bt);
	return C;
}
