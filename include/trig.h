#ifndef TRIG_H
#define TRIG_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double trig_sin(double x);
double trig_cos(double x);
double trig_tan(double x);

double trig_arcsin(double x);
double trig_arccos(double x);
double trig_arctan(double x);

double deg_to_rad(double deg);
double rad_to_deg(double rad);

#endif