#pragma once
#include <iostream>

using namespace std;

// stack with dynamic resizing, 
template <class T>
class Stack
{
private:
    T *niz;
    int trbr;
    int size;
    double 

public:
    Stack();
    Stack(int size);
    ~Stack();

    // important methods
    void Push(T element);
    T Pop();
    T Peek();
    bool IsEmpty();
    int Size();
    void Clear();
    int Search(T element);
    Stack Copy();
    void Reverse();
    void Merge(Stack& secondStack);
};

template <class T>
inline Stack<T>::Stack()
{
    this->trbr = 0;
    this->size = 100;
    this->niz = new T[100];
}

template <class T>
inline Stack<T>::Stack(int size)
{
    this->trbr = 0;
    this->size = size;
    this->niz = new T[this->size];
}

template <class T>
inline Stack<T>::~Stack()
{
    delete[] this->niz;
}

// inserts new element and increses number of elements in stack
template <class T>
inline void Stack<T>::Push(T element)
{
    this->niz[trbr++] = element;
}
