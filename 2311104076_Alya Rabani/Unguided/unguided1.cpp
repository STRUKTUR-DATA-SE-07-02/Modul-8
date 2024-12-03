#include <iostream>
using namespace std;

// Struktur untuk node dalam linked list
struct Node {
    string data;
    Node* next;
};

// Kelas Queue yang menggunakan linked list
class Queue {
private:
    Node* front; // Penanda depan antrian
    Node* back;  // Penanda belakang antrian
    int count;   // Jumlah elemen dalam antrian

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        count = 0;
    }

    ~Queue() {
        clearQueue();
    }

    bool isFull() {
        // Untuk linked list, antrian tidak pernah penuh (kecuali memori habis)
        return false;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueAntrian(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode; // Jika antrian kosong, node baru menjadi front
        } else {
            back->next = newNode; // Hubungkan node baru ke belakang antrian
        }
        back = newNode; // Update back ke node baru
        count++; // Increment jumlah antrian
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* temp = front; // Simpan node depan untuk dihapus
        front = front->next; // Update front ke node berikutnya

        if (front == nullptr) {
            back = nullptr; // Jika antrian menjadi kosong, update back juga
        }

        delete temp; // Hapus node yang sudah tidak diperlukan
        count--; // Decrement jumlah antrian
    }

    int countQueue() {
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian(); // Hapus semua elemen
        }
    }

    void viewQueue() {
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int index = 1;

        while (current != nullptr) {
            cout << index++ << ". " << current->data << endl;
            current = current->next;
        }

        // Jika antrian kosong
        if (isEmpty()) {
            cout << "(kosong)" << endl;
        }
    }
};

int main() {
    Queue queue; // Membuat objek antrian

    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}