#ifndef FRAC_H
#define FRAC_H

typedef struct {
    int num;
    int den;
} Fraction;

int gcd(int a, int b);
Fraction frac_simplify(Fraction f);
Fraction frac_add(Fraction a, Fraction b);
Fraction frac_sub(Fraction a, Fraction b);
Fraction frac_mul(Fraction a, Fraction b);
Fraction frac_div(Fraction a, Fraction b);

#endif