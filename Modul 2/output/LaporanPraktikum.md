# **Laporan Praktikum Modul 2 \- PENGENALAN BAHASA C++ (BAGIAN KEDUA)**

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

## Guided

### 1. Fungsi

```
#include <iostream>
using namespace std;
int maks3(int a, int b, int c);
int main(){
    int x,y,z;
    cout << "masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "masukkan nilai bilangan ke-2 = ";
    cin >> y;
    cout << "masukkan nilai bilangan ke-3 = ";
    cin >> z;
    cout << "nilai maksimumnya adalah =" << maks3(x,y,z);
    return 0;
}
int maks3(int a, int b, int c){
    int temp_max = a;
    if(b > temp_max)
    temp_max = b;
    if(c > temp_max)
    temp_max = c;
    return (temp_max);
}
```

sebuah kode yang menggunakan bahasa c++ yang berfungsi untuk menentukan nilai terbesar dari tiga buah bilangan inputan pengguna. program ini bekerja dengan menerima tiga angka melalui cin lalu memanggil fungsi maks3 yang membandingkan setiap angka menggunakan variabel penampung temp max dan percabangan if untuk mengembalikan nilai maksimumnya ke terminal.

### 2. Prosedur

```
#include <iostream>
using namespace std;

void tulis(int x);
int main() {
    int jum;
    cout << "jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}

void tulis(int x){
    for (int i=0; i<x; i++)
        cout << "baris ke-" << i+1 << endl;
}
```

sebuah kode yang menggunakan bahasa c++ yang berfungsi untuk mencetak teks baris secara berulang sesuai jumlah yang diinput pengguna. program ini bekerja dengan menerima angka inputan jumlah baris lalu memanggil prosedur tulis yang menggunakan perulangan for untuk menampilkan teks baris ke beserta nomor urutnya ke terminal tanpa mengembalikan nilai

### 3. Parameter Fungsi

```
#include <iostream>
using namespace std;

// 1. Call by Value: variabel asli TIDAK berubah
void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// 2. Call by Pointer: variabel asli IKUT berubah (pakai *)
void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Call by Reference: variabel asli IKUT berubah (pakai &)
void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;

    cout << "=== Nilai Awal ===" << endl;
    cout << "a = " << a << ", b = " << b << endl << endl;

    // Uji Call by Value
    tukarValue(a, b);
    cout << "Setelah tukarValue (Call by Value):" << endl;
    cout << "a = " << a << ", b = " << b << " (Tetap)" << endl << endl;

    // Uji Call by Pointer (Mengirimkan alamat &a dan &b)
    tukarPointer(&a, &b);
    cout << "Setelah tukarPointer (Call by Pointer):" << endl;
    cout << "a = " << a << ", b = " << b << " (Berubah)" << endl << endl;

    // Uji Call by Reference (Langsung mengirimkan variabel a dan b)
    tukarReference(a, b);
    cout << "Setelah tukarReference (Call by Reference):" << endl;
    cout << "a = " << a << ", b = " << b << " (Berubah kembali)" << endl;

    return 0;
}
```

sebuah kode yang menggunakan bahasa c++ yang berfungsi untuk mendemonstrasikan perbedaan tiga metode pengiriman parameter yaitu pemanggilan berdasarkan nilai, pointer, dan referensi dalam menukar dua nilai variabel. program ini bekerja dengan menjalankan ketiga fungsi penukar tersebut lalu menampilkan perubahan nilai variabel a dan b di terminal untuk membuktikan bahwa pemanggilan nilai tidak mengubah variabel asli sedangkan pemanggilan pointer dan referensi berhasil mengubah nilai variabel aslinya.

## Unguided

### 1\. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.

source code unguided 1

```
#include <iostream>
using namespace std;

void cetakMatriks(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
void penjumlahan(int A[3][3], int B[3][3]) {
    cout << "\nHasil Penjumlahan (A + B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << endl;
    }
}
void pengurangan(int A[3][3], int B[3][3]) {
    cout << "\nHasil Pengurangan (A - B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] - B[i][j] << " ";
        }
        cout << endl;
    }
}
void perkalian(int A[3][3], int B[3][3]) {
    cout << "\nHasil Perkalian (A * B):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int total = 0;
            for (int k = 0; k < 3; k++) {
                total += A[i][k] * B[k][j];
            }
            cout << total << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    cout << "Matriks A:\n";
    cetakMatriks(A);
    cout << "\nMatriks B:\n";
    cetakMatriks(B);
    penjumlahan(A, B);
    pengurangan(A, B);
    perkalian(A, B);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%202/output/OutputSoal1.png)


sebuah kode yang menggunakan bahasa c++ yang berfungsi untuk mengolah matriks array dua dimensi berukuran 3x3. program ini bekerja dengan menyediakan fungsi cetak matriks untuk menampilkan bentuk matriks, serta fungsi penjumlahan dan pengurangan yang memanfaatkan perulangan bersarang untuk mengoperasi tiap elemen matriks a dan b secara langsung lalu menampilkan seluruh hasilnya di terminal.

### 2\.Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.

source code unguided 2
```
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;
    int z = 30;

    int *px = &x;
    int *py = &y;
    int *pz = &z;
    int temp;

    cout << "angka x awal: " << *px << endl; 
    cout << "angka y awal: " << *py << endl;
    cout << "angka z awal: " << *pz << endl;
    temp = *px;
    *px = *py;
    *py = *pz;
    *pz = temp;

    cout << "\nangka x akhir: " << x << endl;
    cout << "angka y akhir: " << y << endl;
    cout << "angka z akhir: " << z << endl;
    return 0;
}
```

### Output Unguided 2 :

##### Output 2

![Screenshot Output Unguided 2_2](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%202/output/OutputSoal2.png)

sebuah kode yang menggunakan bahasa c++ yang berfungsi untuk melakukan pertukaran nilai dari tiga variabel yaitu x, y, dan z menggunakan konsep pointer. program ini bekerja dengan mendeklarasikan pointer px, py, dan pz yang menunjuk ke alamat memori variabel asli, lalu memanfaatkan variabel penampung temp untuk menggeser dan menukar posisi nilainya secara berurutan untuk kemudian menampilkan nilai awal dan nilai akhirnya di terminal.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut:

```text
arrA = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1}
```

Buatlah program yang dapat mencari **nilai minimum, maksimum, dan rata-rata** dari array tersebut!

#### Ketentuan:

1. Untuk mencari **nilai minimum dan maksimum**, harus dibuat menjadi sebuah **function**.
2. Untuk mencari **nilai rata-rata**, harus dibuat menjadi sebuah **procedure**.
3. Buat output di dalam fungsi utama (`main`) untuk menampilkan **nilai rata-rata** yang sudah didapatkan melalui procedure sebelumnya.
4. Gunakan metode **pass by reference** atau **pass by pointer**.
5. Buat **menu sederhana** untuk menjalankan setiap procedure/function.

#### Tampilan Menu

```text
--- Menu Program Array ---

1. Tampilkan isi array
2. Cari nilai maksimum
3. Cari nilai minimum
4. Hitung nilai rata-rata
```


source code unguided 3
```
#include <iostream>
using namespace std;

int minimum(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int maksimum(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i > max; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void HRataRata(int arr[], int n, float &rataRata)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    rataRata = total / n;
}

void tampilArray(int arr[], int n)
{
    cout << "Isi Array: ";
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arrA[] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int n = 10;
    int x;
    float rataRata = 0;

    do
    {
        cout << "---Menu Program Array---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari indeks maksimum\n";
        cout << "3. Cari indeks minimum\n";
        cout << "4. Hitung rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu 1-5: ";
        cin >> x;
        cout << endl;

        switch (x)
        {
        case 1:
            tampilArray(arrA, n);
            break;
        case 2:
            cout << "nilai maksimumnya " << maksimum (arrA, n) << endl;
            break;
        case 3:
            cout << "nilai minimumnya " << minimum (arrA, n) << endl;
            break;
        case 4:
            HRataRata(arrA, n, rataRata);
            cout << "rata rata " << rataRata << endl;
            break;

        case 5:
            cout << "program selesai\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    }
    while (x!=5);
    return 0;
}
```
### Output Unguided 3 :

##### Output 3

![Screenshot Output Unguided 2_3](https://raw.githubusercontent.com/Zhafif-Yusuf/Stuktur-Data_109082500137_Zhafif-Yusuf-Al-Amin/main/Modul%202/output/OutputSoal3.png)

sebuah kode yang menggunakan bahasa c++ yang berfungsi untuk mengolah data didalam array satu dimensi melalui program menu interaktif berbasis perulangan do while. program ini bekerja dengan menerima input pilihan menu dari pengguna melalui cin, lalu mengeksekusi fungsi yang dipilih seperti menampilkan seluruh isi array, mencari nilai maksimum dan minimum, hingga menghitung nilai rata-rata dari elemen array tersebut untuk ditampilkan di terminal.

## Kesimpulan

pada praktikum kali ini saya dapat mengetahui dasar dasar bahasa C++ mulai dari operasi dasar, percabangan sampai perulangan. Saya sangat menyukainya:D

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). MIT Press.

[2] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.

[3] Tim Dosen Struktur Data. (2026). Modul Praktikum Struktur Data. Fakultas Informatika, Universitas Telkom.

[4] Munir, R. (2011). Algoritma dan Pemrograman dalam Bahasa Pascal, C, dan C++. Informatika Bandung.

[5] Tanenbaum, A. M., Langsam, Y., & Augenstein, M. J. (1996). Data Structures Using C and C++ (2nd ed.). Prentice-Hall.