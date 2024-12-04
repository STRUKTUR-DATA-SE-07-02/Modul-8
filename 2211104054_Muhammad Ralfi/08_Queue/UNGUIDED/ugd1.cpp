#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " berhasil ditambahkan ke antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }
    Node* temp = front;
    front = front->next;
    cout << temp->data << " dihapus dari antrian.\n";
    delete temp;
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }
    Node* temp = front;
    cout << "Data dalam antrian:\n";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    viewQueue();
    dequeue();
    viewQueue();
    return 0;
}
