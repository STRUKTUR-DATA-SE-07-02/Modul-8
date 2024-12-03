#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(string nama, string nim) {
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

void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong!" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Queue kosong!" << endl;
    } else {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->nama << " (" << temp->nim << ")" << endl;
            temp = temp->next;
        }
    }
}

int main() {
    enqueue("Andi", "24001");
    enqueue("Maya", "24002");
    viewQueue();
    dequeue();
    viewQueue();
    return 0;
}