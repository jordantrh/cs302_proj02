#include "volsort.h"

List::List() {
  head = NULL;
  size = 0;
}

List::~List() {
    while(head->next != NULL){
        Node* X = head;
        //cout << X->string << endl;
        head = head->next;
        delete X;
    }
    delete head;
}
