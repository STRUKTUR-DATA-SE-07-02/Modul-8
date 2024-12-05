#include <iostream>
#include <limits>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Pointer front dan rear
Node* front = nullptr;
Node* rear = nullptr;

// Fungsi mengecek apakah Queue kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi menambahkan elemen dengan prioritas berdasarkan NIM
void enqueueWithPriority(const string& nama, const string& nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty() || nim < front->nim) {
        newNode->next = front;
        front = newNode;
        if (rear == nullptr) {
            rear = newNode;
        }
    } else {
        Node* temp = front;
        while (temp->next != nullptr && temp->next->nim < nim) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) {
            rear = newNode;
        }
    }
    cout << "Data berhasil ditambahkan ke antrian.\n";
}

// Fungsi menghapus elemen dari Queue
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong! Tidak ada yang dihapus.\n";
    } else {
        Node* temp = front;
        cout << "Menghapus: Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

// Fungsi menampilkan elemen di Queue
void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
    } else {
        Node* temp = front;
        cout << "Data antrian (berdasarkan prioritas):\n";
        cout << "----------------------------------\n";
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
        cout << "----------------------------------\n";
    }
}

// Fungsi untuk membersihkan seluruh queue
void clearQueue() {
    while (!isEmpty()) {
        dequeue();
    }
    cout << "Semua data dalam antrian telah dihapus.\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n=== Menu Queue (Prioritas) ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Hapus Antrian\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih (1-4): ";
        cin >> pilihan;

        // Validasi input agar tidak terjadi infinite loop
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid! Masukkan angka antara 1 hingga 4.\n";
            continue;
        }

        switch (pilihan) {
            case 1: {
                string nama, nim;
                cout << "Masukkan Nama: ";
                cin.ignore(); // Membersihkan buffer sebelum menerima input string
                getline(cin, nama);
                cout << "Masukkan NIM: ";
                getline(cin, nim);
                enqueueWithPriority(nama, nim);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Keluar dari program. Terima kasih!\n";
                clearQueue();
                break;
            default:
                cout << "Pilihan tidak valid! Masukkan angka antara 1 hingga 4.\n";
                break;
        }
    } while (pilihan != 4);

    return 0;
}
