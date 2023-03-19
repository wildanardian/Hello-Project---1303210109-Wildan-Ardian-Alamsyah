#ifndef HANOI_H_INCLUDED
#define HANOI_H_INCLUDED

#include <iostream>
using namespace std;

#define infoLL(P) (P)->infoLL
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)

typedef int infotype;
typedef struct element *adr;

struct element
{
  infotype infoLL;
  adr next;
  adr prev;
};

struct List
{
  adr first;
  adr last;
};

void createList(List &L);
adr newElement(infotype x);
void insertfirst_push(List &L, adr p);
void insertLast(List &L, adr p);
void insertAfter(adr prec, adr p);
void sortedInsert(List &L, adr p);
void insertionSort(List &L);
void add(List &L, int n);
void show(List L);
void showalltower(List l1, List l2, List l3);
int cektower(List L);
int pangkat(int a, int b);
void move(List &L1, List &L2, List &L3, int n);
void pindahtower2(List &t1, List &t2);
void deletefirst_pop(List &L, adr p);
int menuLL();


#endif // HANOI_H_INCLUDED
