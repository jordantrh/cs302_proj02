// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

void stl_sort(List &l, bool numeric) {
  vector<Node *> nodeVect;
    
  Node* tempN = new Node();
  tempN = temp.head;
  while(tempN->next != NULL){
      Node* nextN = tempN->next;
      nodeVect.push_back(tempN);
      tempN = nextN;
  }
  nodeVect.push_back(tempN);
  
  for(int i = 0; i < nodeVect.size(); i++){
      cout << "-" << nodeVect[i]->string << endl;
  }
  
  //std::sort(nodeVect.begin(), nodeVect.end(), node_number_compare);
  
  
  if(numeric){
      std::sort(nodeVect.begin(), nodeVect.end(), node_number_compare);
  }
  else{
      std::sort(nodeVect.begin(), nodeVect.end(), node_string_compare);
  }
  
  for(int i = 0; i < nodeVect.size(); i++){
      cout << "+" << nodeVect[i]->string << endl;
  }
  
  temp.head = nodeVect[0];
  temp.head->next = NULL;
  for(int i = 1; i < nodeVect.size(); i++){
      tempN = nodeVect[i];
      tempN->next = temp.head;
      temp.head = tempN;
  }
  //cout << nodeVect.size() << endl;
  
  //delete tempN;
}

