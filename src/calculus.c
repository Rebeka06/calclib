#include "calculus.h"

#include <stdio.h>
#include <math.h>

// Factorial
double factorial(int n) {
    double res = 1;
    for(int i=2;i<=n;i++) res *= i;
    return res;
}


// e^x using series 
double series_exp(double x, int n) {
    double sum = 1, term = 1;
    for(int i=1;i<=n;i++){
        term *= x/i;
        sum += term;
    }
    return sum;
}

// Sin(x) using series
double series_sin(double x, int n){
    double sum=0, term=x;
    for(int i=0;i<n;i++){
        if(i>0) term *= -x*x/(2*i*(2*i+1));
        sum += term;
    }
    return sum;
}

// Cos(x) using series
double series_cos(double x, int n){
    double sum=1, term=1;
    for(int i=1;i<n;i++){
        term *= -x*x/(2*i*(2*i-1));
        sum += term;
    }
    return sum;
}

//Fibonacci Sequence
double fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    double a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c = a+b;
        a = b;
        b = c;
    }
    return b;
}