#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "Gilar ");
    enQueue(Q, "Aflah ");
    enQueue(Q, "Aedil ");
    enQueue(Q, "Fathir ");
    enQueue(Q, "Kevin ");
    enQueue(Q, "Zulfa ");
    cout<<endl;

    cout<<"--isi Queue Setelah enQueue---"<<endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout<<endl;

    cout<<"--Isi Queue Setelah deQueue--"<<endl;
    viewQueue(Q);

    clearQueue;
    return 0;
    
}