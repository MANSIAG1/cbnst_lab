#include <stdio.h>
#include <stdlib.h>

int main() {
    float x, u1, u, y;
    int i, j, n, fact;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the table
    float **a = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        a[i] = (float *)malloc((n + 1) * sizeof(float));
    }

    printf("Enter values of X:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i][0]);
    }

    printf("Enter values of Y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i][1]);
    }

    printf("Enter the value of x for which you want y: ");
    scanf("%f", &x);

    // Find the Difference Table
    for (j = 2; j <= n; j++) {
        for (i = 0; i < n - j + 1; i++) {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    // Print the Difference Table
    printf("The Difference Table is as follows:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n - i; j++) {
            printf("%.4f ", a[i][j]);
        }
        printf("\n");
    }

    // Check if x is within the range of given x values
// Check if x is within the range of given x values
if (x < a[0][0] || x > a[n - 1][0]) {
    printf("Error: x is out of bounds of the given x values.\n");
    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    return 1;
}

    // Find the appropriate u and y value for interpolation
    int index = 0;
    while (index < n - 1 && x > a[index + 1][0]) {
        index++;
    }

    u = (x - a[index][0]) / (a[index + 1][0] - a[index][0]);
    y = a[index][1];

    // Initial k, u1, j
    u1 = u;
    fact = 1;
    j = 2;  // Corresponds to the column number in the difference table

    for (i = index - 1; i >= 0; i--) {
        y += (u1 * a[i][j]) / fact;
        // Update k, u1, j
        fact *= j; 
        u1 *= (u + (j - 1));
        j++;
    }

    printf("\nValue at X = %g is = %.4f\n", x, y);

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}

