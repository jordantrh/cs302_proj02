// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    Node *thehead = qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
    Node *Left, *Right, *Pivot;
    
    //base case
    //if one node or empty list
    if (head->next == NULL) {
        return head;
    }

    
    //divide
    //pivot = first node
    Pivot = head;
    
    
    //partition()
    partition(head, Pivot, Left, Right, numeric);
    
    //recursivelly call qsort() on left
    Left = qsort(Left, numeric);
    //recursively call qsort() on right
    Right = qsort(Right, numeric);

    return concatenate(Left, Right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {

    
    //divides the list into two smaller sublists. everything smaller than or equal to the pivot goes to the left. 
    //Anything bigger goes to the right
    while(head->next != NULL){
        head = head->next;
        if(node_number_compare(head, pivot)){
            right = head;
            right = right->next;
        }else{
            left = head;
            left = left->next; 
        }
    }
    right->next = NULL;
    left->next = NULL;
}

Node *concatenate(Node *left, Node *right) {
    //head is the node for the head of the new linked list.
    //body is the rest of the list
    Node *Head, *Body;
    //combines two sublist.
    Head = left;
    Head->next = Body;
    
    while(left->next != NULL){
        left = left->next;
        Body = left;
        Body = Body->next;
    }

    Body = right;
    Body = Body->next;
    while(right->next != NULL){
        right = right->next;
        Body = right;
        Body = Body->next;
    }

    return Head;

}

