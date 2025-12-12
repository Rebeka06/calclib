#ifndef MATRIX_H
#define MATRIX_H

double** matrix_multiply(double** A, int rowsA, int columnsA,
                         double** B, int rowsB, int columnsB);

double** create_minor(double** A, int n, int removed_columns);
void free_minor(double** M, int size);

#endif