#include "volsort.h"

//List constructor, sets default values for the head as empty and the size of the list
//as zero
List::List() {
  head = NULL;
  size = 0;
}

//List deconstructor, takes the head of the list and then deletes them until the next
//pointer reches null, then ending by deleting the current node after doing so
List::~List() {
    while(head->next != NULL){
        Node* X = head;
        head = head->next;
        delete X;
    }
    delete head;
}

//Compares nodes by numbers
bool node_number_compare(const Node *a, const Node *b){
  return a->number > b->number;
}

//Compares nodes by string
bool node_string_compare(const Node *a, const Node *b){
  return a->string > b->string; 
}
