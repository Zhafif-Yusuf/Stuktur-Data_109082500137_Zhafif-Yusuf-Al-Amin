# **Laporan Praktikum Modul 1 \- Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)**

# 

Zhafif Yusuf Al Amin \- 109082500137
## Dasar Teori

### A. Abstract Data Type (ADT)
Abstract Data Type (ADT) atau Tipe Data Abstrak adalah model matematika untuk struktur data yang mendefinisikan perilaku dari sudut pandang pembuat atau pengguna, terlepas dari bagaimana struktur data tersebut diimplementasikan secara konkret di dalam memori komputer[1][2]. ADT memisahkan antara spesifikasi logis (apa yang dapat dilakukan oleh struktur data) dan implementasi fisik (bagaimana operasi tersebut dilakukan)[2][5].

#### 1. Konsep Dasar ADT
Abstraksi Data (Data Abstraction): Menyembunyikan detail implementasi internal dari struktur data dan hanya menampilkan antarmuka (interface) atau operasi publik yang dapat diakses oleh pengguna[2]. Hal ini memungkinkan pemrogram untuk fokus pada fungsionalitas tingkat tinggi tanpa harus terikat pada detail tingkat rendah[3].
Enkapsulasi (Encapsulation): Membungkus data bersama dengan fungsi-fungsi atau prosedur yang memanipulasi data tersebut ke dalam satu unit modular yang terisolasi[5].

#### 2. Komponen ADT
Domain Data: Himpunan nilai atau tipe data yang mendefinisikan bentuk informasi yang disimpan di dalam ADT[1].
Himpunan Operasi (Operations): Kumpulan fungsi atau prosedur yang diizinkan untuk memanipulasi domain data tersebut (seperti inisialisasi, penyisipan, penghapusan, pencarian, dan pengecekan kondisi kosong)[2][5].

#### 3. Hubungan ADT dengan Struktur Data
ADT bersifat konseptual, sedangkan struktur data adalah perwujudan konkret (implementasi nyata) dari ADT tersebut dalam bahasa pemrograman tertentu (seperti C++ atau Go)[2][3]. Sebagai contoh, ADT List atau Queue dapat diimplementasikan menggunakan struktur data berbasis Array maupun berbasis Linked List, di mana pengguna ADT tidak perlu mengetahui apakah penyimpanan internalnya menggunakan alokasi statis atau dinamis[1][2].

### B. Struktur Data dan Linked List
Dalam implementasinya, ADT sering kali diwujudkan menggunakan berbagai struktur data, salah satunya adalah linked list untuk struktur data linier dinamis[1][2].

#### 1. Pengertian Struktur Data
Struktur data merupakan cara atau skema dalam mengorganisasikan, menyimpan, dan mengelola data di dalam memori komputer agar dapat diakses dan dimanipulasi secara efisien oleh program[3]. Pemilihan struktur data yang tepat sangat mempengaruhi performa sistem, efisiensi memori, serta kompleksitas waktu eksekusi suatu algoritma[3][4].

#### 2. Klasifikasi Struktur Data
Struktur Data Linier: Elemen-elemen data disusun secara berurutan atau sekuensial[4]. Contohnya meliputi Array, Linked List, Stack, dan Queue[3][4].
Struktur Data Non-Linier: Elemen-elemen data tersusun secara hierarkis atau saling terhubung tidak dalam satu garis lurus[4]. Contohnya mencakup Tree dan Graph[3][4].

#### 3. Linked List
Linked list merupakan struktur data linier dinamis yang alokasi memorinya dilakukan pada saat program dijalankan (runtime)[1][2]. Berbeda dengan array yang mengalokasikan memori secara berurutan dan berukuran tetap (static contiguous memory), linked list dapat bertambah atau berkurang ukurannya sesuai kebutuhan[1][2]. Setiap node pada linked list umumnya terdiri dari bagian data (infotype) dan pointer penunjuk ke node berikutnya[1][5].

## Guided

### 1. Buku

source code unguided 1
buku.h
```
#ifndef BUKU_H
#define BUKU_H
#include <iostream>
using namespace std;
struct buku
{
    string judul;
    int halaman;
    string penulis;
    
};

void editIsi(string judul, int halaman, string penulis,buku &buku);
void tampilkanIsiBuku(buku buku);
bool checkPenulis(buku buku);

#endif
```
buku.cpp
```
#include "buku.h"
void editIsi(string judul, int halaman, string penulis,buku &buku){
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilkanIsiBuku(buku buku)
{
    cout << "Judul Buku: " << buku.judul << endl;
    cout << "Jumlah Halaman: " << buku.halaman << endl;
    cout << "Penulis: " << buku.penulis << endl;
}
bool checkPenulis(buku buku)
{
    return buku.penulis == "";
}
```
main.cpp
```
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
```

Sebuah kode yang menggunakan bahasa C++ yang berfungsi untuk mengimplementasikan konsep Abstract Data Type (ADT) pada data buku dengan pemisahan struktur modular dalam tiga file (buku.h, buku.cpp, dan main.cpp). Program ini bekerja dengan menyediakan prosedur editIsi untuk memasukkan dan mengubah data buku (judul, halaman, dan penulis), prosedur tampilkanIsiBuku untuk mencetak informasi lengkap buku ke terminal, serta fungsi checkPenulis untuk memvalidasi apakah nama penulis buku kosong atau terisi, yang kemudian diuji secara interaktif melalui fungsi utama (main).

## Unguided

### 1\. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

source code unguided 1
data.h
```
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
```
data.cpp
```
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
```
main.cpp
```
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
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%203/output/OutputSoal1.png)


Sebuah kode yang menggunakan bahasa C++ yang berfungsi untuk mengelola dan menyimpan data mahasiswa ke dalam struktur array dengan kapasitas maksimal 10 data. Program ini bekerja dengan memanfaatkan konsep Abstract Data Type (ADT) yang terbagi menjadi tiga file modular (data.h, data.cpp, dan main.cpp). Program menyediakan fungsi khusus untuk menghitung nilai akhir berdasarkan bobot UTS, UAS, dan tugas, serta prosedur untuk menambah dan menampilkan seluruh data mahasiswa secara terstruktur melalui menu interaktif di terminal.

### 2\. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:


source code unguided 2
pelajaran.h
```
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
pelajaran.cpp
```
#include "pelajaran.h"
#include <iostream>

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
main.cpp
```
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 2

![Screenshot Output Unguided 2_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%203/output/OutputSoal2.png)

Sebuah kode yang menggunakan bahasa C++ yang berfungsi untuk mengimplementasikan konsep Abstract Data Type (ADT) pada data mata pelajaran melalui tiga file modular (pelajaran.h, pelajaran.cpp, dan main.cpp). Program ini bekerja dengan menyediakan fungsi create_pelajaran untuk membentuk dan menginisialisasi data pelajaran baru beserta kodenya, serta prosedur tampil_pelajaran untuk mencetak informasi nama pelajaran dan kodenya ke terminal.

### 3\.Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

source code unguided 3
soal3.h
```
#ifndef SOAL3_H
#define SOAL3_H

void tampilkanArray2D(int arr[3][3]);

void tukarElemenArray2D(int arr1[3][3], int arr2[3][3], int baris, int kolom);

void tukarNilaiPointer(int *ptr1, int *ptr2);

#endif
```
soal3.cpp
```
#include "soal3.h"
#include <iostream>

using namespace std;

void tampilkanArray2D(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarElemenArray2D(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        int temp = arr1[baris][kolom];
        arr1[baris][kolom] = arr2[baris][kolom];
        arr2[baris][kolom] = temp;
    }
}

void tukarNilaiPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```
main.cpp
```
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
```
### Output Unguided 3 :

##### Output 3

![Screenshot Output Unguided 2_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%203/output/OutputSoal3.png)

Sebuah kode yang menggunakan bahasa C++ yang berfungsi untuk mengelola dan memanipulasi dua buah array dua dimensi berukuran 3x3 serta variabel pointer integer secara modular terbagi dalam tiga file (soal3.h, soal3.cpp, dan main.cpp). Program ini bekerja dengan menyediakan prosedur tampilkanArray2D untuk mencetak matriks, prosedur tukarElemenArray2D untuk menukar isi elemen tertentu antara kedua array pada posisi baris dan kolom yang diinginkan, serta prosedur tukarNilaiPointer yang memanfaatkan dereference pointer untuk menukarkan isi variabel yang ditunjuk secara langsung lalu menampilkan seluruh hasil perubahannya di terminal.

## Kesimpulan
Pada praktikum kali ini saya dapat mengetahui dasar-dasar penerapan Abstract Data Type (ADT) dalam bahasa C++ menggunakan pemisahan file modular (header .h, implementasi .cpp, dan main .cpp), pengelolaan array (baik array 1D untuk data mahasiswa maupun array 2D matriks), serta pemanfaatan pointer untuk memanipulasi nilai variabel secara langsung. Saya sangat menyukainya:D

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). MIT Press.

[2] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.

[3] Tim Dosen Struktur Data. (2026). Modul Praktikum Struktur Data. Fakultas Informatika, Universitas Telkom.

[4] Munir, R. (2011). Algoritma dan Pemrograman dalam Bahasa Pascal, C, dan C++. Informatika Bandung.

[5] Tanenbaum, A. M., Langsam, Y., & Augenstein, M. J. (1996). Data Structures Using C and C++ (2nd ed.). Prentice-Hall.