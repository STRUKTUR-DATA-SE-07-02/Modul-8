#include <iostream>
using namespace std;

// Struktur Node untuk linked list
struct Node
{
    int data;
    Node *next;
};

// Kelas Queue
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

    // Menambahkan elemen ke dalam queue
    void enqueue(int x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
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
    int peek()
    {
        if (!isEmpty())
        {
            return front->data;
        }
        cout << "Queue is empty\n";
        return -1;
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
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue elements: ";
    q.display();

    cout << "Front element: " << q.peek() << "\n";

    q.dequeue(); // Dequeue element

    cout << "After dequeuing, queue elements: ";
    q.display();

    return 0;
}
