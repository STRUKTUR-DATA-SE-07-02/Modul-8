#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string data;
    Node* next;
};

// Pointer untuk head dan tail queue
Node* head = nullptr;
Node* tail = nullptr;

// Fungsi mengecek apakah queue kosong
bool isEmpty() {
    return head == nullptr;
}

// Fungsi untuk menambahkan elemen ke queue
void enqueue(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Data \"" << data << "\" berhasil ditambahkan ke antrian.\n";
}

// Fungsi untuk menghapus elemen dari queue
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
    cout << "Data \"" << temp->data << "\" telah keluar dari antrian.\n";
    delete temp;
}

// Fungsi untuk menampilkan elemen dalam queue
void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    Node* current = head;
    cout << "Isi antrian:\n";
    while (current != nullptr) {
        cout << "- " << current->data << endl;
        current = current->next;
    }
}

// Fungsi utama
int main() {
    enqueue("Asep");
    enqueue("Ahmad");
    viewQueue();
    dequeue();
    viewQueue();
    return 0;
}