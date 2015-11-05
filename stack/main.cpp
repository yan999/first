#include <iostream>
#include <stdlib.h>
#include <conio.h>
//#include <windows.h>
#include "list.h"
using namespace std;

int main()
{
    stack S1,S2,S3;
    int n, inp;
    bool win = false;
    createStack(&S1);
    createStack(&S2);
    createStack(&S3);
    while (inp!=3){
        system("cls");
        cout << "The Tower of Hanoi\nPindahkan semua cakram dari Tower 1 ke Tower 2" << endl;
        cout << "MENU"<<endl;
        cout<< "1. Restart Game"<<endl;
        cout<< "2. Pindah Cakram"<<endl;
        cout<< "3. Keluar"<<endl;
        cout<< "Input: "<<endl;
        cin >> inp;
            if(inp==1)
                {createStack(&S1); createStack(&S2); createStack(&S3);
                    cout << "Masukkan Jumlah Cakram: ";cin >> n; createHanoi(&S1,n);
                    cout<<"\nT1\n"; printInfo(&S1); cout<<"\nT2\n"; printInfo(&S2); cout<<"\nT3\n"; printInfo(&S3);
                    cout << "Press any key to continue"; _getche();}
            else if(inp==2)
                {int a,b; cout << "Tower Asal: "; cin >> a; bool x;
                    cout << "Tower Tujuan: "; cin >> b;
                    if (a == 1){
                        if (b == 2)
                            x = Move(&S1,&S2);
                        else if (b == 3)
                            x = Move (&S1,&S3);
                        else
                            x = false;
                    }
                    else if (a == 2){
                        if (b == 1)
                            x = Move(&S2,&S1);
                        else if (b == 3)
                            x = Move (&S2,&S3);
                        else
                            x = false;
                    }
                    else if (a == 3){
                        if (b == 1)
                            x = Move(&S3,&S1);
                        else if (b == 2)
                            x = Move (&S3,&S2);
                        else
                            x = false;
                    }
                    else
                        x = false;
                    //Cek pindah
                    if (x)
                        cout << "Cakram Sudah dipindah" << endl;
                    else
                        cout << "Tidak bisa!!!" << endl;
                    //Cek complete
                    win = isComplete(&S2,n);
                    if (win)
                        cout << "Anda Menang!";
                    cout<<"\nT1\n"; printInfo(&S1); cout<<"\nT2\n"; printInfo(&S2); cout<<"\nT3\n"; printInfo(&S3);
                    cout << "Press any key to continue"; _getche();}

        }

    return 0;
}
