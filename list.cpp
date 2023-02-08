#include "volsort.h"

List::List() {
  head = NULL;
  size = 0;
}

List::~List() {
  while (head != NULL)
    {
        Node* tmpNode = head;
        delete head;
        head = tmpNode;
    }
}
