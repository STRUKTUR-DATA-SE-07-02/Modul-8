#include <iostream>
#define MAX 100
using namespace std;

// Node untuk setiap elemen Mahasiswa
class Node {
public:
    string nama;   // Nama mahasiswa
    string nim;    // NIM mahasiswa
    Node* next;    // Pointer ke node berikutnya

    // Konstruktor untuk Node
    Node(string n, string no) {
        nama = n;
        nim = no;
        next = nullptr;
    }
};

// Kelas Queue Mahasiswa menggunakan linked list
class Queue {
private:
    Node* front; // Pointer ke elemen depan Queue
    Node* rear;  // Pointer ke elemen belakang Queue
    int size;    // Ukuran Queue

public:
    // Konstruktor Queue
    Queue() {
        front = rear = nullptr;
        size = 0;
    }

    // Mengecek apakah Queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Mengecek apakah Queue penuh
    bool isFull() {
        return size >= MAX;
    }

    // Menambahkan mahasiswa ke Queue
    void enqueue(string nama, string nim) {
        if (isFull()) {
            cout << "Queue Overflow: Tidak bisa menambahkan lebih banyak mahasiswa.\n";
            return;
        }

        Node* newNode = new Node(nama, nim);
        if (isEmpty()) {
            front = rear = newNode; // Jika Queue kosong
        } else {
            rear->next = newNode; // Tambahkan node baru ke belakang
            rear = newNode;       // Perbarui rear
        }
        size++;
    }

    // Menghapus mahasiswa dari depan Queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;      // Simpan node depan untuk dihapus
        front = front->next;     // Pindahkan front ke node berikutnya
        delete temp;             // Hapus node lama
        if (front == nullptr)    // Jika Queue kosong, rear juga harus null
            rear = nullptr;
        size--;
    }

    // Menampilkan mahasiswa depan Queue tanpa menghapusnya
    void peek() {
        if (!isEmpty()) {
            cout << "Nama: " << front->nama << ", NIM: " << front->nim << endl;
        } else {
            cout << "Queue is empty\n";
        }
    }

    // Menampilkan semua mahasiswa di Queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* current = front; // Mulai dari depan
        int nomor = 1;
        while (current) {      // Iterasi sampai akhir
            cout << nomor << ". Nama: " << current->nama
                 << ", NIM: " << current->nim << endl;
            current = current->next;
            nomor++;
        }
    }

    // Menampilkan antrian dengan prioritas NIM
    void displayPrioritas() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        // Salin data ke array untuk sorting
        Node* array[MAX];
        Node* current = front;
        int count = 0;
        while (current) {
            array[count++] = current;
            current = current->next;
        }

        // Sorting array berdasarkan NIM (Bubble Sort)
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (array[j]->nim > array[j + 1]->nim) {
                    Node* temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }

        // Tampilkan dengan urutan prioritas
        int nomor = 1;
        for (int i = 0; i < count; i++) {
            cout << nomor << ". Nama: " << array[i]->nama
                 << ", NIM: " << array[i]->nim << endl;
            nomor++;
        }
    }
};

// Fungsi utama untuk menguji Queue Mahasiswa
int main() {
    Queue q;

    // Menambahkan mahasiswa ke Queue
    q.enqueue("Andi", "2311110022");
    q.enqueue("Budi", "2311110011");
    q.enqueue("Cici", "2311110033");

    // Menampilkan mahasiswa di Queue
    cout << "Queue Mahasiswa: \n";
    q.display();

    // Menampilkan mahasiswa depan
    cout << "\nMahasiswa di depan antrian: \n";
    q.peek();

    // Menampilkan antrian dengan prioritas NIM
    cout << "\nQueue Mahasiswa dengan Prioritas NIM: \n";
    q.displayPrioritas();

    // Menghapus mahasiswa dari depan Queue
    q.dequeue();

    cout << "\nSetelah mengeluarkan mahasiswa pertama: \n";
    q.display();

    return 0;
}
