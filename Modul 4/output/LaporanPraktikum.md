# **Laporan Praktikum Modul 4 \- SINGLY LINKED LIST (Bagian Pertama)**

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

### 1. list

source code Guided 1
list.h
```
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void delokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertlast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);
#endif

```
list.cpp
```
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist list)
{
    if (list.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(linkedlist &list)
{
    list.first = Nil;
}
void createList(linkedlist &list)
{
    list.first = Nil;
}

address alokasi(string name, string nim, int umur)
{
    address nodeBaru;
    nodeBaru = new node;
    nodeBaru->isidata.nama = name;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    delete node;
}
void insertFirst(linkedlist &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedlist &list, address nodeBaru, address Prev)
{
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}
void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address lastNode = List.first;
        while (lastNode->next != Nil)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = nodeBaru;
    }
}
void delFirst(linkedlist &List)
{
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        delokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    address nodeHapus, nodePrev;
    if (isEmpty(List)==false)
    {
        nodeHapus=List.first;
        if (nodeHapus->next==Nil)
        {
            List.first->next=Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next!=Nil)
            {
                nodePrev=nodeHapus;
                nodeHapus=nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
    cout << "List kosong" << endl;
    }
}
void delAfter(linkedlist &list, address nodeHapus, address nodePrev)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
void printList(linkedlist list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
int nbList(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void delist(linkedlist &list)
{
    address nodeHapus;
    while (!isEmpty(list))
    {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
}


```
main.cpp
```
#include <iostream>
#include "buku.h"
using namespace std;
int main()
{
    buku novel;
    string judul, penulis;
    int halaman;
    cout << "Masukkan Judul Buku: ";
    cin >> judul;
    cout << "Masukkan Jumlah Halaman: ";
    cin >> halaman;
    cout << "Masukkan Penulis: ";
    cin >> penulis;
    editIsi(judul, halaman, penulis, novel);
    tampilkanIsiBuku(novel);
    cout << checkPenulis(novel) << endl;
    return 0;
}
```

Sebuah kode yang menggunakan bahasa C++ yang berfungsi untuk mengimplementasikan konsep Abstract Data Type (ADT) Singly Linked List pada data mahasiswa dengan pemisahan struktur modular dalam file (list.h, list.cpp, dan main.cpp). Program ini bekerja dengan menyediakan berbagai prosedur operasi dasar seperti insertFirst, insertAfter, dan insertLast untuk memasukkan data mahasiswa (nama, NIM, umur), prosedur printList untuk mencetak informasi lengkap mahasiswa ke terminal, serta prosedur penghapusan seperti delFirst, delLast, dan delAfter untuk menghapus node dari dalam list.

## Unguided

### 1\. Buatlah program Abstract Data Type (ADT) Singly Linked List dalam bahasa C++ yang dibagi menjadi file Singlylist.h, Singlylist.cpp, dan main.cpp dengan spesifikasi: tipe infotype bertipe int, address berupa pointer ke ElmList, struktur ElmList berisi info dan next, serta struktur List berisi First; lengkapi prototipe primitif (createList, alokasi, dealokasi, printInfo, insertFirst)

source code unguided 1
Singlylist.h
```
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif 
```
Singlylist.cpp
```
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}
```
main.cpp
```
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    
    createList(L);
    
    P1 = alokasi(2);
    insertFirst(L, P1);
    
    P2 = alokasi(0);
    insertFirst(L, P2);
    
    P3 = alokasi(8);
    insertFirst(L, P3);
    
    P4 = alokasi(12);
    insertFirst(L, P4);
    
    P5 = alokasi(9);
    insertFirst(L, P5);
    
    printInfo(L);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Zhafif-Yusuf Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/blob/main/Modul%204/output/OutputSoal1.png)


Dari AI: Program C++ ini sebenarnya adalah implementasi dari konsep Abstract Data Type (ADT) Singly Linked List yang kodenya dipecah jadi tiga file modular biar rapi, yaitu Singlylist.h buat nyiapin kerangka struktur node (info dan next) beserta prototipe fungsinya, Singlylist.cpp buat nulis isi logika kodenya seperti createList, alokasi memori, sampai insertFirst, dan main.cpp sebagai tempat eksekusi utamanya. Di bagian main-nya, program ini bikin list kosong terus masukin angka 2, 0, 8, 12, sama 9 satu-persatu ke bagian depan list pakai metode insertFirst, yang mana karena sifatnya di depan, urutan penyisipannya bikin data terakhir ada di posisi awal, lalu semuanya langsung dicetak ke layar secara berurutan lewat prosedur printInfo


## Kesimpulan
Pada praktikum kali ini saya dapat memahami cara kerja Singly Linked List sebagai struktur data dinamis satu arah yang fleksibel menggunakan pointer. Saya juga berhasil menerapkan konsep Abstract Data Type (ADT) secara modular melalui pemisahan file header (.h), implementasi (.cpp), dan program utama (main.cpp). Melalui uji coba fungsi insertFirst secara berurutan pada data 2, 0, 8, 12, dan 9, program sukses menampilkan urutan akhir 9 12 8 0 2, yang membuktikan bahwa elemen baru berhasil disisipkan di posisi paling depan. Saya sangat menyukainya:D

## Referensi
Laboratorium Informatika Telkom University. (2026). Modul 04 Praktikum Struktur Data: Singly Linked List (Bagian Pertama). Bandung: Fakultas Informatika Telkom University.   Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.