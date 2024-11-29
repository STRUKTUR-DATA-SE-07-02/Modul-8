// Diadaptasi ulang dari kode-kode GUIDED
#include <iostream>
#include <string>

struct Mhs
{
    int nim;
    std::string nama;
};

class Node
{
public:
    struct Mhs data;
    Node *next;

    Node(struct Mhs value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = nullptr;
        back = nullptr;
    }

    bool is_empty()
    {
        return front == nullptr;
    }

    void enqueue(struct Mhs x)
    {
        Node *new_node = new Node(x);

        if (is_empty())
        {
            front = new_node;
            back = new_node;
            return;
        }
        back->next = new_node;
        back = new_node;
    }

    void dequeue()
    {
        if (is_empty())
        {
            std::cout << "Antrian kosong!\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr)
            back = nullptr;
    }

    int peek()
    {
        if (!is_empty())
        {
            return front->data.nim;
        }
        std::cout << "Antrian kosong!\n";
        return -1;
    }

    void display()
    {
        if (is_empty())
        {
            std::cout << "Antrian kosong!\n";
            return;
        }
        Node *current = front;
        while (current)
        {
            std::cout << current->data.nim << "-" << current->data.nama << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

int main()
{
    Queue q;

    int much_data = 0;

    struct Mhs mahasiswa;
    mahasiswa.nama = "";
    mahasiswa.nim = 0;

    std::cout << "Berapa banyak data yang ingin kamu masukkan? Masukkan: ";
    std::cin >> much_data;
    std::cin.ignore();

    for (int i = 0; i < much_data; i = i + 1)
    {
        std::cout << "Nama: ";
        std::getline(std::cin, mahasiswa.nama);

        std::cout << "NIM: ";
        std::cin >> mahasiswa.nim;
        std::cin.ignore();

        q.enqueue(mahasiswa);
        std::cout << '\n';
    }

    std::cout << "Elemen-elemen antrian: ";
    q.display();

    std::cout << "Elemen awal: " << q.peek() << "\n";
    q.dequeue();

    std::cout << "Elemen-elemen antrian setelah pengurangan: ";
    q.display();

    return 0;
}