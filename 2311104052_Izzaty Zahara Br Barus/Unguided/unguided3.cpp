#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty() || front->nim > nim) {
            newNode->next = front;
            front = newNode;
            if (rear == nullptr) {
                rear = newNode;
            }
        } else {
            Node* current = front;
            while (current->next != nullptr && current->next->nim < nim) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == nullptr) {
                rear = newNode;
            }
        }
        cout << nama << " dengan NIM " << nim << " telah ditambahkan ke antrian." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* temp = front;
        cout << front->nama << " dengan NIM " << front->nim << " telah dikeluarkan dari antrian." << endl;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* temp = front;
        cout << "Data antrian:" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue("izzaty", "2311104052");
    queue.enqueue("zahara", "2311104049");
    queue.enqueue("br", "2311104048");
    queue.enqueue("barus", "2311104047");
    queue.viewQueue();
    queue.dequeue();
    queue.viewQueue();
    return 0;
}