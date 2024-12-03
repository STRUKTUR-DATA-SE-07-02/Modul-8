#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = nullptr; 
Node* back = nullptr;  

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string data) {
    Node* newNode = new Node{data, nullptr};
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
    cout << "Data antrian:" << endl;
    Node* temp = front;
    int count = 1;
    while (temp != nullptr) {
        cout << count++ << ". " << temp->data << endl;
        temp = temp->next;
    }
    if (isEmpty()) {
        cout << "(Antrian kosong)" << endl;
    }
}

int main() {
    int pilihan;
    string nama;

    do {
        cout << "Menu:\n1. Tambah Antrian\n2. Hapus Antrian\n3. Lihat Antrian\n4. Keluar\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                enqueueAntrian(nama);
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
