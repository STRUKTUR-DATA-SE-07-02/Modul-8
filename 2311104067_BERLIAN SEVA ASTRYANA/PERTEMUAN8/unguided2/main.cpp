#include <iostream>
using namespace std;

// Node untuk menyimpan data queue
class Node {
public:
    string nama;
    string nim;
    Node* next;

    Node(string nama, string nim) {
        this->nama = nama;
        this->nim = nim;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string nama, string nim) {
        Node* newNode = new Node(nama, nim);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* current = front;
        while (current) {
            cout << "Nama: " << current->nama << ", NIM: " << current->nim << "\n";
            current = current->next;
        }
    }
};

int main() {
    Queue q;
    int n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nama, nim;
        cout << "Nama Mahasiswa: ";
        cin >> nama;
        cout << "NIM Mahasiswa: ";
        cin >> nim;
        q.enqueue(nama, nim);
    }

    cout << "\nAntrian Mahasiswa:\n";
    q.display();

    q.dequeue();
    cout << "\nSetelah dequeue:\n";
    q.display();

    return 0;
}
