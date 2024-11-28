#include <iostream>
#include <string>
using namespace std;

// Node untuk linked list
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Struktur Queue untuk mahasiswa
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
        Node* newNode = new Node{nama, nim, nullptr};
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
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
        if (front == nullptr) back = nullptr;
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
    Queue q;
    int n;
    string nama, nim;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore();  // Menghapus karakter newline setelah input integer

    for (int i = 0; i < n; i++) {
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, nama);
        cout << "Masukkan NIM Mahasiswa: ";
        getline(cin, nim);
        q.enqueue(nama, nim);
    }

    cout << "\nData mahasiswa dalam queue:" << endl;
    q.display();

    cout << "\nMenghapus elemen dari queue..." << endl;
    q.dequeue();
    q.display();

    return 0;
}
