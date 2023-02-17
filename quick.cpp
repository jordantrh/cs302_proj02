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
    /*
    if(Head_check != NULL){
        while(Head_check->next != NULL){
            cout << Head_check->number << "|" ;
            Head_check = Head_check->next;
        }
        cout << Head_check->number << "|" ;
        cout << endl;
    }
    */
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
  
    
    //cout << "this is pivot in partition " << i << ": " << pivot->number << endl;
    //cout << "partition ";
    iterator = head->next; 
    while(iterator != NULL){
       //
        value_is_numeric = (numeric) ? node_number_compare(pivot, iterator) : node_string_compare(pivot, iterator);

        //cout << "this is iterator in partition " << i << ": " << iterator->number << endl;
        if(value_is_numeric){
            if(right == NULL){
                //cout << "Compare greater than pivot " << i << endl << endl;
                right = iterator;
                Tail_R = iterator; 
                //Tail_R->next = 0;
                //right = Tail_R;
                //Tail_R = Tail_R->next;
                //cout << "Tail_R is :" << Tail_R->number << endl;
            }else{
                //cout << "Compare greater than pivot " << i << endl;
                Tail_R->next = iterator;
                Tail_R = Tail_R->next;
               // cout << "Tail_R is :" << Tail_R->number << endl;
            }
        }else{
            if(left == NULL){
                //cout << "Compare less than pivot " << i << endl << endl;
                left = iterator;
                Tail_L = iterator; 
                //left = Tail_L;
            }else{
                //cout << "Compare less than pivot " << i << endl;
                Tail_L->next = iterator;
                Tail_L = Tail_L->next;
                //cout << "Tail_L is :" << Tail_L->number << endl << endl;
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
    
    //i++;
    //Tail_L->next = NULL;
    //free(iterator);
    //IF LEFT = NULL
    //LEFT = HEAD
    //LEFT_TAIL = HEAD;
    //Left_Tail = Left_Tail-> Next; 
    
}

Node *concatenate(Node *left, Node *right) {
    //head is the node for the head of the new linked list.
    //body is the rest of the list
    Node *Head, *Body;
    //combines two sublist.
    //Head = left;
    
    if(left == NULL){
        Head = right;
        return Head;
        //return right;
       // Body = left->next;
       // Head->next = Body;
    }else{
        Head = left;
    }
    
    Body = left;
    if(Body != NULL){
        //cout << " i: " << i << endl;
        //cout << "Left value " << i << ":" << left->number << endl;
        while(Body->next != NULL){
           Body = Body->next;

           
        }
        //cout << endl;
    }
    Body->next = right;
    //Head->next = Body;
    //i++;

    
    return Head;

}

