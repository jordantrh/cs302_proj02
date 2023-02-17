// quick.cpp
// #include "list.cpp"

#include "volsort.h"

#include <iostream>

// using namespace std;
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
    Node *Left, *Right, *Pivot;
    // Node *Left_check, *Right_check;
    Left = NULL;
    Right = NULL;
    //base case
    //if one node or empty list
    if (head->next == NULL || head == NULL) {
        return head;
    }
    
    //divide
    //Pivot = first node
    Pivot = head;
    
    //partition()
    partition(head, Pivot, Left, Right, numeric);
    //cout << "did partition";
    //recursivelly call qsort() on left
    // Left_check = Left;
    // Right_check = Right;

    //  if(Left_check != NULL){
    //     cout << "Left: ";
    //     while(Left_check->next != NULL){
    //         cout << Left_check->number << "|" ;
    //         Left_check = Left_check->next;
    //     }
    //     cout << Left_check->number << "|" ;
    //     cout << endl;
    // }
    // if(Right_check != NULL){
    //     cout << "Right: ";
    //     while(Right_check->next != NULL){
    //         cout << Right_check->number << "|" ;
    //         Right_check = Right_check->next;
    //     }
    //     cout << Right_check->number << "|" ;
    //     cout << endl;
    // }
    
    if(Left != NULL){
        Left = qsort(Left, numeric);
    }
    
    //recursively call qsort() on right
    if(Right != NULL){
        Right = qsort(Right, numeric);
    }
    
    // if(Left != NULL){
    //     while(Left->next != NULL){
    //         cout << "Left number b4 concat: " << Left->number << "|" ;
    //         Left = Left->next;
    //     }
    //     cout << Left->number << "|" ;
    //     cout << endl;
    // }
    //free(Left);
    //free(Right);
    //head->next = NULL;
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
    // cout << "pivot in partition " << i << ": " << pivot->number << endl;
    //cout << "partition ";
    iterator = head->next; 
    while(iterator != NULL){
       //
       //cout << "this is compare in partition " << i << ": " << iterator->number << endl;
       
       value_is_numeric = (numeric) ? node_number_compare(pivot, iterator) : node_string_compare(pivot, iterator);

        if(value_is_numeric){
            if(right == NULL){
                //cout << "Compare greater than pivot " << i << endl << endl;
                right = iterator;
                Tail_R = iterator; 
                //right = Tail_R;
            }
            else{
                //cout << "Compare greater than pivot " << i << endl;
                Tail_R->next = iterator;
                Tail_R = Tail_R->next;
                //cout << "Tail_R is :" << Tail_R->number << endl << endl;
            }
        }
        else{
            if(left == NULL){
                    //cout << "Compare less than pivot " << i << endl << endl;
                    left = iterator;
                    Tail_L = iterator; 
                    //left = Tail_L;
            }
            else{
                //cout << "Compare less than pivot " << i << endl;
                Tail_L->next = iterator;
                Tail_L = Tail_L->next;
                //cout << "Tail_L is :" << Tail_L->number << endl << endl;
            }
        }

        
        iterator = iterator->next;
    }

    if (Tail_R != NULL) Tail_R->next = NULL;
    if (Tail_L != NULL) Tail_L->next = NULL;

    i++;
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
        //cout << "right value " << i << ":" << right->number << endl;
       // Body = left->next;
       // Head->next = Body;
    }
    else{
        Head = left;
    }
    
    Body = left;
    if(Body != NULL){
        //cout << " i: " << i << endl;
        //cout << "Left value " << i << ":" << left->number << endl;
        while(Body->next != NULL){
           Body = Body->next;
           //cout << left->number << " " ;
        //    Body = left;
        //    Body = Body->next;
           
        }
        //cout << endl;
    }

    Body->next = right;
    //left->next = right;
    //Head->next = Body;
    //i++;

    // if(Head != NULL){
    //     while(Head->next != NULL){
    //         cout << "Concatenated: " << Head->number << "|" ;
    //         Head = Head->next;
    //     }
    //     cout << endl;
    // }

    return Head;

}

// int main() {
//     bool numeric = true;
//     List l;
    
//     l.push_front("2");
//     l.push_front("22");
//     l.push_front("3");
//     l.push_front("45");
//     l.push_front("4");
//     l.push_front("4");
//     Node* temp = l.head;
    
//     for(int i = 0; i < l.size; i++){
//       cout << "woo " << temp->number << endl;
//        temp = temp->next;
//     }

//     quick_sort(l, numeric);
//     temp = l.head; 
//     cout << l.size << "sorteeeeeed \n\n";
//     for(int i = 0; i < l.size; i++){
//       cout << "woo " << temp->number << endl;
//         temp = temp->next;
//     }
// }