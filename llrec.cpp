#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* curr = head;
    head = head->next;

    llpivot(head, smaller, larger, pivot);

    if (curr->val <= pivot) {
        curr->next = smaller;
        smaller = curr;
    } else {
        curr->next = larger;
        larger = curr;
    }
}