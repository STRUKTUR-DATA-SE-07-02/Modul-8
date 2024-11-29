#include <iostream>
using namespace std;

class Mahasiswa {
public:
    string nama;
    string nim;

    Mahasiswa(string _nama = "", string _nim = "") {
        nama = _nama;
        nim = _nim;
    }
};

class Node {
public:
    Mahasiswa data;
    Node* next;
    Node(Mahasiswa value) {
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
        return front == nullptr;
    }

    void enqueueAntrian(Mahasiswa data) {
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
    }

    void viewQueue() {
        cout << "Data antrian mahasiswa:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Nama: " << current->data.nama
                 << ", NIM: " << current->data.nim << endl;
            current = current->next;
            index++;
        }

        // Menampilkan slot kosong
        for (int i = index; i <= maksimalQueue; i++) {
            cout << i << ". (kosong)" << endl;
        }
    }

    int getMaksimalQueue() {
        return maksimalQueue;
    }
};

int main() {
    Queue q;

    // Input data mahasiswa
    string nama, nim;
    int maksimalQueue = q.getMaksimalQueue();

    for (int i = 0; i < maksimalQueue; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa ke-" << i+1 << ": ";
        getline(cin, nim);
        q.enqueueAntrian(Mahasiswa(nama, nim));
    }

    cout << endl;
    q.viewQueue();
    return 0;
}