#include <iostream>
#include <string>
using namespace std;

// Node untuk linked list
struct Node {
    string nama;
    int nim;
    Node* next;
};

// Inisialisasi queue
Node* front = nullptr;
Node* rear = nullptr;

// Fungsi mengecek apakah queue kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi enqueue
void enqueue(string nama, int nim) {
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

// Fungsi dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong!" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

// Fungsi melihat data di queue
void viewQueue() {
    if (isEmpty()) {
        cout << "Queue kosong!" << endl;
    } else {
        Node* temp = front;
        cout << "Data antrian mahasiswa:" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }
}

int main() {
    enqueue("Andi", 12345);
    enqueue("Budi", 54321);
    enqueue("Citra", 23456);

    cout << "Isi queue:" << endl;
    viewQueue();

    cout << "\nDequeuing satu elemen..." << endl;
    dequeue();
    viewQueue();

    return 0;
}