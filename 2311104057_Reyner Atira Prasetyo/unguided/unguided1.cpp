#include <iostream>
using namespace std;

class Node {
public:
    int data;      // Data yang disimpan
    Node* next;    // Pointer ke node berikutnya

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;   // Pointer ke elemen terdepan
    Node* rear;    // Pointer ke elemen terakhir

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Cek apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Menambahkan elemen ke dalam queue (enqueue)
    void enqueue(int x) {
        Node* newNode = new Node(x); // Alokasi node baru
        if (rear == nullptr) { // Jika queue kosong
            front = rear = newNode;
        } else {
            rear->next = newNode; // Tambahkan node di akhir
            rear = newNode;       // Update rear
        }
    }

    // Menghapus elemen dari queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front; // Simpan elemen yang akan dihapus
        front = front->next; // Geser front ke elemen berikutnya
        if (front == nullptr) rear = nullptr; // Jika queue kosong, reset rear
        delete temp; // Dealokasi node
    }

    // Mendapatkan elemen di depan tanpa menghapusnya
    int peek() {
        if (!isEmpty()) {
            return front->data;
        }
        cout << "Queue is empty\n";
        return -1; 
    }

    // Menampilkan semua elemen dalam queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Destructor untuk membersihkan memori
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue elements: ";
    q.display();

    cout << "Front element: " << q.peek() << "\n";

    q.dequeue();

    cout << "After dequeuing, queue elements: ";
    q.display();

    return 0;
}
