#include "poly.h"

#include <stdlib.h>
#include <string.h>


double poly_evaluate(double coeffs[], int degree, double x) {
    double result = coeffs[degree];  
    for (int i = degree - 1; i >= 0; i--) {
        result = result * x + coeffs[i];   
    }
    return result;
}



void poly_derivative(double coeffs[], int degree, double deriv_coeffs[]) {
    for (int i = 1; i <= degree; i++) {
        deriv_coeffs[i-1] = i * coeffs[i];  
    }
}



void poly_integral(double coeffs[], int degree, double integral_coeffs[], double C) {
    integral_coeffs[0] = C; // constant 
    for (int i = 0; i <= degree; i++) {
        integral_coeffs[i+1] = coeffs[i] / (i + 1); // a_i / (i+1)
    }
}



void poly_multiply(double A[], int degA, double B[], int degB, double result[], int *degResult) {
 
    for (int i = 0; i <= degA + degB; i++)
        result[i] = 0;


    for (int i = 0; i <= degA; i++) {
        for (int j = 0; j <= degB; j++) {
            result[i + j] += A[i] * B[j];
        }
    }

    *degResult = degA + degB;
}


