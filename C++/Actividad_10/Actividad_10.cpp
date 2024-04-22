/************************************PRESENTACIÓN***************************************
NOMBRE: Cristhian German Ramirez Ruiz.
FECHA: 18 de Abril de 2024.
PROGRAMA: Actividad_10.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO.
DESCRIPCION: Este programa muestra diferentes opciones para manipular un vector, agregando 
nuevos elementos al final del mismo o eliminandolos. Ademas muestra la sumatoria del valor
de los elementos y un listado de estos. Tambien se puede ordenar el vector de forma ascendente
con los algoritmos Quicksort o burbuja, el usuario elige que algoritmo usar,
una vez que este ordenado, se puede buscar un elemento en el vector, y si este existe, se puede
editar o borrar el elemento.
****************************************************************************************/
#include<iostream> 
#include <windows.h>
using namespace std;
#include "libs/Functions.h"
#include "libs/colors.h"

bool Ordenado = false;

//Funcionprincipal del programa
int main(){
    bool Salir = false;
    bool confirm;
    int opci;
    
    cout << ORANGE << "Bienvenido a suma con vectores c++" << endl;//mensaje de bienvenida
    do{
        opci = menu();
        
        switch (opci)
        {
        case 1:
            
            guardado();
            break;
        case 2:
            agregado();
            Ordenado = false;
            break;
        case 3:
            printList(numero);
            break;
        case 4:
            plusList();
            break;
        case 5:
            if(numero.empty()){
                cerr << RED << "El vector esta vacio, no hay elementos para editar o borrar" << endl;
                
            }else{
                Eleccion = menu2();
                Edicion();
                Ordenado = false;
            }
            break;
        case 6:
            Comfirm_empty();
            Ordenado = false;
            break;
        case 7:
            if(Ordenado == false){
                int n = numero.size();
                Quicksort(numero,0, n-1);
                cout << GREEN << "¡Vector ordenado!" << endl;
                Ordenado = true;
            }else{
                cerr << RED << "El vector ya esta ordenado" << endl;
            }
            break;
        case 8:
            if(Ordenado == false){
                int Burbuja = Confirm_burbja();
                if (Burbuja == 2){
                    Ordenado = true;
                }
                
            }else{
                cerr << RED << "El vector ya esta ordenado" << endl;
            }
            break;
        case 9:
            if(numero.empty()){
                cerr << RED << "El vector esta vacio, favor de ingresar datos en el vector" << endl;
            }else if(Ordenado != true){
                cerr << RED << "El vector no esta ordenado, favor de ordenarlo" << endl;
            }else{
                BusquedaBinaria(numero);
            }
            break;
        case 10:
            confirm = Comfirm_exit();
            if(confirm == true){
                cout << MAGENTA << "Gracias por usar el programa" << endl;
                Sleep(5000);
                Salir = true;
            }
            break;
        default:
            cerr << RED << "Opcion no valida" << endl;
            break;
        }
    }while(!Salir);//Condicion del programa, se ejecutara mientras la opcion de salida sea falsa.
    return 0;//Fin del programa
}