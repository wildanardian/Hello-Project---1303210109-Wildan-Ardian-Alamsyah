#include "hanoi.h"

// BIKIN LIST
void createList(List &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

// BUAT ELEMENT/NODE BARU
adr newElement(infotype x)
{
    adr P = new element;
    infoLL(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

// BUAT NAMBAH DI AKHIR LIST
void insertLast(List &L, adr p)
{
    if (first(L) == NULL)
    {
        first(L) = p;
        last(L) = p;
    }
    else
    {
        next(last(L)) = p;
        last(L) = p;
    }
}
// BUAT NAMBAH DI AWAL LIST
void insertfirst_push(List &L, adr p)
{
    if (first(L) == NULL)
    {
        first(L) = p;
        last(L) = p;
    }
    else
    {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }
}

// BUAT NAMBAH DI ANTARA LIST
void insertAfter(adr prec, adr p)
{
    if (prec != NULL)
    {
        next(p) = next(prec);
        prev(p) = prec;
        next(prec) = p;
        prev(next(p)) = p;
    }
}

// HAPUS DI AWAL LIST
void deletefirst_pop(List &L, adr p)
{
    if (first(L) != NULL)
    {
        if (first(L) == last(L))
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            first(L) = next(first(L));
            prev(first(L)) = NULL;
            next(p) = NULL;
        }
    }
}
// n adalah jumlah inputan
void add(List &L, int n)
{
    infotype x;
    int inputan;
    adr p;
    for (int i = 1; i <= n; i++)
    {
        cout << "input angka : ";
        cin >> inputan;
        x = inputan;
        p = newElement(x);
        insertLast(L, p);
    }
}

// BUAT NAMBAH DATA AGAR OTOMATIS TERURUT
void sortedInsert(List &L, adr p)
{
    adr q = first(L);
    if (first(L) != NULL && infoLL(p) <= infoLL(first(L)))
    {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }
    else if (first(L) != NULL && infoLL(p) > infoLL(first(L)))
    {
        while (q != NULL && infoLL(p) > infoLL(q))
        {
            q = next(q);
        }
        if (q == NULL)
        {
            insertLast(L, p);
        }
        else
        {
            insertAfter(prev(q), p);
        }
    }
    else
    {
        first(L) = p;
        last(L) = p;
    }
}

// BUAT NGURUTIN ISI LIST SECARA DESCENDING
void insertionSort(List &L)
{
    List sorted;
    createList(sorted);
    adr current = first(L);
    while (current != NULL)
    {
        adr p = newElement(infoLL(current));
        sortedInsert(sorted, p);
        current = next(current);
    }
    L = sorted;
}

// MENAMPILKAN ISI LIST
void show(List L)
{
    if (first(L) != NULL)
    {
        adr p = first(L);
        while (p != NULL)
        {
            cout << infoLL(p) << endl;
            p = next(p);
        }
        cout << endl;
    }
    else
    {
        cout << "List Kosong" << endl;
    }
}

// menampilkan menara HANOI
void showalltower(List l1, List l2, List l3)
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "pengecekan jumlah piringan di menara 1 : " << cektower(l1) << endl;
    cout << "pengecekan jumlah piringan di menara 2 : " << cektower(l2) << endl;
    cout << "pengecekan jumlah piringan di menara 3 : " << cektower(l3) << endl;
    cout << "------------------------------------------------------------------" << endl;
    if (first(l1) != NULL)
    {
        cout << "Menara 1 : " << endl;
        adr p = first(l1);
        while (p != NULL)
        {
            cout << infoLL(p) << endl;
            p = next(p);
        }
        cout << endl;
    }
    else
    {
        cout << "menara 1 kosong" << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    if (first(l2) != NULL)
    {
        cout << "Menara 2 : " << endl;
        adr Q = first(l2);
        while (Q != NULL)
        {
            cout << infoLL(Q) << endl;
            Q = next(Q);
        }
        cout << endl;
    }
    else
    {
        cout << "menara 2 kosong" << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    if (first(l3) != NULL)
    {
        cout << "Menara 3 : " << endl;
        adr S = first(l3);
        while (S != NULL)
        {
            cout << infoLL(S) << endl;
            S = next(S);
        }
        cout << endl;
    }
    else
    {
        cout << "menara 3 kosong" << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}

// cek isi tower
int cektower(List L)
{
    adr cek = first(L);
    int count = 0;
    while (cek != NULL)
    {
        count++;
        cek = next(cek);
    }
    return count;
}

void pindahtower2(List &t1, List &t2)
{
    if (first(t1) != NULL)
    {
        adr p = first(t1);
        deletefirst_pop(t1, p);
        insertfirst_push(t2, p);
    }
}

// prosedur pangkat recursive
int pangkat(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * pangkat(a, b - 1);
    }
}

void move(List &L1, List &L2, List &L3, int n)
{
    if (n == 1)
    {
        pindahtower2(L1, L3);
        showalltower(L1, L2, L3);
    }
    else
    {
        move(L1, L3, L2, n - 1);
        pindahtower2(L1, L3);
        showalltower(L1, L2, L3);
        move(L2, L1, L3, n - 1);
    }
}

int menuLL()
{
    cout << "----------------- MENU LINK LIST ---------------" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. Tampilkan Data sebelum sorting" << endl;
    cout << "3. Tampilkan Data sudah ter sorting" << endl;
    cout << "4. menjalankan program menara hanoi" << endl;
    cout << "5. keluar" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Masukkan pilihan : ";
    int pilihan;
    cin >> pilihan;
    return pilihan;
}
