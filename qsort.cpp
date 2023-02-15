// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int node_number_compare(const void * a, const void * b){
    int aVal = (*(const struct Node *)a).number;
    int bVal = (*(const struct Node *)b).number;
    
    return bVal - aVal;
}

int node_string_compare(const void * a, const void * b)
{
   return strcmp(* (char * const *) a, * (char * const *) b);
}

void qsort_sort(List &l, bool numeric) {
  const int listSize = l.size;
  
  vector<Node *> nodeVect;
  
  Node* tempN = new Node();
  tempN = l.head;
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
  l.head->next = NULL;
  for(int i = 1; i < nodeVect.size(); i++){
      tempN = nodeVect[i];
      tempN->next = l.head;
      l.head = tempN;
  }
}

