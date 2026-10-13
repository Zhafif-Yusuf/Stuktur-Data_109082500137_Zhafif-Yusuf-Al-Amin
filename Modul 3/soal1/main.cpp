#include <iostream>
#include "data.h"

using namespace std;

int main() {
    ListMahasiswa listMhs;
    listMhs.n = 0; // Inisialisasi jumlah awal data

    int pilihan;
    do {
        cout << "\n=== MENU PENGELOLAAN DATA MAHASISWA ===" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Tampilkan Data Mahasiswa" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer newline setelah input angka

        if (pilihan == 1) {
            if (listMhs.n >= 10) {
                cout << "Maaf, data sudah mencapai batas maksimal (10 mahasiswa)!\n";
                continue;
            }

            Mahasiswa mhs;
            cout << "\n--- Input Data Mahasiswa ke-" << listMhs.n + 1 << " ---\n";
            cout << "NIM   : ";
            getline(cin, mhs.nim);
            cout << "Nama  : ";
            getline(cin, mhs.nama);
            cout << "UTS   : ";
            cin >> mhs.uts;
            cout << "UAS   : ";
            cin >> mhs.uas;
            cout << "Tugas : ";
            cin >> mhs.tugas;

            tambahMahasiswa(listMhs, mhs);

        } else if (pilihan == 2) {
            tampilkanData(listMhs);
        } else if (pilihan == 3) {
            cout << "Keluar dari program. Terima kasih!\n";
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi!\n";
        }

    } while (pilihan != 3);

    return 0;
}