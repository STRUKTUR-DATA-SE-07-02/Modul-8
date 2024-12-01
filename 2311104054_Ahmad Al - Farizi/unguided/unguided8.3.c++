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

void enqueuePrioritized(string nama, int nim) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = back = newNode;
    } else if (front->nim > nim) {
        newNode->next = front;
        front = newNode;
    } else {
        Mahasiswa* temp = front;
        while (temp->next != nullptr && temp->next->nim < nim) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) {
            back = newNode;
        }
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
    enqueuePrioritized("Andi", 12345);
    enqueuePrioritized("Maya", 67890);
    enqueuePrioritized("Budi", 23456);

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
