#include <iostream>
#include <string>

using namespace std;

const int MAKSIMAL_QUEUE = 5; // Maksimal antrian
int front = 0;               // Penanda antrian depan
int back = 0;                // Penanda antrian belakang
string queueTeller[MAKSIMAL_QUEUE]; // Array untuk menyimpan antrian

// Cek apakah antrian penuh
bool isFull() {
    return back == MAKSIMAL_QUEUE;
}

// Cek apakah antrian kosong
bool isEmpty() {
    return back == 0;
}

// Fungsi menambahkan antrian
void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        // Kondisi ketika queue kosong
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            // Antrian sudah ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

// Fungsi mengurangi antrian
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        // Geser elemen ke depan
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

// Fungsi menghitung banyak antrian
int countQueue() {
    return back;
}

// Fungsi menghapus semua antrian
void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        // Reset semua elemen
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

// Fungsi melihat antrian
void viewQueue() {
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < MAKSIMAL_QUEUE; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    // Contoh penggunaan fungsi-fungsi queue
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    
    return 0;
}