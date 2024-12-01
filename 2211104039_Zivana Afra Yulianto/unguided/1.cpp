#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node *front = nullptr;
Node *back = nullptr;

bool isEmpty()
{
    return front == nullptr;
}

void enqueueAntrian(string data)
{
    Node *newNode = new Node();
    newNode->data = data;
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
            back = nullptr; // Jika kosong
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
            cout << temp->data << endl;
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
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");

    viewQueue();

    dequeueAntrian();
    viewQueue();

    clearQueue();
    viewQueue();

    return 0;
}
