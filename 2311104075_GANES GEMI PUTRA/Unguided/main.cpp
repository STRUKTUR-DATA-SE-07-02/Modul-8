#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Ukuran maksimal queue
typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head, tail;
};

// Prototipe fungsi
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);

// Alternatif 1: Head Diam, Tail Bergerak
void enqueueAlt1(Queue &Q, infotype x);
infotype dequeueAlt1(Queue &Q);

// Alternatif 2: Head dan Tail Bergerak
void enqueueAlt2(Queue &Q, infotype x);
infotype dequeueAlt2(Queue &Q);

// Alternatif 3: Circular Queue
void enqueueAlt3(Queue &Q, infotype x);
infotype dequeueAlt3(Queue &Q);

void printInfo(Queue Q);

int main() {
    Queue Q;
    createQueue(Q);

    int pilihan, alternatif, nilai;
    cout << "Pilih Alternatif Queue:\n";
    cout << "1. Head Diam, Tail Bergerak\n";
    cout << "2. Head dan Tail Bergerak\n";
    cout << "3. Circular Queue\n";
    cout << "Pilihan: ";
    cin >> alternatif;

    do {
        cout << "\nMenu Queue:\n";
        cout << "1. Tambah Data (Enqueue)\n";
        cout << "2. Hapus Data (Dequeue)\n";
        cout << "3. Tampilkan Queue\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                if (alternatif == 1) enqueueAlt1(Q, nilai);
                else if (alternatif == 2) enqueueAlt2(Q, nilai);
                else if (alternatif == 3) enqueueAlt3(Q, nilai);
                break;

            case 2:
                if (alternatif == 1) cout << "Data dihapus: " << dequeueAlt1(Q) << endl;
                else if (alternatif == 2) cout << "Data dihapus: " << dequeueAlt2(Q) << endl;
                else if (alternatif == 3) cout << "Data dihapus: " << dequeueAlt3(Q) << endl;
                break;

            case 3:
                printInfo(Q);
                break;

            case 4:
                cout << "Keluar dari program.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}

// Inisialisasi queue kosong
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

// Mengecek apakah queue kosong
bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

// Mengecek apakah queue penuh
bool isFullQueue(Queue Q) {
    return (Q.tail + 1) % MAX_SIZE == Q.head;
}

// **Alternatif 1: Head Diam, Tail Bergerak**
void enqueueAlt1(Queue &Q, infotype x) {
    if (Q.tail == MAX_SIZE - 1) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) Q.head = 0;
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeueAlt1(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype temp = Q.info[Q.head];
        if (Q.head == Q.tail) createQueue(Q);
        else Q.head++;
        return temp;
    }
}

// **Alternatif 2: Head dan Tail Bergerak**
void enqueueAlt2(Queue &Q, infotype x) {
    if (Q.tail == MAX_SIZE - 1) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) Q.head = Q.tail = 0;
        else Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeueAlt2(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype temp = Q.info[Q.head];
        if (Q.head == Q.tail) createQueue(Q);
        else Q.head++;
        return temp;
    }
}

// **Alternatif 3: Circular Queue**
void enqueueAlt3(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) Q.head = Q.tail = 0;
        else Q.tail = (Q.tail + 1) % MAX_SIZE;
        Q.info[Q.tail] = x;
    }
}

infotype dequeueAlt3(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        infotype temp = Q.info[Q.head];
        if (Q.head == Q.tail) createQueue(Q);
        else Q.head = (Q.head + 1) % MAX_SIZE;
        return temp;
    }
}

// Menampilkan isi queue
void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong." << endl;
    } else {
        cout << "Isi Queue: ";
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
}
