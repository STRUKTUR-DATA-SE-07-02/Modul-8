#include <iostream>
#include <string>
using namespace std;

// Node untuk linked list
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Struktur Queue dengan prioritas berdasarkan NIM
struct PriorityQueue {
    Node* front;

    PriorityQueue() {
        front = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string nama, string nim) {
        Node* newNode = new Node{nama, nim, nullptr};

        if (isEmpty() || nim < front->nim) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->nim < nim) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
            return;
        }
        Node* temp = front;
        cout << "Data mahasiswa dalam queue:" << endl;
        while (temp) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PriorityQueue pq;
    int n;
    string nama, nim;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, nama);
        cout << "Masukkan NIM Mahasiswa: ";
        getline(cin, nim);
        pq.enqueue(nama, nim);
    }

    cout << "\nData mahasiswa setelah diurutkan berdasarkan NIM:" << endl;
    pq.display();

    return 0;
}
