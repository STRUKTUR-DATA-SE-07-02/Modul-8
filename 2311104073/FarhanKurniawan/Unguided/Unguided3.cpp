#include <iostream>
#include <string>
using namespace std;

// Node untuk menyimpan data mahasiswa
struct Node {
    string namaMahasiswa;
    string nimMahasiswa;
    Node* next;
};

// Pointer untuk mengelola queue
Node* front = nullptr; // Awal antrian

bool isEmpty() { // Mengecek apakah queue kosong
    return (front == nullptr);
}

void enqueueAntrian(string nama, string nim) { 
    // Fungsi menambahkan data dengan prioritas NIM
    Node* newNode = new Node();
    newNode->namaMahasiswa = nama;
    newNode->nimMahasiswa = nim;
    newNode->next = nullptr;

    if (isEmpty() || nim < front->nimMahasiswa) {
        // Jika queue kosong atau prioritas lebih tinggi
        newNode->next = front;
        front = newNode;
    } else {
        // Sisipkan di posisi yang sesuai
        Node* current = front;
        while (current->next != nullptr && current->next->nimMahasiswa < nim) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    cout << "Mahasiswa (" << nama << ", " << nim << ") berhasil ditambahkan ke antrian." << endl;
}

void dequeueAntrian() { // Fungsi menghapus data dari queue
    if (isEmpty()) {
        cout << "Antrian kosong, tidak ada yang dapat dihapus." << endl;
    } else {
        Node* temp = front;
        front = front->next;
        cout << "Mahasiswa (" << temp->namaMahasiswa << ", " << temp->nimMahasiswa << ") telah keluar dari antrian." << endl;
        delete temp;
    }
}

void viewQueue() { // Fungsi untuk melihat data pada queue
    if (isEmpty()) {
        cout << "Antrian kosong." << endl;
    } else {
        cout << "Data antrian berdasarkan prioritas NIM:" << endl;
        Node* temp = front;
        int nomor = 1;
        while (temp != nullptr) {
            cout << nomor++ << ". Nama: " << temp->namaMahasiswa 
                 << ", NIM: " << temp->nimMahasiswa << endl;
            temp = temp->next;
        }
    }
}

void clearQueue() { // Fungsi untuk menghapus semua data pada queue
    while (!isEmpty()) {
        dequeueAntrian();
    }
    cout << "Semua data dalam antrian telah dihapus." << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu Antrian Mahasiswa dengan Prioritas NIM:\n";
        cout << "1. Tambah Antrian (Enqueue)\n";
        cout << "2. Hapus Antrian (Dequeue)\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Kosongkan Antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan input buffer

        switch (pilihan) {
            case 1: {
                string nama, nim;
                cout << "Masukkan nama mahasiswa: ";
                getline(cin, nama);
                cout << "Masukkan NIM mahasiswa: ";
                getline(cin, nim);
                enqueueAntrian(nama, nim);
                break;
            }
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
