#include <iostream>
#include <string>
using namespace std;

// Node untuk linked list
struct Node {
    string nama;
    int nim;
    Node* next;
};

// Inisialisasi queue
Node* front = nullptr;

// Fungsi enqueue dengan prioritas NIM
void enqueue(string nama, int nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (front == nullptr || nim < front->nim) {
        newNode->next = front;
        front = newNode;
    } else {
        Node* temp = front;
        while (temp->next != nullptr && temp->next->nim < nim) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Fungsi melihat data di queue
void viewQueue() {
    Node* temp = front;
    while (temp != nullptr) {
        cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
        temp = temp->next;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nama;
        int nim;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "NIM: ";
        cin >> nim;
        enqueue(nama, nim);
    }

    cout << "\nQueue berdasarkan prioritas NIM:" << endl;
    viewQueue();

    return 0;
}