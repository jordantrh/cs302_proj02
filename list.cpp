#include "volsort.h"

using namespace std;

List::List() {
  head = NULL;
  size = 0;
}

List::~List() {
  Node *x = head;
  Node *temp;

    while(x != NULL){
        //Node* X = head;
        temp = x->next;
        delete x;
        x = temp;
    }
}

// void push_front definition
void List::push_front(const std::string &s){
  Node* newNode = new Node();
  //newNode->string = s;
  //newNode->number = std::stoi(s);
  
  if (head == NULL) {
    size = 1;
  }

  else {
    size++;
    newNode->next = head;
  }
  

  head = newNode;

  head->string = s;
  head->number = std::stoi(s);


}
// Functions -------------------------------------------------------------------

//implement in this file (volsort.h), used by quick, merge and stl
bool node_number_compare(const Node *a, const Node *b){
  return a->number < b->number;
}

//implement in this file (volsort.h), used by quick, merge and stl
bool node_string_compare(const Node *a, const Node *b){
  return a->string < b->string; 
}

