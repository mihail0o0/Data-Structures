#include <iostream>

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
public:
    Node();
    Node(T data);
    ~Node();

};

template <class T>
Node<T>::Node()
{

}

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
}

template <class T>
Node<T>::~Node()
{
    
}
