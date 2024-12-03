#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk menyimpan data mahasiswa
class Node {
public:
    string nama;    // Menyimpan nama mahasiswa
    string nim;     // Menyimpan NIM mahasiswa
    Node* next;     // Pointer ke node berikutnya

    // Constructor untuk node baru
    Node(string namaMhs, string nimMhs) {
        nama = namaMhs;
        nim = nimMhs;
        next = nullptr;
    }
};

// Kelas Queue untuk data mahasiswa
class QueueMahasiswa {
private:
    Node* depan;
    Node* belakang;
    int jumlahMahasiswa;

public:
    // Constructor
    QueueMahasiswa() {
        depan = nullptr;
        belakang = nullptr;
        jumlahMahasiswa = 0;
    }

    // Mengecek apakah queue kosong
    bool apakahKosong() {
        return depan == nullptr;
    }

    // Menambah data mahasiswa ke queue
    void tambahMahasiswa(string nama, string nim) {
        Node* nodeBaru = new Node(nama, nim);
        jumlahMahasiswa++;

        if (apakahKosong()) {
            depan = belakang = nodeBaru;
            cout << "\nMahasiswa pertama berhasil ditambahkan\n";
            return;
        }

        belakang->next = nodeBaru;
        belakang = nodeBaru;
        cout << "\nMahasiswa berhasil ditambahkan ke queue\n";
    }

    // Menghapus data mahasiswa dari queue
    void hapusMahasiswa() {
        if (apakahKosong()) {
            cout << "\nQueue masih kosong!\n";
            return;
        }

        Node* temp = depan;
        depan = depan->next;
        cout << "\nMahasiswa " << temp->nama << " (NIM: " << temp->nim << ") berhasil dihapus\n";
        delete temp;
        jumlahMahasiswa--;

        if (depan == nullptr) {
            belakang = nullptr;
        }
    }

    // Menampilkan data semua mahasiswa
    void tampilkanMahasiswa() {
        if (apakahKosong()) {
            cout << "\nQueue masih kosong!\n";
            return;
        }

        cout << "\nDaftar Mahasiswa (Total: " << jumlahMahasiswa << " mahasiswa):\n";
        cout << "==========================================\n";
        Node* current = depan;
        int nomor = 1;
        while (current != nullptr) {
            cout << nomor << ". Nama: " << current->nama << "\n   NIM : " << current->nim << endl;
            current = current->next;
            nomor++;
        }
        cout << "==========================================\n";
    }
};

int main() {
    QueueMahasiswa antrian;
    int pilihan;
    string nama, nim;

    do {
        cout << "\n=== PROGRAM ANTRIAN MAHASISWA ===\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Hapus Mahasiswa\n";
        cout << "3. Tampilkan Daftar Mahasiswa\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda (1-4): ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan Data Mahasiswa\n";
                cout << "Nama: ";
                getline(cin, nama);
                cout << "NIM : ";
                getline(cin, nim);
                antrian.tambahMahasiswa(nama, nim);
                break;
            case 2:
                antrian.hapusMahasiswa();
                break;
            case 3:
                antrian.tampilkanMahasiswa();
                break;
            case 4:
                cout << "\nProgram selesai!\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
