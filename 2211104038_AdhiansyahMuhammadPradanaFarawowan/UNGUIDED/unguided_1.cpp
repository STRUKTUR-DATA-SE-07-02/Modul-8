// Diadaptasi ulang dari kode-kode GUIDED
#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

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

    bool is_empty()
    {
        return front == nullptr;
    }

    void enqueue(int x)
    {
        Node *newNode = new Node(x);

        if (is_empty())
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
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
            rear = nullptr;
    }

    int peek()
    {
        if (!is_empty())
        {
            return front->data;
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
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

int main()
{
    Queue q;

    q.enqueue(21);
    q.enqueue(41);
    q.enqueue(61);

    std::cout << "Elemen-elemen antrian: ";
    q.display();

    std::cout << "Elemen awal: " << q.peek() << "\n";
    q.dequeue();

    std::cout << "Elemen-elemen antrian setelah pengurangan: ";
    q.display();

    return 0;
}
