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
int main()
{
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    int filas, columnas, opcion;

    cout << "Filas y columnas: ";
    cin >> filas >> columnas;

    cout << "Matriz A:\n";
    ingresar(A, filas, columnas);

    cout << "Matriz B:\n";
    ingresar(B, filas, columnas);

    cout << "\n1. Sumar\n2. Restar\n3. Multiplicar\nOpcion: ";
    cin >> opcion;

    switch(opcion)
    {
        case 1:
            sumar(A, B, R, filas, columnas);
            cout << "\nResultado suma:\n";
            break;
        case 2:
            resta(A, B, R, filas, columnas);
            cout << "\nResultado resta:\n";
            break;
        case 3:
            multiplicar(A, B, R, filas, columnas);
            cout << "\nResultado multiplicacion:\n";
            break;
        default:
            cout << "Opcion invalida";
            return 0;
    }

    mostrar(R, filas, columnas);

    return 0;
}
