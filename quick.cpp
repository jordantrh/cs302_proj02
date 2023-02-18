// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);
int i = 0;
// Implementations

void quick_sort(List &l, bool numeric) {
    l.head = qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
    Node *Left, *Right, *Pivot, *Left_check, *Right_check, *Head_check;
    Left = NULL;
    Right = NULL;
    //base case
    //if one node or empty list
    if (head->next == NULL || head == NULL) {
        return head;
    }
    Head_check = head;
    
    //divide
    //Pivot = first node
    Pivot = head;
    
    //partition()
    partition(head, Pivot, Left, Right, numeric);

    //recursivelly call qsort() on left
    if(Left != NULL){
        Left = qsort(Left, numeric);
    }
    
    //recursively call qsort() on right
    if(Right != NULL){
        Right = qsort(Right, numeric);
    }
    //combine the two list
    head->next = NULL;
    head = concatenate(Left, head);
    return concatenate(head, Right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    bool value_is_numeric;
    Node *Tail_L, *Tail_R, *iterator;
    //divides the list into two smaller sublists. everything smaller than or equal to the pivot goes to the left. 
    //Anything bigger goes to the right
    Tail_L = NULL;
    Tail_R = NULL;
    bool condition;
    //use iterator to cycle through the list
    iterator = head->next; 
    while(iterator != NULL){
       //for if statement
        value_is_numeric = (numeric) ? node_number_compare(pivot, iterator) : node_string_compare(pivot, iterator);
        //if greater, go to right list
        if(value_is_numeric){
            if(right == NULL){
                right = iterator;
                Tail_R = iterator; 
            }else{
                Tail_R->next = iterator;
                Tail_R = Tail_R->next;
            }
        //if less than, go to right list
        }else{
            if(left == NULL){
                left = iterator;
                Tail_L = iterator; 
            }else{
                Tail_L->next = iterator;
                Tail_L = Tail_L->next;
            }
        }
        
        iterator = iterator->next;
        
    }

    if(Tail_L != NULL){
        Tail_L->next = NULL;
    }
        
    if(Tail_R != NULL){
        Tail_R->next = NULL;
    }
    
}

Node *concatenate(Node *left, Node *right) {
    //head is the node for the head of the new linked list.
    //body is the rest of the list
    Node *Head, *Body;
    //combines two sublist.
    
    
    //if left is null head just needs to be set to right
    if(left == NULL){
        Head = right;
        return Head;
    }else{
        Head = left;
    }
    
    //use body to get to end of left and set the ->next of the last value to right
    Body = left;
    if(Body != NULL){
        while(Body->next != NULL){
           Body = Body->next;
        }
    }
    Body->next = right;
    
    return Head;

}
