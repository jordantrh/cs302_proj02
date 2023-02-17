// merge.cpp
// 2/17/23
// Written and Commented by Jordan Huff

/*
    This file sorts a linked list of values using the merge sort algorithm.
*/

#include "volsort.h"
#include <iostream>

using namespace std;

// Prototypes
Node* msort(Node *head, bool numeric);                  // the recursive merge sort function
void  split(Node *head, Node *&left, Node *&right);     // the function handling the splitting of sublists
Node *merge(Node *left, Node *right, bool numeric);     // the function handling the merging of sublists

// Implementations

// the main function that runs merge sort, results in a sorted list
void merge_sort(List &l, bool numeric) {
     l.head = msort(l.head, numeric);
}

// recursively splits up list and remerges based on order
Node* msort(Node *head, bool numeric) {

    Node *left_head, *right_head;   // pointers to the heads of split sublists
    
    // the head of a one-node list is returned
    if (head->next == NULL) {
        return head;
    }

    // splits list into two sublists
    split(head, left_head, right_head);

    // recursively runs msort for the split sublists
    left_head = msort(left_head, numeric);
    right_head = msort(right_head, numeric);

    // merges sublists after they have been sorted
    return merge(left_head, right_head, numeric);
    
}

// splits lists into sublists
void split(Node *head, Node *&left, Node *&right) {
    
    Node* slow_ptr = head;              // pointer that will reach middle of list through tortoise and hare method
    Node* fast_ptr = head->next;        // pointer that will reach end of list through tortoise and hare method

    // tortoise and hare method
    while (fast_ptr != NULL) {          // I spoke with Maria Hernandez about optimizing the tortoise and hare: https://www.quora.com/What-is-a-slow-pointer-and-a-fast-pointer-in-a-linked-list
        fast_ptr = fast_ptr->next;
        if (fast_ptr != NULL) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
    }
    
    // the two sublists are split with slow_ptr being the last value in the left sublist
    left = head;
    right = slow_ptr->next;
    slow_ptr->next = NULL;

}

// merges two split sublists
Node *merge(Node *left, Node *right, bool numeric) {
    
    Node *temp;                     // temporary value for iteration
    Node *head;                     // head of list
    bool multi_type_comparison;     // boolean representing the comparison between two values 
    
    
    // compares two values, whether they are numbers or strings
    multi_type_comparison = (numeric) ? node_number_compare(left, right) : node_string_compare(left, right); // This style of testing for numeric was recommended by Maria Hernandez
    
    // sets head first
    if (multi_type_comparison) {
        head = left;
        left = left->next;
    }

    else {
        head = right;
        right = right->next;
    }
    
    // iterator initialization
    temp = head;

    // loops until left and right segments have been gone through entirely
    while(left != NULL ||  right != NULL) {
        // if left segment is spent, only right values can be inserted
        if (left == NULL) {
            temp->next = right;
            right = right->next;
            temp = temp->next;
            continue;
        }

        // if right segment is spent, only left values can be inserted
        if (right == NULL) {
            temp->next = left;
            left = left->next;
            temp = temp->next;
            continue;
        }

        // inserts values in order
        multi_type_comparison = (numeric) ? node_number_compare(left, right) : node_string_compare(left, right);
        if (multi_type_comparison) {
                temp->next = left;
                left = left->next;
        }
            else {
                temp->next = right;
                right = right->next;
            }
        
        temp = temp->next; 
    }

    // head of sorted list is returned
    return head;
}