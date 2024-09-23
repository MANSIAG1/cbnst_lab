#include <stdio.h>
#include <math.h>

void printMatrix(float matrix[][80], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(float matrix[][80], int n) {
    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }
        // Swap the maximum row with the current row
        for (int k = 0; k <= n; k++) {
            float temp = matrix[i][k];
            matrix[i][k] = matrix[maxRow][k];
            matrix[maxRow][k] = temp;
        }
        
        // Normalize the pivot row
        float pivot = matrix[i][i];
        if (pivot == 0) {
            printf("Matrix is singular or has no unique solution.\n");
            return;
        }
        for (int j = 0; j <= n; j++) {
            matrix[i][j] /= pivot;
        }
        
        // Print the intermediate matrix after normalization
        printf("After normalizing row %d:\n", i + 1);
        printMatrix(matrix, n);

        // Eliminate the current column in other rows
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = matrix[k][i];
                for (int j = 0; j <= n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
        
        // Print the intermediate matrix after elimination
        printf("After eliminating column %d:\n", i + 1);
        printMatrix(matrix, n);
    }
    
    printf("Final values:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }
}

int main() {
    int n;
 
    printf("Enter matrix order: ");
    scanf("%d", &n);

    float matrix[80][80];
    printf("Enter augmented matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Equation %d:\n", i + 1);
        for (int j = 0; j <= n; j++) {
            printf("Coefficient for variable %d: ", j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Initial matrix:\n");
    printMatrix(matrix, n);
    
    gaussJordan(matrix, n);

    return 0;
}

