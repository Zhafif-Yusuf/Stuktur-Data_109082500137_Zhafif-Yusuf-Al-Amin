#include "data.h"
#include <iostream>

using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3f * uts) + (0.4f * uas) + (0.3f * tugas);
}


void tambahMahasiswa(ListMahasiswa &lm, Mahasiswa mhs) {
    if (lm.n < 10) {
        mhs.nilaiAkhir = hitungNilaiAkhir(mhs.uts, mhs.uas, mhs.tugas);
        lm.data[lm.n] = mhs;
        lm.n++;
        cout << "Data mahasiswa berhasil ditambahkan!\n";
    } else {
        cout << "Kapasitas array penuh (maksimal 10 mahasiswa)!\n";
    }
}

void tampilkanData(const ListMahasiswa &lm) {
    if (lm.n == 0) {
        cout << "\nBelum ada data mahasiswa.\n";
        return;
    }

    cout << "\n=========================================\n";
    cout << "          DAFTAR NILAI MAHASISWA         \n";
    cout << "=========================================\n";
    for (int i = 0; i < lm.n; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "NIM         : " << lm.data[i].nim << endl;
        cout << "Nama        : " << lm.data[i].nama << endl;
        cout << "Nilai UTS   : " << lm.data[i].uts << endl;
        cout << "Nilai UAS   : " << lm.data[i].uas << endl;
        cout << "Nilai Tugas : " << lm.data[i].tugas << endl;
        cout << "Nilai Akhir : " << lm.data[i].nilaiAkhir << endl;
        cout << "-----------------------------------------\n";
    }
}