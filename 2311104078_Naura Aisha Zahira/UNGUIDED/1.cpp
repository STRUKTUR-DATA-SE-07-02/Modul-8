#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* next;
};

struct Queue {
    Mahasiswa* front;
    Mahasiswa* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string nama, int nim) {
        Mahasiswa* newMahasiswa = new Mahasiswa{nama, nim, nullptr};
        if (isEmpty()) {
            front = rear = newMahasiswa;
        } else {
            rear->next = newMahasiswa;
            rear = newMahasiswa;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Mahasiswa* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Mahasiswa* temp = front;
            cout << "Data antrian mahasiswa:" << endl;
            while (temp != nullptr) {
                cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
                temp = temp->next;
            }
        }
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue antrian;
    int pilihan;
    string nama;
    int nim;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Hapus Mahasiswa\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Kosongkan Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        // Validasi input untuk menghindari karakter tidak valid
        if (cin.fail()) {
            cin.clear(); // Menghapus flag error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Kosongkan buffer
            cout << "Input tidak valid! Masukkan angka yang sesuai." << endl;
            continue;
        }

        switch (pilihan) {
        case 1:
            cin.ignore(); // Membersihkan karakter newline yang tertinggal
            cout << "Masukkan Nama Mahasiswa: ";
            getline(cin, nama); // Membaca nama dengan spasi
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> nim;
            if (cin.fail()) { // Validasi jika NIM bukan angka
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input NIM tidak valid! Masukkan angka." << endl;
                break;
            }
            antrian.enqueue(nama, nim);
            break;
        case 2:
            antrian.dequeue();
            break;
        case 3:
            antrian.viewQueue();
            break;
        case 4:
            antrian.clearQueue();
            cout << "Antrian dikosongkan." << endl;
            break;
        case 0:
            cout << "Keluar..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
