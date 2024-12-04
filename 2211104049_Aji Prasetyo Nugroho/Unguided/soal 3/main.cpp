#include<iostream>
#include<string>

using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

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

        // Jika queue kosong
        if (isEmpty()) {
            front = back = newNode;
        } else {
            // Jika NIM mahasiswa baru lebih kecil dari NIM yang ada di front
            if (newNode->nim < front->nim) {
                newNode->next = front;
                front = newNode;
            } else {
                Node* current = front;
                while (current->next != nullptr && current->next->nim < newNode->nim) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                if (newNode->next == nullptr) {
                    back = newNode;
                }
            }
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
    string nama, nim;

    cout << "Masukkan data mahasiswa untuk antrian:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Masukkan nama mahasiswa: ";
        cin >> nama;
        cout << "Masukkan NIM mahasiswa: ";
        cin >> nim;
        queue.enqueue(nama, nim);
    }

    queue.viewQueue();
    queue.dequeue();
    queue.viewQueue();

    return 0;
}