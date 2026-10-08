#include <iostream>
#include "buku.h"
using namespace std;
int main(){
    buku novel;
    string judul, penulis;
    int halaman;
    cout << "Masukkan Judul Buku: ";
    cin>> judul;
    cout << "Masukkan Jumlah Halaman: ";
    cin >> halaman; 
    cout << "Masukkan Penulis: ";
    cin >> penulis;
    editIsi(judul, halaman, penulis, novel);
    tampilkanIsiBuku(novel);
    cout << checkPenulis(novel)<<endl;
    return 0;

    
}