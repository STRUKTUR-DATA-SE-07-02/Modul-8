#include <iostream>
using namespace std;

// Struktur untuk node dalam linked list
struct Node {
    string nama; // Nama mahasiswa
    string nim;  // NIM mahasiswa
    Node* next;  // Pointer ke node berikutnya
};

// Kelas Queue yang menggunakan linked list
class Queue {
private:
    Node* front; // Penanda depan antrian
    Node* back;  // Penanda belakang antrian
    int count;   // Jumlah elemen dalam antrian

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        count = 0;
    }

    ~Queue() {
        clearQueue();
    }

    bool isFull() {
        // Untuk linked list, antrian tidak pernah penuh (kecuali memori habis)
        return false;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueAntrian(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        // Jika antrian kosong, tambahkan node baru
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            // Jika NIM dari node baru lebih kecil dari front, masukkan di depan
            if (nim < front->nim) {
                newNode->next = front;
                front = newNode;
            } else {
                // Cari posisi untuk menyisipkan node baru
                Node* current = front;
                while (current->next != nullptr && current->next->nim < nim) {
                    current = current->next; // Cari node yang NIM-nya lebih besar
                }
                // Sisipkan node baru
                newNode->next = current->next;
                current->next = newNode;

                // Jika node baru ditambahkan di belakang, update back
                if (newNode->next == nullptr) {
                    back = newNode;
                }
            }
        }
        count++; // Increment jumlah antrian
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* temp = front; // Simpan node depan untuk dihapus
        front = front->next; // Update front ke node berikutnya

        if (front == nullptr) {
            back = nullptr; // Jika antrian menjadi kosong, update back juga
        }

        delete temp; // Hapus node yang sudah tidak diperlukan
        count--; // Decrement jumlah antrian
    }

    int countQueue() {
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian(); // Hapus semua elemen
        }
    }

    void viewQueue() {
        cout << "Data antrian mahasiswa:" << endl;
        Node* current = front;
        int index = 1;

        while (current != nullptr) {
            cout << index++ << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
        }

        // Jika antrian kosong
        if (isEmpty()) {
            cout << "(kosong)" << endl;
        }
    }
};

int main() {
    Queue queue; // Membuat objek antrian

    queue.enqueueAntrian("Alya", "2311104076");
    queue.enqueueAntrian("Winda", "2311104020");
    queue.enqueueAntrian("Anin", "2311104017");
    queue.enqueueAntrian("Fenny", "2311104027");
    queue.enqueueAntrian("Elsa", "2311104002");
    queue.enqueueAntrian("Yani", "2311104031");
    
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}