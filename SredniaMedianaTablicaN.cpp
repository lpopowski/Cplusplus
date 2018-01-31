#include <iostream>
#include <cstdlib>
using namespace std;
int ile;
float mediana;

void quicksort(float *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
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

float srednia(float *tab, int ile) //dynamiczne rezerwowanie pamiêci (tyle ile poda u¿ytkownik)
{
    float suma=0;
    for (int i=0; i<ile; i++)
    {
        suma+=*tab;
        tab++;
    }
    return suma/ile;
}
int main()
{

    cout << "Ile liczb w tablicy: ";
    if (!(cin >> ile)) //zabezpieczenie przed wpisaniem tekstu
    {
        cerr <<"To nie jest liczba!";
        exit (0);
    }
    float *tablica;
    tablica = new float [ile];

     cout <<"Podaj liczby: ";
     for (int i=0; i<ile; i++)
     {
         cout <<endl<<"Podaj " <<i+1 <<" liczbe : ";
        if (!(cin >>tablica [i])) //zabezpieczenie przed wpisaniem tekstu
        {
            cerr <<"To nie jest liczba, sproboj jeszcze raz!";
            exit (0);
        }
     }

    cout<<"Srednia wynosi: "<<srednia(tablica, ile)<<endl;

    quicksort(tablica, 0, ile-1);

    if (ile%2 == 0)
        {
            mediana = tablica[(ile-1)/2]+tablica[ile/2];
            mediana = mediana/2;
        }
        else
        {
            mediana = tablica [ile/2];
        }
    cout << "Mediana wynosi: " << mediana << endl;
    delete [] tablica;
    return 0;
}

