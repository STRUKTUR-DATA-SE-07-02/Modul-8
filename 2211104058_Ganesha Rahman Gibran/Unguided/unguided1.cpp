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
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
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
        cout << "Antrian kosong!" << endl;
    } else {
        Node* temp = front;
        cout << "Data antrian:" << endl;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

int main() {
    enqueue("Andi");
    enqueue("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
