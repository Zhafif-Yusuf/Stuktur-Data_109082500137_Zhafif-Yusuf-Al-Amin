#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;
const int MAX = 10;

typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(addresss &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack); 
void update(stack &listStack, int posisi);
void view(stack &listStack);
void searchData(stack listStack, int data);
#endif