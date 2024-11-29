//Konsep Antrian (Queue) dengan atribut Nama dan NIM

#include <iostream>
using namespace std;

// Struktur Node untuk Linked List dengan atribut Nama dan NIM
struct Node {
    string nama;
    int nim;
    Node* next;
};

// Pointer global untuk front dan rear
Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(string nama, int nim) {
    Node* newNode = new Node{nama, nim, nullptr};
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Mahasiswa " << nama << " dengan NIM " << nim << " ditambahkan ke antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
    } else {
        Node* temp = front;
        front = front->next;
        cout << "Mahasiswa " << temp->nama << " dengan NIM " << temp->nim << " dikeluarkan dari antrian.\n";
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
    } else {
        Node* temp = front;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << "\n";
            temp = temp->next;
        }
    }
}

int main() {
    int choice, nim;
    string nama;

    do {
        cout << "\nMenu:\n1. Tambah Antrian (Enqueue)\n2. Hapus Antrian (Dequeue)\n3. Lihat Antrian\n4. Keluar\nPilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                enqueue(nama, nim);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 4);

    return 0;
}

