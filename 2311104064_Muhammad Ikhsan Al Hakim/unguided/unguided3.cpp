#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* head = nullptr;

bool isEmpty() {
    return head == nullptr;
}

void enqueue(string nama, string nim) {
    if (nim.length() != 10) {
        cout << "NIM harus berjumlah 10 digit.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty() || nim < head->nim) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->nim <= nim) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    cout << "Mahasiswa " << nama << " dengan NIM " << nim << " berhasil ditambahkan ke antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    cout << "Mahasiswa " << temp->nama << " dengan NIM " << temp->nim << " telah keluar dari antrian.\n";
    delete temp;
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    Node* current = head;
    cout << "Isi antrian mahasiswa (prioritas berdasarkan NIM):\n";
    while (current != nullptr) {
        cout << "Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
    }
}

int main() {
    int choice;
    string nama, nim;

    do {
        cout << "\nMenu Queue Mahasiswa:\n";
        cout << "1. Tambah Mahasiswa (Enqueue)\n";
        cout << "2. Hapus Mahasiswa (Dequeue)\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                enqueue(nama, nim);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 4);

    return 0;
}