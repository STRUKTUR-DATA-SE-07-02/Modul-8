#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;  // Nama Mahasiswa
    string nim;   // NIM Mahasiswa
    Node* next;   // Pointer ke node berikutnya

    Node(string name, string nim) {
        this->name = name;
        this->nim = nim;
        this->next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* front;  // Pointer ke elemen terdepan

public:
    PriorityQueue() {
        front = nullptr;
    }

    // Cek apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Menambahkan mahasiswa ke dalam queue (enqueue)
    void enqueue(string name, string nim) {
        Node* newNode = new Node(name, nim);
        if (isEmpty() || nim < front->nim) { // Sisipkan di depan jika queue kosong atau NIM lebih kecil
            newNode->next = front;
            front = newNode;
        } else {
            // Cari posisi yang sesuai berdasarkan NIM
            Node* temp = front;
            while (temp->next != nullptr && temp->next->nim < nim) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Menghapus mahasiswa dari queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Menampilkan mahasiswa di depan tanpa menghapusnya
    void peek() {
        if (!isEmpty()) {
            cout << "Nama Mahasiswa: " << front->name << ", NIM: " << front->nim << "\n";
        } else {
            cout << "Queue is empty\n";
        }
    }

    // Menampilkan semua mahasiswa dalam queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Antrian Mahasiswa (Prioritas NIM Kecil):\n";
        while (temp != nullptr) {
            cout << "Nama: " << temp->name << ", NIM: " << temp->nim << "\n";
            temp = temp->next;
        }
    }

    // Destructor untuk membersihkan memori
    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    string name, nim;

    do {
        cout << "\nMenu Antrian Mahasiswa\n";
        cout << "1. Tambah Mahasiswa (Enqueue)\n";
        cout << "2. Hapus Mahasiswa (Dequeue)\n";
        cout << "3. Lihat Mahasiswa di Depan (Peek)\n";
        cout << "4. Tampilkan Semua Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        // Cek apakah input valid
        if (cin.fail()) {
            cin.clear();                
            cin.ignore(1000, '\n');     
            cout << "Input tidak valid! Masukkan angka.\n";
            continue;                   
        }

        switch (choice) {
        case 1:
            cout << "Masukkan Nama Mahasiswa: ";
            cin.ignore(); 
            getline(cin, name);
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> nim;
            pq.enqueue(name, nim);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.peek();
            break;
        case 4:
            pq.display();
            break;
        case 5:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (choice != 5);

    return 0;
}
