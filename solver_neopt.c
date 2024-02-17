/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */

double* transpose(int size, double *A) {
    double *C;
	C = calloc(size * size, sizeof(*C));
    for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{	
			C[i * size + j] = A[j * size + i];
		}
	}

    return C;
}

double* multiply_upper(int size, double *A, double* B) {
	
    double *C;
	C = calloc(size * size, sizeof(*C));
     for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = i; k < size; k++) {
                C[i * size + j] += A[i * size + k] * B[k * size + j];
            }
        }
    }
    
    return C;
}

double* normal_multiply(int size, double *A, double* B) {
	
    double *C;
	C = calloc(size * size, sizeof(*C));
     for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i * size + j] += A[i * size + k] * B[k * size + j];
                
            }
        }
    }
    
    return C;
}

double* multiply_lower(int size, double *A, double* B) {
	
    double *C;
	C = calloc(size * size, sizeof(*C));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = j; k < size; k++) {
                C[i * size + j] += A[i * size + k] * B[k * size + j];
            }
        }
    }
    
    return C;
}

double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");
	
	double* C = calloc(N * N, sizeof(*C));
	double* AT = transpose(N, A);
    double* BT = transpose(N, B);
    double* M1 = multiply_upper(N, A, B);
    double* M2 = multiply_lower(N, M1, AT);
    double* M3 = normal_multiply(N, BT, BT);

	for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            C [i * N + j] = M2[i * N + j] + M3[i * N + j];

	free(AT);
	free(BT);
	free(M1);
	free(M2);
	free(M3);

	return C;
}
