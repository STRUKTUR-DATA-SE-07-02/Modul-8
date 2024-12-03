#include <iostream>
#include <string>
using namespace std;

class PrioritizedStudentQueue {
private:
    struct Student {
        string nama;
        string nim;
        Student* next;
        Student(string n, string id) : nama(n), nim(id), next(nullptr) {}
    };
    Student* front;
    Student* rear;

public:
    PrioritizedStudentQueue() : front(nullptr), rear(nullptr) {}

    void enqueue() {
        string nama, nim;
        cout << "Masukkan nama mahasiswa: ";
        cin.ignore(); // Membersihkan buffer sebelum getline
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa: ";
        cin >> nim;

        Student* newStudent = new Student(nama, nim);

        // Queue kosong
        if (isEmpty()) {
            front = rear = newStudent;
            return;
        }

        // NIM lebih kecil dari front, masukkan di depan
        if (nim < front->nim) {
            newStudent->next = front;
            front = newStudent;
            return;
        }

        // Cari posisi yang tepat berdasarkan NIM
        Student* current = front;
        while (current->next && current->next->nim < nim) {
            current = current->next;
        }

        newStudent->next = current->next;
        current->next = newStudent;

        // Update rear jika diperlukan
        if (newStudent->next == nullptr) {
            rear = newStudent;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
            return;
        }
        Student* temp = front;
        front = front->next;
        cout << "Mahasiswa " << temp->nama << " dikeluarkan dari antrian." << endl;
        delete temp;
        if (front == nullptr) rear = nullptr;
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
            return;
        }
        Student* current = front;
        int i = 1;
        while (current) {
            cout << i++ << ". Nama: " << current->nama 
                 << ", NIM: " << current->nim << endl;
            current = current->next;
        }
    }

    bool isEmpty() { return front == nullptr; }
};

int main() {
    PrioritizedStudentQueue queue;
    int pilihan;
    do {
        cout << "\nMenu Antrian Mahasiswa Prioritas:" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Hapus Mahasiswa" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: queue.enqueue(); break;
            case 2: queue.dequeue(); break;
            case 3: queue.viewQueue(); break;
            case 4: cout << "Keluar dari program." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl; break;
        }
    } while (pilihan != 4);

    return 0;
}