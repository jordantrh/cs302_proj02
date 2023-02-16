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

bool node_number_compare(const Node *a, const Node *b){
  return a->number > b->number;
}

bool node_string_compare(const Node *a, const Node *b){
  return a->string > b->string; 
}
