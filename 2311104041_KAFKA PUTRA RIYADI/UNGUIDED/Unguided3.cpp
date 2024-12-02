#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string nim;
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
    void enqueueAntrian(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            Node* current = front;
            Node* previous = nullptr;

            while (current != nullptr && current->nim < nim) {
                previous = current;
                current = current->next;
            }

            if (previous == nullptr) {
                newNode->next = front;
                front = newNode;
            } else {
                previous->next = newNode;
                newNode->next = current;
                if (current == nullptr) {
                    back = newNode; 
                }
            }
        }
        size++;
        cout << "Mahasiswa " << nama << " (NIM: " << nim << ") ditambahkan ke antrian." << endl;
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

        cout << "Mahasiswa " << temp->nama << " (NIM: " << temp->nim << ") dikeluarkan dari antrian." << endl;
        delete temp;
        size--;
    }

    int countQueue() {
        return size;
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Data antrian mahasiswa:" << endl;
        Node* current = front;
        int position = 1;

        while (current != nullptr) {
            cout << position++ << ". " << current->nama << " (NIM: " << current->nim << ")" << endl;
            current = current->next;
        }
    }
};

int main() {
    Queue queue;
    string nama, nim;

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa ke-" << i+1 << ": ";
        getline(cin, nim);
        queue.enqueueAntrian(nama, nim);
    }

    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}
