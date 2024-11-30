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

    // Fungsi untuk menyisipkan node berdasarkan prioritas NIM
    void insertSorted(Mahasiswa data) {
        Node* newNode = new Node(data);

        // Jika queue kosong atau NIM baru lebih kecil dari front
        if (isEmpty() || newNode->data.nim < front->data.nim) {
            newNode->next = front;
            front = newNode;
            if (back == nullptr) back = newNode;
            return;
        }

        // Cari posisi yang tepat untuk menyisipkan
        Node* current = front;
        while (current->next != nullptr &&
               current->next->data.nim <= newNode->data.nim) {
            current = current->next;
        }

        // Sisipkan node baru
        newNode->next = current->next;
        current->next = newNode;

        // Update back jika node baru adalah elemen terakhir
        if (newNode->next == nullptr) {
            back = newNode;
        }
    }

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
            return;
        }

        // Gunakan fungsi penyisipan terurut
        insertSorted(data);
        size++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
        size--;

        if (front == nullptr) {
            back = nullptr;
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
        cout << "Data antrian mahasiswa (diurutkan berdasarkan NIM):" << endl;
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
    int maksimalQueue = q.getMaksimalQueue(); // Mendapatkan nilai maksimalQueue

    for (int i = 0; i < maksimalQueue; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa ke-" << i+1 << ": ";
        getline(cin, nim);

        q.enqueueAntrian(Mahasiswa(nama, nim));
    }

    cout << endl;
    q.viewQueue();
    cout << "Jumlah antrian = " << q.countQueue() << endl;

    q.dequeueAntrian();
    cout << endl;
    q.viewQueue();
    cout << "Jumlah antrian setelah dihapus 1= " << q.countQueue() << endl;

    q.clearQueue();
    cout << endl;
    q.viewQueue();

    cout << "Jumlah antrian setelah di-clear= " << q.countQueue() << endl;
    
    return 0;
}
