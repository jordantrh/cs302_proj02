// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <string>
#include <iostream>

using namespace std;

struct Node {
    std::string string;
    int         number;
    Node       *next;
};

struct List {
    Node       *head;
    size_t      size;

    List(); 					// define in list.cpp
    ~List();					// define in list.cpp

  //    void push_front(const std::string &s);	//define below
  void push_front(const std::string &s);
};

// void push_front definition
void List::push_front(const std::string &s){
    //Creates node
  Node* newNode = new Node;
  newNode->string = s;
  
    //If node is numeric, convert it to integer if possible
    //if not, set to 0 instead
    try
    {
        newNode->number = std::stoi(s);
    }
    catch(std::invalid_argument const& ex)
    {
        newNode->number = 0;
    }
  
    //Set node to head if head in list is set to empty
    //otherwise, set the new node as the head
  if(head == NULL){
    head = newNode;
  }
  else{
      newNode->next = head;
      head = newNode;
  }
  size++;
}

// Functions -------------------------------------------------------------------

bool node_number_compare(const Node *a, const Node *b);
bool node_string_compare(const Node *a, const Node *b);
//Both functions mention above implemented in list.cpp to avoid compile-time issues

// implement in this file (volsort.h) to make it easier for TAs to grade
void dump_node(Node *n){
    cout << "string: " << n->string << "   number: " << n->number << endl;
}			

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation

#endif
