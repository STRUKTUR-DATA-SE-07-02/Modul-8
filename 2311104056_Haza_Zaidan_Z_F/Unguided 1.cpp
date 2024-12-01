#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* back;
    int size;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    bool isFull() {
        return false; // Linked list tidak memiliki batas ukuran tetap
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    int count() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void view() {
        cout << "Isi queue: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    // Input data oleh user
    int jumlahData;
    cout << "Masukkan jumlah nama: ";
    cin >> jumlahData;
    cin.ignore(); // Membersihkan buffer newline

    for (int i = 0; i < jumlahData; i++) {
        string nama;
        cout << "Masukkan nama ke-" << i + 1 << ": ";
        getline(cin, nama);
        queue.enqueue(nama);
    }

    cout << "\nData dalam queue setelah input:\n";
    queue.view();

    return 0;
}