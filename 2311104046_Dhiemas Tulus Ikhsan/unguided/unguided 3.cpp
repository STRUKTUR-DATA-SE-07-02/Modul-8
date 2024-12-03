#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Tambahkan header ini untuk sort
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Mahasiswa dengan Nama: " << nama << " dan NIM: " << nim << " berhasil ditambahkan ke antrian." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Tidak ada mahasiswa yang dapat dikeluarkan." << endl;
    } else {
        Node* temp = front;
        cout << "Mahasiswa dengan Nama: " << temp->nama << " dan NIM: " << temp->nim << " telah dikeluarkan dari antrian." << endl;
        front = front->next;
        delete temp;
        if (front == nullptr) rear = nullptr; // Jika queue menjadi kosong
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Queue is empty. Tidak ada mahasiswa dalam antrian." << endl;
    } else {
        cout << "Daftar mahasiswa dalam antrian (prioritas berdasarkan NIM):\n";

        // Salin elemen-elemen queue ke dalam vektor untuk diurutkan
        Node* temp = front;
        vector<pair<string, string>> sortedQueue;
        while (temp != nullptr) {
            sortedQueue.push_back({temp->nim, temp->nama});
            temp = temp->next;
        }

        // Urutkan berdasarkan NIM menggunakan fungsi sort
        sort(sortedQueue.begin(), sortedQueue.end(), [](pair<string, string> a, pair<string, string> b) {
            return a.first < b.first; // Urutkan berdasarkan NIM
        });

        // Tampilkan elemen yang sudah diurutkan
        for (auto& item : sortedQueue) {
            cout << "Nama: " << item.second << ", NIM: " << item.first << endl;
        }
    }
}

int main() {
    int pilihan;
    string nama, nim;

    do {
        cout << "\nMenu Queue:\n";
        cout << "1. Tambah mahasiswa (enqueue)\n";
        cout << "2. Hapus mahasiswa (dequeue)\n";
        cout << "3. Lihat antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); // Menghindari bug input getline setelah cin
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                enqueue(nama, nim);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
