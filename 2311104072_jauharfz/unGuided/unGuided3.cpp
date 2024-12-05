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

class PrioritasAntrianMahasiswa {
private:
    Node* front;
    Node* rear;
    int jumlahMahasiswa;

public:
    PrioritasAntrianMahasiswa() {
        front = NULL;
        rear = NULL;
        jumlahMahasiswa = 0;
    }

    bool isEmpty() {
        return front == NULL;
    }

    // Menambah mahasiswa dengan prioritas berdasarkan NIM
    void tambahMahasiswaPrioritas() {
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

        // Jika antrian kosong
        if (isEmpty()) {
            front = rear = newNode;
        }
        // Jika NIM baru lebih kecil dari NIM di depan (prioritas tertinggi)
        else if (mhs.nim < front->data.nim) {
            newNode->next = front;
            front = newNode;
        }
        // Mencari posisi yang tepat berdasarkan NIM
        else {
            Node* current = front;
            Node* previous = NULL;

            while (current != NULL && mhs.nim >= current->data.nim) {
                previous = current;
                current = current->next;
            }

            if (current == NULL) { // Tambah di akhir
                rear->next = newNode;
                rear = newNode;
            } else { // Tambah di tengah
                previous->next = newNode;
                newNode->next = current;
            }
        }

        jumlahMahasiswa++;
        cout << "\nMahasiswa berhasil ditambahkan ke antrian!" << endl;
    }

    // Menghapus mahasiswa dari depan antrian
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

    // Menampilkan daftar antrian mahasiswa (sudah terurut berdasarkan NIM)
    void tampilkanAntrian() {
        if (isEmpty()) {
            cout << "\nAntrian kosong!" << endl;
            return;
        }

        cout << "\nDaftar Antrian Mahasiswa (Diurutkan berdasarkan NIM)" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "No.\tNIM\t\tNama" << endl;
        cout << "------------------------------------------------" << endl;

        Node* current = front;
        int nomor = 1;
        while (current != NULL) {
            cout << nomor << "\t"
                 << current->data.nim << "\t"
                 << current->data.nama << endl;
            current = current->next;
            nomor++;
        }
        cout << "------------------------------------------------" << endl;
        cout << "Total mahasiswa dalam antrian: " << jumlahMahasiswa << endl;
    }

    // Melihat data mahasiswa prioritas tertinggi (NIM terkecil)
    void lihatPrioritas() {
        if (isEmpty()) {
            cout << "\nAntrian kosong!" << endl;
            return;
        }

        cout << "\nMahasiswa dengan prioritas tertinggi:" << endl;
        cout << "Nama: " << front->data.nama << endl;
        cout << "NIM : " << front->data.nim << endl;
    }
};

int main() {
    PrioritasAntrianMahasiswa antrian;
    int pilihan;

    do {
        cout << "\n=== PROGRAM ANTRIAN PRIORITAS MAHASISWA ===" << endl;
        cout << "1. Tambah Mahasiswa ke Antrian" << endl;
        cout << "2. Panggil Mahasiswa (Hapus dari Antrian)" << endl;
        cout << "3. Tampilkan Semua Antrian" << endl;
        cout << "4. Lihat Mahasiswa Prioritas Tertinggi" << endl;
        cout << "0. Keluar Program" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                antrian.tambahMahasiswaPrioritas();
            break;
            case 2:
                antrian.panggilMahasiswa();
            break;
            case 3:
                antrian.tampilkanAntrian();
            break;
            case 4:
                antrian.lihatPrioritas();
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
