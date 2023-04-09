#pragma once
#include <iostream>
#include <math.h>

using namespace std;

// stack with dynamic resizing
template <class T>
class Stack
{
private:
    T *niz;
    int trbr;
    int size;
    double threshold; // value used for dynamic resizing the stack

    bool thresholdCheck();
    void resizeStack();

public: 
    Stack();
    Stack(int size);
    Stack(int size, double threshold);
    ~Stack();

    // important methods
    void push(T element);
    T pop();
    T peek();
    bool IsEmpty();
    int getSize();
    int getMaximumSize();
    void Clear();
    int search(T element);
    void reverse();
    void merge(Stack &secondStack);
    void printStack();
};

// returns true if we'we reached threshold 
template <class T>
inline bool Stack<T>::thresholdCheck()
{
    if(static_cast<int>(this->size * threshold) <= this->trbr){
        return true;
    }

    return false;
}

template <class T>
inline void Stack<T>::resizeStack()
{
    if(thresholdCheck() == false) return;

    // store stack in temp array
    T* temp = new T[this->trbr];

    for(int i = 0; i < this->trbr; i++){
        temp[i] = this->niz[i];
    }

    // rezise
    this->size *= 2;
    this->niz = new T[this->size]; 

    // refill the original array
    for(int i = 0; i < this->trbr; i++){
        this->niz[i] = temp[i];
    }
}

template <class T>
inline Stack<T>::Stack()
{
    this->trbr = 0;
    this->size = 100;
    this->threshold = 0.8;
    this->niz = new T[100];
}

template <class T>
inline Stack<T>::Stack(int size)
{
    this->trbr = 0;
    this->size = size;
    this->threshold = 0.8;
    this->niz = new T[this->size];
}

template <class T>
inline Stack<T>::Stack(int size, double trehsold) : Stack(size)
{
    this->threshold = threshold;
}

template <class T>
inline Stack<T>::~Stack()
{
    delete[] this->niz;
}

// inserts new element and increses number of elements in stack
// first resizes the stack if needed
template <class T>
inline void Stack<T>::push(T element)
{
    resizeStack();

    this->niz[trbr++] = element;
}

template <class T>
inline T Stack<T>::pop()
{
    if(this->trbr == 0) throw "The stack is empty";
    
    this->trbr--;
    return this->niz[this->trbr + 1];
}

template <class T>
inline T Stack<T>::peek()
{
    return this->niz[this->trbr];
}

template <class T>
inline bool Stack<T>::IsEmpty()
{
    if(this->trbr == 0) return false;

    return true;
}

template <class T>
inline int Stack<T>::getSize()
{
    return this->trbr;
}

template <class T>
inline int Stack<T>::getMaximumSize()
{
    return this->size;
}

template <class T>
inline void Stack<T>::Clear()
{
    this->trbr = 0;
}

// returns index from top of stack
// -1 if element does not exist in stack
template <class T>
inline int Stack<T>::search(T element)
{
    for(int i = 0; i < this->trbr; i++){
        if(this->niz[i] == element){
            return (this->trbr - i) - 1;
        }
    }

    return -1;
}

template <class T>
inline void Stack<T>::reverse()
{
    T pom;
    int trailingIndex;

    for(int i = 0; i < floor(this->trbr / 2); i++){
        trailingIndex = (this->trbr - 1) - i;

        pom = this->niz[i];
        this->niz[i] = this->niz[trailingIndex];
        this->niz[trailingIndex] = pom;
    }
}

template <class T>
inline void Stack<T>::merge(Stack& secondStack)
{
    for(int i = 0; i < secondStack.getSize(); i++){
        Stack::push(secondStack.niz[i]);
    }
}

template <class T>
inline void Stack<T>::printStack()
{
    for(int i = 0; i < this->trbr; i++){
        cout << this->niz[i] << endl;
    }
}
