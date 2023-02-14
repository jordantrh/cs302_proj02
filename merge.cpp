// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {

    //recursively split up list and remerge based on order
    Node *thehead = msort(l.head, numeric);
    // when recursion is finished, a sorted list should be completed

}

Node *msort(Node *head, bool numeric) {
    
    Node *left_head, *right_head;
    
    if (head->next == NULL) {
        return head;
    }

    split(head, left_head, right_head);

    left_head = msort(left_head, numeric);

    right_head = msort(right_head, numeric);

    return merge(left_head, right_head, numeric);
    
}

void split(Node *head, Node *&left, Node *&right) {
    Node *slow_ptr = head, *fast_ptr = head; 
    while(!slow_ptr && !fast_ptr && fast_ptr->next != NULL) {   // https://www.quora.com/What-is-a-slow-pointer-and-a-fast-pointer-in-a-linked-list 
            slow_ptr = slow_ptr->next;  // moves one node ahead at a time 
            fast_ptr = fast_ptr->next->next;  // moves two nodes ahead at a time 
    }

    left = head;
    right = slow_ptr->next;
    slow_ptr->next = NULL;

}

Node *merge(Node *left, Node *right, bool numeric) {
    
    Node *temp;
    Node *head;

    int left_nulls = 0, right_nulls = 0;

    // sets head first
    if (node_number_compare(left, right)) {
        head = left;
        left = left->next;
    }

    else {
        head = right;
        right = right->next;
    }
    
    // loops until left and right segments have been gone through entirely
    temp = head;
    while(left->next != NULL || right->next != NULL) {
        
        // if left segment is spent, insert rights only
        if (left->next == NULL) {
            if (left_nulls > 0) {
                temp->next = right;
                right = right->next;
                continue;
            }
            left_nulls++;
        }

        // if right segment is spent, insert lefts only
        if (right->next == NULL) {
            if (right_nulls > 0) {
                temp->next = left;
                left = left->next;
                continue;
            }
            right_nulls++;
        }

        // if left is less than right, left is inserted
        if (node_number_compare(right, left)) {
            temp->next = left;
            left = left->next;
        }

        // if right is less than left, right is inserted
        else {
            temp->next = right;
            right = right->next;
        }
        
        temp = temp->next;
    }

    return head;
}
















// Node *msort(Node *head, bool numeric);
// void  split(Node *head, Node *&left, Node *&right);
// Node *merge(Node *left, Node *right, bool numeric);

// // Implementations

// void merge_sort(List &l, bool numeric) {

// }

// Node *msort(Node *head, bool numeric) {
    
// }

// void split(Node *head, Node *&left, Node *&right) {
//     // if the segment is the first half
//     if (left == head) {
//         // loop through nodes to the right of "right", deleting them
//         Node* temp = right->next;
//         while(1){
//             if (temp->next != NULL) {
//                 Node* nextN = temp->next;
//                 delete temp;
//                 temp = nextN;
//             }
//             else {
//                 delete temp;
//                 break;
//             }
//         }

//         right->next = NULL;
//     }

//     // if the segment is the second half
//     else {
//         // loop through first node until "left", deleting them
        
//         while(1){
//             Node* temp = head;
//             if (temp->next != left) {
//                 Node* nextN = temp->next;
//                 delete temp;
//                 temp = nextN;
//             }
//             else {
//                 delete temp;
//                 break;
//             }
//         }

//         right->next = NULL;
//     }
// }

// Node *merge(Node *left, Node *right, bool numeric) {
    
//     // loop through left side until end is reached
//     Node* temp = left;
//     while(1) {
//         if (temp->next != NULL) {
//             temp = temp->next;
//         }
//         else {
//             break;
//         }
//     }

//     // conect end of left side with right side
//     temp->next = right;


//     return left;
// }















// Node *msort(Node *head, bool numeric);
// void  split(Node *head, Node *&left, Node *&right);
// Node *merge(Node *left, Node *right, bool numeric);

// // Implementations

// void merge_sort(List &l, bool numeric) {

//     //recursively split up list and remerge based on order
//     Node *thehead = msort(l.head, numeric);
//     // when recursion is finished, a sorted list should be completed

// }

// Node *msort(Node *head, bool numeric) {
    
//     Node *left_head, *right_head;
    
//     // end case: if there are only two to compare
//     if (head->next->next == NULL) {
//         node_number_compare(head, head->next);
//     }
//     else {
//         // halves list
//         Node *slow_ptr = head, *fast_ptr = head; 
//         while(!slow_ptr && !fast_ptr && fast_ptr->next != NULL) {   // https://www.quora.com/What-is-a-slow-pointer-and-a-fast-pointer-in-a-linked-list 
//                 slow_ptr = slow_ptr->next;  // moves one node ahead at a time 
//                 fast_ptr = fast_ptr->next->next;  // moves two nodes ahead at a time 
//         }
        
//         split(head, slow_ptr, fast_ptr);

//         // left side
//         left_head = msort(head, numeric);

//         // right side
//         right_head = msort(slow_ptr, numeric);
//     }

//     return merge(left_head, right_head, numeric);


// }

// void split(Node *head, Node *&left, Node *&right) {
//     left->next = NULL;
// }

// Node *merge(Node *left, Node *right, bool numeric) {
    
//     while

//     return left;
// }