#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node
{
private:
    
public:
    T value;
    Node *next;
    Node();
    Node(T, Node*);
    void setValue(T);
    void setNext(Node *);
    T getValue();
    Node*getNext();

    ~Node() = default;
};

template <typename T>
Node<T>::Node(){
    value = {};
    next = nullptr;
}

template <typename T>
Node<T>::Node(T value_, Node *next_){
    value = value_;
    next = next_;
}

template <typename T>
void Node<T>::setValue(T value_){
    value = value_;
}

template <typename T>
void Node<T>::setNext(Node *next_){
    next = next_;
}

template <typename T>
T Node<T>::getValue() {
    return value;
}

template <typename T>
Node<T>* Node<T>::getNext(){
    return next;
}

#endif