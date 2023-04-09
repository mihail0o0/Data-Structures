#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class LinkedList
{
private:
    int size;
    Node<T> *head;

public:
    LinkedList();
    ~LinkedList();

    // za dodavanje
    void addFront(T data);
    void addBack(T data);
    void addMiddle(T data, Node<T> *node);
    void addMiddleToPosition(T data, int position);
    void addMiddleAfterValue(T data, T value);

    // za brisanje
    void removeFront();
    void removeBack();
    void removeAfter(Node<T> *position);
    void removeAfterPosition(int position);
    void removeAfterValue(T value);

    // dodatne funkcije
    void moveForward(T el);
    void insertSorted(int el);

    // helper functions
    void clear();
    void incSize();
    void decSize();
    bool isEmpty();
    int getSize();

    // za stampu
    void printList();
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    // clear();
}

template <class T>
inline void LinkedList<T>::addFront(T data)
{
    Node<T> *newNode = new Node<T>(data);

    if (this->head == nullptr)
    {
        head = newNode;
        incSize();
        return;
    }

    newNode->next = head;
    head = newNode;
    incSize();
}

template <class T>
inline void LinkedList<T>::addBack(T data)
{
    Node<T> *newNode = new Node<T>(data);

    if (this->head == nullptr)
    {
        this->head = newNode;
        incSize();
        return;
    }

    Node<T> *inode;
    for (inode = head; inode->next != nullptr; inode = inode->next)
        ;

    inode->next = newNode;
    incSize();
}

template <class T>
inline void LinkedList<T>::addMiddle(T data, Node<T> *node)
{
    Node<T> *newNode = new Node<T>(data);

    if (node == nullptr)
    {
        head = newNode;
        incSize();
        return;
    }

    newNode->next = node->next;
    node->next = newNode;
    incSize();
}

template <class T>
inline void LinkedList<T>::addMiddleToPosition(T data, int position)
{
    if (this->size <= position || position < 0)
    {
        cout << "Invalidna pozicija" << endl;
        return;
    }

    Node<T> *inode = head;
    while (position != 0)
    {
        inode = inode->next;
        position--;
    }

    addMiddle(data, inode);
}

template <class T>
inline void LinkedList<T>::addMiddleAfterValue(T data, T value)
{
    Node<T> *inode = head;
    while (inode->data != value && inode != nullptr)
    {
        inode = inode->next;
    }

    if (inode == nullptr)
    {
        cout << "Nema elementa sa vrednoscu" << value << endl;
        return;
    }

    addMiddle(data, inode);
}

template <class T>
inline void LinkedList<T>::removeFront()
{
    if (this->head == nullptr)
    {
        return;
    }

    if (this->head->next == nullptr)
    {
        Node<T>* temp = this->head;
        this->head = nullptr;
        delete temp;

        decSize();
        return;
    }

    Node<T>* temp = this->head;
    head = head->next;
    delete temp;
    decSize();
}

template <class T>
inline void LinkedList<T>::removeBack()
{
    if (this->head == nullptr)
    {
        return;
    }

    if (this->head->next == nullptr)
    {
        Node<T>* temp = this->head;
        this->head = nullptr;
        delete temp;

        decSize();
        return;
    }

    Node<T> *pnode = head;
    Node<T> *inode = pnode->next;

    while (inode->next != nullptr)
    {
        pnode = inode;
        inode = pnode->next;
    }

    
    pnode->next = nullptr;
    delete inode;
    decSize();
}

template <class T>
inline void LinkedList<T>::removeAfter(Node<T> *position)
{
    if (this->head == nullptr || this->head->next == nullptr)
    {
        return;
    }

    Node<T> *toRemove = position->next;

    if(position->next == nullptr){
        return;
    }

    position->next = toRemove->next;
    toRemove->next = nullptr;
    delete toRemove;
    
    decSize();
}

template <class T>
inline void LinkedList<T>::removeAfterPosition(int position)
{
    if (position >= this->size - 1 || position < 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node<T> *inode = head;

    while (position != 0)
    {
        inode = inode->next;
        position--;
    }

    removeAfter(inode);
}

template <class T>
inline void LinkedList<T>::removeAfterValue(T value)
{
    Node<T> *inode = head;

    while (inode != nullptr && inode->data != value)
    {
        inode = inode->next;
    }

    if (inode != nullptr)
    {
        removeAfter(inode);
        return;
    }

    cout << "Nema takve vrednosti" << endl;
}

// prvo pojavljivanje, info = el, pomera za jedno mesto prema glavi
template <class T>
inline void LinkedList<T>::moveForward(T el)
{
    // ako je lista prazna
    if(this->head == nullptr){
        return;
    }

    // ako je trazeni element head
    if(this->head->data == el){
        return;
    }

    if(this->head->next->data == el){
        Node<T>* inode = this->head->next;

        this->head->next = inode->next;
        inode->next = this->head;
        head = inode;

        return;
    }

    Node<T>* inode = this->head;
    Node<T>* jnode = this->head;
    Node<T>* knode = this->head;

    while(inode != nullptr){
        if(inode->data == el){
            knode->next = inode;
            jnode->next = inode->next;
            inode->next = jnode;
            return;
        }

        knode = jnode;
        jnode = inode;
        inode = inode->next;
    }

}


template <class T>
inline void LinkedList<T>::insertSorted(int el)
{
    Node* newNode = new Node<(el);
    // ako je prazna
    if(this->head == nullptr){
        return;
    }

    if(this->head->data > el){
        newNode->next = this->head;
        this->head = newNode;
        return;
    }

    Node* iNode = this->head;
    Node* lNode = this->head;

    // opsti slucaj
    while(iNode != nullptr){
        if(iNode->data > el){
            newNode->next = iNode;
            lNode->next = newNode;
            return;
        }
        
        lNode = iNode;
        iNode = iNode->next;
    }

    // nije pronadjen ( stavi na kraj )
    lNode->next = newNode;


}

template <class T>
inline void LinkedList<T>::clear()
{
    Node<T>* inode = head;

    this->head = nullptr;


    while(inode != nullptr){
        Node<T>* temp = inode;
        inode = inode->next;

        delete temp;
    }

    this->size = 0;

}

template <class T>
inline bool LinkedList<T>::isEmpty()
{
    if(this->head == nullptr){
        return false;
    }

    return true;
}

template <class T>
inline int LinkedList<T>::getSize()
{
    return this->size;
}

template <class T>
inline void LinkedList<T>::incSize()
{
    this->size++;
}

template <class T>
inline void LinkedList<T>::decSize()
{
    this->size--;
}

template <class T>
inline void LinkedList<T>::printList()
{
    for (Node<T> *inode = head; inode != nullptr; inode = inode->next)
    {
        cout << inode->data << endl;
    }
}