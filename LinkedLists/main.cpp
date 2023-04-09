#include <iostream>
#include "LinkedList.h"
#include "Test.h"

int main() {
  LinkedList<int>* ll = new LinkedList<int>();

  ll->addBack(10);
  ll->addBack(20);
  ll->addBack(30);
  ll->addBack(40);

  ll->insertSorted(45);

  ll->printList();

  
  return 0;
}