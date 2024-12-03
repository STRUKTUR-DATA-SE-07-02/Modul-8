#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan struktur node untuk data antrian mahasiswa
struct Mahasiswa {
    string nama;     // Nama mahasiswa
    string nim;      // NIM mahasiswa
    Mahasiswa* next; // Pointer ke node berikutnya
};

// Mendefinisikan kelas Antrian dengan linked list
class Queue {
private:
    Mahasiswa* front;  // Menunjuk ke elemen pertama dalam antrian
    Mahasiswa* back;   // Menunjuk ke elemen terakhir dalam antrian

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

    // Fungsi untuk menambahkan data ke antrian (enqueue) dengan prioritas berdasarkan NIM
    void enqueue(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa; // Membuat node baru
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty()) {
            // Jika antrian kosong, node baru menjadi front dan back
            front = newNode;
            back = newNode;
        } else {
            // Jika antrian tidak kosong, kita cari posisi yang sesuai berdasarkan NIM
            if (stoi(nim) < stoi(front->nim)) {
                // Jika NIM lebih kecil dari NIM di depan, insert di depan
                newNode->next = front;
                front = newNode;
            } else {
                // Mencari posisi yang sesuai di antrian
                Mahasiswa* current = front;
                while (current->next != nullptr && stoi(nim) > stoi(current->next->nim)) {
                    current = current->next;
                }
                // Menyisipkan node baru setelah node current
                newNode->next = current->next;
                current->next = newNode;

                // Jika node yang ditambahkan berada di belakang, update back
                if (newNode->next == nullptr) {
                    back = newNode;
                }
            }
        }
    }

    // Fungsi untuk mengeluarkan data dari antrian (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Mahasiswa* temp = front;
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
            Mahasiswa* current = front;
            cout << "Data antrian mahasiswa:" << endl;
            int position = 1;
            while (current != nullptr) {
                cout << position << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
                current = current->next;
                position++;
            }
        }
    }

    // Fungsi untuk menghitung jumlah data dalam antrian
    int countQueue() {
        int count = 0;
        Mahasiswa* current = front;
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
    string nama, nim;

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
                cout << "Masukkan Nama Mahasiswa: ";
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                getline(cin, nim);
                q.enqueue(nama, nim);
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