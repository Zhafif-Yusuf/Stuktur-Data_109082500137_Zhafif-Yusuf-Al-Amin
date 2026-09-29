# **Laporan Praktikum Modul 1 \- Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)**

# 

Zhafif Yusuf Al Amin \- 109082500137

## Dasar Teori


A. Stuktur Data
Struktur data adalah tata letak atau cara mengorganisasikan, mengelola, dan menyimpan data di dalam memori komputer agar dapat diakses serta dimanipulasi secara efisien oleh suatu algoritma [1]. Penggunaan struktur data yang tepat sangat mempengaruhi performa sistem, kompleksitas waktu (time complexity), serta efisiensi penggunaan ruang memori (space complexity) [2].

### 

...

#### 1\. Pengertian Struktur Data
Struktur data dapat didefinisikan sebagai skema pengorganisasian data yang diterapkan pada kumpulan elemen data beserta himpunan operasi yang berlaku pada data tersebut [1]. Secara garis besar, struktur data memfasilitasi pemrosesan data berjumlah besar secara terstruktur sehingga penanganan data menjadi lebih optimal [3].

#### 2\. Klasifikasi Struktur Data
Struktur data secara umum dikelompokkan menjadi dua kategori utama, yaitu struktur data linier dan struktur data non-linier [2]:

Struktur Data Linier: Elemen-elemen data tersusun secara berurutan atau sekuensial dalam satu baris [2]. Contoh dari struktur data linier antara lain Array, Linked List, Stack (Tumpukan), dan Queue (Antrean) [1], [2].

Struktur Data Non-Linier: Elemen-elemen data tidak tersusun secara berurutan, melainkan terhubung secara hierarkis atau berjejaring [2]. Contoh dari struktur data non-linier adalah Tree (Pohon) dan Graph (Graf) [3].

#### 3\. Operasi Dasar pada Struktur Data
Setiap jenis struktur data mendukung serangkaian operasi dasar yang digunakan untuk memanipulasi data di dalamnya, antara lain [1], [3]:

Pengaksesan (Traversing): Mengunjungi setiap elemen data dalam struktur data setidaknya satu kali untuk melakukan pemrosesan tertentu [1].

Penisipan (Insertion): Menambahkan elemen data baru ke dalam struktur data [3].

Penghapusan (Deletion): Menghapus elemen data yang ada dari struktur data [3].

Pencarian (Searching): Menemukan lokasi atau keberadaan suatu elemen data berdasarkan kunci tertentu [1].

Pengurutan (Sorting): Menyusun ulang elemen-elemen data berdasarkan urutan tertentu (misalnya ascending atau descending) [2].

B. Linked List
Linked list merupakan struktur data linier dinamis yang alokasi memorinya dilakukan pada saat program dijalankan (runtime)[1][2]. Berbeda dengan array yang mengalokasikan memori secara berurutan dan berukuran tetap (static contiguous memory), linked list dapat bertambah atau berkurang ukurannya sesuai kebutuhan tanpa memuat batas maksimum di awal[1][2]. Setiap node pada linked list umumnya terdiri dari dua bagian utama, yaitu infotype (data) dan next (pointer penunjuk ke node berikutnya)[1][5].
### 

...

#### 1\. Jenis-Jenis Linked List
Berdasarkan struktur dan arah penunjukan pointer-nya, linked list dibedakan menjadi[1][2]:

Singly Linked List: Node hanya memiliki satu pointer yang menunjuk ke node berikutnya, dan node terakhir menunjuk ke nilai NULL[1].

Doubly Linked List: Node memiliki dua pointer, yaitu penunjuk ke node berikutnya (next) dan penunjuk ke node sebelumnya (prev)[2].

Circular Linked List: Pointer pada node terakhir menunjuk kembali ke node pertama (head), sehingga membentuk ikatan melingkar[1][2].

#### 2\. Operasi pada Linked List
Operasi utama yang biasa diterapkan pada linked list antara lain[1][5]:

Penyisipan (Insertion): Menambahkan node baru di awal (insert first), di akhir (insert last), atau di antara node tertentu (insert after)[1].

Penghapusan (Deletion): Menghapus node di awal (delete first), di akhir (delete last), atau node tertentu, lalu membebaskan alokasi memorinya (dealokasi)[5].

Penelusuran (Traversal): Menelusuri setiap node dari ujung awal (head) hingga ujung akhir (tail) untuk menampilkan atau memproses data[1][5].

#### 3\. Kelebihan dan Kekurangan Linked List
Kelebihan:

Pengalokasian memori bersifat dinamis sesuai kebutuhan data[1][2].

Operasi penyisipan dan penghapusan data bersifat efisien karena tidak memerlukan penggeseran (shifting) elemen data di memori[1][5].

Kekurangan:

Membutuhkan alokasi memori tambahan untuk menyimpan pointer/alamat pada setiap node[1][2].

Tidak mendukung akses acak (random access) secara langsung menggunakan indeks seperti pada array; pencarian harus dilakukan secara sekuensial (sequential search)[1][5].


## Unguided

### 1\. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.\

source code unguided 1
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
### Output Unguided 1 :

##### Output 1

\!\[Screenshot Output Unguided 1\_1\]([https://github.com/(username](https://github.com/\(username) github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh : ![Screenshot Output Unguided 1\_1]()

##### Output 2

\!\[Screenshot Output Unguided 1\_2\]([https://github.com/(username](https://github.com/\(username) github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1

### 2\. (isi dengan soal unguided 2\)

source code unguided 2

### Output Unguided 2 :

##### Output 1

\!\[Screenshot Output Unguided 2\_1\]([https://github.com/(username](https://github.com/\(username) github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh : ![Screenshot Output Unguided 2\_1]()

##### Output 2

\!\[Screenshot Output Unguided 2\_2\]([https://github.com/(username](https://github.com/\(username) github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3\. (isi dengan soal unguided 3\)

source code unguided 3

### Output Unguided 3 :

##### Output 1

\!\[Screenshot Output Unguided 3\_1\]([https://github.com/(username](https://github.com/\(username) github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh : ![Screenshot Output Unguided 3\_1]()

##### Output 2

\!\[Screenshot Output Unguided 3\_2\]([https://github.com/(username](https://github.com/\(username) github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan

...

## Referensi

Daftar Pustaka / Referensi Jurnal
[1] Parmar, V. P., & Kumbharana, C. K. (2015). Comparing Linear Search and Binary Search Algorithms to Search an Element from a Linear List Implemented through Static Array, Dynamic Array and Linked List. International Journal of Computer Applications, 121(3), 11-17.

[2] Drozdek, A. (2013). Data Structures and Algorithms in C++ (4th ed.). Cengage Learning.

[3] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson Education.

[4] Karumanchi, N. (2017). Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles (5th ed.). CareerMonk Publications.

[5] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). MIT Press.

...