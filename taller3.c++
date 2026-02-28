#include <iostream>
#include <fstream>
using namespace std;
struct producto{
    string nombre;
    int id,cantidad;
    float precio;
    
};
int main(){
    int opcion,idbuscar,cantidadnueva;
    producto pr;
    bool encontrado;
    do{
        cout << "\nMenú de inventario\n";
        cout <<"1) Agregar un nuevo producto\n";
        cout <<"2) Listar productos almacenados\n";
        cout <<"3) Buscar producto por ID\n";
        cout <<"4) Actualizar cantidad\n";
        cout <<"5) Calcular valor total del inventario\n";
        cout <<"6) Salir\n";
        cin >>opcion;
        if(opcion == 1){
            cout <<"ingrese la ID:";
            cin>> pr.id;
            ifstream leer("inventario.txt");
            encontrado = false;
            int idnuevo=pr.id;
            while(leer>>pr.id>>pr.nombre>>pr.precio>>pr.cantidad){
                if(pr.id==idnuevo){
                    encontrado=true;
                }
                
            }
            leer.close();
            if(encontrado){
                cout <<"esa ID ya existe\n";
            }else{
                cout<<"ingrese el nombre de producto:";
                cin>>pr.nombre;
                cout<<"ingrese el precio de producto:";
                cin>>pr.precio;
                cout<<"ingrese la cantidad;";
                cin>> pr.cantidad;
                ofstream guardar("invetario.txt",ios::app);
                guardar << pr.id<<""
                <<pr.nombre<<""
                <<pr.precio<<""
                <<pr.cantidad<< endl;
                guardar.close();
                cout<<"producto guardado\n";
            }
        }
        if(opcion ==2){
            ifstream leer("inventario.txt");
            while(leer>>pr.id>>pr.nombre>>pr.precio>>pr.cantidad){
                cout<<"ID"<<pr.id<<endl;
                cout<<"Nombre:"<<pr.nombre<<endl;
                cout<<"precio:"<<pr.precio<<endl;
                cout<<"cantidad:"<<pr.cantidad<<endl;
                cout<<"------\n";
        }
        leer.close();


    }
    if(opcion==3){
        cout<<"ingrese la ID que debe buscar:";
        cin>>idbuscar;
        ifstream leer("inventario.txt");
        encontrado=false;
        while(leer>>pr.id>>pr.nombre>>pr.precio>>pr.cantidad){
            if(pr.id==idbuscar){
                cout<<"Nombre:"<<pr.nombre<<endl;
                cout<<"precio:"<<pr.precio<<endl;
                cout<<"cantidad:"<<pr.cantidad<<endl;
                encontrado=true;
            }
    }
    if(!encontrado){
        cout<<"no existe lo que estas buscando\n";
    }
    leer.close();
    
}
if(opcion==4){
    cout<<"ingrese su ID:";
    cin>>idbuscar;
    cout<<"nueva cantidad:";
    cin>>cantidadnueva;
    ifstream leer("inventario,txt");
    ofstream temp("temp.txt");
    while(leer>>pr.id>>pr.nombre>>pr.precio>>pr.cantidad){
        if(pr.id==idbuscar){
            pr.cantidad=cantidadnueva;
        }
        temp <<pr.id<<""
        <<pr.nombre<<""
        <<pr.precio<<""
        <<pr.cantidad<<endl;
}
leer.close();
temp.close();
remove("inventario.txt");
rename("temp,txt","inventario.txt");
cout<<"cantidad actualizada\n";
}
if(opcion==5){
    float total = 0;
    ifstream leer("inventario.txt");
    while(leer>>pr.id>>pr.nombre>>pr.precio>>pr.cantidad){
        total=total+(pr.precio*pr.cantidad);
}
leer.close();
cout <<"total de inventario"<<total<<endl;
}
}while(opcion !=6);
return 0;
}
