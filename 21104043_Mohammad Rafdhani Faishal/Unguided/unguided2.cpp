#include <iostream>
using namespace std;

struct Node {
    string nama;
    int nim;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(string nama, int nim) {
    Node* newNode = new Node{nama, nim, nullptr};
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "mahasiswa " << nama << " dengan NIM " << nim << " ditambahkan ke antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "antrian kosong.\n";
    } else {
        Node* temp = front;
        front = front->next;
        cout << "mahasiswa " << temp->nama << " dengan NIM " << temp->nim << " dikeluarkan dari antrian.\n";
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "antrian kosong.\n";
    } else {
        Node* temp = front;
        while (temp != nullptr) {
            cout << "nama: " << temp->nama << ", NIM: " << temp->nim << "\n";
            temp = temp->next;
        }
    }
}

int main() {
    int choice, nim;
    string nama;

    do {
        cout << "\nMenu:\n1. enqueue\n2. dequeue\n3. list\n4. Keluar\nchoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "insert name: ";
                cin >> nama;
                cout << "insert NIM: ";
                cin >> nim;
                enqueue(nama, nim);
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
                cout << "invalid.\n";
        }
    } while (choice != 4);

    return 0;
}
