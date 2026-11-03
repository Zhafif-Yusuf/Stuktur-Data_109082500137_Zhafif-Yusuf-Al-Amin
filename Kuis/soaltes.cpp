#include <iostream>
#include <string>

using namespace std;

const int MAX_CAPACITY = 100;

struct Queue {
    string data[MAX_CAPACITY];
    int head;
    int tail;
    int count;
};

void initQueue(Queue &q) {
    q.head = 0;
    q.tail = -1;
    q.count = 0;
}

bool isEmpty(Queue &q) {
    return (q.count == 0);
}

bool isFull(Queue &q) {
    return (q.count == MAX_CAPACITY);
}

void enqueue(Queue &q, string plat) {
    if (isFull(q)) {
        cout << "Antrean penuh!\n";
        return;
    }
    q.tail = (q.tail + 1) % MAX_CAPACITY;
    q.data[q.tail] = plat;
    q.count++;
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrean kosong!\n";
        return;
    }
    cout << "Kendaraan dengan plat " << q.data[q.head] << " dipersilakan masuk.\n";
    q.head = (q.head + 1) % MAX_CAPACITY;
    q.count--;
}

void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "Daftar tunggu kendaraan kosong.\n";
        return;
    }
    cout << "Daftar Kendaraan yang Masih Menunggu:\n";
    for (int i = 0; i < q.count; i++) {
        int idx = (q.head + i) % MAX_CAPACITY;
        cout << "- " << q.data[idx] << "\n";
    }
}

int main() {
    cout << "Zhafif Yusuf Al Amin\n";
    cout << "109082500137\n\n";

    Queue antreanParkir;
    initQueue(antreanParkir);

    string platInput;

    // 1. Masukkan minimal lima nomor kendaraan secara manual via CLI[cite: 2]
    cout << "=== 1. Masukkan 5 Nomor Kendaraan Awal ===\n";
    for (int i = 1; i <= 5; i++) {
        cout << "Masukkan plat nomor kendaraan ke-" << i << ": ";
        getline(cin, platInput);
        enqueue(antreanParkir, platInput);
    }
    cout << "\n";
    display(antreanParkir);
    cout << "\n";

    // 2. Proses dua kendaraan[cite: 2]
    cout << "=== 2. Memproses Dua Kendaraan ===\n";
    dequeue(antreanParkir);
    dequeue(antreanParkir);
    cout << "\n";
    display(antreanParkir);
    cout << "\n";

    // 3. Masukkan 2 kendaraan baru karena ada slot kosong, lalu tampilkan kembali antrean[cite: 2]
    cout << "=== 3. Masukkan 2 Kendaraan Baru (Mengisi Slot Kosong) ===\n";
    for (int i = 1; i <= 2; i++) {
        cout << "Masukkan plat nomor kendaraan baru ke-" << i << ": ";
        getline(cin, platInput);
        enqueue(antreanParkir, platInput);
    }
    cout << "\n";
    display(antreanParkir);

    return 0;
}