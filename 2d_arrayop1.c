#include <stdio.h>

#define SIZE 3

void inputMatrix(int matrix[SIZE][SIZE], char name) {
    printf("Enter elements for Matrix %c (3x3):\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[SIZE][SIZE], char *name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE], int order) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (order == 1) { // A - B
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            } else { // B - A
                result[i][j] = matrix2[i][j] - matrix1[i][j];
            }
        }
    }
}

void multiplyMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}

int main() {
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], result[SIZE][SIZE];
    int choice, subChoice, transChoice;

    
    inputMatrix(matrix1, 'A');
    inputMatrix(matrix2, 'B');

    while (1) {
        printf("\nEnter the number you want to operate\n");
        printf("1. Addition [+]\n2. Subtraction [-]\n3. Multiplication [*]\n4. Transpose [T]\n5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        
        if (choice != 5) {
            displayMatrix(matrix1, "Matrix A");
            displayMatrix(matrix2, "Matrix B");
        }

        switch (choice) {
            case 1: 
                addMatrices(matrix1, matrix2, result);
                printf("\nResult of Addition (A + B):\n");
                displayMatrix(result, "Result");
                break;
            case 2: 
                printf("1. A - B\n2. B - A\nEnter your choice: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    subtractMatrices(matrix1, matrix2, result, 1);
                    printf("\nResult of Subtraction (A - B):\n");
                    displayMatrix(result, "Result");
                } else if (subChoice == 2) {
                    subtractMatrices(matrix1, matrix2, result, 2);
                    printf("\nResult of Subtraction (B - A):\n");
                    displayMatrix(result, "Result");
                } else {
                    printf("Invalid choice!\n");
                }
                break;
            case 3: 
                multiplyMatrices(matrix1, matrix2, result);
                printf("\nResult of Multiplication (A * B):\n");
                displayMatrix(result, "Result");
                break;
            case 4: 
                printf("1. Transpose Matrix A\n2. Transpose Matrix B\nEnter your choice: ");
                scanf("%d", &transChoice);
                if (transChoice == 1) {
                    transposeMatrix(matrix1, result);
                    printf("\nTranspose of Matrix A:\n");
                    displayMatrix(result, "Result");
                } else if (transChoice == 2) {
                    transposeMatrix(matrix2, result);
                    printf("\nTranspose of Matrix B:\n");
                    displayMatrix(result, "Result");
                } else {
                    printf("Invalid choice!\n");
                }
                break;
            case 5: 
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}