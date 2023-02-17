// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int node_number_compare(const void * a, const void * b){
    int aVal = (*(const Node **)a)->number;
    int bVal = (*(const Node **)b)->number;
    
    return aVal - bVal;
}

int node_string_compare(const void * a, const void * b)
{
    return ((*(const Node **)a)->string).compare((*(const Node **)b)->string);
}

void qsort_sort(List &l, bool numeric) {
  const int listSize = l.size;
  
  vector<Node *> nodeVect;
  
  Node* tempN = l.head;
  while(tempN->next != NULL){
      Node* nextN = tempN->next;
      nodeVect.push_back(tempN);
      tempN = nextN;
  }
  nodeVect.push_back(tempN);
  
  if(numeric){
      std::qsort(&nodeVect[0], listSize, sizeof(Node *), node_number_compare);
  }
  else{
      std::qsort(&nodeVect[0], listSize, sizeof(Node *), node_string_compare);
  }
  
  l.head = nodeVect[0];
  tempN = l.head;
  for (unsigned int i = 1; i < nodeVect.size(); i++) {
    l.head->next = nodeVect[i];
    l.head = l.head->next;
  }

  l.head->next = NULL;
  l.head = tempN;
  
}