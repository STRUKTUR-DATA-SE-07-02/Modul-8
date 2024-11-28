#include <iostream>
#include <string>
using namespace std;

// Node untuk linked list
struct Node {
    string data;
    Node* next;
};

// Struktur Queue
struct Queue {
    Node* front; // Elemen pertama
    Node* back;  // Elemen terakhir

    Queue() {
        front = nullptr;
        back = nullptr;
    }

    // Mengecek apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Menambahkan elemen ke queue
    void enqueue(string data) {
        Node* newNode = new Node{data, nullptr};
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    // Menghapus elemen dari queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) back = nullptr;
    }

    // Menampilkan elemen dalam queue
    void display() {
        if (isEmpty()) {
            cout << "Queue kosong\n";
            return;
        }
        Node* temp = front;
        cout << "Isi queue: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int jumlah;

    cout << "Masukkan jumlah data: ";
    cin >> jumlah;

    for (int i = 1; i <= jumlah; i++) {
        string data;
        cout << "Masukkan data ke-" << i << ": ";
        cin >> data;
        q.enqueue(data);
    }

    cout << "\nData dalam queue setelah input:\n";
    q.display();

    cout << "\nProses dequeue...\n";
    q.dequeue();
    q.display();

    return 0;
}
