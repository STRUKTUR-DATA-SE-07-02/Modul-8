#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
    int count; 
};

Queue* createQueue() {
    Queue* queue = new Queue();
    queue->front = nullptr;
    queue->rear = nullptr;
    queue->count = 0; 
    return queue;
}

bool isEmpty(Queue* queue) {
    return (queue->front == nullptr);
}

void enqueue(Queue* queue, string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->count++;
    cout << data << " ditambahkan ke antrian." << endl;
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Antrian kosong." << endl;
        return;
    }
    Node* temp = queue->front;
    cout << temp->data << " dikeluarkan dari antrian." << endl;
    queue->front = queue->front->next;
    delete temp;
    queue->count--; 

    if (queue->front == nullptr) {
        queue->rear = nullptr;
        cout << "Antrian telah dikosongkan." << endl;
    }
}

void viewQueue(Queue* queue) {
    Node* current = queue->front;
    cout << "Data antrian :" << endl;
    int index = 1;
    while (current != nullptr) {
        cout << index++ << ". " << current->data << endl;
        current = current->next;
    }
    cout << "Jumlah antrian = " << queue->count << endl; 
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, "Putra");
    enqueue(queue, "Zahara");
    enqueue(queue, "Izaaty");
    viewQueue(queue);
    dequeue(queue);
    viewQueue(queue);
    dequeue(queue);
    dequeue(queue); 
    return 0;
}