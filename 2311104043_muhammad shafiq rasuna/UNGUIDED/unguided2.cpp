#include <iostream>
using namespace std;

// Node structure for the queue
struct Node {
    string nama; // Nama mahasiswa
    string nim;  // NIM mahasiswa
    Node* next;  // Pointer to the next node
};

// Global pointers
Node* front = nullptr; // Front of the queue
Node* back = nullptr;  // Back of the queue

// Function to check if the queue is empty
bool isEmpty() {
    return front == nullptr;
}

// Function to enqueue (add) a new student to the queue
void enqueueAntrian(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = back = newNode; // Queue is empty
    } else {
        back->next = newNode; // Add to the end of the queue
        back = newNode;
    }
}

// Function to dequeue (remove) a student from the queue
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            back = nullptr; // Reset back if queue becomes empty
        }
    }
}

// Function to count the number of students in the queue
int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to clear the entire queue
void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

// Function to view the queue
void viewQueue() {
    cout << "Data antrian mahasiswa:" << endl;
    if (isEmpty()) {
        cout << "(Antrian kosong)" << endl;
    } else {
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index++ << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
        }
    }
}

int main() {
    // Adding students to the queue
    enqueueAntrian("Andi", "12345678");
    enqueueAntrian("Maya", "87654321");
    enqueueAntrian("Budi", "13579111");

    // Viewing the queue
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    // Removing a student from the queue
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    // Clearing the queue
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
