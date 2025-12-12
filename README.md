CALCLIB
A C library for mathematical computation assistance, designed to help with polynomials, linear algebra, calculus, fractions, and trigonometry.
Built with CMake and standard C libraries.

Requirements
CMake 3.16 or higher
A C11-compatible compiler (GCC, Clang, MSVC, etc.)
Standard C libraries


Quick Start
1. Clone the repository
bashgit clone <(https://github.com/Rebeka06/CalcLib.git)> calclib
cd calclib
2. Build the project
bash mkdir build
cd build
cmake ..
make
3. Run tests
bashctest --output-on-failure

Features
# Polynomial Operations (poly.c)

Evaluate polynomials using Horner's method
Calculate derivatives and integrals
Multiply polynomials


# Matrix Operations (matrix.c)

Matrix multiplication
Matrix inversion (Gauss-Jordan elimination)
Minor matrix creation

# Calculus & Series (calculus.c)

Factorial computation
Series approximations for e^x, sin(x), cos(x)
Fibonacci sequence generation

# Fraction Arithmetic (frac.c)

Add, subtract, multiply, and divide fractions
Automatic simplification with GCD

# Trigonometry (trig.c)

Standard and inverse trig functions
Degree/radian conversion utilities


Building and Testing
Standard build
bashmkdir build
cd build
cmake ..
make
Run all tests
bashctest --verbose
Run specific test
bash./tests/test_poly
./tests/test_matrix
./tests/test_calculus
./tests/test_frac
./tests/test_trig
Clean build (start fresh)
bashrm -rf build
mkdir build
cd build
cmake ..
make
Build on Windows
bashmkdir build
cd build
cmake ..
cmake --build .

## Running the Sample Application

The repository includes a sample application (`src/sample.c`) that demonstrates the library's capabilities.

# Build and run the sample:
```bash
mkdir build
cd build
cmake ..
make
./calclib_demo  # Linux/Mac
# or
./calclib_demo.exe  # Windows
```

# What the sample demonstrates:
- Polynomial evaluation and operations
- Matrix multiplication and inversion
- Series approximations (e^x, sin, cos)
- Fraction arithmetic
- Trigonometric functions

The sample application provides a quick way to see the library in action before integrating it into your own projects.



Usage Examples

# Polynomial Operations
c#include "calclib.h"

int main() {
    // Evaluate polynomial: 2x^2 + 3x + 1 at x = 2
    double coeffs[] = {1.0, 3.0, 2.0};  // constant term first
    double result = poly_evaluate(coeffs, 2, 2.0);
    printf("Result: %f\n", result);  // Output: 15.0
    
    // Calculate derivative
    double deriv[2];
    poly_derivative(coeffs, 2, deriv);
    // deriv now contains coefficients of 4x + 3
    
    // Multiply polynomials: (2x + 1) * (x + 3)
    double A[] = {1.0, 2.0};  // 2x + 1
    double B[] = {3.0, 1.0};  // x + 3
    double product[4];
    int product_deg;
    poly_multiply(A, 1, B, 1, product, &product_deg);
    // product now contains 2x^2 + 7x + 3
    
    return 0;
}


# Matrix Operations
c#include "calclib.h"

int main() {
    // Create 2x2 matrices
    double** A = malloc(2 * sizeof(double*));
    double** B = malloc(2 * sizeof(double*));
    for (int i = 0; i < 2; i++) {
        A[i] = malloc(2 * sizeof(double));
        B[i] = malloc(2 * sizeof(double));
    }
    
    // Initialize matrices
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    
    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;
    
    // Multiply matrices
    double** C = matrix_multiply(A, 2, 2, B, 2, 2);
    
    // Invert matrix
    double** inv = inverse_simple(A, 2);
    
    // Free memory
    for (int i = 0; i < 2; i++) {
        free(A[i]); free(B[i]); free(C[i]); free(inv[i]);
    }
    free(A); free(B); free(C); free(inv);
    
    return 0;
}


# Series Approximations
c#include "calclib.h"

int main() {
    // Approximate e^2 using 10 terms
    double exp_approx = series_exp(2.0, 10);
    printf("e^2 ≈ %f\n", exp_approx);
    
    // Approximate sin(π/4) using 10 terms
    double sin_approx = series_sin(M_PI / 4.0, 10);
    printf("sin(π/4) ≈ %f\n", sin_approx);
    
    // Approximate cos(π/3) using 10 terms
    double cos_approx = series_cos(M_PI / 3.0, 10);
    printf("cos(π/3) ≈ %f\n", cos_approx);
    
    // Calculate 10th Fibonacci number
    double fib = fibonacci(10);
    printf("F(10) = %f\n", fib);
    
    return 0;
}


# Fraction Arithmetic
c#include "calclib.h"

int main() {
    Fraction a = {3, 4};   // 3/4
    Fraction b = {2, 5};   // 2/5
    
    Fraction sum = frac_add(a, b);
    printf("%d/%d + %d/%d = %d/%d\n", 
           a.num, a.den, b.num, b.den, sum.num, sum.den);
    // Output: 3/4 + 2/5 = 23/20
    
    Fraction diff = frac_sub(a, b);
    printf("%d/%d - %d/%d = %d/%d\n", 
           a.num, a.den, b.num, b.den, diff.num, diff.den);
    // Output: 3/4 - 2/5 = 7/20
    
    Fraction prod = frac_mul(a, b);
    printf("%d/%d * %d/%d = %d/%d\n", 
           a.num, a.den, b.num, b.den, prod.num, prod.den);
    // Output: 3/4 * 2/5 = 3/10 (automatically simplified)
    
    Fraction quot = frac_div(a, b);
    printf("%d/%d ÷ %d/%d = %d/%d\n", 
           a.num, a.den, b.num, b.den, quot.num, quot.den);
    // Output: 3/4 ÷ 2/5 = 15/8
    
    return 0;
}


# Trigonometry
c#include "calclib.h"

int main() {
    // Standard functions (input in radians)
    double sine = trig_sin(M_PI / 6);
    printf("sin(π/6) = %f\n", sine);  // 0.5
    
    double cosine = trig_cos(M_PI / 3);
    printf("cos(π/3) = %f\n", cosine);  // 0.5
    
    double tangent = trig_tan(M_PI / 4);
    printf("tan(π/4) = %f\n", tangent);  // 1.0
    
    // Inverse functions
    double angle1 = trig_arcsin(0.5);
    printf("arcsin(0.5) = %f radians\n", angle1);  // π/6
    
    double angle2 = trig_arccos(0.5);
    printf("arccos(0.5) = %f radians\n", angle2);  // π/3
    
    double angle3 = trig_arctan(1.0);
    printf("arctan(1.0) = %f radians\n", angle3);  // π/4
    
    // Conversions
    double rad = deg_to_rad(180.0);
    printf("180° = %f radians\n", rad);  // π
    
    double deg = rad_to_deg(M_PI);
    printf("π radians = %f°\n", deg);  // 180.0
    
    return 0;
}

# Project Structure
calclib/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── calclib.h
│   ├── poly.h
│   ├── matrix.h
│   ├── calculus.h
│   ├── frac.h
│   └── trig.h
├── src/
│   ├── poly.c
│   ├── matrix.c
│   ├── calculus.c
│   ├── frac.c
│   └── trig.c
│   └── sample_app.c
└── tests/
    ├── CMakeLists.txt
    ├── test_poly.c
    ├── test_matrix.c
    ├── test_calculus.c
    ├── test_frac.c
    └── test_trig.c

API Reference
Polynomial Functions

double poly_evaluate(double coeffs[], int degree, double x) - Evaluate polynomial at x using Horner's method
void poly_derivative(double coeffs[], int degree, double deriv_coeffs[]) - Calculate derivative coefficients
void poly_integral(double coeffs[], int degree, double integral_coeffs[], double C) - Calculate integral coefficients with constant C
void poly_multiply(double A[], int degA, double B[], int degB, double result[], int *degResult) - Multiply two polynomials

Matrix Functions

double** matrix_multiply(double** A, int rowsA, int columnsA, double** B, int rowsB, int columnsB) - Multiply two matrices (returns NULL if dimensions incompatible)
double** inverse_simple(double** A, int n) - Invert square matrix using Gauss-Jordan elimination (returns NULL if singular)
double** create_minor(double** A, int n, int removed_columns) - Create minor matrix by removing first row and specified column
void free_minor(double** M, int size) - Free memory allocated for minor matrix

Calculus Functions

double factorial(int n) - Calculate n! (factorial)
double series_exp(double x, int n) - Approximate e^x using first n terms of Taylor series
double series_sin(double x, int n) - Approximate sin(x) using first n terms of Taylor series
double series_cos(double x, int n) - Approximate cos(x) using first n terms of Taylor series
double fibonacci(int n) - Calculate nth Fibonacci number (F(0)=0, F(1)=1)

Fraction Functions

int gcd(int a, int b) - Calculate greatest common divisor using Euclidean algorithm
Fraction simplify(Fraction f) - Reduce fraction to lowest terms
Fraction add(Fraction a, Fraction b) - Add two fractions (result is automatically simplified)
Fraction sub(Fraction a, Fraction b) - Subtract two fractions (result is automatically simplified)
Fraction mul(Fraction a, Fraction b) - Multiply two fractions (result is automatically simplified)
Fraction div(Fraction a, Fraction b) - Divide two fractions (result is automatically simplified)

Trigonometry Functions

double trig_sin(double x) - Calculate sine (input in radians)
double trig_cos(double x) - Calculate cosine (input in radians)
double trig_tan(double x) - Calculate tangent (input in radians)
double trig_arcsin(double x) - Calculate arcsine (returns radians, input must be in [-1, 1])
double trig_arccos(double x) - Calculate arccosine (returns radians, input must be in [-1, 1])
double trig_arctan(double x) - Calculate arctangent (returns radians)
double deg_to_rad(double deg) - Convert degrees to radians
double rad_to_deg(double rad) - Convert radians to degrees


Notes

The library uses standard C libraries: math.h, stdlib.h, stdio.h, string.h.
Polynomial coefficients are stored with the constant term first: [a₀, a₁, a₂, ...] represents a₀ + a₁x + a₂x² + ...
Matrix operations return NULL on error (incompatible dimensions, singular matrix, etc.).
All fraction operations automatically simplify the result.
Trigonometric functions use radians (use conversion functions for degrees).
Memory management for matrices is manual - always free allocated memory.


Troubleshooting
CMake can't find the compiler?

Make sure you have a C compiler installed (GCC, Clang, or MSVC)
On Linux: sudo apt-get install build-essential cmake
On macOS: Install Xcode Command Line Tools: xcode-select --install
On Windows: Install MinGW or Visual Studio

Build fails?

Make sure you're using CMake 3.15 or higher: cmake --version
Try a clean build: rm -rf build && mkdir build && cd build && cmake .. && make

Tests failing?

Run individual tests to isolate issues: ./tests/test_poly
Check that all source files are compiled correctly

Linking errors?

Make sure you're linking against the math library (-lm flag is usually automatic with CMake)


Tips for Developers

Always free dynamically allocated memory (especially for matrices)
Check return values from matrix operations for NULL (indicates error)
Use ctest --verbose to see detailed test output
When using fractions, denominators should never be zero
Trigonometric functions expect radians - use conversion functions if working with degrees

For better series approximations, use more terms (but be aware of computational cost)

