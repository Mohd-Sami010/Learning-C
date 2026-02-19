/*
Program Name : Euler Method and Mass-Spring System
Description  :
    This program numerically solves ordinary differential
    equations using Euler's method. It also models the free
    oscillations of a mass-spring system by converting a
    second-order ODE into a system of first-order equations.
*/

#include <stdio.h>

/* Function defining dy/dx = f(x,y) = x + y */
double f(double x, double y)
{
    return x + y;
}

int main(void)
{
    /* Variables for Euler's method */
    double x0, y0, h;
    int n, i;

    /* Variables for mass-spring system */
    double m, k;
    double x, v, t;

    /* Euler method for first-order ODE */
    printf("Euler Method for dy/dx = x + y\n");
    printf("Enter initial x0 and y0: ");
    scanf("%lf %lf", &x0, &y0);

    printf("Enter step size h and number of steps: ");
    scanf("%lf %d", &h, &n);

    printf("\n x\t y\n");
    for (i = 0; i < n; i++)
    {
        printf("%lf\t%lf\n", x0, y0);
        y0 = y0 + h * f(x0, y0);
        x0 = x0 + h;
    }

    /* Mass-spring system */
    printf("\nMass-Spring System (Free Oscillation)\n");
    printf("Enter mass m and spring constant k: ");
    scanf("%lf %lf", &m, &k);

    printf("Enter initial displacement and velocity: ");
    scanf("%lf %lf", &x, &v);

    printf("Enter time step h and number of steps: ");
    scanf("%lf %d", &h, &n);

    t = 0.0;

    printf("\n t\t x\t v\n");
    for (i = 0; i < n; i++)
    {
        printf("%lf\t%lf\t%lf\n", t, x, v);

        /* Euler updates */
        x = x + h * v;
        v = v - h * (k / m) * x;
        t = t + h;
    }

    return 0;
}
