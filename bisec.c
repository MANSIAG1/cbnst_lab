#include <stdio.h>
#include <math.h>

double f(double x) {
    // return x * sin(x); 
    return (x * x * x) - (4 * x) - 9;
}

void bisection(double firstno, double endno, double tolerance_value) {
    if ((f(firstno) * f(endno)) >= 0) {
        printf("Incorrect first and end numbers\n");
        return;
    }

    double x2;
    int iteration = 1;

    printf("%-10s %-10s %-10s %-10s\n", "Iteration", "First", "End", "f(x2)");

    while ((endno - firstno) >= tolerance_value) {
        x2 = (firstno + endno) / 2;
        printf("%-10d %-10.6f %-10.6f %-10.6f\n", iteration, firstno, endno, f(x2));
        iteration++;
        
        if (f(x2) == 0.0) {
            printf("The result is %.6f\n", x2);
            return;
        }
        
        if (f(firstno) * f(x2) < 0) {
            endno = x2;
        } else {
            firstno = x2;
        }
    }

    printf("The result is %.6f\n", x2);
}

int main() {
    double firstno, endno, tolerance_value;
    printf("Enter the first number of the interval: ");
    scanf("%lf", &firstno);
    printf("Enter the second number of the interval: ");
    scanf("%lf", &endno);
    printf("Enter the tolerance value: ");
    scanf("%lf", &tolerance_value);

    bisection(firstno, endno, tolerance_value);

    return 0;
}
