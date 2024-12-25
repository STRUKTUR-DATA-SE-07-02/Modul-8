#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};
class Queue {
private:
    Node* front;
    Node* back;
    int size;
    const int maksimalQueue = 5;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }
    bool isFull() {
        return size == maksimalQueue;
    }
    bool isEmpty() {
        return size == 0;
    }
    void enqueueAntrian(string data) {
        if (isFull()) {
            cout << "Antrian penuh" << endl;
        } else {
            Node* newNode = new Node(data);
            if (isEmpty()) {
                front = back = newNode;
            } else {
                back->next = newNode;
                back = newNode;
            }
            size++;
        }
    }
    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
            if (front == nullptr) {
                back = nullptr;
            }
        }
    }
    int countQueue() {
        return size;
    }
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
        cout << "Antrian telah dikosongkan" << endl;
    }
    void viewQueue() {
        cout << "Data antrian teller:" << endl;
        if (isEmpty()) {
            cout << "(Kosong)" << endl;
        } else {
            Node* current = front;
            int i = 1;
            while (current != nullptr) {
                cout << i++ << ". " << current->data << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    Queue q;

    q.enqueueAntrian("Andi");
    q.enqueueAntrian("Maya");

    q.viewQueue();
    cout << "Jumlah antrian = " << q.countQueue() << endl;

    q.dequeueAntrian();
    q.viewQueue();
    cout << "Jumlah antrian = " << q.countQueue() << endl;

    q.clearQueue();
    q.viewQueue();
    cout << "Jumlah antrian = " << q.countQueue() << endl;

    return 0;
}
