#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk linked list
struct Node
{
    string nama;
    string nim;
    Node *next;
};

// Kelas Queue dengan prioritas berdasarkan NIM
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Mengecek apakah queue kosong
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Menambahkan elemen ke dalam queue dengan prioritas berdasarkan NIM
    void enqueue(string nama, string nim)
    {
        Node *newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            // Menyisipkan node pada posisi yang tepat berdasarkan NIM
            Node *temp = front;
            Node *prev = nullptr;

            // Cari posisi yang tepat (NIM lebih kecil didahulukan)
            while (temp != nullptr && temp->nim < nim)
            {
                prev = temp;
                temp = temp->next;
            }

            // Menyisipkan elemen di awal atau di tengah
            if (prev == nullptr)
            {
                newNode->next = front;
                front = newNode;
            }
            else
            {
                newNode->next = temp;
                prev->next = newNode;
            }

            // Jika node baru ditambahkan di akhir
            if (newNode->next == nullptr)
            {
                rear = newNode;
            }
        }
    }

    // Mengeluarkan elemen dari queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;

        // Jika setelah dequeue queue menjadi kosong
        if (front == nullptr)
        {
            rear = nullptr;
        }
    }

    // Melihat elemen terdepan
    void peek()
    {
        if (!isEmpty())
        {
            cout << "Front - Nama: " << front->nama << ", NIM: " << front->nim << endl;
        }
        else
        {
            cout << "Queue is empty\n";
        }
    }

    // Menampilkan semua elemen dalam queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = front;
        while (temp != nullptr)
        {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    Queue q;
    int n;
    string nama, nim;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore(); // Membersihkan newline character setelah cin

    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan Nama Mahasiswa ke-" << (i + 1) << ": ";
        getline(cin, nama);
        cout << "Masukkan NIM Mahasiswa ke-" << (i + 1) << ": ";
        getline(cin, nim);
        q.enqueue(nama, nim);
    }

    cout << "\nQueue elements (dengan prioritas berdasarkan NIM):\n";
    q.display();

    cout << "\nElemen terdepan (Front) queue: ";
    q.peek();

    // Dequeue beberapa elemen untuk menunjukkan perubahan queue
    cout << "\nSetelah dequeue:\n";
    q.dequeue();
    q.display();

    return 0;
}
