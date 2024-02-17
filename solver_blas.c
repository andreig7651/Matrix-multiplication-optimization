/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"
#include <cblas.h>
#include <string.h>

double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");
	double* C = calloc(N * N, sizeof(*C));
    memcpy(C, B, N * N * sizeof(double));

    cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1.0, A, N, C, N);
    cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1.0, A, N, C, N);
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasTrans, N, N, N, 1.0, B, N, B, N, 1.0, C, N);
    
	return C;
}
