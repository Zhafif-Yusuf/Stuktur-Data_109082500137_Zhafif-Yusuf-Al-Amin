#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;
    int z = 30;

    int *px = &x;
    int *py = &y;
    int *pz = &z;
    int temp;

    cout << "angka x awal: " << *px << endl; 
    cout << "angka y awal: " << *py << endl;
    cout << "angka z awal: " << *pz << endl;
    temp = *px;
    *px = *py;
    *py = *pz;
    *pz = temp;

    cout << "\nangka x akhir: " << x << endl;
    cout << "angka y akhir: " << y << endl;
    cout << "angka z akhir: " << z << endl;
    return 0;
}