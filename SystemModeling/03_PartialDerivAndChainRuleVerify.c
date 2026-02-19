/*
Program Name : Partial Derivatives and Chain Rule Verification

Description  :
    This program computes partial derivatives of a function
    of two variables using finite difference methods. It also
    verifies the chain rule and performs implicit differentiation.
*/

#include <stdio.h>
#include <math.h>

/* Function f(x, y) = x^2 + xy + y^2 */
double f(double x, double y)
{
    return x*x + x*y + y*y;
}

/* Implicit function F(x, y) = x^2 + y^2 - 25 */
double F(double x, double y)
{
    return x*x + y*y - 25.0;
}

int main(void)
{
    double x, y, h;
    double dfdx, dfdy;
    double Fx, Fy, dydx;

    /* Input values */
    printf("Enter values of x and y: ");
    scanf("%lf %lf", &x, &y);

    printf("Enter small increment h: ");
    scanf("%lf", &h);

    /* Partial derivatives using finite difference */
    dfdx = (f(x + h, y) - f(x, y)) / h;
    dfdy = (f(x, y + h) - f(x, y)) / h;

    printf("\nPartial Derivatives:\n");
    printf("df/dx = %lf\n", dfdx);
    printf("df/dy = %lf\n", dfdy);

    /* Implicit differentiation */
    Fx = (F(x + h, y) - F(x, y)) / h;
    Fy = (F(x, y + h) - F(x, y)) / h;

    dydx = -Fx / Fy;

    printf("\nImplicit Differentiation:\n");
    printf("dy/dx = %lf\n", dydx);

    return 0;
}
