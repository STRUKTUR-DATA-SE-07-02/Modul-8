#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Kelas Queue
class Queue {
private:
    Node *front, *rear;
    int count;

public:
    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    // Cek apakah queue kosong
    bool isEmpty() {
        return front == NULL;
    }

    // Menambah data ke queue (enqueue)
    void enqueue(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        cout << "Data berhasil ditambahkan ke antrian!" << endl;
    }

    // Menghapus data dari queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
        count--;

        if (front == NULL) {
            rear = NULL;
        }
        cout << "Data terdepan berhasil dihapus dari antrian!" << endl;
    }

    // Menampilkan semua data dalam queue
    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
            return;
        }

        cout << "\nData dalam antrian:" << endl;
        cout << "--------------------------------" << endl;
        cout << "No.\tNIM\t\tNama" << endl;
        cout << "--------------------------------" << endl;

        Node* current = front;
        int i = 1;
        while (current != NULL) {
            cout << i << "\t" << current->nim << "\t" << current->nama << endl;
            current = current->next;
            i++;
        }
        cout << "--------------------------------" << endl;
    }

    // Menghitung jumlah data dalam queue
    int size() {
        return count;
    }

    // Membersihkan queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Antrian telah dibersihkan!" << endl;
    }
};

int main() {
    Queue q;
    int pilihan;
    string nama, nim;

    do {
        cout << "\n=== MENU PROGRAM QUEUE MAHASISWA ===" << endl;
        cout << "1. Tambah Data (Enqueue)" << endl;
        cout << "2. Hapus Data Terdepan (Dequeue)" << endl;
        cout << "3. Tampilkan Data" << endl;
        cout << "4. Jumlah Data" << endl;
        cout << "5. Hapus Semua Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan NIM: ";
                getline(cin, nim);
                q.enqueue(nama, nim);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Jumlah data dalam antrian: " << q.size() << endl;
                break;
            case 5:
                q.clear();
                break;
            case 0:
                cout << "Program selesai!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
