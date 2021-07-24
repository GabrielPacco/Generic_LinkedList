#include <iostream>
#include "LinkedList.h"
#include "IteratorList.h"
#include "Iterator.h"

using namespace std;

int main() {

	LinkedList<string> L1;

    L1.addFront("Estas"); 
    L1.addFront("Como"); 
    L1.addFront("Amigo"); 
    L1.addFront("Hola");

    L1.print();

    cout << endl;

    L1.popFront();
    //L1.popBack(); 

    L1.print();
    cout << endl;

    //L1.insertpos("Hello", 1);

    LinkedList<double> list;

    list.addFront(23.45); 
    list.addFront(12.45); 
    list.addFront(64.64); 

    LinkedList<int> L2;

    L2.addFront(2);
    L2.addFront(5);
    L2.addFront(4);
    L2.addFront(24);

    //Llama al constructor de copia, copia los datos de la lista1 a la lista2
	LinkedList<int> L3 = L2;
    cout<<"\nConstruida la lista2 para que sea = a la lista1, los elementos de la lista2 son los siguientes: " << endl;
	
    L3.print();

    //Llama al constructor copy move, mueve los datos de la lista2 a la lista3
    LinkedList<int> L4 = std::move(L2);
    cout << "Construida la lista3 con los recursos movidos de la lista2, los elementos son los siguientes: " << endl;

    L4.print();
    cout << endl;

    //Llama al operador de asignación sobrecargado, copia los datos de list3 a list
	//LinkedList<int> list3 = L2;
    //cout << "\nDatos asignados de la lista3 a la lista, los elementos son los siguientes: " << endl;

    //list3.print();

    //Llama al operador de movimiento de asignación sobrecargado, mueve los recursos de la lista3 a la lista
    //LinkedList<int> list3;
	//list3 = std::move(L2);
    //cout << "Mover los recursos de la L2 a la lista3, los elementos son los siguientes: " << endl;

    //list3.print();

    cout<<endl;
    /*
    //cout<<L1;
    string aux;
    Iterator<string> *it = L1.getIterator();
    while (it->HasNext()){
        aux = it->Next();
        cout<<aux<<endl;
    }
    */
    return 0;
}

