#include <iostream>
#define MAX 100 

using namespace std;

class Queue {
private:
    int front, rear; 
    int arr[MAX];    
public:
    
    Queue() {
        front = -1;
        rear = -1;
    }

   
    bool isFull() { 
        return rear == MAX - 1; 
    }

    
    bool isEmpty() { 
        return front == -1 || front > rear; 
    }

    
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0; 
        arr[++rear] = x;            
    }

   
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++; 
    }
   
    int peek() {
        if (!isEmpty()) {
            return arr[front];
        }
        cout << "Queue is empty\n";
        return -1; 
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};


int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue elements: ";
    q.display();

    cout << "Front element: " << q.peek() << "\n";
   
    cout << "After dequeuing, queue elements: ";
    q.display();

    return 0;
}
