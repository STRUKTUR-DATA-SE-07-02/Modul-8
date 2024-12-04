#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string NIM;
    Node* next;
};

Node* front = nullptr;

void enqueue(string nama, string NIM) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->NIM = NIM;
    newNode->next = nullptr;

    // Jika queue kosong atau NIM lebih kecil dari elemen pertama
    if (front == nullptr || NIM < front->NIM) {
        newNode->next = front;
        front = newNode;
    } else {
        // Menyisipkan elemen berdasarkan urutan NIM
        Node* temp = front;
        while (temp->next != nullptr && temp->next->NIM < NIM) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
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
    enqueue("Andi", "54321");
    enqueue("Budi", "12345");
    enqueue("Citra", "34567");
    viewQueue();
    dequeue();
    viewQueue();
    return 0;
}
