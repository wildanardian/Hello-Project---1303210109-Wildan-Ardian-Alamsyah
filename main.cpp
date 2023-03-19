#include "hanoi.h"
#include "tower.h"

int main()
{
    // array
    hanoi src, temp, dest;
    int pilihan2, nilai, choise, n;

    createStack(src);
    createStack(temp);
    createStack(dest);

    // link list
    int rumus = 2;
    int jumlahtower;
    List tower1;
    createList(tower1);
    List tower2;
    createList(tower2);
    List tower3;
    createList(tower3);

    cout << "Tugas Besar Struktur Data" << endl;
    cout << "program Menara Hanoi" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "nama        : george ibrahim hanif" << endl;
    cout << "nim         : 1303213147" << endl;
    cout << "kelas       : IT 45 03" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "nama        : Wildan Ardian Alamsyah" << endl;
    cout << "nim         : 1303210109" << endl;
    cout << "kelas       : IT 45 03" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << " 1 Hanoi Tower Link list" << endl;
    cout << " 2 Hanoi Tower Array" << endl;
    cout << "masukkan pilihan anda : ";
    cin >> choise;
    while (choise < 3)
    {
        if (choise == 1)
        {
            cout << "hanoi dengan link list" << endl;
            int pilih = menuLL();
            while (pilih < 5)
            {

                switch (pilih)
                {
                case 1:
                {
                    cout << "......................................................................................................................." << endl;
                    cout << "masukan jumlah piringan : ";
                    cin >> jumlahtower;
                    add(tower1, jumlahtower);
                    cout << "......................................................................................................................." << endl;
                    break;
                }
                case 2:
                {
                    cout << "......................................................................................................................." << endl;
                    show(tower1);
                    cout << "......................................................................................................................." << endl;
                    break;
                }
                case 3:
                {
                    cout << "......................................................................................................................." << endl;
                    insertionSort(tower1);
                    show(tower1);
                    cout << "......................................................................................................................." << endl;
                    break;
                }
                case 4:
                {
                    cout << "......................................................................................................................." << endl;
                    int nJMLH = cektower(tower1);
                    cout << "jumlah piringan : " << nJMLH << endl;
                    cout << "jumlah total perpindahan : " << pangkat(rumus, nJMLH) - 1 << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "show all tower sebelum pindah" << endl;
                    showalltower(tower1, tower2, tower3);
                    cout << endl;
                    cout << "show all tower setelah pindah" << endl;
                    move(tower1, tower2, tower3, nJMLH);
                    showalltower(tower1, tower2, tower3);
                    cout << "end program" << endl;
                    cout << "......................................................................................................................." << endl;
                    break;
                }
                default:
                {
                    cout << "......................................................................................................................." << endl;
                    cout << "keluar dari program" << endl;
                    break;
                }
                    cout << "......................................................................................................................." << endl;
                }
                pilih = menuLL();
            }
        }
        else if (choise == 2 && choise != 0)
        {
            // cek
            pilihan2 = menu();
            while (pilihan2 != 0)
            {
                switch (pilihan2)
                {
                case 1:
                    cout << "Masukkan jumlah piringan : ";
                    cin >> n;

                    for (int i = 1; i <= n; i++)
                    {
                        cout << "Masukkan piringan ke-" << i << ": ";
                        cin >> nilai;
                        push(src, nilai);
                    }
                    cout << endl;
                    break;
                case 2:
                    // buat cek apakah tower asal/tower A nya kosong
                    if (!kosong(src))
                    {
                        cout << "Tampilan array sebelum sorting: " << endl;
                        cout << "A: ";
                        printStack(src);
                        cout << "B: ";
                        printStack(temp);
                        cout << "C: ";
                        printStack(dest);
                        cout << endl;
                    }
                    else
                    {
                        cout << "Data tidak tersedia..." << endl;
                    }
                    break;
                case 3:
                    // buat cek apakah tower asal/tower A nya kosong
                    if (!kosong(src))
                    {
                        cout << "Tampilan array sebelum sorting: " << endl;
                        insertionSort(src);
                        cout << "A: ";
                        printStack(src);
                        cout << "B: ";
                        printStack(temp);
                        cout << "C: ";
                        printStack(dest);
                        cout << endl;
                    }
                    else
                    {
                        cout << "Data tidak tersedia..." << endl;
                    }
                    break;
                case 4:
                    // buat cek apakah tower asal/tower A nya kosong, baru bisa eksekusi hanoi nya
                    if (!kosong(src))
                    {
                        cout << "Program Hanoi" << endl;
                        moved(src, temp, dest, n);
                    }
                    else
                    {
                        cout << "Data tidak tersedia..." << endl;
                    }
                    cout << endl;
                    break;
                default:
                    cout << "Pilihan tidak ada" << endl;
                    break;
                }
                pilihan2 = menu();
            }
            // cek
        }
        cout << " 1 Hanoi Tower Link list" << endl;
        cout << " 2 Hanoi Tower Array" << endl;
        cout << "masukkan pilihan anda : ";
        cin >> choise;
    }
    return 0;
}
