#include <stdio.h>

#define MAX 10

void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements (use 0 for sparse positions):\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int sum[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum[i][j] = a[i][j] + b[i][j];
}

void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            trans[j][i] = mat[i][j];
}

int main() {
    int rows, cols;
    int mat1[MAX][MAX], mat2[MAX][MAX], sum[MAX][MAX], transpose[MAX][MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    printf("\nEnter first sparse matrix:\n");
    readMatrix(mat1, rows, cols);

    printf("\nEnter second sparse matrix:\n");
    readMatrix(mat2, rows, cols);

    addMatrices(mat1, mat2, sum, rows, cols);
    printf("\nSum of the matrices:\n");
    displayMatrix(sum, rows, cols);

    transposeMatrix(sum, transpose, rows, cols);
    printf("\nTranspose of the resulting matrix:\n");
    displayMatrix(transpose, cols, rows);

    return 0;
}
