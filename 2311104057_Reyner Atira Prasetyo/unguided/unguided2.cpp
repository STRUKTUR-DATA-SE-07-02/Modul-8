#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;  // Nama Mahasiswa
    string nim;   // NIM Mahasiswa
    Node* next;   // Pointer ke node berikutnya

    Node(string name, string nim) {
        this->name = name;
        this->nim = nim;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* front;  // Pointer ke elemen terdepan
    Node* rear;   // Pointer ke elemen terakhir

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Cek apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Menambahkan mahasiswa ke dalam queue (enqueue)
    void enqueue(string name, string nim) {
        Node* newNode = new Node(name, nim);
        if (rear == nullptr) {  // Jika queue kosong
            front = rear = newNode;
        } else {
            rear->next = newNode;  // Tambahkan node di akhir
            rear = newNode;        // Update rear
        }
        cout << "Mahasiswa " << name << " dengan NIM " << nim << " telah ditambahkan ke antrian\n";
    }

    // Menghapus mahasiswa dari queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;      // Simpan elemen yang akan dihapus
        front = front->next;     // Geser front ke elemen berikutnya
        if (front == nullptr)    // Jika queue kosong, reset rear
            rear = nullptr;
        cout << "Mahasiswa " << temp->name << " dengan NIM " << temp->nim << " telah dihapus dari antrian\n";
        delete temp;             // Dealokasi node
    }

    // Menampilkan mahasiswa di depan tanpa menghapusnya
    void peek() {
        if (!isEmpty()) {
            cout << "Nama Mahasiswa: " << front->name << ", NIM: " << front->nim << "\n";
        } else {
            cout << "Queue is empty\n";
        }
    }

    // Menampilkan semua mahasiswa dalam queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Antrian Mahasiswa:\n";
        while (temp != nullptr) {
            cout << "Nama: " << temp->name << ", NIM: " << temp->nim << "\n";
            temp = temp->next;
        }
    }

    // Destructor untuk membersihkan memori
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    int choice;
    string name, nim;

    do {
        cout << "\nMenu Antrian Mahasiswa\n";
        cout << "1. Tambah Mahasiswa (Enqueue)\n";
        cout << "2. Hapus Mahasiswa (Dequeue)\n";
        cout << "3. Lihat Mahasiswa di Depan (Peek)\n";
        cout << "4. Tampilkan Semua Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();                // Reset error flag
            cin.ignore(1000, '\n');     // Hapus input yang salah dari buffer
            cout << "Input tidak valid! Masukkan angka.\n";
            continue;                   // Kembali ke awal loop
        }

        switch (choice) {
        case 1:
            cout << "Masukkan Nama Mahasiswa: ";
            cin.ignore();
            getline(cin, name);
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> nim;
            q.enqueue(name, nim);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
