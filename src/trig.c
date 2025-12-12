#include "trig.h"

#include <math.h>

//Basics of Trigonometry
double trig_sin(double x) { return sin(x); }
double trig_cos(double x) { return cos(x); }
double trig_tan(double x) { return tan(x); }

// Inversions of Trigonometry
double trig_arcsin(double x) { return asin(x); } // returns radians
double trig_arccos(double x) { return acos(x); } // returns radians
double trig_arctan(double x) { return atan(x); } // returns radians

// Degree/radian Conversion

double deg_to_rad(double deg) { return deg * M_PI / 180.0; }
double rad_to_deg(double rad) { return rad * 180.0 / M_PI; }