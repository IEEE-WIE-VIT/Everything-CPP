// Program to compute and display transpose.
#include <iostream>
using namespace std;

int main() {
    int r, c, m[10][10], transpose[10][10], i, j;

    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;

    cout << "\nEnter elements of matrix: " << endl;

    // Storing matrix elements
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            cout << "Enter element m" << i + 1 << j + 1 << ": ";
            cin >> m[i][j];
        }
    }

    // Display matrix elements
    cout << "\nEntered Matrix: " << endl;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            cout << " " << m[i][j];
            if (j == c - 1)
            cout << endl << endl;
        }
    }

    // Compute transpose
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            transpose[j][i] = m[i][j];
        }

    // Display transpose elements
    cout << "\nTranspose of Matrix: " << endl;
    for (i = 0; i < c; ++i)
        for (j = 0; j < r; ++j) {
            cout << " " << transpose[i][j];
            if (j == r - 1)
            cout << endl << endl;
        }

    return 0;
}