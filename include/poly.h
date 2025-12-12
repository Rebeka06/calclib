#ifndef POLY_H
#define POLY_H

double poly_evaluate(double coeffs[], int degree, double x);
void poly_derivative(double coeffs[], int degree, double deriv_coeffs[]);
void poly_integral(double coeffs[], int degree, double integral_coeffs[], double C);
void poly_multiply(double A[], int degA, double B[], int degB, double result[], int *degResult);

#endif