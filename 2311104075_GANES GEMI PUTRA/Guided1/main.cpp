#include <iostream>
using namespace std;

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata nilai: " << rata2(mhs) << endl;
    return 0;
}

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input nilai 1: ";
    cin >> m.nilai1;
    cout << "Input nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return static_cast<float>(m.nilai1 + m.nilai2) / 2;
}
