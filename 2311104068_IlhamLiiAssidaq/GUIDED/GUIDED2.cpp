#include <iostream>

using namespace std;

class Node {
public:
    int data;     
    Node* next;   

    Node(int value) {
        data = value;
        next = NULL;  
    }
};

class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    Queue() {
        front = rear = NULL;  
    }

    bool isEmpty() { 
        return front == NULL;  
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode; 
        rear = newNode;     
    }

    void dequeue() {
        if (isEmpty()) {
           cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;     
        front = front->next;    
        delete temp;            
        if (front == NULL)       
            rear = NULL;       
    }

    int peek() {
        if (!isEmpty()) {
            return front->data;
        }
       cout << "Queue is empty\n";
        return -1; 
    }

    void display() {
        if (isEmpty()) {
           cout << "Queue is empty\n";
            return;
        }
        Node* current = front; 
        while (current) {     
           cout << current->data << " ";
            current = current->next;
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

    q.dequeue();
   cout << "After dequeuing, queue elements: ";
    q.display();

    return 0;
}

