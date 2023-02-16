// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
//#include "list.cpp"

// using namespace std;
// int main() {
void stl_sort(List &l, bool numeric) {

    // bool numeric = true;
    // List l; 
    // l.push_front("2");
    // l.push_front("22");
    // l.push_front("3");
    // l.push_front("45");
    // l.push_front("4");

    vector<Node *> nodeVect;
   
    Node* tempN = l.head;
  //tempN = temp.head;
    while(tempN != NULL){
        //Node* nextN = tempN->next;
        nodeVect.push_back(tempN);
        tempN = tempN->next;
    }
 // nodeVect.push_back(tempN);
//     for(unsigned int i = 0; i < nodeVect.size(); i++){
//       cout << nodeVect[i]->string << endl;
//   }

    if(numeric){
        std::sort(nodeVect.begin(), nodeVect.end(), node_number_compare);
    }
    else{
        std::sort(nodeVect.begin(), nodeVect.end(), node_string_compare);
    }

    l.head = nodeVect[0];
    tempN = l.head;
    for(unsigned int i = 1; i < nodeVect.size(); i++){
        l.head->next = nodeVect[i];
        l.head = l.head->next;
    }
    l.head->next = NULL;
    l.head = tempN;
    
    // while(tempN != NULL) {
    //     cout << tempN->number << ' ';
    //     tempN = tempN->next;
    // }
  
  //std::sort(nodeVect.begin(), nodeVect.end(), node_number_compare);
  
  /*
  if(numeric){
      std::sort(nodeVect.begin(), nodeVect.end(), node_number_compare);
  }
  else{
      std::sort(nodeVect.begin(), nodeVect.end(), node_string_compare);
  }
  
  for(unsigned int i = 0; i < nodeVect.size(); i++){
      cout << "+" << nodeVect[i]->string << endl;
  }
  
  temp.head = nodeVect[0];
  temp.head->next = NULL;
  for(int i = 1; i < nodeVect.size(); i++){
      tempN = nodeVect[i];
      tempN->next = temp.head;
      temp.head = tempN;
  }*/
  //cout << nodeVect.size() << endl;
  
  //delete tempN;
}