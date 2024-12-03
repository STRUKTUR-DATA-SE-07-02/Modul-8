#include <iostream>
#include <string>
using namespace std;

class QueueLinkedList {
private:
    struct Node {
        string data;
        Node* next;
        Node(string val) : data(val), next(nullptr) {}
    };
    Node *front, *rear;
    int size;

public:
    QueueLinkedList() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue(string data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (front == nullptr) rear = nullptr;
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
            return;
        }
        Node* current = front;
        int i = 1;
        while (current) {
            cout << i++ << ". " << current->data << endl;
            current = current->next;
        }
    }

    bool isEmpty() { return front == nullptr; }
    int getSize() { return size; }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    QueueLinkedList queue;
    queue.enqueue("Andi");
    queue.enqueue("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.getSize() << endl;
    queue.dequeue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.getSize() << endl;
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.getSize() << endl;
    return 0;
}