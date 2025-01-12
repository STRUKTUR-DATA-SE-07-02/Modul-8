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

void enqueue(int data) {
    Node* newNode = new Node{data, nullptr};
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "data " << data << " enqueued.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "null.\n";
    } else {
        Node* temp = front;
        front = front->next;
        cout << "data " << temp->data << " dequeued.\n";
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "null.\n";
    } else {
        Node* temp = front;
        cout << "list : ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int choice, data;

    do {
        cout << "\nmenu:\n1. Enqueue\n2. Dequeue\n3. list\n4. Keluar\nchoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "insert number: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "exit.\n";
                break;
            default:
                cout << "invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}