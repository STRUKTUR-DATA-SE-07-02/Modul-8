#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk menyimpan data mahasiswa
struct Node {
    string nama;  // Nama mahasiswa
    string nim;   // NIM mahasiswa
    Node* next;   // Pointer ke node berikutnya
};

// Pointer untuk mengelola antrian
Node* front = nullptr; // Node paling depan
Node* rear = nullptr;  // Node paling belakang

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi untuk menambahkan mahasiswa ke antrian
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
    cout << "Mahasiswa bernama \"" << nama << "\" dengan NIM \"" << nim
         << "\" berhasil ditambahkan ke antrian." << endl;
}

// Fungsi untuk menghapus mahasiswa dari antrian
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong, tidak ada mahasiswa yang dapat dikeluarkan." << endl;
        return;
    }

    Node* temp = front;
    cout << "Mahasiswa bernama \"" << temp->nama << "\" dengan NIM \"" << temp->nim
         << "\" telah keluar dari antrian." << endl;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr; // Jika antrian menjadi kosong
    }
    delete temp;
}

// Fungsi untuk menampilkan isi antrian
void viewQueue() {
    if (isEmpty()) {
        cout << "Isi antrian: [Kosong]" << endl;
        return;
    }

    cout << "Daftar mahasiswa dalam antrian:\n";
    Node* temp = front;
    while (temp != nullptr) {
        cout << "- Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
        temp = temp->next;
    }
}

// Fungsi utama untuk menjalankan program
int main() {
    enqueue("Andi", "2311101234");
    enqueue("Maya", "2023105678");
    enqueue("Siti", "2311140456");
    viewQueue();
    dequeue();
    viewQueue();
    return 0;
}
