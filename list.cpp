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

  //   try
  //   {
  //       newNode->number = std::stoi(s);
  //   }
  //   catch(std::invalid_argument const& ex)
  //   {
  //       newNode->number = 0;
  //   }
  
  // if(head == NULL){
  //   head = newNode;
  // }
  // else{
  //     newNode->next = head;
  //     head = newNode;
  // }
  // size++;
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

// // implement in this file (volsort.h) to make it easier for TAs to grade
// void dump_node(Node *n){
//   Node* temp = head;
//   while (temp->next != NULL) {
//     cout << "string: " << temp->string "   number: " << temp->number << endl;
//     temp = temp->next;
//   }
// }	