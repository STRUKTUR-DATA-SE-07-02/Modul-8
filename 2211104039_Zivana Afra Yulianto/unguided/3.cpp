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

    if (isEmpty() || nim < front->nim)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        Node *temp = front;
        while (temp->next != nullptr && temp->next->nim < nim)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
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
    string nama, nim;
    int n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

}