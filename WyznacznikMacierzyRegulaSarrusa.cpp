#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main()
{
   int ** A,n,i;

  cout<< "Podaj rozmiar macierzy kwadratowej n x n (max n=7) n = "; cin >> n;
  if (n<=0 || n>7)
    {
        do
        {
           cout <<"liczba nie z tego przedzialu podaj jeszcze raz: ";
           cin >> n;
        } while (n<0 && n>7);

    }


  // tworzymy tablicê wskaŸników

  A = new int * [n];

  // tworzymy kolejne tablice wierszy

  for(i = 0; i < n; i++) A[i] = new int [n];

  // wypelnianie  macierz liczbami z zakresu

   for(int  i = 0; i < n; i++)
   {
       cout<< "Podaj " <<i+1<< " wiersz ";
       for( int j = 0; j < n; j++)
       {

        cin>> A[i][j]; cin.get();
        if (A[i][j]>9 || A[i][j]<0)
        {
           cout <<"Liczba: "<<A[i][j]<<" nie z tego przedzialu podaj wiersz jeszcze raz"<<endl;
            j=n;
            i--;
        }

       }
       cin.clear(); cin.sync();
   }

   cout<<endl;
   cout<<"Podana macierz:"<<endl;
    //wyswietlenie  macierzy
    for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++) cout << A[i][j] << " ";
    cout << endl;
  }
  // obliczanie wyznacznika

int x=0, x2=1, y=0, y2=1;
  for(int i=0;i<n;i++)
  {
    for (int j=0; j<n; j++)
    {
        if ((i+j)>=n)
        {
            x2= x2*A[abs(n-(i+j))][j];
            y2= y2*A[abs(n-(i+j))][(n-1)-j];
        }
        else
        {
            x2=x2*A[i+j][j];
            y2=y2*A[i+j][(n-1)-j];
        }
    }
    x=x+x2;
    y=y+y2;
    x2=1;
    y2=1;
  }

  cout<<endl;
  cout<<"Wyznacznik podanej macierzy o wymiarach "<<n<<"x"<<n<<" wg reguly Sarrusa wynosi detA = "<<x-y;

  // najpierw usuwamy tablice wierszy

  for(i = 0; i < n; i++) delete [] A[i];

  // teraz usuwamy tablicê wskaŸników

  delete [] A;

  return 0;
}
