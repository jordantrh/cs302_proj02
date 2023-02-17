// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

// using namespace std;

void stl_sort(List &l, bool numeric) {
  vector<Node *> nodeVect;
    
  Node* tempN = l.head;
  while(tempN->next != NULL){
      Node* nextN = tempN->next;
      nodeVect.push_back(tempN);
      tempN = nextN;
  }
  nodeVect.push_back(tempN);
  
//   for(unsigned int i = 0; i < nodeVect.size(); i++){
//       cout << "-" << nodeVect[i]->string << endl;
//   }
  
  //std::sort(nodeVect.begin(), nodeVect.end(), node_number_compare);
  
  
  if(numeric){
      std::sort(nodeVect.begin(), nodeVect.end(), node_number_compare);
  }
  else{
      std::sort(nodeVect.begin(), nodeVect.end(), node_string_compare);
  }
  
//   for(unsigned int i = 0; i < nodeVect.size(); i++){
//       cout << "+" << nodeVect[i]->string << endl;
//   }
  
  // l.head = nodeVect[0];
  // l.head->next = NULL;
  // // for (unsigned int i = nodeVect.size() - 1; i > 0; i--){
  // for(unsigned int i = 1; i < nodeVect.size(); i++){
  //     tempN = nodeVect[i];
  //     tempN->next = l.head;
  //     l.head = tempN;
  // }

  l.head = nodeVect[0];
  tempN = l.head;
  for (unsigned int i = 1; i < nodeVect.size(); i++) {
    l.head->next = nodeVect[i];
    l.head = l.head->next;
  }

  l.head->next = NULL;
  l.head = tempN;

  //cout << nodeVect.size() << endl;
  
  //delete tempN;
}