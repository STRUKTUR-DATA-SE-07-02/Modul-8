#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* berikut;
};

class Queue {
private:
    Node* depan;
    Node* belakang;

public:
    Queue() {
        depan = nullptr;
        belakang = nullptr;
    }

    bool kosong() {
        return depan == nullptr;
    }

    void enqueue(string nama, string nim) {
        Node* nodeBaru = new Node();
        nodeBaru->nama = nama;
        nodeBaru->nim = nim;
        nodeBaru->berikut = nullptr;

        if (belakang == nullptr) {
            depan = belakang = nodeBaru;
        } else {
            belakang->berikut = nodeBaru;
            belakang = nodeBaru;
        }
    }

    void dequeue() {
        if (kosong()) {
            cout << "Antrian kosong (Underflow)\n";
            return;
        }

        Node* sementara = depan;
        depan = depan->berikut;

        if (depan == nullptr) {
            belakang = nullptr;
        }

        delete sementara;
    }

    void tampilkan() {
        if (kosong()) {
            cout << "Antrian kosong\n";
            return;
        }

        Node* sementara = depan;
        while (sementara != nullptr) {
            cout << "Nama: " << sementara->nama << ", NIM: " << sementara->nim << "\n";
            sementara = sementara->berikut;
        }
    }
};

int main() {
    Queue antrian;
    int jumlah;

    cout << "Masukkan jumlah mahasiswa yang ingin diinput: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        string nama, nim;
        cout << "Masukkan nama mahasiswa: ";
        cin >> ws;
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa: ";
        cin >> nim;
        antrian.enqueue(nama, nim);
    }

    cout << "\nData antrian mahasiswa:\n";
    antrian.tampilkan();

    antrian.dequeue();
    cout << "\nSetelah 1 mahasiswa keluar dari antrian:\n";
    antrian.tampilkan();

    return 0;
}
