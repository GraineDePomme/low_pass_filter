#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double v_in(double t) {
    int temp = floor(2 * t);
    if (temp % 2 == 0) {
        return 1.0;
    } else {
        return -1.0;
    }
}


double dvout_dt(double v_out, double t, double rc) {
    return (1 / rc) * (v_in(t) - v_out);
}


double next_step_rk4(double vout, double t, double h, double rc) {
    double k1 = h * dvout_dt(vout, t, rc);
    double k2 = h * dvout_dt(vout + k1 / 2, t + h / 2, rc);
    double k3 = h * dvout_dt(vout + k2 / 2, t + h / 2, rc);
    double k4 = h * dvout_dt(vout + k3, t + h, rc);
    return vout + (k1 + 2*k2 + 2*k3 + k4) / 6;
}


int main(int argc, char** argv) {
    const double t0 = atof(argv[1]);
    const double tf = atof(argv[2]);
    const int steps_count = atoi(argv[3]);
    const double rc = atof(argv[4]);

    const double h = (tf - t0) / steps_count;

    double t = t0;  
    double vout = 0.0;

    printf("t,vin,vout\n");

    for (t = t0 ; t <= tf ; t += h) {
        printf("%f,%f,%f\n", t, v_in(t), vout);
        vout = next_step_rk4(vout, t, h, rc);
    }

    return 0;
}