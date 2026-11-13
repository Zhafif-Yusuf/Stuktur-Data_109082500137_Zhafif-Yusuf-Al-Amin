# **Laporan Praktikum MODUL 7 - STACK**

# 


Zhafif Yusuf Al Amin \- 109082500137
## Dasar Teori

### A. Konsep Dasar Doubly Linked List EDIT
#### 1. Definisi Doubly Linked List EDIT
EDIT Doubly linked list (list berkait ganda) adalah struktur data linier yang terdiri dari sekumpulan node yang saling terhubung secara dinamis melalui pointer. Berbeda dengan singly linked list yang hanya memiliki satu pointer penunjuk, setiap node pada doubly linked list memiliki tiga bagian, yaitu bagian data (info), pointer next yang menunjuk ke node sesudahnya, dan pointer prev yang menunjuk ke node sebelumnya. Dengan dua arah pointer ini, penelusuran data dapat dilakukan secara maju maupun mundur.

#### 2. Perbedaan dengan Singly Linked List EDIT
EDIT Pada singly linked list, node hanya dapat ditelusuri satu arah dari First hingga Nil. Pada doubly linked list, pointer prev memungkinkan akses ke node sebelumnya secara langsung. Hal ini mempermudah operasi penghapusan dan penyisipan di tengah atau di akhir list, karena tidak perlu menelusuri list dari awal untuk mencari node sebelumnya. Selain itu, doubly linked list umumnya menyimpan dua pointer penanda, yaitu First yang menunjuk ke node pertama dan Last yang menunjuk ke node terakhir, sehingga operasi insertLast dan deleteLast dapat dilakukan tanpa menelusuri seluruh list. Kekurangannya, setiap node membutuhkan memori tambahan untuk menyimpan pointer prev, dan pengelolaan pointer menjadi lebih rumit karena ada dua arah yang harus dijaga konsistensinya.

#### 3. Hubungan ADT dengan Struktur Data EDIT
EDIT Pada praktikum ini, doubly linked list diimplementasikan sebagai Abstract Data Type (ADT) yang dipisah menjadi beberapa file. File Doublylist.h berisi definisi tipe data dan deklarasi fungsi (prototype), Doublylist.cpp berisi implementasi fungsi-fungsi tersebut, dan main.cpp berisi program utama yang memanggil fungsi ADT. Tipe data yang digunakan adalah kendaraan (berisi nopol, warna, dan thnBuat) yang dialiaskan sebagai infotype, struct ElmList sebagai node (berisi info, next, dan prev), serta struct List yang berisi pointer First dan Last. Jika list kosong, First dan Last bernilai NULL. Jika list hanya berisi satu elemen, First dan Last menunjuk ke node yang sama.

### B. Operasi Dasar pada Doubly Linked List EDIT
#### 1. Inisialisasi dan Manajemen Memori EDIT
EDIT Fungsi CreateList mengeset L.First dan L.Last menjadi NULL sehingga list terbentuk dalam kondisi kosong. Fungsi alokasi membuat node baru secara dinamis menggunakan operator new, mengisi info dengan data yang diberikan, serta mengeset next dan prev menjadi NULL. Fungsi dealokasi menghapus node dengan operator delete dan mengeset pointer menjadi NULL agar memori dikembalikan ke sistem dan tidak terjadi kebocoran memori (memory leak).

#### 2. Operasi Penyisipan (Insert First)EDIT
EDIT Operasi insertLast menambahkan node baru di akhir list. Jika list masih kosong, First dan Last langsung menunjuk ke node baru. Jika list sudah berisi, prev node baru diarahkan ke Last lama, next dari Last lama diarahkan ke node baru, kemudian Last diperbarui menunjuk ke node baru tersebut.

#### 3. Operasi Penelusuran dan Pencarian (printInfo dan findElm) EDIT
EDIT Fungsi printInfo menelusuri list dari First menggunakan pointer next hingga bertemu NULL, sambil menampilkan nomor polisi, warna, dan tahun pembuatan tiap kendaraan. Jika list kosong, ditampilkan pesan “List Kosong”. Fungsi findElm juga menelusuri list dengan cara yang sama untuk mencari node yang nopol-nya sama dengan data yang dicari. Fungsi ini mengembalikan alamat node jika ditemukan dan NULL jika tidak ditemukan. Fungsi ini dimanfaatkan untuk mencegah data dengan nomor polisi yang sama dimasukkan dua kali.

#### 4. Operasi Penghapusan (Delete) EDIT
EDIT Terdapat tiga operasi penghapusan pada program ini:

EDIT deleteFirst: melepas node pertama. First dipindahkan ke node berikutnya dan prev-nya diset NULL. Jika hanya ada satu elemen, First dan Last menjadi NULL.
deleteLast: melepas node terakhir. Last dipindahkan ke node sebelumnya dan next-nya diset NULL. Jika hanya ada satu elemen, First dan Last menjadi NULL.
deleteAfter: melepas node yang berada setelah node Prec. Pointer next milik Prec diarahkan ke node sesudah node yang dihapus, dan pointer prev node tersebut diarahkan kembali ke Prec.
Ketiga fungsi hanya melepas node dari list dan menyimpannya pada parameter P. Penghapusan memori dilakukan terpisah menggunakan fungsi dealokasi.

## Guided 1

### 1. Stack

source code Guided 1
stack.h
```
#ifndef STACK_TABLE
#define STACK_TABLE
#include <iostream>
using namespace std;
const int MAX = 10;

struct stackTable
{
    int data[MAX];
    int top;
};
bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);
void push(stackTable &s, int angka);
void pop(stackTable &s); 
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);
#endif
```
stack.cpp
```

#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s)
{
    return s.top == -1;
}
bool isFull(stackTable s)
{
    return s.top == MAX - 1;
}
void createStack(stackTable &s)
{
    s.top = -1;
}
void push(stackTable &s, int angka)
{

    if (isFull(s))
    {
        cout << "Stack penuh!" << endl;
    }
    else
    {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data" << angka << "berhasil ditambahkan kedalam stack !" << endl;
    }
}

void pop(stackTable &s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        int val = s.data[s.top];
        s.top--;
        cout << "Data" << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    // index = top

    int idx = s.top - (posisi - 1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        for (int i = s.top; i >= 0; --i)
        {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i)
    {
        if (s.data[i] == data)
        {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found)
    {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

```
main.cpp
```
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    update(s, 2);
    update(s, 1);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
EDIT : Program ini membuat doubly linked list untuk data makanan. List kosong dibuat dulu, lalu 5 node ditambahkan dengan insertFirst, insertLast, insertAfter, dan insertBefore sampai urutannya D - A - C - E - B. Setelah itu data diubah dengan fungsi update, dicari dengan findByName dan findByMinRating, lalu dihapus dengan deleteByName, deleteFirst, dan deleteBefore. Isi list ditampilkan di tiap tahap untuk melihat hasilnya.

## Guided 2

### 2. Stack

source code Guided 1
stack.h
```
#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;
const int MAX = 10;

typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(addresss &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack); 
void update(stack &listStack, int posisi);
void view(stack &listStack);
void searchData(stack listStack, int data);
#endif
```
stack.cpp
```
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack)
{
    if (listStack.top == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createStack(stack &listStack)
{
    listStack.top = Nil;
}

address alokasi(int angka)
{
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru)
{
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack)
{
    address nodeHapus;
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " << nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi)
{
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        if (posisi == 0)
        {
            cout << "Posisi tidak valid!" << endl;
        }
        else
        {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while (nodeBantu != Nil)
            {
                if (count < posisi)
                {
                    nodeBantu = nodeBantu->next;
                    count++;
                }
                else if (count == posisi)
                {
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        while (nodeBantu != Nil)
        {
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while (nodeBantu != Nil)
        {
            if (nodeBantu->dataAngka == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            }
            else
            {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if (found == false)
        {
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
main.cpp
```
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
EDIT : Program ini membuat doubly linked list untuk data makanan. List kosong dibuat dulu, lalu 5 node ditambahkan dengan insertFirst, insertLast, insertAfter, dan insertBefore sampai urutannya D - A - C - E - B. Setelah itu data diubah dengan fungsi update, dicari dengan findByName dan findByMinRating, lalu dihapus dengan deleteByName, deleteFirst, dan deleteBefore. Isi list ditampilkan di tiap tahap untuk melihat hasilnya.

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

![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%207/output/OutputSoal1.png)

EDIT Sebuah program yang dimana data kendaraan (nopol, warna, dan tahun buat) disimpan dalam doubly linked list menggunakan ADT yang dipisah ke Doublylist.h, Doublylist.cpp, dan main.cpp. Program meminta input 4 data kendaraan dan mengecek nopol dengan findElm supaya tidak ada yang kembar, lalu data yang lolos dimasukkan dengan insertLast dan ditampilkan dengan printInfo. Setelah itu program mencari data berdasarkan nopol, lalu menghapus data berdasarkan nopol memakai deleteFirst, deleteLast, atau deleteAfter sesuai posisinya, dan node yang dilepas dihapus dari memori dengan dealokasi. Terakhir, isi list ditampilkan lagi untuk memastikan datanya sudah berkurang.

## Kesimpulan
EDIT  dari praktikum Modul 6, saya jadi paham bahwa doubly linked list adalah struktur data yang tiap elemennya punya dua pointer, yaitu next dan prev, sehingga list bisa dibaca dari depan maupun belakang. Lewat ADT yang dibuat di Doublylist.h, Doublylist.cpp, dan main.cpp, saya belajar membuat list, menambah data dengan insertLast, menampilkan data dengan printInfo, mencari data dengan findElm (sekaligus mencegah nopol ganda), serta menghapus data dengan deleteFirst, deleteLast, dan deleteAfter. Yang paling penting, saya harus teliti menjaga pointer First, Last, next, dan prev supaya list tetap tersambung dengan benar.

## Referensi
EDIT Laboratorium Informatika Telkom University. (2026). Modul 04 Praktikum Struktur Data: Singly Linked List (Bagian Pertama). Bandung: Fakultas Informatika Telkom University.   Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.