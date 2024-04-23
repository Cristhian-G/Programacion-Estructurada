#include<iostream> 
#include<vector>
#include<string>
#include<numeric>
#include <random>
#include <algorithm>
#include "Verify.h"
#include "colors.h"
using namespace std;
//Declaracion de variables globales y el vector
int respuesta;
bool guardar = false;
size_t Eleccion;
random_device Generate;
mt19937 gen(Generate());
 

vector<int> numero;

int NumRandom(){
    uniform_int_distribution<> dist(0, 200);
    int num = dist(gen);
    return num;
}

//funcion de menu principal
int menu(){
    int eleccion;
    cout << CYAN << "MENU"<<endl;
    cout << GRAY << "1) Ingresar datos" << endl << "2) Ingresar un elemento nuevo" << endl <<"3) Mostrar lista de valores" << endl << "4) Mostrar sumatoria de elementos" << endl;
    cout << GRAY << "5) Borrar o editar algun elemento" << endl << "6) Vaciar arreglo" << endl << "7) Ordenar Arreglo (Quicksort)" <<endl << "8) Ordenar arreglo (Burbuja)" << endl;
    cout << GRAY << "9) Buscar elemento" << endl << "10) Salir" << endl;
    cout << WHITE;

    while(!(cin >> eleccion) || eleccion < 1 || eleccion > 10){
        cerr << RED << "ERROR\nPor favor seleccione una opcion valida"<< endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return eleccion;
}


//fubncion de menu secundario para borrar po modificar un elemento
int menu2(){
    int Eleccion;
    cout << BLUE << "Seleccione el elemento que desea modificar" << endl;
    cout << LBLUE << "Posicion:" << endl;
    cout << WHITE;
    for(size_t i=0 ;i < numero.size() ;i++){
        cout << "Elemento " << i <<  ": " << numero[i] << endl;
    }
    
    while(!(cin >> Eleccion) || (Eleccion < 0 || Eleccion >= numero.size())){
        cerr << RED << "Error\nSeleccione una opcion valida" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Eleccion;
}

//Funcion para editar o elmininar algun elemento del vectos
void Edicion(){
    int del = 0;
    int edit = 0;
    cout << BLUE << "Desea Borrar o Editar este elemento\?\n1) Editar\n2) Borrar" << endl;//Muestra mensaje para seleccionar editar o borrar el elemento del vector
    while(!(cin >> respuesta)||(respuesta < 1 || respuesta > 2)){
        cerr  << RED << "Error\nSeleccione una opcion valida:\n1) Borrar\n2) Editar"<< endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << WHITE;
        cin >> respuesta;
    }
    if(respuesta == 1){//Caso de editar el elemento
        cout << YELLOW << "Seguro que desea Editar este elemento?\n1) Si\n2) No" << endl;//Mensaje para confirmar si desea borrar el elemento
        while(!(cin >> edit)|| (edit < 1 || edit > 2)){
            cerr << RED << "Error\nSeleccione una opcion valida\n1) Si\n2) No" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << WHITE;
            cin >> edit;
        }
        if(edit == 1){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << BLUE << "Ingrese el nuevo elemento" << endl;//Mensaje para ingresar el nuevo elemento
            cout << WHITE;
            numero[Eleccion] =  Verify_int();//Llama la funcion de validacion para guardar para verificar y guardar el nuevo elemento
            cout << GREEN << "Elemento editado" << endl;
        }else{
            cout << YELLOW <<"¡Operación cancelada!" << endl;
        }
    }else if(respuesta == 2){//Caso de borrar el elemento
        cout << YELLOW << "Seguro que desea borrar este elemento?\n1) Si\n2) No" << endl;//Mensaje para confirmar si desea borrar el elemento
        cout << WHITE;
    while(!(cin >> del)|| (del < 1 || del > 2)){
        cerr  << RED << "Error\nSeleccione una opcion valida\n1) Si\n2) No" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> del;
    }
    if(del == 1){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        numero.erase(numero.begin()+Eleccion);
        cout << GREEN<< "Elemento borrado" << endl;
    }else{
        cout << YELLOW <<"¡Operación cancelada!" << endl;
    }
    }
}

//Funcion para ingresar los numeros
int vector_size(){
    int Size = 0;
    if(guardar == false){
        cout << BLUE << "¿Cuantos elementos desea guardar?" << endl;
        cout << YELLOW << "Tenga en cuenta que el limite es de 50 elementos y el minimo 3 elementos" << endl;
        cout << WHITE;
        while(!(std::cin >> Size)|| Size < 3 || Size > 50){
            cerr << RED << "Error, ingrese un tamaño valido"<< endl;
            cout << YELLOW << "Tamaño maximo: 50 elementos\nTamaño minimo: 3 elementos" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return Size;
}

void guardado(int Size){
    if(guardar == false){
        if(Size > 0){
            std::cout << LBLUE << "Ingresar datos" << endl;//Mensaje de ingreso de datos
            cout << WHITE;

            cout << GRAY "Elija una opcion:"<< endl;
            cout << LBLUE<< "1) ingresar manual"<< endl;
            cout << LGREEN << "2) Ingresado automatico " << endl;
            cout << WHITE;
            if(cin.peek() == '\n')cin.ignore();
            while(!(std::cin >> Eleccion) || (Eleccion < 1 || Eleccion > 2)){
                cerr << RED << "Error, seleccione una opcion valida" << endl;
                cin.clear();
                cin.ignore();
            }

            if(Eleccion == 2){
                for(int i = 0; i < Size; i++){
                    numero.push_back(NumRandom());
                }
            }else{
                cout << LBLUE << "Ingrese un numero:" << endl;
                cout << WHITE;
                if(cin.peek() == '\n') cin.ignore();
                numero.push_back(Verify_int());
                guardado(Size -1);
            }
            guardar = true;
        }
        }else{
            cerr << YELLOW << "Los datos ya fueron ingresados" << endl;
        }
    }



//funcion para ingresar los datos de forma dinamica
void agregado(){
    char respuesta;
    while(true){
        cout << BLUE << "Ingrese el nuevo dato:" << endl;
        if(cin.peek() == '\n') cin.ignore();
        cout << WHITE;
        numero.push_back(Verify_int());
        cout << LBLUE << "Desea continuar?" << endl <<"s/n" << endl;
        cout << WHITE;
        if(cin.peek() == '\n') cin.ignore();
        cin >> respuesta;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume el carácter de nueva línea
        if(respuesta == 's' || respuesta=='S'){
            continue;
        }else if(respuesta == 'n' || respuesta=='N'){
            break;
        }
    }
}

 

//fucion para impreimir la lista de datos ingresados
void PrintList(int i){
    if(i < numero.size()){
        cout << numero[i]<< endl;
        i++;
        PrintList(i);
    }
}

//funncion para sumar los datos de la lista de forma dinamica
void plusList(){
    int Resultado = accumulate(numero.begin(), numero.end(), 0);
    cout << GREEN << "La sumatoria de los numeros es : " << WHITE <<Resultado << endl;
}

//funcion para confirmat si el usuario desea borrar la lista de datos ingresados
void Comfirm_empty(){
    int confirm1;
    cout << YELLOW << "Seguro que desea vaciar el vector?\n 1) Si\n 2) No" << endl;
    cout << WHITE;
    cin >> confirm1;
    while(cin.fail()||(confirm1 < 1 && confirm1 > 2)){
        cerr << RED << "Error, por favor intente de nuevo con las opciones 1 o 2" << endl;
        cin.clear();
        cin.ignore();
        cin >> confirm1;
    }

    if(confirm1 == 1){
        numero.clear();
        cout << GREEN << "Vector vaciado con exito" << endl;
        guardar = false;
    }else{
        cout << YELLOW << "Operación cancelada"<< endl;
    }
}

//Funcion para confirmar si el usuario desea salir del programa
bool Comfirm_exit(){
    int comrfirm2;
    cout << YELLOW << "Seguro que desea salir del programa?\n1) Si\n2) No" << endl;
    cout << WHITE;
    cin >> comrfirm2;
    while(cin.fail() || (comrfirm2 < 1 && comrfirm2 > 2)){
        cerr << RED << "Error, Por favor intente de nuevo con las opciones 1 o 2"<< endl;
        cin.clear();
        cin.ignore();
        cin >> comrfirm2;
    }

    if(comrfirm2 == 1){
        return true;
    }else{
        return false;
    }
}

int Particion(vector<int> &numero, int izq, int der){
    int pivot = numero[der];
    int i = (izq - 1);

    for(int j = izq; j <= der - 1; j++){
        if(numero[j] < pivot){
            i++;
            swap(numero[i], numero[j]);
        }
    }

    swap(numero[i + 1], numero[der]);
    return (i + 1);
}

void Quicksort(vector<int> &numero, int izq, int der){
    if(izq < der){
        int pi = Particion(numero, izq, der);
        Quicksort(numero,izq, pi - 1);
        Quicksort(numero, pi + 1, der);
    }
}

void burbuja(vector<int> &numero){
    for(size_t i = 0; i < numero.size(); i++){
        for(size_t j = 0; j < numero.size() - i - 1; j++){
            if(numero[j] > numero[j + 1]){
                int temporal = numero[j];
                numero[j] = numero[j + 1];
                numero[j + 1] = temporal;
            }
        }
    }
}

void BusquedaBinaria(vector<int> &numero){
    int izq = 0;
    int der = numero.size() - 1;

    int medio = (izq + der) / 2;
    int valor = 0;
    bool encontrado = false;

    cout << BLUE << "Ingrese el valor a buscar: ";
    cout << WHITE;
    cin >> valor;
    while(izq <= der){
        if(numero[medio] == valor){
            cout << GREEN << "El valor se encuentra en la posicion: " << WHITE << medio << endl;
            encontrado = true;
            break;
        }else if(numero[medio] > valor){
            der = medio - 1;
        }else{
            izq = medio + 1;
        }
        medio = (izq + der) / 2;
    }

    if(!encontrado){
        cerr << RED << "El valor no se encuentra en el vector." << endl;
    }
}

int Confirm_burbja(){
    int Election;
    cout << YELLOW << "ADVERTENCIA:\nEl ordenamiento de burbuja es mas lento." << endl;
    cout << YELLOW << "Le recomendamos utilizar el ordenamiento \"Quicksort\"" << endl;
    cout << YELLOW << "¿Desea continuar con el procedimiento?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << WHITE;
    while(!(cin >> Election) ||( Election < 1 || Election > 2 )){
        cerr << RED << "Error:\nSeleccione una opcion valida." << endl;
        cin.clear();
        cin.ignore();
        cout << WHITE;
        cin >> Election;
    }

    if(Election == 1){
        burbuja(numero);
        cout << GREEN<< "¡Vector Ordenado!"<<endl;
        return 2;
    }else{
        cout << YELLOW << "¡Procedimiento cancelado!" << endl;
        return -1;
    }
}
