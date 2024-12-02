#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan struktur node untuk data antrian
struct Node {
    string data;     // Data yang disimpan (misalnya nama mahasiswa atau data lainnya)
    Node* next;      // Pointer ke node berikutnya
};

// Mendefinisikan kelas Antrian dengan linked list
class Queue {
private:
    Node* front;     // Menunjuk ke elemen pertama dalam antrian
    Node* back;      // Menunjuk ke elemen terakhir dalam antrian

public:
    // Konstruktor untuk inisialisasi antrian
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    // Mengecek apakah antrian kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Fungsi untuk menambahkan data ke antrian (enqueue)
    void enqueue(string data) {
        Node* newNode = new Node; // Membuat node baru
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;  // Jika antrian kosong, node baru menjadi front dan back
            back = newNode;
        } else {
            back->next = newNode;  // Menambahkan node baru di belakang
            back = newNode;        // Update back ke node baru
        }
    }

    // Fungsi untuk mengeluarkan data dari antrian (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;  // Menggeser front ke node berikutnya
            delete temp;          // Menghapus node lama
            if (front == nullptr) {
                back = nullptr;   // Jika antrian kosong, update back menjadi null
            }
        }
    }

    // Fungsi untuk melihat data dalam antrian
    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* current = front;
            cout << "Data antrian:" << endl;
            int position = 1;
            while (current != nullptr) {
                cout << position << ". " << current->data << endl;
                current = current->next;
                position++;
            }
        }
    }

    // Fungsi untuk menghitung jumlah data dalam antrian
    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi untuk menghapus semua data dalam antrian
    void clearQueue() {
        while (!isEmpty()) {
            dequeue();  // Menghapus data satu per satu
        }
        cout << "Antrian telah dikosongkan." << endl;
    }
};

int main() {
    Queue q;
    int pilihan;
    string data;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah antrian\n";
        cout << "2. Hapus antrian\n";
        cout << "3. Lihat antrian\n";
        cout << "4. Hapus semua antrian\n";
        cout << "5. Hitung jumlah antrian\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Untuk membersihkan newline setelah input pilihan menu

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                getline(cin, data);
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.viewQueue();
                break;
            case 4:
                q.clearQueue();
                break;
            case 5:
                cout << "Jumlah antrian: " << q.countQueue() << endl;
                break;
            case 6:
                cout << "Terima kasih!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    }
}
