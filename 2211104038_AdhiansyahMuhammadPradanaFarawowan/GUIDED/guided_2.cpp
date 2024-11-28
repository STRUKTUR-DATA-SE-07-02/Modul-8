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
            std::cout << "Queue is empty!\n";
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
        std::cout << "Queue is empty!\n";
        return -1;
    }

    void display()
    {
        if (is_empty())
        {
            std::cout << "Queue is empty!\n";
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

    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(13);

    std::cout << "Queue elements: ";
    q.display();

    std::cout << "Front element: " << q.peek() << "\n";
    q.dequeue();
    q.dequeue();

    std::cout << "Queue elements after dequeueing twice: ";
    q.display();

    return 0;
}