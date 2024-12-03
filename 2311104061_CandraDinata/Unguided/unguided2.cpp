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

// Fungsi enqueue
void enqueue(string nama, int nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (front == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Fungsi melihat data di queue
void viewQueue() {
    Node* temp = front;
    while (temp != nullptr) {
        cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
        temp = temp->next;
    }
}

int main() {
    string nama;
    int nim;

    cout << "Masukkan data mahasiswa ke dalam queue (Masukkan 0 untuk berhenti):" << endl;
    while (true) {
        cout << "Nama: ";
        cin.ignore();
        getline(cin, nama);
        if (nama == "0") break;

        cout << "NIM: ";
        cin >> nim;
        if (nim == 0) break;

        enqueue(nama, nim);
    }

    cout << "\nData dalam queue:" << endl;
    viewQueue();

    return 0;
}
