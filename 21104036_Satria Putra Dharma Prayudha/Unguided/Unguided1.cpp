//Implementasi Queue Menggunakan Linked List

#include <iostream>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Pointer global untuk front dan rear
Node* front = nullptr;
Node* rear = nullptr;

// Fungsi untuk memeriksa apakah queue kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi untuk menambahkan data ke dalam queue
void enqueue(int data) {
    Node* newNode = new Node{data, nullptr};
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Data " << data << " ditambahkan ke antrian.\n";
}

// Fungsi untuk menghapus data dari queue
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
    } else {
        Node* temp = front;
        front = front->next;
        cout << "Data " << temp->data << " dikeluarkan dari antrian.\n";
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

// Fungsi untuk melihat data dalam queue
void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
    } else {
        Node* temp = front;
        cout << "Data antrian: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int choice, data;

    do {
        cout << "\nMenu:\n1. Tambah Antrian (Enqueue)\n2. Hapus Antrian (Dequeue)\n3. Lihat Antrian\n4. Keluar\nPilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> data;
                enqueue(data);
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