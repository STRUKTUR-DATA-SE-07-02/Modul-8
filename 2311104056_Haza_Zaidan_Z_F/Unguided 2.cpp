#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    long long nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* back;
    int size;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    bool isFull() {
        return false; // Linked list tidak memiliki batas ukuran tetap
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(string nama, long long nim) {
        Node* newNode = new Node();
        newNode->data.nama = nama;
        newNode->data.nim = nim;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    int count() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void view() {
        cout << "\nData mahasiswa dalam queue:\n" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl;
            current = current->next;
            index++;
        }
    }
};

int main() {
    Queue queue;

    // Input data mahasiswa oleh user
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;
    cin.ignore(); // Membersihkan buffer newline

    for (int i = 0; i < jumlahMahasiswa; i++) {
        string nama;
        long long nim;
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, nama);
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> nim;
        cin.ignore(); // Membersihkan buffer newline

        queue.enqueue(nama, nim);
    }

    queue.view();

    cout << "\nJumlah antrian = " << queue.count() << endl;
    return 0;
}