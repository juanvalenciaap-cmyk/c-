#include <iostream>
using namespace std;
const int MAX = 10;
void ingresar(int m[MAX][MAX], int f,int c)
{
    for(int i=0; i<f;i++)
    for(int j=0;j<c;j++)
    cin>>m[i][j];
}
void mostrar(int m[MAX][MAX], int f, int c)
{
      for(int i=0; i<f;i++)
      {
        for(int j=0;j<c;j++)
        cout<<m[i][j]<<" ";
        cout<<endl;
      }
}
void sumar (int a[MAX][MAX], int b[MAX][MAX], int r[MAX][MAX], int f, int c)
{
    for(int i=0;i<f;i++)
     for(int j=0;j<c;j++)
    r[i][j] =a[i][j] + b[i][j];
     
}

void resta (int a[MAX][MAX], int b[MAX][MAX], int r[MAX][MAX], int f, int c)
{
    for(int i=0;i<f;i++)
     for(int j=0;j<c;j++)
    r[i][j] =a[i][j] - b[i][j];
     
}

void multiplicar (int a[MAX][MAX], int b[MAX][MAX], int r[MAX][MAX], int f, int c)
{
    for(int i=0;i<f;i++)
     for(int j=0;j<c;j++)
    r[i][j] =a[i][j] * b[i][j];
     
}
