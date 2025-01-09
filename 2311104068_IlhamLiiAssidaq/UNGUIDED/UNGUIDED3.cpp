#include <iostream>
#include <string>
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
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0; 
    return queue;
}

bool isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, string name, string nim) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->nim = nim;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        if (nim < queue->front->nim) {
            newNode->next = queue->front;
            queue->front = newNode;
        } else {
            Node* current = queue->front;
            while (current->next != NULL && current->next->nim < nim) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;

            if (newNode->next == NULL) {
                queue->rear = newNode;
            }
        }
    }
    queue->count++; 
    cout << "Mahasiswa " << name << " (NIM: " << nim << ") ditambahkan ke antrian." << endl;
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Antrian kosong." << endl;
        return;
    }
    Node* temp = queue->front;
    cout << "Mahasiswa " << temp->name << " (NIM: " << temp->nim << ") dikeluarkan dari antrian." << endl;
    queue->front = queue->front->next;
    delete temp;
    queue->count--; 

    if (queue->front == NULL) {
        queue->rear = NULL;
        cout << "Antrian telah dikosongkan." << endl;
    }
}

void viewQueue(Queue* queue) {
    Node* current = queue->front;
    cout << "Data antrian mahasiswa:" << endl;
    int index = 1;
    while (current != NULL) {
        cout << index++ << ". Nama: " << current->name << ", NIM: " << current->nim << endl;
        current = current->next;
    }
    cout << "Jumlah antrian = " << queue->count << endl;
}

int main() {
    Queue* queue = createQueue();
    int n;
    
    cout << "Masukkan jumlah mahasiswa yang ingin ditambahkan: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string name, nim;
        cout << "Masukkan nama mahasiswa: ";
        getline(cin, name);
        cout << "Masukkan NIM mahasiswa: ";
        getline(cin, nim);
        enqueue(queue, name, nim);
    }

    viewQueue(queue);

    while (!isEmpty(queue)) {
        dequeue(queue);
        viewQueue(queue);
    }

    return 0;
}

