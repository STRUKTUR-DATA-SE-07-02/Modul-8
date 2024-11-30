//#include <iostream>
//#define MAX 100
//
//using namespace std;
//
//class Queue {
//private:
//    int front, rear;
//    int arr[MAX];
//public:
//
//    Queue() {
//        front = -1;
//        rear = -1;
//    }
//
//
//    bool isFull() {
//        return rear == MAX - 1;
//    }
//
//
//    bool isEmpty() {
//        return front == -1 || front > rear;
//    }
//
//
//    void enqueue(int x) {
//        if (isFull()) {
//            cout << "Queue Overflow\n";
//            return;
//        }
//        if (front == -1) front = 0;
//        arr[++rear] = x;
//    }
//
//
//    void dequeue() {
//        if (isEmpty()) {
//            cout << "Queue Underflow\n";
//            return;
//        }
//        front++;
//    }
//
//    int peek() {
//        if (!isEmpty()) {
//            return arr[front];
//        }
//        cout << "Queue is empty\n";
//        return -1;
//    }
//
//
//    void display() {
//        if (isEmpty()) {
//            cout << "Queue is empty\n";
//            return;
//        }
//        for (int i = front; i <= rear; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << "\n";
//    }
//};
//
//
//int main() {
//    Queue q;
//
//    q.enqueue(10);
//    q.enqueue(20);
//    q.enqueue(30);
//
//    cout << "Queue elements: ";
//    q.display();
//
//    cout << "Front element: " << q.peek() << "\n";
//
//    cout << "After dequeuing, queue elements: ";
//    q.display();
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//// Node untuk setiap elemen Queue
//class Node {
//public:
//    int data;      // Data elemen
//    Node* next;    // Pointer ke node berikutnya
//
//    // Konstruktor untuk Node
//    Node(int value) {
//        data = value;
//        next = nullptr;
//    }
//};
//
//// Kelas Queue menggunakan linked list
//class Queue {
//private:
//    Node* front; // Pointer ke elemen depan Queue
//    Node* rear;  // Pointer ke elemen belakang Queue
//
//public:
//    // Konstruktor Queue
//    Queue() {
//        front = rear = nullptr;
//    }
//
//    // Mengecek apakah Queue kosong
//    bool isEmpty() {
//        return front == nullptr;
//    }
//
//    // Menambahkan elemen ke Queue
//    void enqueue(int x) {
//        Node* newNode = new Node(x);
//        if (isEmpty()) {
//            front = rear = newNode; // Jika Queue kosong
//            return;
//        }
//        rear->next = newNode; // Tambahkan node baru ke belakang
//        rear = newNode;       // Perbarui rear
//    }
//
//    // Menghapus elemen dari depan Queue
//    void dequeue() {
//        if (isEmpty()) {
//           cout << "Queue Underflow\n";
//            return;
//        }
//        Node* temp = front;      // Simpan node depan untuk dihapus
//        front = front->next;     // Pindahkan front ke node berikutnya
//        delete temp;             // Hapus node lama
//        if (front == nullptr)    // Jika Queue kosong, rear juga harus null
//            rear = nullptr;
//    }
//
//    // Mengembalikan elemen depan Queue tanpa menghapusnya
//    int peek() {
//        if (!isEmpty()) {
//            return front->data;
//        }
//       cout << "Queue is empty\n";
//        return -1; // Nilai sentinel
//    }
//
//    // Menampilkan semua elemen di Queue
//    void display() {
//        if (isEmpty()) {
//           cout << "Queue is empty\n";
//            return;
//        }
//        Node* current = front; // Mulai dari depan
//        while (current) {      // Iterasi sampai akhir
//           cout << current->data << " ";
//            current = current->next;
//        }
//       cout << "\n";
//    }
//};
//
//// Fungsi utama untuk menguji Queue
//int main() {
//    Queue q;
//
//    // Menambahkan elemen ke Queue
//    q.enqueue(10);
//    q.enqueue(20);
//    q.enqueue(30);
//
//    // Menampilkan elemen di Queue
//   cout << "Queue elements: ";
//    q.display();
//
//    // Menampilkan elemen depan
//   cout << "Front element: " << q.peek() << "\n";
//
//    // Menghapus elemen dari depan Queue
//    q.dequeue();
//   cout << "After dequeuing, queue elements: ";
//    q.display();
//
//    return 0;
//}

#include<iostream>

using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosong
                queueTeller[0] = data; front++;
                back++;
                } else { // Antrianya ada isi queueTeller[back] = data; back++;
                }
                }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) { queueTeller[i] = queueTeller[i + 1];
        }
        back--;
        }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
            cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) { queueTeller[i] = "";
        }
        back = 0;
        front = 0;
        }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl; for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
    cout << i + 1 << ". " << queueTeller[i] << endl;

    } else {
        cout << i + 1 << ". (kosong)" << endl;
        }
        }
}

int main() {
    enqueueAntrian("Andi");

    enqueueAntrian("Maya");

    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
