// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

// using namespace std;

//STL sort function
void stl_sort(List &l, bool numeric) {
  //Set vector up for sorting
  vector<Node *> nodeVect;
    
  //Put nodes in vector
  Node* tempN = l.head;
  while(tempN->next != NULL){
      Node* nextN = tempN->next;
      nodeVect.push_back(tempN);
      tempN = nextN;
  }
  nodeVect.push_back(tempN);
  
  //Sort vector backed on if numeric or not
  if(numeric){
      std::sort(nodeVect.begin(), nodeVect.end(), node_number_compare);
  }
  else{
      std::sort(nodeVect.begin(), nodeVect.end(), node_string_compare);
  }

  //Place nodes back in list after sorting
  l.head = nodeVect[0];
  tempN = l.head;
  for (unsigned int i = 1; i < nodeVect.size(); i++) {
    l.head->next = nodeVect[i];
    l.head = l.head->next;
  }

  l.head->next = NULL;
  l.head = tempN;
}
