#include <iostream>
using namespace std;

void cetakMatriks(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
void penjumlahan(int A[3][3], int B[3][3]) {
    cout << "\nHasil Penjumlahan (A + B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << endl;
    }
}
void pengurangan(int A[3][3], int B[3][3]) {
    cout << "\nHasil Pengurangan (A - B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] - B[i][j] << " ";
        }
        cout << endl;
    }
}
void perkalian(int A[3][3], int B[3][3]) {
    cout << "\nHasil Perkalian (A * B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int total = 0;
            for (int k = 0; k < 3; k++) {
                total += A[i][k] * B[k][j];
            }
            cout << total << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    cout << "Matriks A:\n";
    cetakMatriks(A);
    cout << "\nMatriks B:\n";
    cetakMatriks(B);
    penjumlahan(A, B);
    pengurangan(A, B);
    perkalian(A, B);

    return 0;
}