#include <iostream>
using namespace std;

#include<iostream>
using namespace std;

int** memoryAllocation(int rows, int cols) {
    int** ptr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        ptr[i] = new int[cols];
    }
    return ptr;
}

void arrayInput(int** ptr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> *(*(ptr + i) + j);
        }
    }
}

void displayOutput(int** ptr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(ptr + i) + j) << " ";
        }
        cout << endl;
    }
}

void freeMemory(int** ptr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

void matrixAddition(int** mat1, int** mat2, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void matrixSubtraction(int** mat1, int** mat2, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void matrixMultiplication(int** mat1, int** mat2, int** result, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible. Columns of first matrix must be equal to rows of second matrix." << endl;
        return;
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter number of rows of matrix 1: ";
    cin >> rows1;
    cout << "Enter number of columns of matrix 1: ";
    cin >> cols1;
    int** mat1 = memoryAllocation(rows1, cols1);
    cout << "Enter elements of matrix 1:" << endl;
    arrayInput(mat1, rows1, cols1);

    cout << "Enter number of rows of matrix 2: ";
    cin >> rows2;
    cout << "Enter number of columns of matrix 2: ";
    cin >> cols2;
    int** mat2 = memoryAllocation(rows2, cols2);
    cout << "Enter elements of matrix 2:" << endl;
    arrayInput(mat2, rows2, cols2);

    // Matrix addition
    if (rows1 == rows2 && cols1 == cols2) {
        int** sum = memoryAllocation(rows1, cols1);
        matrixAddition(mat1, mat2, sum, rows1, cols1);
        cout << "Result of Matrix Addition:" << endl;
        displayOutput(sum, rows1, cols1);
        freeMemory(sum, rows1, cols1);
    } else {
        cout << "Matrix addition is not possible. Matrices must have the same dimensions." << endl;
    }

    // matrix subtraction
    if (rows1 == rows2 && cols1 == cols2) {
        int** minus = memoryAllocation(rows1, cols1);
        matrixSubtraction(mat1, mat2, minus, rows1, cols1);
        cout << "Result of Matrix Subtraction:" << endl;
        displayOutput(minus, rows1, cols1);
        freeMemory(minus, rows1, cols1);
    } else {
        cout << "Matrix subtraction is not possible. Matrices must have the same dimensions." << endl;
    }
    // Matrix multiplication
    if (cols1 == rows2) {
        int** product = memoryAllocation(rows1, cols2);
        matrixMultiplication(mat1, mat2, product, rows1, cols1, rows2, cols2);
        cout << "Result of Matrix Multiplication:" << endl;
        displayOutput(product, rows1, cols2);
        freeMemory(product, rows1, cols2);
    } else {
        cout << "Matrix multiplication is not possible. The number of columns of matrix 1 must be equal to the number of rows of matrix 2." << endl;
    }

    freeMemory(mat1, rows1, cols1);
    freeMemory(mat2, rows2, cols2);

    return 0;
}
