#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* front = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty() || newNode->nim < front->nim) {
        newNode->next = front;
        front = newNode;
    } else {
        Node* temp = front;
        while (temp->next != nullptr && temp->next->nim < newNode->nim) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong!" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
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
    enqueue("Andi", "24002");
    enqueue("Maya", "24001");
    enqueue("Ryan", "24003");
    viewQueue();
    dequeue();
    viewQueue();
    return 0;
}