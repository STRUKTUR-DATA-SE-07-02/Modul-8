#include <iostream>
using namespace std;

class Node{
public:
    string nama;
    string nim;   
    Node* next;   
    Node(string namaMahasiswa, string nimMahasiswa){
        nama = namaMahasiswa;
        nim = nimMahasiswa;
        next = nullptr;
    }
};
class Queue{
private:
    Node* front;
    Node* back; 
    int size;   
    const int maksimalQueue = 5; 

public:
    Queue(){
        front = nullptr;
        back = nullptr;
        size = 0;
    }
    bool isFull(){
        return size == maksimalQueue;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueueAntrian(string namaMahasiswa, string nimMahasiswa) {
        if(isFull()){
            cout << "Antrian penuh" << endl;
        }else{
            Node* newNode = new Node(namaMahasiswa, nimMahasiswa);
            if (isEmpty()){
                front = back = newNode;
            }else{
                back->next = newNode;  
                back = newNode;        
            }
            size++;
        }
    }
    void dequeueAntrian(){
        if(isEmpty()){
            cout << "Antrian kosong" << endl;
        }else{
            Node* temp = front;
            front = front->next;
            delete temp;        
            size--;
            if(front == nullptr){
                back = nullptr;
            }
        }
    }
    int countQueue(){
        return size;
    }
    void clearQueue(){
        while(!isEmpty()){
            dequeueAntrian();
        }
        cout<<"Antrian telah dikosongkan"<<endl;
    }
    void viewQueue(){
        cout<<"Data antrian mahasiswa:"<<endl;
        if(isEmpty()){
            cout<<"(Kosong)"<<endl;
        }else{
            Node* current = front;
            int i = 1;
            while(current != nullptr){
                cout<<i++<<". Nama: "<<current->nama 
                     <<", NIM: "<<current->nim<<endl;
                current = current->next;
            }
        }
    }
};
int main(){
    Queue q;
    int pilihan;

    do{
        cout<<"\nMenu Antrian Mahasiswa:" <<endl;
        cout<<"1. Tambah mahasiswa ke antrian"<<endl;
        cout<<"2. Hapus mahasiswa dari antrian"<<endl;
        cout<<"3. Lihat semua antrian"<<endl;
        cout<<"4. Bersihkan antrian"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<"Pilihan: ";
        cin>>pilihan;

        switch(pilihan){
        case 1:{
            if(q.isFull()){
                cout<<"Antrian penuh, tidak dapat menambahkan data baru."<<endl;
            }else{
                string nama, nim;
                cout<<"Masukkan nama mahasiswa: ";
                cin.ignore(); 
                getline(cin, nama);
                cout<<"Masukkan NIM mahasiswa: ";
                cin>>nim;
                q.enqueueAntrian(nama, nim);
            }
            break;
        }
        case 2:
            q.dequeueAntrian();
            break;
        case 3:
            q.viewQueue();
            break;
        case 4:
            q.clearQueue();
            break;
        case 5:
            cout<<"Keluar dari program."<<endl;
            break;
        default:
            cout<<"Pilihan tidak valid."<<endl;
        }
    }while(pilihan != 5);

    return 0;
}
