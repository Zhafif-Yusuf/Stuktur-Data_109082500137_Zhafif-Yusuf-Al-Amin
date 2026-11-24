#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    if (Q.head == -1 && Q.tail == -1) {
        return true;
    } else {
        return false;
    }
}

bool isFullQueue(Queue Q) {
    if (Q.tail == 4) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            Q.tail = Q.tail + 1;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -999;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            // Jika elemen tinggal 1, reset ke kondisi kosong (-1)
            Q.head = -1;
            Q.tail = -1;
        } else {
            // Mekanisme Alternatif 1: Head diam, elemen digeser ke depan
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail = Q.tail - 1;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}