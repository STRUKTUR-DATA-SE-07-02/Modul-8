#include<iostream>
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
    string nama, nim;

    cout << "Masukkan data mahasiswa untuk antrian:" << endl;

    int jumlahMahasiswa;
    cout << "Berapa jumlah mahasiswa yang ingin dimasukkan ke dalam antrian? ";
    cin >> jumlahMahasiswa;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nMasukkan nama mahasiswa: ";
        cin.ignore(); // Untuk membersihkan buffer input
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa: ";
        cin >> nim;
        queue.enqueue(nama, nim);
    }

    queue.viewQueue();

    return 0;
}