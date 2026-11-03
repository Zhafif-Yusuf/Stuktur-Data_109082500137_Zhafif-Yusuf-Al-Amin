# **Laporan Praktikum MODUL 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)**

# 


Zhafif Yusuf Al Amin \- 109082500137
## Dasar Teori

### A. Konsep Dasar Linked List dan Pointer
#### 1. Definisi Linked List
Linked list (atau list berkait) merupakan salah satu struktur data linier yang terdiri dari sekumpulan elemen data (node/simpul) yang saling terhubung secara dinamis. Berbeda dengan array yang menyimpan data dalam blok memori yang bersebelahan (kontigu), elemen-elemen pada linked list tersebar di memori komputer dan dihubungkan satu sama lain menggunakan pointer. Setiap node setidaknya memiliki dua bagian utama, yaitu bagian data (info) dan bagian penunjuk (next atau successor).

#### 2. Keunggulan Linked List Dibandingkan Array
Dalam bahasa pemrograman C++, linked list umumnya diimplementasikan menggunakan pointer karena menawarkan fleksibilitas yang lebih tinggi dibandingkan struktur array. Keunggulan utamanya terletak pada sifat alokasi memori yang dinamis, di mana penambahan atau pengurangan elemen dapat dilakukan saat program berjalan (runtime) tanpa mengalokasikan ruang memori maksimum di awal seperti pada array statis. Selain itu, operasi penyisipan (insertion) maupun penghapusan (deletion) elemen data pada linked list relatif lebih efisien dan mudah dilakukan karena hanya perlu mengubah arah alokasi pointer tanpa harus melakukan pergeseran (shifting) elemen-elemen lain seperti yang terjadi pada struktur array

#### 3. Hubungan ADT dengan Struktur Data
Singly Linked List merupakan variasi struktur data linked list yang paling sederhana karena hanya menggunakan satu arah pointer penunjuk (yaitu pointer next) untuk menghubungkan antar-node sehingga pembacaan elemen hanya dapat dilakukan secara maju. Struktur ini terdiri dari elemen atau node sebagai unit tempat penyimpanan data di memori, serta variabel pointer first (atau head) yang bertindak sebagai pintu masuk utama dengan menyimpan alamat memori elemen pertama di dalam list. Jika list dalam kondisi kosong, maka pointer first akan menunjuk ke nilai Nil (atau NULL), sedangkan untuk list yang memiliki isi, node paling terakhir selalu ditandai dengan pointer next yang menunjuk ke nilai Nil sebagai penanda akhir dari rantai data.

### B. Operasi Dasar pada Singly Linked List
#### 1. Inisialisasi dan Manajemen Memori
Proses pembentukan awal list diawali dengan fungsi Create List yang bertugas mengeset nilai pointer L.first menjadi Nil untuk menandakan bahwa list baru berhasil dibuat dalam kondisi kosong. Dalam mengelola elemen, alokasi memori dilakukan secara dinamis menggunakan operator new di C++ untuk memesan ruang memori baru bagi node yang akan dimasukkan, sementara proses dealokasi dilakukan menggunakan sintaks delete untuk mengembalikan ruang memori yang tidak terpakai kembali ke sistem agar mencegah terjadinya kebocoran memori (memory leak).

#### 2. Operasi Penyisipan (Insert First)
Operasi Insert First merupakan metode penambahan elemen baru yang ditempatkan di posisi paling depan atau menjadi node pertama di dalam list. Langkah algoritmanya dimulai dengan mengarahkan pointer next dari node baru ($P$) menuju ke node yang sedang ditunjuk oleh L.first, kemudian memperbarui pointer L.first agar menunjuk secara langsung ke alamat node baru ($P$) tersebut.

#### 3. Operasi Penelusuran dan Menampilkan Data (View / Print Info)
Operasi penelusuran (traversal) atau printInfo dilakukan dengan cara mengunjungi setiap node di dalam list secara berurutan mulai dari node pertama (L.first) hingga node terakhir. Selama proses penelusuran berlangsung, program akan mengakses dan menampilkan nilai info yang tersimpan pada masing-masing node ke layar terminal sampai penunjuk pointer menemukan nilai Nil.

## Guided

### 1. list Makanan

source code Guided 1
listMakanan.h
```
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
using namespace std;

struct makanan
{
    string nama;
    string jenis;
    float harga;
    float rating;
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node
{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist
{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```
listMakanan.cpp
```
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
using namespace std;

struct makanan
{
    string nama;
    string jenis;
    float harga;
    float rating;
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node
{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist
{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```
main.cpp
```
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    // D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");
    findByMinRating(List, 9.0);

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl
         << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```


## Unguided

### 1\.

source code unguided 1
Doublylist.h
```
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Fungsi Tambahan Soal 2 & 3
address findElm(List L, infotype x);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```
Doublylist.cpp
```
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
        P->prev = NULL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void printInfo(List L) {
    address P = L.First;
    if (P == NULL) {
        cout << "List Kosong" << endl;
    } else {
        while (P != NULL) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->next;
        }
    }
}

void insertLast(List &L, address P) {
    if (L.First == NULL && L.Last == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.First = L.First->next;
            L.First->prev = NULL;
            P->next = NULL;
        }
    }
}

void deleteLast(List &L, address &P) {
    if (L.Last != NULL) {
        P = L.Last;
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = NULL;
            P->prev = NULL;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}
```
main.cpp
```
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
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%206/output/OutputSoal1.png)





## Kesimpulan
Berdasarkan praktikum Modul 5 tentang Singly Linked List, dapat disimpulkan bahwa Singly Linked List merupakan struktur data yang menghubungkan setiap elemen menggunakan pointer next, sehingga data dapat dikelola secara dinamis. Melalui implementasi ADT Singly Linked List menggunakan bahasa C++ dengan file terpisah, yaitu Singlylist.h, Singlylist.cpp, dan main.cpp, praktikan dapat memahami cara membuat list kosong, mengalokasikan dan menghapus memori, menambahkan elemen menggunakan insertFirst, serta menampilkan isi list menggunakan printInfo. Selain itu, praktikan juga mempelajari cara mencari elemen menggunakan fungsi findElm dan menghitung jumlah seluruh nilai menggunakan fungsi sumInfo. Berdasarkan hasil pengujian, penambahan data 2, 0, 8, 12, dan 9 menggunakan insertFirst menghasilkan urutan 9, 12, 8, 0, dan 2, dengan total nilai sebesar 31. Dengan demikian, praktikum ini membantu praktikan memahami konsep dasar, cara kerja pointer, serta penerapan operasi dasar pada struktur data Singly Linked List dalam bahasa C++.


## Referensi
Laboratorium Informatika Telkom University. (2026). Modul 04 Praktikum Struktur Data: Singly Linked List (Bagian Pertama). Bandung: Fakultas Informatika Telkom University.   Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.