#include <iostream>
#include <string>

using namespace std;

const int kuota=100;

struct dokumen {
    string nama;
    int halaman;
};

struct queue {
    dokumen data[kuota];
    int head;
    int tail;
    int count;
};

void initQueue(queue &q){
    q.head=0;
    q.tail=-1;
    q.count=0;
}

bool isEmpty(queue &q){
    return (q.count==0);
}

bool isFull(queue &q){
    return (q.count==kuota);
}

void tambahData (queue &q, string nama, int halaman){
    if (isFull(q)){
        cout<<"antrian penuh\n";
        return;
    }
    q.tail = (q.tail+1)%kuota;
    q.data[q.tail].nama=nama;
    q.data[q.tail].halaman=halaman;
    q.count++;
}

void kurangData(queue &q){
    if(isEmpty(q)){
    cout<<"antrian kosong\n";
    return;
    }
    cout<<"dokumen"<<q.data[q.head].nama<<q.data[q.head].halaman<<"dipersilahkan masuk\n";
    q.head=(q.head+1)%kuota;
    q.count--;
}

void display(queue &q){
    if(isEmpty(q)){
        cout<<"tidak daftar pekerjaan yang belum selesai\n";
        return;
    }
    cout<<"daftar pekerjaan yang belum selesai\n";
    for(int i=0;i<q.count;i++){
        int idx=(q.head+i)%kuota;
        cout <<" "<<q.data[idx].nama<<q.data[idx].halaman<<"\n";
    }
}

int main(){
    queue antrianParkir;
    initQueue(antrianParkir);

    string inputPlat;
    char pilihan;
    int jumlahHlm;
//INPUT
    cout<<"masukkan 4 dokumen\n";
    for (int i=1;i<=4;i++){
        cout<<"masukkan nama dokumen ke-" << i <<":";
        getline(cin, inputPlat);
        cout<<"masukkan halaman dokumen ke-" << i <<":";
        cin>>jumlahHlm;
        cin.ignore();
        cout<<endl;
    }
//SHOW
    cout<<"tampilkan antrian\n";
    display(antrianParkir);
    cout<<"\n";

//PROSES
    cout<<"proses dua kendaraaan\n";
    cout<<"apakah ingin memproses dua dokumen? y/n\n";
    cin>>pilihan;
    cin.ignore();
    
    if (pilihan=='y'||'Y'){
        kurangData(antrianParkir);
        kurangData(antrianParkir);
    }else{
        cout<<"proses dibatalkan\n";
    }
}