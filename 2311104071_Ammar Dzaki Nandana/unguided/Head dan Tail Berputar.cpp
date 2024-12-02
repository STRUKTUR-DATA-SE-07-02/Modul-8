bool isFullQueue(const Queue &Q) {
    return (Q.tail + 1) % MAX_SIZE == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh! Tidak dapat menambah elemen." << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
        }
        Q.tail = (Q.tail + 1) % MAX_SIZE;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong! Tidak dapat mengambil elemen." << endl;
        return -1;
    } else {
        infotype temp = Q.info[Q.head];
        if (Q.head == Q.tail) { // Jika Queue hanya memiliki satu elemen
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX_SIZE;
        }
        return temp;
    }
}
