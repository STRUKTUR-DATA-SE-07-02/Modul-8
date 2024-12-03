#include <iostream>
using namespace std;

// Node untuk menyimpan data queue
class Node {
public:
    string nama;
    string nim;
    Node* next;

    Node(string nama, string nim) {
        this->nama = nama;
        this->nim = nim;
        this->next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string nama, string nim) {
        Node* newNode = new Node(nama, nim);
        if (isEmpty() || nim < front->nim) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            while (current->next != nullptr && current->next->nim < nim) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* current = front;
        cout << "Daftar Mahasiswa Prioritas:\n";
        while (current) {
            cout << "Nama: " << current->nama << ", NIM: " << current->nim << "\n";
            current = current->next;
        }
    }
};

int main() {
    PriorityQueue pq;
    int n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nama, nim;
        cout << "Nama Mahasiswa: ";
        cin >> nama;
        cout << "NIM Mahasiswa: ";
        cin >> nim;
        pq.enqueue(nama, nim);
    }

    cout << "\nAntrian berdasarkan prioritas NIM:\n";
    pq.display();

    return 0;
}
