#include <iostream>
#include "soal3.h"

using namespace std;

int main() {
    int arrayA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arrayB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int x = 100;
    int y = 200;
    int *ptrX = &x;
    int *ptrY = &y;

    cout << "=== DEMONSTRASI ARRAY 2D (3x3) ===" << endl;
    cout << "Array A awal:" << endl;
    tampilkanArray2D(arrayA);
    
    cout << "\nArray B awal:" << endl;
    tampilkanArray2D(arrayB);

    int targetBaris = 1, targetKolom = 1;
    cout << "\nMenukar isi kedua array pada posisi [baris " << targetBaris << ", kolom " << targetKolom << "]..." << endl;
    tukarElemenArray2D(arrayA, arrayB, targetBaris, targetKolom);

    cout << "\nArray A setelah ditukar:" << endl;
    tampilkanArray2D(arrayA);
    
    cout << "\nArray B setelah ditukar:" << endl;
    tampilkanArray2D(arrayB);

    cout << "\n========================================" << endl;
    cout << "=== DEMONSTRASI POINTER INTEGER ===" << endl;
    cout << "Nilai awal yang ditunjuk pointer:" << endl;
    cout << "Nilai *ptrX (x) = " << *ptrX << endl;
    cout << "Nilai *ptrY (y) = " << *ptrY << endl;

    tukarNilaiPointer(ptrX, ptrY);

    cout << "\nSetelah fungsi tukarNilaiPointer dijalankan:" << endl;
    cout << "Nilai *ptrX (x) = " << *ptrX << endl;
    cout << "Nilai *ptrY (y) = " << *ptrY << endl;

    return 0;
}