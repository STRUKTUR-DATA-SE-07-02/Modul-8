#include <iostream>
#define MAX 100

class Queue
{
private:
    int front, rear;
    int arr[MAX];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool is_full()
    {
        return rear == MAX - 1;
    }

    bool is_empty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(int x)
    {
        if (is_full())
        {
            std::cout << "Queue is full!\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = x;
    }

    void dequeue()
    {
        if (is_empty())
        {
            std::cout << "Queue is empty!\n";
            return;
        }
        front++;
    }

    int peek()
    {
        if (!is_empty())
        {
            return arr[front];
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
        for (int i = front; i <= rear; i++)
        {
            std::cout << arr[i] << " ";
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

    std::cout << "Queue elements: ";
    q.display();

    std::cout << "Front element: " << q.peek() << "\n";
    q.dequeue();

    std::cout << "Queue elements after dequeueing: ";
    q.display();

    return 0;
}
