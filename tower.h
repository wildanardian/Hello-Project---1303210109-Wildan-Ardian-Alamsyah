#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED

#include <iostream>
using namespace std;

#define top(S) S.top
#define info(S) S.info

struct hanoi
{
    int info[10];
    int top;
};

void createStack(hanoi &H);
bool kosong(hanoi H);
bool penuh(hanoi H);
void push(hanoi &H, int x);
void pop(hanoi &H, int &x);
void printStack(hanoi H);
void moved(hanoi &A, hanoi &B, hanoi &C, int n);
void insertionSort(hanoi &H);
int menu();

#endif // TOWER_H_INCLUDED
