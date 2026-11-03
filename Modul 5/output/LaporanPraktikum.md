# **Laporan Praktikum Modul 5 \- SINGLY LINKED LIST (BAGIAN KEDUA)**

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
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);


//tambahan cuy//
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, int nilaiAwal, int nilaiAkhir);

// update lagi//
void updateFirst(linkedlist &list);
void updateLast(linkedlist &list);
void updateAfter(linkedlist list,address &prev);
void updateByNim(linkedlist &list, string nim);

address findNodeByData(linkedlist list, string nim);
#endif

```
list.cpp
```
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
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
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
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

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &list)
{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;
    list.first->isidata = newData;
}

void updateLast(linkedlist &list)
{
    if (isEmpty(list))
    {
        cout << "List kosong!" << endl;
        return;
    }
    else
    {
    
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    address nodeBantu = list.first;
    while (nodeBantu->next != Nil)
    {
        nodeBantu = nodeBantu->next;
    }

    nodeBantu->isidata = newData;
}
}

void updateAfter(linkedlist list, address &prev)
{
     if (isEmpty(list))
    {
        cout << "List kosong!" << endl;
        return;
    }
    else
    {
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    prev->next->isidata = newData;
}
}
void updateByNim(linkedlist &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = findNodeByData(list, nim);

        if (nodeBantu != Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;

            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// prosedur-prosedur untuk searching data didalam list
address findNodeByData(linkedlist List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodeByAddress(linkedlist List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur > nilaiAwal && umur < nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}

```
main.cpp
```
#include "list.h"
#include <iostream>
using namespace std;

int main(){
	linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    // updateFirst(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    // printList(List);
    // updateLast(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    // printList(List);

    // updateAfter(List, nodeC);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER NODE C ---" << endl;
    // printList(List);

    updateByNim(List, "2211110014");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);
    return 0;

}
```

program ini pake konsep adt singly linked list dengan struktur file modular (list.h, list.cpp, dan main.cpp) buat ngelola data mahasiswa yang isinya nama, nim, sama umur, di mana file header nyiapin semua prototipe fungsi dasar kayak insert, delete, searching, dan update, file implementation ngurusin logika kodenya secara lengkap, dan file main jalanin inisialisasi list, alokasi data 5 mahasiswa, proses insert, serta uji coba update data berdasarkan nim buat ditampilin ke terminal.

## Unguided

### 1\.Buatlah program Abstract Data Type (ADT) Singly Linked List dalam bahasa C++ yang dibagi menjadi file Singlylist.h, Singlylist.cpp, dan main.cpp dengan spesifikasi: tipe infotype bertipe int, address berupa pointer ke ElmList, struktur ElmList berisi info dan next, serta struktur List berisi First; lengkapi prototipe primitif (createList, alokasi, dealokasi, printInfo, insertFirst).                                                                                    Lakukan uji coba implementasi pada file main.cpp dengan memasukkan data menggunakan insertFirst secara berurutan untuk nilai 2, 0, 8, 12, dan 9 sehingga saat dicetak menghasilkan urutan 9 12 8 0 2.                                                                                                 Buatlah fungsi tambahan pencarian elemen berupa findElm(L, x) untuk mencari elemen dengan nilai info 8 di dalam list.                                                                                              Buatlah fungsi tambahan untuk menghitung jumlah total keseluruhan info dari seluruh elemen di dalam list (9 + 12 + 8 + 0 + 2 = 31). 

source code unguided 1
Singlylist.h
```
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// Tambahan soal nomor 3 & 4
address findElm(List L, infotype x);
int sumInfo(List L);

#endif
```
Singlylist.cpp
```
// Zhafif Yusuf Al Amin
// 109082500137

#include "Singlylist.h"

void createList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

int sumInfo(List L) {
    int total = 0;
    address P = L.First;
    while (P != NULL) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```
main.cpp
```
#include "Singlylist.h"

int main() {
    cout << "Zhafif Yusuf Al Amin" << endl;
    cout << "109082500137" << endl;

    List L;
    address P1, P2, P3, P4, P5 = NULL;
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

    address found = findElm(L, 8);
    if (found != NULL) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan" << endl;
    }

    cout << "Total info dari kelima elemen adalah " << sumInfo(L) << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%205/output/OutputSoal1.png)


Program ini pake konsep ADT Singly Linked List dengan pemisahan file modular (Singlylist.h, Singlylist.cpp, dan main.cpp) buat ngelola data integer lewat struktur node berpenunjuk arah satu atau singly linked list, di mana file header nyiapin kerangka struktur data sama prototipe fungsi dasar kayak createList, alokasi, dealokasi, printInfo, dan insertFirst beserta tambahan fungsi pencarian findElm dan penjumlahan sumInfo, file implementation ngurusin logika kodenya secara lengkap, dan file main jalanin inisialisasi list, alokasi nilai angka tertentu (2, 0, 8, 12, dan 9) pakai metode insertFirst (yang bikin urutan elemen di dalam list jadi 9 12 8 0 2), fungsi cetak, pencarian elemen 8, sampai perhitungan total keseluruhan info untuk ditampilin ke terminal.


## Kesimpulan
Berdasarkan praktikum Modul 5 tentang Singly Linked List, dapat disimpulkan bahwa Singly Linked List merupakan struktur data yang menghubungkan setiap elemen menggunakan pointer next, sehingga data dapat dikelola secara dinamis. Melalui implementasi ADT Singly Linked List menggunakan bahasa C++ dengan file terpisah, yaitu Singlylist.h, Singlylist.cpp, dan main.cpp, praktikan dapat memahami cara membuat list kosong, mengalokasikan dan menghapus memori, menambahkan elemen menggunakan insertFirst, serta menampilkan isi list menggunakan printInfo. Selain itu, praktikan juga mempelajari cara mencari elemen menggunakan fungsi findElm dan menghitung jumlah seluruh nilai menggunakan fungsi sumInfo. Berdasarkan hasil pengujian, penambahan data 2, 0, 8, 12, dan 9 menggunakan insertFirst menghasilkan urutan 9, 12, 8, 0, dan 2, dengan total nilai sebesar 31. Dengan demikian, praktikum ini membantu praktikan memahami konsep dasar, cara kerja pointer, serta penerapan operasi dasar pada struktur data Singly Linked List dalam bahasa C++.


## Referensi
Laboratorium Informatika Telkom University. (2026). Modul 04 Praktikum Struktur Data: Singly Linked List (Bagian Pertama). Bandung: Fakultas Informatika Telkom University.   Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.