/**
 * Easy
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
 * the linked list should become 1 -> 2 -> 4 after calling your function.
 */

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode* node) {
    struct ListNode* temp;
    node->val = node->next->val;
    temp = node->next;
    node->next = node->next->next;
    //free(temp);
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("N\n");
}


int main() {
    struct ListNode n1, n2, n3;
    struct ListNode *p1, *ph;
    
    ph = &n1;
    p1 = ph;
    n1.val = 3;
    n1.next = &n2;

    n2.val = 4;
    n2.next = &n3;

    n3.val = 5;
    n3.next = NULL;

    printList(&n1);

    p1=&n2;
    deleteNode(p1);
    
    printList(&n1);

    return 0;
}