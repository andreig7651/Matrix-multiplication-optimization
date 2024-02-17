#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 4

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
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = i; k < N; k++) {
                C[i * size + j] += A[i * size + k] * B[k * size + j];
            }
        }
    }
    
    return C;
}

double* normal_multiply(int size, double *A, double* B) {
	
    double *C;
	C = calloc(size * size, sizeof(*C));
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
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
                C[i * N + j] += A[i * N + k] * B[k * N + j];
            }
        }
    }
    
    return C;
}


int main(void)
{
	int numMatrixElems = N * N;
	double *A;
	double *B;
    double *C;
	

	A = malloc(numMatrixElems * sizeof(*A));
	B = malloc(numMatrixElems * sizeof(*B));

	srand(123);
    
	for (int i = 0; i < numMatrixElems; i++)
	{
		A[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
		B[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
	}

	A[4] = 0;
	A[8] = 0;
	A[9] = 0;
	A[12] = 0;
	A[13] = 0;
	A[14] = 0;

    double* AT = transpose(N, A);
    double* BT = transpose(N, B);
    double* M1 = multiply_upper(N, A, B);
    double* M2 = multiply_lower(N, M1, AT);
    double* M3 = normal_multiply(N, BT, BT);

	printf("===================A==================\n");
	for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%f ", A[i * N + j]);
        printf("\n");
    }

	printf("===================AT==================\n");
	for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%f ", AT[i * N + j]);
        printf("\n");
    }

	printf("===================B==================\n");
	for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%f ", B[i * N + j]);
        printf("\n");
    }

	printf("===================BT==================\n");
	for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%f ", BT[i * N + j]);
        printf("\n");
    }
    
    printf("===================RES==================\n");
	for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%f ", M2[i * N + j]);
        printf("\n");
    }

	free(A);
	free(B);
	free(C);

	return 0;
}