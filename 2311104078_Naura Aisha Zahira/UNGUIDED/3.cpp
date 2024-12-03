#include <iostream>
#include <string>
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

    void enqueuePriority(string nama, int nim) {
        Mahasiswa* newMahasiswa = new Mahasiswa{nama, nim, nullptr};
        if (isEmpty() || front->nim > nim) {
            newMahasiswa->next = front;
            front = newMahasiswa;
            if (rear == nullptr) {
                rear = newMahasiswa;
            }
        } else {
            Mahasiswa* temp = front;
            while (temp->next != nullptr && temp->next->nim < nim) {
                temp = temp->next;
            }
            newMahasiswa->next = temp->next;
            temp->next = newMahasiswa;
            if (newMahasiswa->next == nullptr) {
                rear = newMahasiswa;
            }
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
        cout << "1. Tambah Mahasiswa Berdasarkan Prioritas\n";
        cout << "2. Hapus Mahasiswa\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Kosongkan Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan Nama Mahasiswa: ";
            cin >> nama;
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> nim;
            antrian.enqueuePriority(nama, nim);
            break;
        case 2:
            antrian.dequeue();
            break;
        case 3:
            antrian.viewQueue();
            break;
        case 4:
            antrian.clearQueue();
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
