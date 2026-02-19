/*
Program Name : Stationary Point Classification Using Partial Derivatives
Description  :
    This program numerically evaluates first-order and second-order
    partial derivatives of a two-variable function using finite
    difference approximations. It then applies the Hessian determinant
    test to classify the stationary point as a local minimum, local
    maximum, saddle point, or inconclusive.
*/

#include <stdio.h>
#include <math.h>

/* Function f(x,y) = x^3 + y^3 - 3xy */
double f(double x, double y)
{
    return x*x*x + y*y*y - 3*x*y;
}

/* Constraint function g(x,y) = x^2 + y^2 - 1 */
double g(double x, double y)
{
    return x*x + y*y - 1.0;
}

int main(void)
{
    double x, y, h;
    double fx, fy, fxx, fyy, fxy;
    double D;

    printf("Enter values of x and y: ");
    scanf("%lf %lf", &x, &y);

    printf("Enter small increment h: ");
    scanf("%lf", &h);

    /* First-order partial derivatives */
    fx = (f(x + h, y) - f(x, y)) / h;
    fy = (f(x, y + h) - f(x, y)) / h;

    /* Second-order partial derivatives */
    fxx = (f(x + h, y) - 2*f(x, y) + f(x - h, y)) / (h*h);
    fyy = (f(x, y + h) - 2*f(x, y) + f(x, y - h)) / (h*h);
    fxy = (f(x + h, y + h) - f(x + h, y) - f(x, y + h) + f(x, y)) / (h*h);

    D = fxx * fyy - fxy * fxy;

    printf("\nFirst Derivatives:\n");
    printf("fx = %lf, fy = %lf\n", fx, fy);

    printf("\nSecond Derivatives:\n");
    printf("fxx = %lf, fyy = %lf, fxy = %lf\n", fxx, fyy, fxy);

    printf("\nClassification of Stationary Point:\n");

    if (D > 0 && fxx > 0)
        printf("Local Minimum\n");
    else if (D > 0 && fxx < 0)
        printf("Local Maximum\n");
    else if (D < 0)
        printf("Saddle Point\n");
    else
        printf("Inconclusive Test\n");

    return 0;
}
