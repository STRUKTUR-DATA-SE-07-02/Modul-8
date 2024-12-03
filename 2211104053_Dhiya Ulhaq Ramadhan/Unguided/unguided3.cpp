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

// Kelas Queue Prioritas untuk mahasiswa
class QueuePrioritasMahasiswa {
private:
    Node* depan;
    Node* belakang;
    int jumlahMahasiswa;

public:
    // Constructor
    QueuePrioritasMahasiswa() {
        depan = nullptr;
        belakang = nullptr;
        jumlahMahasiswa = 0;
    }

    // Mengecek apakah queue kosong
    bool apakahKosong() {
        return depan == nullptr;
    }

    // Menambah mahasiswa dengan prioritas berdasarkan NIM
    void tambahMahasiswa(string nama, string nim) {
        Node* nodeBaru = new Node(nama, nim);
        jumlahMahasiswa++;

        // Jika queue kosong atau NIM baru lebih kecil dari NIM depan
        if (apakahKosong() || nim < depan->nim) {
            nodeBaru->next = depan;
            depan = nodeBaru;
            if (belakang == nullptr) {
                belakang = nodeBaru;
            }
            cout << "\nMahasiswa ditambahkan di awal queue\n";
            return;
        }

        // Mencari posisi yang tepat berdasarkan NIM
        Node* current = depan;
        while (current->next != nullptr && current->next->nim <= nim) {
            current = current->next;
        }

        nodeBaru->next = current->next;
        current->next = nodeBaru;

        if (current == belakang) {
            belakang = nodeBaru;
        }

        cout << "\nMahasiswa ditambahkan ke queue sesuai prioritas NIM\n";
    }

    // Menghapus mahasiswa dari queue
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

        cout << "\nDaftar Mahasiswa Berdasarkan Prioritas NIM";
        cout << "\n(Total: " << jumlahMahasiswa << " mahasiswa):\n";
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
    QueuePrioritasMahasiswa antrian;
    int pilihan;
    string nama, nim;

    do {
        cout << "\n=== PROGRAM ANTRIAN PRIORITAS MAHASISWA ===\n";
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
