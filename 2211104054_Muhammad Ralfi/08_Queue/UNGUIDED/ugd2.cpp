#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string NIM;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(string nama, string NIM) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->NIM = NIM;
    newNode->next = nullptr;

    if (front == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Mahasiswa " << nama << " dengan NIM " << NIM << " berhasil ditambahkan.\n";
}

void dequeue() {
    if (front == nullptr) {
        cout << "Antrian kosong.\n";
        return;
    }
    Node* temp = front;
    cout << "Mahasiswa " << temp->nama << " dengan NIM " << temp->NIM << " dikeluarkan dari antrian.\n";
    front = front->next;
    delete temp;
}

void viewQueue() {
    if (front == nullptr) {
        cout << "Antrian kosong.\n";
        return;
    }
    Node* temp = front;
    cout << "Data dalam antrian:\n";
    while (temp != nullptr) {
        cout << "Nama: " << temp->nama << ", NIM: " << temp->NIM << "\n";
        temp = temp->next;
    }
}

int main() {
    enqueue("Andi", "12345");
    enqueue("Budi", "67890");
    viewQueue();
    dequeue();
    viewQueue();
    return 0;
}
