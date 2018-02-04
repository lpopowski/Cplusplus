#include <iostream>
#include <cstdlib>
using namespace std;
int ile;
int ile2;

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]>v) i++;
        while(tablica[j]<v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j);
    if(i<prawy) quicksort(tablica, i, prawy);
}
int main()
{
    cout << "podaj ilosc liczb do ulozenia (mniej niz 15): ";
    cin >> ile2;
    if (ile2<=0 || ile2>14)
    {
        cout <<"liczba nie z tego przedzialu"<<endl;
        exit (0);
    }
    else ile=ile2;

    int *tablica;
    tablica= new int [ile];

    cout <<"Podaj liczby z przedzialu 0-9: "<<endl;
     for (int i=0; i<ile; i++)
     {
         cout <<endl<<"Podaj " <<i+1 <<" liczbe: ";
         cin >>tablica [i];
        if (tablica [i]>9 || tablica[i]<0)
        {
           cout <<"Liczba nie z tego przedzialu sprobuj od nowa!"<<endl;
           exit (0);
        }
     }
    quicksort(tablica, 0, ile-1);

    int liczba=0;

    for (int i=0; i<ile; i++)
    {
        liczba=liczba*10 + tablica[i];
    }
     cout << "Najwieksza mozliwa liczba wynosi: " <<liczba;
    delete [] tablica;
    return 0;
}
