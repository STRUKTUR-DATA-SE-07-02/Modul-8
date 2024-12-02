#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* front = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty() || front->nim > nim) {
        newNode->next = front;
        front = newNode;
    } else {
        Node* current = front;
        while (current->next != nullptr && current->next->nim <= nim) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    cout << "Data antrian mahasiswa berdasarkan prioritas (NIM terkecil di depan):" << endl;
    if (isEmpty()) {
        cout << "(Antrian kosong)" << endl;
    } else {
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index++ << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
        }
    }
}

int main() {
    int choice;
    do {
        cout << "\nMenu Antrian Mahasiswa dengan Prioritas:" << endl;
        cout << "1. Tambah Mahasiswa ke Antrian" << endl;
        cout << "2. Hapus Mahasiswa dari Antrian" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Hapus Semua Antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string nama, nim;
                cout << "Masukkan Nama Mahasiswa: ";
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
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
                cout << "Semua antrian telah dihapus." << endl;
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 5);

    return 0;
}
