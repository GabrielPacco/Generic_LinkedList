#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include <iostream>
#include "Node.h"
#include "IteratorList.h"
using namespace std;

template <typename T>
class LinkedList
{
private:
    int size;
    Node<T>* head;
public:

    LinkedList();
    LinkedList(int, Node<T>*);

    void add_front(T);
    void add_back(T);
    void insertpos(T, int);
	void popFront();          // borra el nodo cabeza y nombra su nodo 'next' como nueva cabeza
	void popBack(); 
    void remove(int);
    void print();
	virtual Iterator<T> *getIterator();

    ~LinkedList();

    // copy constructor
	LinkedList(LinkedList<T>& source);
	// copy move constructor
	LinkedList(LinkedList<T>&& source);
	// operador de asignación sobrecargado para el tipo de lista
	LinkedList<T>& operator=(LinkedList<T>& source);
	// operador de movimiento de asignación sobrecargado para el tipo de lista
	LinkedList<T>& operator=(LinkedList<T>&& source);

    int count();
    void outputAll();

    // devuelve el elemento del nodo principal
	T& front() const;
	// devuelve true si la lista está vacía
	bool empty() const;
	// añade un nuevo nodo al frente de la lista con el elemento 'e' como dato
	const T& addFront(const T& ele);
};


template <typename T>
LinkedList<T>::LinkedList():head (nullptr){
    size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(int size_, Node<T>* head_){
    this->head = head_;
    this->size = size_;
}

template <typename T>
void LinkedList<T>::add_front(T value){
    head = new Node<T>(value, head);
    size++;
}

template <typename T>
void LinkedList<T>::add_back(T value){
    Node<T> *aux = head;
    Node<T> *act;
    if(aux==nullptr){
        add_front(value);
    }
    else{
        while (aux->getNext() != nullptr){
            aux = aux->getNext();
        }
        act = new Node<T>(value, nullptr);
        aux->setNext(act);
    }
    ++size;
}

template<typename T>
void LinkedList<T>::insertpos(T value,int pos){
    if(pos<size+1){
        Node<T> *newNode= new Node<T>(value);
        Node<T> *tmp =head;
        for (int i=0;i<=pos-2;i++){
            tmp=tmp->getNext();
        }
        newNode -> setNext(tmp->getNext() ); 
        tmp->setNext(newNode);
    }
    else{
        cout<<"No";
    }
    size++;
}
// Elimina el nodo actual 'head' y luego hace que el nodo 'head' apunte al
// siguiente nodo de la lista. 
template <typename T>
void LinkedList<T>::popFront()
{
	if (empty()){
		cout<<"La lista esta vacia"<<endl;
	}
	Node<T>* actual = head;
	head = head->next;
	delete actual;
    size++;
}
template<typename T>
void LinkedList<T>::popBack(){
    int tam=size-1;
        Node<T> *aux, *act=head;
        if (tam!=0){
            int i=0;
            while(i<tam){
                aux = act; act = act->getNext();
                i++;
            }
            aux -> setNext() = act->getNext(); 
                act = nullptr;
                delete act;
        }
        else{
            head = head -> getNext(); 
                act = nullptr;
                delete act;
        }
        size--;
}

template <typename T>
void LinkedList<T>::remove(int pos){
    Node<T> *aux = head;
    Node<T> *aux2;
    int i=1;
    if(aux != nullptr){
        if(pos == 1){
            head = aux->getNext();
        }
        else{
            while (i < pos && aux->getNext() != nullptr){
                aux2 = aux;
                aux = aux->getNext();
                i++;
            }
            aux2->setNext(aux->getNext());
        }
        delete aux;
    }
    size--;
}
// Recorre la lista e imprime cada elemento del nodo.
template <typename T>
void LinkedList<T>::print()
{
	Node<T>* tmp = head;
	while (tmp != nullptr)
	{
		std::cout << tmp->value << std::endl;
		tmp = tmp->next;
	}
}

//Crea un nodo que Itera la lista enlazada
template <typename T>
Iterator<T>* LinkedList<T>::getIterator(){
    return new IteratorList<T>(head);
}
// destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	while (!empty())
		popFront();
}

// El constructor de copia toma otra lista como parámetro 'source' entonces
// recorre cada nodo y utiliza la función 'addFront(const T& e)' para reconstruir
// una nueva lista con los datos copiados.
//
// Ejemplo de llamada a este constructor:
// LinkedList<int> list1 = list;
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>& source)
{
	Node<T>* temp = source.head;
	for (int i = 0; i < source.count()-1; i++)
	{
		temp = temp->next;		
	}
	for (int a = source.count()-1; a > 0; a--)
	{
		temp = source.head;
		for (int i = 0; i < a; i++)
		{
			temp = temp->next;
		}
		addFront(temp->value);
	}
	addFront(source.head->value);
}

// Copiar Mover El constructor toma una lista Rvalue como parámetro 'source' entonces
// libera los recursos de 'esta' lista llamando a su destructor (asegura que no hay
// no hay punteros colgantes). A continuación, rellena el nodo 'head' con la dirección de 
// el nodo cabeza de la lista 'fuente', con lo que "mueve" sus recursos.
//
// Ejemplo de llamada a este constructor:
// LinkedList<int> list1 = std::move(list);
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& source)
{
	this->~LinkedList();
	head = source.head;
}

// El Operador de Asignación sobrecargado toma otra lista como parámetro 'source' y
// devuelve una referencia a 'this' lista (para operaciones list=list1=list2).
// La asignación se realiza comprobando primero qué lista tiene mayor tamaño,
// si la lista original contiene más elementos se recorta al tamaño de la lista 'source'
// de origen. Si la lista 'source' es mayor se añaden elementos a la lista original. A continuación, 
// la lista original se sobrescribe con los datos de la lista de origen.
//
// this es una copia no destructiva que deja la lista original intacta, para copias grandes no es
// no es preferible (ver operador de asignación de movimiento sobrecargado).
//
// Ejemplo de llamada a este operador sobrecargado:
// lista1 = lista;
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& source)
{
	if (this == &source)
		return *this;

	Node<T>* tempThis = head;
	Node<T>* tempSource = source.head;

	int diff = this->count() - source.count();

	if (diff > 0)
	{
		for (int i = 0; i < diff; i++)
		{
			this->popFront();
		}
	}
	tempThis = head;

	for (int i = 0; i < source.count(); i++)
	{
		if ((tempThis->next == nullptr) && (i != source.count() - 1))
		{
			Node<T>* newNode = new Node<T>;
			tempThis->next = newNode;
			newNode->next = nullptr;
		}
		tempThis->value = tempSource->getValue();
		tempThis = tempThis->next;
		tempSource = tempSource->next;
	}
	return *this;
}

// El Operador de Asignación de Movimientos sobrecargado toma una lista Rvalue como parámetro 'source'
// y devuelve una ref a 'this' lista (para operaciones list=std::move(list1)=std::move(list2)).
// El movimiento se realiza liberando los recursos a la lista original y reinstalando
// su nodo 'head' como el nodo 'head' de la lista 'source'.
//
// Esto ES un movimiento destructivo ya que ahora tanto la lista original como la lista 'source' están apuntando
// a la misma memoria, es decir, los datos no se copian, los recursos se mueven.
//
// Ejemplo de llamada a este operador sobrecargado:
// list1 = std::move(list);
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& source)
{
	if (this == &source)
		return *this;

	this->~LinkedList();
	head = source.head;

	return *this;
}

// Devuelve true si la lista está vacía.
template <typename T>
bool LinkedList<T>::empty() const
{
	return head == nullptr;
}

// Añade un nuevo nodo a la lista y almacena el parámetro 'ele' como su 'elem'.
//
// Se realiza cambiando su puntero 'next' para que apunte al nodo actual 
// el nodo 'head' actual, y luego cambiando el puntero 'head' para que apunte a este nodo.
template <typename T>
const T& LinkedList<T>::addFront(const T& ele)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = ele;
	newNode->next = head;
	head = newNode;
	return ele;
    size++;
}

// Se recorre la lista para contar cada elemento y luego se devuelve
// la cantidad.
template <typename T>
int LinkedList<T>::count()
{
	Node<T>* temp = head;
	int count = 0;
	while (temp != nullptr)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

#endif