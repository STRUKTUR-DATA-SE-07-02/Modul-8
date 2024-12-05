#include <iostream>
#include <string>
using namespace std;

// Struktur untuk data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
};

// Struktur node untuk linked list
struct Node {
    Mahasiswa data;
    Node* next;
};

class AntrianMahasiswa {
private:
    Node* front;
    Node* rear;
    int jumlahMahasiswa;

public:
    // Constructor
    AntrianMahasiswa() {
        front = NULL;
        rear = NULL;
        jumlahMahasiswa = 0;
    }

    // Mengecek apakah antrian kosong
    bool isEmpty() {
        return front == NULL;
    }

    // Menambah mahasiswa ke antrian
    void tambahMahasiswa() {
        Mahasiswa mhs;
        cout << "\nMasukkan Data Mahasiswa" << endl;
        cout << "----------------------" << endl;
        cout << "Nama Mahasiswa : ";
        getline(cin, mhs.nama);
        cout << "NIM Mahasiswa  : ";
        getline(cin, mhs.nim);

        Node* newNode = new Node();
        newNode->data = mhs;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        jumlahMahasiswa++;
        cout << "\nMahasiswa berhasil ditambahkan ke antrian!" << endl;
    }

    // Menghapus mahasiswa dari antrian
    void panggilMahasiswa() {
        if (isEmpty()) {
            cout << "\nAntrian kosong!" << endl;
            return;
        }

        Node* temp = front;
        cout << "\nMemanggil mahasiswa dengan data:" << endl;
        cout << "Nama: " << temp->data.nama << endl;
        cout << "NIM : " << temp->data.nim << endl;

        front = front->next;
        delete temp;
        jumlahMahasiswa--;

        if (front == NULL) {
            rear = NULL;
        }
    }

    // Menampilkan daftar antrian mahasiswa
    void tampilkanAntrian() {
        if (isEmpty()) {
            cout << "\nAntrian kosong!" << endl;
            return;
        }

        cout << "\nDaftar Antrian Mahasiswa" << endl;
        cout << "------------------------" << endl;
        cout << "No.\tNIM\t\tNama" << endl;
        cout << "------------------------" << endl;

        Node* current = front;
        int nomor = 1;
        while (current != NULL) {
            cout << nomor << "\t"
                 << current->data.nim << "\t"
                 << current->data.nama << endl;
            current = current->next;
            nomor++;
        }
        cout << "------------------------" << endl;
        cout << "Total mahasiswa dalam antrian: " << jumlahMahasiswa << endl;
    }

    // Melihat data mahasiswa di depan antrian
    void lihatDepan() {
        if (isEmpty()) {
            cout << "\nAntrian kosong!" << endl;
            return;
        }

        cout << "\nMahasiswa di depan antrian:" << endl;
        cout << "Nama: " << front->data.nama << endl;
        cout << "NIM : " << front->data.nim << endl;
    }
};

int main() {
    AntrianMahasiswa antrian;
    int pilihan;

    do {
        cout << "\n=== PROGRAM ANTRIAN MAHASISWA ===" << endl;
        cout << "1. Tambah Mahasiswa ke Antrian" << endl;
        cout << "2. Panggil Mahasiswa (Hapus dari Antrian)" << endl;
        cout << "3. Tampilkan Semua Antrian" << endl;
        cout << "4. Lihat Mahasiswa di Depan Antrian" << endl;
        cout << "0. Keluar Program" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                antrian.tambahMahasiswa();
                break;
            case 2:
                antrian.panggilMahasiswa();
                break;
            case 3:
                antrian.tampilkanAntrian();
                break;
            case 4:
                antrian.lihatDepan();
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
