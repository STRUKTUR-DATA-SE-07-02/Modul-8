#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string nama;
    string nim;
    Node *next;
};

Node *front = nullptr;
Node *back = nullptr;

bool isEmpty()
{
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim)
{
    Node *newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
            back = nullptr;
        delete temp;
    }
}

void viewQueue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        cout << "Data antrian:" << endl;
        while (temp != nullptr)
        {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }
}

void clearQueue()
{
    while (!isEmpty())
    {
        dequeueAntrian();
    }
}

int main()
{
    int pilihan;
    string nama, nim;

    do
    {
        cout << "\nMenu Antrian:" << endl;
        cout << "1. Tambah ke antrian (enqueue)" << endl;
        cout << "2. Hapus dari antrian (dequeue)" << endl;
        cout << "3. Lihat antrian" << endl;
        cout << "4. Hapus semua antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nama: ";
            cin.ignore(); // Membersihkan buffer input
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            getline(cin, nim);
            enqueueAntrian(nama, nim);
            break;
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
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
