#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string nama;
    string nim; // Menggunakan string agar mendukung NIM 10 digit
    Node* next;
};

// Pointer untuk head dan tail queue
Node* head = nullptr;
Node* tail = nullptr;

// Fungsi mengecek apakah queue kosong
bool isEmpty() {
    return head == nullptr;
}

// Fungsi untuk menambahkan mahasiswa ke queue
void enqueue(string nama, string nim) {
    if (nim.length() != 10) {
        cout << "NIM harus berjumlah 10 digit.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Mahasiswa " << nama << " dengan NIM " << nim << " berhasil ditambahkan ke antrian.\n";
}

// Fungsi untuk menghapus mahasiswa dari queue
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    cout << "Mahasiswa " << temp->nama << " dengan NIM " << temp->nim << " telah keluar dari antrian.\n";
    delete temp;
}

// Fungsi untuk menampilkan isi antrian mahasiswa
void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    Node* current = head;
    cout << "Isi antrian mahasiswa:\n";
    while (current != nullptr) {
        cout << "Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
    }
}

// Fungsi utama
int main() {
    enqueue("Muhammad Ikhsan Al Hakim", "2311104064");
    enqueue("Gojo", "2024107090");
    viewQueue();
    dequeue();
    viewQueue();
    return 0;
}