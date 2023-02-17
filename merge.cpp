// merge.cpp

#include "volsort.h"

#include <iostream>

using namespace std;

// Prototypes

Node* msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
    //recursively split up list and remerge based on order
     l.head = msort(l.head, numeric);
    // when recursion is finished, a sorted list should be completed

}

Node* msort(Node *head, bool numeric) {
    
    Node *left_head;
    Node *right_head;
    
    if (head->next == NULL) {
        return head;
    }

    split(head, left_head, right_head);

    left_head = msort(left_head, numeric);

    right_head = msort(right_head, numeric);

    return merge(left_head, right_head, numeric);
    
}

void split(Node *head, Node *&left, Node *&right) {
    
    // We spoke with Maria Hernandez about optimizing the tortoise and hare: https://www.quora.com/What-is-a-slow-pointer-and-a-fast-pointer-in-a-linked-list 
    Node* slow_ptr = head;
    Node* fast_ptr = head->next;
    while (fast_ptr != NULL) {
        fast_ptr = fast_ptr->next;
        if (fast_ptr != NULL) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
    }
    
    left = head;
    right = slow_ptr->next;
    slow_ptr->next = NULL;

}

Node *merge(Node *left, Node *right, bool numeric) {
    
    Node *temp;
    Node *head;
    bool condition;
  
    condition = (numeric) ? node_number_compare(left, right) : node_string_compare(left, right);
    // sets head first
    if (condition) {
        head = left;
        left = left->next;
    }

    else {
        head = right;
        right = right->next;
    }
    
    // loops until left and right segments have been gone through entirely
    temp = head;

    while(left != NULL ||  right != NULL) {
        // if left segment is spent, insert rights only
        if (left == NULL) {
            temp->next = right;
            right = right->next;
            temp = temp->next;
            continue;
        }

        // if right segment is spent, insert lefts only
        if (right == NULL) {
            temp->next = left;
            left = left->next;
            temp = temp->next;
            continue;
        }
        condition = (numeric) ? node_number_compare(left, right) : node_string_compare(left, right);
        if (condition) {
                temp->next = left;
                left = left->next;
        }
            else {
                temp->next = right;
                right = right->next;
            }
        
        temp = temp->next; 
    }

    return head;
}