#include "tower.h"

void createStack(hanoi &H)
{
    top(H) = -1;
}

bool kosong(hanoi H)
{
    return top(H) == -1;
}

bool penuh(hanoi H)
{
    return top(H) == 9;
}

void push(hanoi &H, int x)
{
    if (penuh(H))
        cout << "Tower penuh" << endl;
    else
    {
        top(H)++;
        info(H)[top(H)] = x;
    }
}

void pop(hanoi &H, int &x)
{
    if (kosong(H))
        cout << "Tower kosong" << endl;
    else
    {
        x = info(H)[top(H)];
        top(H)--;
    }
}

void printStack(hanoi H)
{
    if (kosong(H))
        cout << "Tower kosong" << endl;
    else
    {
        for (int i = top(H); i >= 0; i--)
        {
            cout << info(H)[i] << " ";
        }
        cout << endl;
    }
}

void moved(hanoi &A, hanoi &B, hanoi &C, int n)
{
    if (n == 1)
    {
        int x;
        pop(A, x);
        push(C, x);
        cout << "A: ";
        printStack(A);
        cout << "B: ";
        printStack(B);
        cout << "C: ";
        printStack(C);
        cout << endl;
    }
    else
    {
        moved(A, C, B, n - 1);
        moved(A, B, C, 1);
        moved(B, A, C, n - 1);
    }
}

void insertionSort(hanoi &H)
{
    int n = top(H) + 1;
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = H.info[i];
        j = i - 1;
        while (temp < H.info[j] && j >= 0)
        {
            H.info[j + 1] = H.info[j];
            j--;
        }
        H.info[j + 1] = temp;
    }
}

int menu()
{
    int pilihan;
    cout << "----------------- MENU LINK LIST ---------------" << endl;
    cout << "1. Input data" << endl;
    cout << "2. Sebelum Sorting" << endl;
    cout << "3. Sesudah Sorting" << endl;
    cout << "4. Jalankan Hanoi" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan: ";
    cout << "--------------------------------------------------" << endl;
    cin >> pilihan;
    return pilihan;
}
