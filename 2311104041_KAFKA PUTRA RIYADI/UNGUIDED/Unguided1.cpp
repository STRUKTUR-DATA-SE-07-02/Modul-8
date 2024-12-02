#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* back;
    int size;

    Queue() { 
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueueAntrian(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        size++;
        cout << data << " ditambahkan ke antrian." << endl;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr) { 
            back = nullptr;
        }

        cout << temp->data << " dikeluarkan dari antrian." << endl;
        delete temp;
        size--;
    }

    int countQueue() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
        cout << "Antrian telah dikosongkan." << endl;
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int position = 1;

        while (current != nullptr) {
            cout << position++ << ". " << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");

    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}
