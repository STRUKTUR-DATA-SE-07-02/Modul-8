#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Data \"" << data << "\" berhasil ditambahkan ke antrian." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        Node* temp = front;
        cout << "Data \"" << temp->data << "\" telah keluar dari antrian." << endl;
        front = front->next;
        delete temp;
        if (front == nullptr) rear = nullptr;
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Isi antrian: [Kosong]" << endl;
    } else {
        cout << "Isi antrian:\n";
        Node* temp = front;
        while (temp != nullptr) {
            cout << "- " << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main() {
    enqueue("Andi");
    enqueue("Maya");
    viewQueue();
    dequeue();
    viewQueue();
    return 0;
}
