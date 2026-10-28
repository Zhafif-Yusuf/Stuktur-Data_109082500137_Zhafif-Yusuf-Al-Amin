// Zhafif Yusuf Al Amin
// 109082500137

#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    cout << "Zhafif Yusuf Al Amin" << endl;
    cout << "109082500137" << endl << endl;

    List L;
    CreateList(L);
    infotype x;
    address P;

    // --- SOAL 1: Input Data Kendaraan ---
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        // Cek apakah nopol sudah terdaftar
        if (findElm(L, x) != NULL) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
            cout << endl;
        }
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);
    cout << endl;

    // --- SOAL 2: Cari Elemen dengan Nopol D001 ---
    string cariNopol;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cariNopol;

    infotype xCari;
    xCari.nopol = cariNopol;
    address pCari = findElm(L, xCari);

    if (pCari != NULL) {
        cout << "\nNomor Polisi : " << pCari->info.nopol << endl;
        cout << "Warna        : " << pCari->info.warna << endl;
        cout << "Tahun        : " << pCari->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
    cout << endl;

    // --- SOAL 3: Hapus Elemen dengan Nopol D003 ---
    string hapusNopol;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    infotype xHapus;
    xHapus.nopol = hapusNopol;
    address pHapus = findElm(L, xHapus);

    if (pHapus != NULL) {
        address pDel = NULL;
        if (pHapus == L.First) {
            deleteFirst(L, pDel);
        } else if (pHapus == L.Last) {
            deleteLast(L, pDel);
        } else {
            deleteAfter(pHapus->prev, pDel);
        }
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl << endl;
        dealokasi(pDel);
    } else {
        cout << "Data tidak ditemukan untuk dihapus." << endl << endl;
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);

    return 0;
}