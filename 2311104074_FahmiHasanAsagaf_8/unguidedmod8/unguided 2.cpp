#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim) {
    Node* newNode = new Node{nama, nim, nullptr};
    if (isEmpty()) {
        front = back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) back = nullptr;
    }
}

void viewQueue() {
    cout << "Data antrian mahasiswa:" << endl;
    Node* temp = front;
    int count = 1;
    while (temp != nullptr) {
        cout << count++ << ". Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
        temp = temp->next;
    }
    if (isEmpty()) {
        cout << "(Antrian kosong)" << endl;
    }
}

int main() {
    int pilihan;
    string nama, nim;

    do {
        cout << "Menu:\n1. Tambah Antrian\n2. Hapus Antrian\n3. Lihat Antrian\n4. Keluar\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                enqueueAntrian(nama, nim);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}