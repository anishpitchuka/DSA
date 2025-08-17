#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to allocate a matrix dynamically
int** allocateMatrix(int m, int n) {
    int **matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}

// Function to free a matrix
void freeMatrix(int **matrix, int m) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to initialize a matrix with random numbers
void initializeMatrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100; // values 0–99
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// (a) Convert matrix to its transpose and print it
void printTranspose(int **matrix, int m, int n) {
    printf("Transpose:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// (b) Maximum diagonal element of a square matrix
int maxDiagonal(int **matrix, int m, int n) {
    int limit = (m < n) ? m : n; // diagonal length = min(m, n)
    int max = matrix[0][0];
    for (int i = 0; i < limit; i++) {
        if (matrix[i][i] > max) {
            max = matrix[i][i];
        }
    }
    return max;
}

// (c) Sum of all entries of a matrix using pointers
int sumMatrix(int **matrix, int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += *(*(matrix + i) + j);
        }
    }
    return sum;
}

// (d) Add two matrices and return the resultant matrix
int** addMatrices(int **A, int **B, int m, int n) {
    int **C = allocateMatrix(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*(C + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
        }
    }
    return C;
}

// (e) Compare two matrices (return 1 if identical, else 0)
int compareMatrices(int **A, int **B, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (*(*(A + i) + j) != *(*(B + i) + j)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    int m, n;
    printf("Enter matrix size (m n): ");
    scanf("%d %d", &m, &n);

    // Allocate and initialize two matrices
    int **A = allocateMatrix(m, n);
    int **B = allocateMatrix(m, n);

    initializeMatrix(A, m, n);
    initializeMatrix(B, m, n);

    printf("Matrix A:\n");
    printMatrix(A, m, n);
    printf("\nMatrix B:\n");
    printMatrix(B, m, n);

    // (a) Transpose
    printf("\nTranspose of A:\n");
    printTranspose(A, m, n);
    printf("\nTranspose of B:\n");
    printTranspose(B, m, n);

    // (b) Maximum diagonal values
    int maxA = maxDiagonal(A, m, n);
    int maxB = maxDiagonal(B, m, n);
    printf("\nMax diagonal element of A: %d", maxA);
    printf("\nMax diagonal element of B: %d\n", maxB);

    // (c) Sum of entries
    printf("\nSum of elements of A: %d", sumMatrix(A, m, n));
    printf("\nSum of elements of B: %d\n", sumMatrix(B, m, n));

    // (d) Add matrices
    int **C = addMatrices(A, B, m, n);
    printf("\nA + B:\n");
    printMatrix(C, m, n);

    // (e) Compare
    printf("\nAre A and B identical? %s\n", compareMatrices(A, B, m, n) ? "Yes" : "No");

    // Free memory
    freeMatrix(A, m);
    freeMatrix(B, m);
    freeMatrix(C, m);

    return 0;
}
