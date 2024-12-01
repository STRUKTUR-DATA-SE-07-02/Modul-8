#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* next;
};

Mahasiswa* front = nullptr;
Mahasiswa* back = nullptr;

bool isFull() {
    return false;
}

bool isEmpty() {
    return front == nullptr;
}

void enqueue(string nama, int nim) {
    Mahasiswa* newNode = new Mahasiswa();
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
        cout << "Antrian kosong" << endl;
    } else {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    Mahasiswa* temp = front;
    int index = 1;
    for (int i = 0; i < 5; i++) {
        if (temp != nullptr) {
            cout << index << ". " << temp->nama << " (" << temp->nim << ")" << endl;
            temp = temp->next;
        } else {
            cout << index << ". (kosong)" << endl;
        }
        index++;
    }
}

int countQueue() {
    int count = 0;
    Mahasiswa* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

int main() {
    enqueue("Andi", 12345);
    enqueue("Maya", 67890);

    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
