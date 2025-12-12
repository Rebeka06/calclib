#include "frac.h"

#include <stdio.h>
#include <math.h>

Fraction frac_simplify(Fraction f);

// GCD calculation
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Fraction frac_simplify(Fraction f) {
    if (f.den == 0) {
        // Handle division by zero
        f.num = 0;
        f.den = 1;
        return f;
    }
    
    int g = gcd(abs(f.num), abs(f.den));
    f.num /= g;
    f.den /= g;
    
    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    
    return f;
}

// Addition of Fractions
Fraction frac_add(Fraction a, Fraction b) {
    Fraction res = {a.num * b.den + b.num * a.den, a.den * b.den};
    return frac_simplify(res);
}

// Subtraction of Fractions
Fraction frac_sub(Fraction a, Fraction b) {
    Fraction res = {a.num * b.den - b.num * a.den, a.den * b.den};
    return  frac_simplify(res);
}

// Multiplication of Fractions
Fraction frac_mul(Fraction a, Fraction b) {
    Fraction res = {a.num * b.num, a.den * b.den};
    return frac_simplify (res);
}

// Division of Fractions
Fraction frac_div(Fraction a, Fraction b) {
    Fraction res = {a.num * b.den, a.den * b.num};
    return frac_simplify(res);
}