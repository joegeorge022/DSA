#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to take the input of a matrix
void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to find the transpose of a matrix
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int transposed[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], sumMatrix[MAX_ROWS][MAX_COLS], transposedMatrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    // Taking input for matrix dimensions
    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Taking input for the two sparse matrices
    printf("\nMatrix 1:\n");
    inputMatrix(matrix1, rows, cols);

    printf("\nMatrix 2:\n");
    inputMatrix(matrix2, rows, cols);

    // Adding the matrices
    addMatrices(matrix1, matrix2, sumMatrix, rows, cols);

    // Displaying the sum of the matrices
    printf("\nSum of Matrix 1 and Matrix 2:\n");
    displayMatrix(sumMatrix, rows, cols);

    // Finding and displaying the transpose of the sum matrix
    transposeMatrix(sumMatrix, transposedMatrix, rows, cols);

    printf("\nTranspose of the sum matrix:\n");
    displayMatrix(transposedMatrix, cols, rows);

    return 0;
}
