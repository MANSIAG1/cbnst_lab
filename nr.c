#include <stdio.h>
#include <math.h>

/* Define function f(x) which is to be solved */
#define f(x) cos(x) - 3 * x + 1

/* Define g1(x) for the fixed point iteration function */
#define g1(x) (1 + cos(x)) / 3

int main() {
    int step = 1, N;
    float x0, x1, e, guess1, guess2;

    /* Inputs */
    printf("Enter first initial guess: ");
    scanf("%f", &guess1);
    printf("Enter second initial guess: ");
    scanf("%f", &guess2);

    /* Choose the guess closest to 0 */
    if (fabs(guess1) < fabs(guess2))
        x0 = guess1;
    else
        x0 = guess2;

    printf("Initial guess closest to 0: %f\n", x0);

    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iterations: ");
    scanf("%d", &N);

    /* Print g1(x0) for the initial guess */
    printf("\ng1(x0) = %f\n", g1(x0));

    /* Implementing Fixed Point Iteration using g1(x) */
    printf("\nStep\t\tx0\t\t\tx1\t\t\tf(x1)\n");
    do {
        x1 = g1(x0);  // Using g1(x)
        printf("%d\t\t%f\t%f\t%f\n", step, x0, x1, f(x1));

        step = step + 1;

        if (step > N) {
            printf("Not Convergent.\n");
            return 1;
        }

        x0 = x1;

    } while (fabs(f(x1)) > e);

    printf("\nThe approx Root is %f after %d iterations\n", x1, step - 1);

    return 0;
}

