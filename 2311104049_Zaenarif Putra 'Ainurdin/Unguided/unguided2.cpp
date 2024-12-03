#include <iostream>
using namespace std;

struct Node {
    string name;
    string nim;
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

void enqueue(Queue* queue, string name, string nim) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->count++; 
    cout << "Mahasiswa " << name << " [NIM: " << nim << "] ditambahkan ke antrian." << endl;
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Antrian kosong." << endl;
        return;
    }
    Node* temp = queue->front;
    cout << "Mahasiswa " << temp->name << " [NIM: " << temp->nim << "] dikeluarkan dari antrian." << endl;
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
    cout << "Data antrian mahasiswa:" << endl;
    int index = 1;
    while (current != nullptr) {
        cout << index++ << ". Nama: " << current->name << ", NIM: " << current->nim << endl;
        current = current->next;
    }
    cout << "Jumlah antrian = " << queue->count << endl;
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, "Zaenarif Putra 'Ainurdin", "2311104049");
    enqueue(queue, "Izzaty Zahara", "2311104052");
    viewQueue(queue);
    dequeue(queue);
    viewQueue(queue);
    dequeue(queue);
    dequeue(queue);
    return 0;
}