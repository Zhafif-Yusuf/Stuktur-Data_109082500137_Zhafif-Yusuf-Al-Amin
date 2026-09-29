# **Laporan Praktikum Modul 1 \- Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)**

# 

Zhafif Yusuf Al Amin \- 109082500137
## Dasar Teori

### A. Stuktur Data
Struktur data merupakan cara atau skema dalam mengorganisasikan, menyimpan, dan mengelola data di dalam memori komputer agar dapat diakses dan dimanipulasi secara efisien oleh program[3]. Pemilihan struktur data yang tepat sangat mempengaruhi performa sistem, efisiensi memori, serta kompleksitas waktu eksekusi suatu algoritma[3][4].

#### 1. Pengertian Struktur Data
Struktur data dapat didefinisikan sebagai tata letak penyimpanan data yang logis beserta himpunan operasi yang dapat diterapkan pada data tersebut[3]. Dengan menerapkan struktur data, pemrosesan himpunan data yang berukuran besar dapat dilakukan secara sistematis dan terstruktur[4].

#### 2. Klasifikasi Struktur Data
Secara garis besar, struktur data dikelompokkan menjadi dua kategori utama, yaitu struktur data linier dan struktur data non-linier[4]:
Struktur Data Linier: Elemen-elemen data disusun secara berurutan atau sekuensial[4]. Contoh dari struktur data linier meliputi Array, Linked List, Stack, dan Queue[3][4].
Struktur Data Non-Linier: Elemen-elemen data tersusun secara hierarkis atau saling terhubung tidak dalam satu garis lurus[4]. Contoh dari struktur data non-linier mencakup Tree dan Graph[3][4].

#### 3. Operasi Dasar pada Struktur Data
Setiap struktur data mendukung berbagai operasi dasar untuk pengolahan data, di antaranya[3][5]:
Pengaksesan (Traversing): Menelusuri atau mengunjungi setiap elemen data dalam struktur data[3].
Penisipan (Insertion): Menambahkan elemen data baru ke dalam lokasi tertentu pada struktur data[5].
Penghapusan (Deletion): Mengeluarkan atau menghapus elemen data dari struktur data[5].
Pencarian (Searching): Menemukan lokasi elemen data berdasarkan kriteria atau nilai kunci tertentu[3].

### B. Linked List
Linked list merupakan struktur data linier dinamis yang alokasi memorinya dilakukan pada saat program dijalankan (runtime)[1][2]. Berbeda dengan array yang mengalokasikan memori secara berurutan dan berukuran tetap (static contiguous memory), linked list dapat bertambah atau berkurang ukurannya sesuai kebutuhan tanpa memuat batas maksimum di awal[1][2]. Setiap node pada linked list umumnya terdiri dari dua bagian utama, yaitu infotype (data) dan next (pointer penunjuk ke node berikutnya)[1][5].

#### 1. Jenis-Jenis Linked List
Berdasarkan struktur dan arah penunjukan pointer-nya, linked list dibedakan menjadi[1][2]:
Singly Linked List: Node hanya memiliki satu pointer yang menunjuk ke node berikutnya, dan node terakhir menunjuk ke nilai NULL[1].
Doubly Linked List: Node memiliki dua pointer, yaitu penunjuk ke node berikutnya (next) dan penunjuk ke node sebelumnya (prev)[2].
Circular Linked List: Pointer pada node terakhir menunjuk kembali ke node pertama (head), sehingga membentuk ikatan melingkar[1][2].

#### 2. Operasi pada Linked List
Operasi utama yang biasa diterapkan pada linked list antara lain[1][5]:
Penyisipan (Insertion): Menambahkan node baru di awal (insert first), di akhir (insert last), atau di antara node tertentu (insert after)[1].
Penghapusan (Deletion): Menghapus node di awal (delete first), di akhir (delete last), atau node tertentu, lalu membebaskan alokasi memorinya (dealokasi)[5].
Penelusuran (Traversal): Menelusuri setiap node dari ujung awal (head) hingga ujung akhir (tail) untuk menampilkan atau memproses data[1][5].

#### 3. Kelebihan dan Kekurangan Linked List
Kelebihan:
Pengalokasian memori bersifat dinamis sesuai kebutuhan data[1][2].
Operasi penyisipan dan penghapusan data bersifat efisien karena tidak memerlukan penggeseran (shifting) elemen data di memori[1][5].

Kekurangan:
Membutuhkan alokasi memori tambahan untuk menyimpan pointer/alamat pada setiap node[1][2].
Tidak mendukung akses acak (random access) secara langsung menggunakan indeks seperti pada array; pencarian harus dilakukan secara sekuensial (sequential search)[1][5].

## Unguided

### 1\. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

source code unguided 1

```
#include <iostream>
using namespace std;

int main() {
    float x;
    float y;
    
    cout << "input x: ";
    cin >> x;
    cout << "input y: ";
    cin >> y;

    cout << "Hasil Penjumlahan : " << x + y << endl;
    cout << "Hasil Pengurangan : " << x - y << endl;
    cout << "Hasil Perkalian   : " << x * y << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%201/output/OutputSoal1.png)


sebuah kode yang menggunakan bahasa cpp yang berfungsi untuk menghitung hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan yang inputannya sebuah float atau bilangan desimal. Program ini bekerja dengan menerima input angka dari pengguna melalui cin, menyimpannya ke dalam variabel x dan y, lalu mengeksekusi operasi matematika dasar secara langsung untuk kemudian menampilkan seluruh hasilnya di terminal menggunakan cout."

### 2\. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai
angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat
positif mulai dari 0 s.d 100)

source code unguided 2
```
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    int n;
    cin >> n;

    if (n < 0 || n > 100)
    {
        cout << "Input harus antara 0 dan 100" << endl;
    }
    else if (n == 0)
    {
        cout << n << " : Nol" << endl;
    }
    else if (n < 10)
    {
        cout << n << " : " << satuan[n] << endl;
    }
    else if (n == 10)
    {
        cout << n << " : sepuluh" << endl;
    }
    else if (n == 11)
    {
        cout << n << " : sebelas" << endl;
    }
    else if (n < 20)
    {
        cout << n << " : " << satuan[n % 10] << " belas" << endl;
    }
    else if (n < 100)
    {
        cout << n << " : " << satuan[n / 10] << " puluh";
        cout << " " << satuan[n % 10] << endl;
    }
    else
    {
        cout << n << " : seratus" << endl;
    }
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%201/output/OutputSoal2.png)

program ini menggunakan bahasa C++ yang berfungsi untuk mengonversi input angka bulat integer dari rentang 0 hingga 100 menjadi teks terbilangnya dalam bahasa indonesia. Program ini memanfaatkan array satuan untuk menyimpan kata dasar angka, serta percabangan if-else untuk mengecek kondisi angka—mulai dari angka khusus (seperti 0, 10, 11, dan 100), angka belasan (n % 10), hingga angka puluhan yang dipecah menjadi digit puluhan (n / 10) dan satuannya (n % 10) untuk menampilkan hasil teksnya di terminal.

### 3\. (Buatlah program yang dapat memberikan input dan output sbb.)

source code unguided 3
```
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;
    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < n - i; s++)
            cout << "  ";
        for (int j = i; j >= 1; j--)
            cout << j << " ";
        cout << "*";
        for (int j = 1; j <= i; j++)
            cout << " " << j;
        cout << endl;
    }
    return 0;
}
```
### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 2_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%201/output/OutputSoal3.png)

sebuah kode yang menggunakan bahasa cpp yang berfungsi untuk mencetak pola angka simetris berbentuk piramida terbalik dengan simbol bintang di tengahnya berdasarkan input n. Program ini memakai perulangan bersarang (nested loop) untuk mengatur spasi di kiri, mencetak angka yang makin mengecil ke kiri, bintang di tengah, lalu angka yang makin membesar ke kanan secara berulang sampai baris bawah tinggal bintangnya aja

## Kesimpulan

pada praktikum kali ini saya dapat mengetahui dasar dasar bahasa C++ mulai dari operasi dasar, percabangan sampai perulangan. Saya sangat menyukainya:D

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). MIT Press.

[2] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.

[3] Tim Dosen Struktur Data. (2026). Modul Praktikum Struktur Data. Fakultas Informatika, Universitas Telkom.

[4] Munir, R. (2011). Algoritma dan Pemrograman dalam Bahasa Pascal, C, dan C++. Informatika Bandung.

[5] Tanenbaum, A. M., Langsam, Y., & Augenstein, M. J. (1996). Data Structures Using C and C++ (2nd ed.). Prentice-Hall.