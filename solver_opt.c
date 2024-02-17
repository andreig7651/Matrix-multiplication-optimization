/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */

double* transpose(int size, double *A) {

	double *C;
	register int i, j;
	register double* pa, *pc;
	C = calloc(size * size, sizeof(*C));
	for (i = 0; i < size; i++) {
		pa = &A[i * size];
        pc = &C[i];
		for (j = 0; j < size; j++)
		{	
			*pc = *pa;
            pa++;
            pc += size;
		}
	}

    return C;
}

double* normal_multiply(int size, double* A, double* B) {

	double *C;
	C = calloc(size * size, sizeof(*C));
	register int i, j, k;
	register double *orig_pa, *pa, *pb;
	register double suma;
	for(i = 0; i < size; i++){
		orig_pa = &(A[i * size + 0]);
		for(j = 0; j < size; j++){
			pa = orig_pa;
			pb = &B[0 * size + j];
			suma = 0.0;
			for(k = 0; k < size; k++){
				suma += *pa * *pb;
				pa++;
				pb += size;
			}
			C[i * size + j] = suma;
		}
	}
	return C;
}

double* upper_multiply(int size, double* A, double* B) {

	double *C;
	C = calloc(size * size, sizeof(*C));
	register int i, j, k;
	register double *orig_pa, *pa, *pb;
	register double suma;
	for(i = 0; i < size; i++){
		orig_pa = &(A[i * size + i]);
		for(j = 0; j < size; j++){
			pa = orig_pa;
			pb = &B[i * size + j];
			suma = 0.0;
			for(k = i; k < size; k++){
				suma += *pa * *pb; 
				pa++;
				pb += size;
			}
			C[i * size + j] = suma;
		}
	}
	return C;
}

double* lower_multiply(int size, double* A, double* B) {

	double *C;
	C = calloc(size * size, sizeof(*C));
	register int i, j, k;
	register double *orig_pa, *pa, *pb;
	register double suma;
	for(i = 0; i < size; i++){
		orig_pa = &(A[i * size + 0]);
		for(j = 0; j < size; j++){
			pa = orig_pa + j;
			pb = &B[j * size + j];
			suma = 0.0;
			for(k = 0; k < size - j; k++){
				suma += *pa * *pb;
				pa++;
				pb += size;
			}
			C[i * size + j] = suma;
		}
	}
	return C;
}

double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");
	double* C = calloc(N * N, sizeof(*C));
	double* AT = transpose(N, A);
    double* BT = transpose(N, B);
    double* M1 = upper_multiply(N, A, B);
    double* M2 = lower_multiply(N, M1, AT);
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
