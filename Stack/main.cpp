#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
    Stack<int> *stack = new Stack<int>(10);
    Stack<int> *stack2 = new Stack<int>(10);
    stack->push(10);
    stack->push(20);
    stack->push(30);

    cout << "Size: " << stack->getSize() << endl;
    cout << "Maximum size: " << stack->getMaximumSize() << endl;
    stack->printStack();

    cout << "Element 30 is on index: " << stack->search(10) << endl;
    cout << endl;
    stack->reverse();
    stack->printStack();

    stack2->push(40);
    stack2->push(50);
    stack2->push(60);

    stack->merge(*stack2);

    cout << endl;
    stack->printStack();
}