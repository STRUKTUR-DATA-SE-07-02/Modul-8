#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Kapasitas maksimum Queue

typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE]; // Array untuk menyimpan elemen Queue
    int head; // Indeks elemen pertama
    int tail; // Indeks elemen terakhir
};

// Fungsi dan prosedur
void createQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif
