#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

double** matrix_multiply(double** A, int rowsA, int columnsA,
                         double** B, int rowsB, int columnsB) {
    if (columnsA != rowsB) {
        printf("Error: The multiplication cannot be done! \n");
        return NULL;
    }
    double** result = malloc(rowsA * sizeof(double*));
    for (int i = 0; i < rowsA; i++) {
        result[i] = malloc(columnsB * sizeof(double));
    }
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            double sum = 0;
            for (int k = 0; k < columnsA; k++) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}



double** create_minor(double** A, int n, int removed_columns) {
    double** M = malloc((n - 1) * sizeof(double*));
    for (int i = 0; i < n - 1; i++) {
        M[i] = malloc((n - 1) * sizeof(double));
    }
    int mi = 0; 
    for (int i = 1; i < n; i++) {
        int mj = 0;    
        for (int j = 0; j < n; j++) {
            if (j == removed_columns) continue;  
            M[mi][mj] = A[i][j];
            mj++;
        }
        mi++;
    }
    return M;
}
void free_minor(double** M, int size) {
    for (int i = 0; i < size; i++) {
        free(M[i]);
    }
    free(M);
}