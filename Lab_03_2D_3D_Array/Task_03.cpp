#include <iostream>

using namespace std;

int main() {
    int matA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int sumMat[3][3];

    cout << "Matrix A:\n";
    int r = 0;
    while (r < 3) {
        for (int c = 0; c < 3; c++) {
            cout << matA[r][c] << " ";
        }
        cout << "\n";
        r++;
    }

    cout << "\nMatrix B:\n";
    for (int i = 0; i < 3; i++) {
        int j = 0;
        while (j < 3) {
            cout << matB[i][j] << " ";
            j++;
        }
        cout << "\n";
    }
    cout << "\n\nSum of Matrix A and B:\n\n";
    int rowIdx = 0;
    while (rowIdx < 3) {
        for (int colIdx = 0; colIdx < 3; colIdx++) {
            sumMat[rowIdx][colIdx] = matA[rowIdx][colIdx] + matB[rowIdx][colIdx];
            cout << sumMat[rowIdx][colIdx] << " ";
        }
        cout << "\n";
        rowIdx++;
    }

    return 0;
}