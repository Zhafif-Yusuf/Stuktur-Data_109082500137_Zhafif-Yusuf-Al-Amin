#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

struct ListMahasiswa {
    Mahasiswa data[10];
    int n;
};

float hitungNilaiAkhir(float uts, float uas, float tugas);
void tambahMahasiswa(ListMahasiswa &lm, Mahasiswa mhs);
void tampilkanData(const ListMahasiswa &lm);

#endif