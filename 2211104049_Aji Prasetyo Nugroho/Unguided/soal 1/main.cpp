#include<iostream>

using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Struktur Queue
struct Queue {
    Node* front;
    Node* back;
    
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string nama, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
        } else {
            Node* current = front;
            cout << "Data antrian: " << endl;
            while (current != nullptr) {
                cout << current->nama << " - " << current->nim << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue("Andi", "12345");
    queue.enqueue("Maya", "67890");
    queue.enqueue("Budi", "23456");

    queue.viewQueue();
    queue.dequeue();
    queue.viewQueue();

    return 0;
}