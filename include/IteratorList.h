#ifndef __ITERATOR_LIST__
#define __ITERATOR_LIST__

#include "Iterator.h"
#include "Node.h"

template <typename T>
class IteratorList:public Iterator<T>{
private:
    Node<T> *Cursor;
public:
    IteratorList(Node<T> *);
    bool HasNext()const;
    virtual T Next();
    ~IteratorList();
};

template <typename T>
IteratorList<T>::IteratorList(Node<T> * NODE){
    Cursor = NODE;
}

template <typename T>
bool IteratorList<T>::HasNext()const{
    return(Cursor != nullptr);
}

template <typename T>
T IteratorList<T>::Next(){
    T aux;
    if(HasNext()){
        aux=Cursor->getValue();
        Cursor=Cursor->getNext();
        return aux;
    }
}

template <typename T>
IteratorList<T>::~IteratorList(){}


#endif