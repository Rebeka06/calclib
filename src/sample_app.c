#include "calclib.h"
#include <stdio.h>

int main() {
    printf("SAMPLE APPLICATION FOR calclib \n\n");

    //Poly
    double poly[] = {1, -3, 2};   // 1 - 3x + 2x²
    printf("Poly Evaluate at x=3: %f\n", poly_evaluate(poly, 2, 3.0));
    double deriv[2];
    poly_derivative(poly, 2, deriv);
    printf("Poly Derivative coeffs: %.1f, %.1f\n", deriv[0], deriv[1]);

    //Matrix
    double Arow1[] = {1, 2}, Arow2[] = {3, 4};
    double* A[] = {Arow1, Arow2};
    double Brow1[] = {2, 0}, Brow2[] = {1, 2};
    double* B[] = {Brow1, Brow2};
    double** C = matrix_multiply(A, 2, 2, B, 2, 2);
    if (C) {
        printf("Matrix C[0][0] = %f\n", C[0][0]);
        free(C[0]);
        free(C);
    } else {
        printf("Matrix multiplication failed\n");
    }

    //Fraction
    Fraction f1 = {1, 2}, f2 = {1, 3};
    Fraction s = frac_add(f1, f2);
    printf("Fraction 1/2 + 1/3 = %d/%d\n", s.num, s.den);

    // Calculus
    printf("Calculus factorial(6) = %f\n", factorial(6));
    printf("Calculus sin(1) approx (10 terms) = %f\n", series_sin(1.0, 10));

    //Trig
    double angle_deg = 45;
    double angle_rad = deg_to_rad(angle_deg);
    printf("Trig sin(45°) = %f\n", trig_sin(angle_rad));
    printf("Trig arctan(1) = %f°\n", rad_to_deg(trig_arctan(1)));

    printf("\nEND OF DEMO \n");
    return 0;
}
