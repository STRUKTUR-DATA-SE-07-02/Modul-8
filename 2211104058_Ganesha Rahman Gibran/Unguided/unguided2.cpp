#include <iostream>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Pointer front dan rear
Node* front = nullptr;
Node* rear = nullptr;

// Fungsi mengecek apakah Queue kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi menambahkan elemen ke Queue
void enqueue(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Fungsi menghapus elemen dari Queue
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

// Fungsi menampilkan elemen di Queue
void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        Node* temp = front;
        cout << "Data antrian:" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu Queue:" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Hapus Antrian" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama, nim;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            getline(cin, nim);
            enqueue(nama, nim);
        } else if (pilihan == 2) {
            dequeue();
        } else if (pilihan == 3) {
            viewQueue();
        }
    } while (pilihan != 4);

    return 0;
}
