#include <iostream>
using namespace std;

// 1. Call by Value: variabel asli TIDAK berubah
void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// 2. Call by Pointer: variabel asli IKUT berubah (pakai *)
void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Call by Reference: variabel asli IKUT berubah (pakai &)
void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;

    cout << "=== Nilai Awal ===" << endl;
    cout << "a = " << a << ", b = " << b << endl << endl;

    // Uji Call by Value
    tukarValue(a, b);
    cout << "Setelah tukarValue (Call by Value):" << endl;
    cout << "a = " << a << ", b = " << b << " (Tetap)" << endl << endl;

    // Uji Call by Pointer (Mengirimkan alamat &a dan &b)
    tukarPointer(&a, &b);
    cout << "Setelah tukarPointer (Call by Pointer):" << endl;
    cout << "a = " << a << ", b = " << b << " (Berubah)" << endl << endl;

    // Uji Call by Reference (Langsung mengirimkan variabel a dan b)
    tukarReference(a, b);
    cout << "Setelah tukarReference (Call by Reference):" << endl;
    cout << "a = " << a << ", b = " << b << " (Berubah kembali)" << endl;

    return 0;
}