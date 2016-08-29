/**
 * Medium
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode *pCurr = &dummy;
    int carry = 0;
    
    while (l1 || l2) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int digit = carry + x +y;
        pCurr->next = (struct ListNode *) calloc(1,sizeof(struct ListNode));
        pCurr = pCurr->next;
        pCurr->val = digit % 10;
        carry = digit / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    
    if (carry != 0) {
        pCurr->next = (struct ListNode *) calloc(1,sizeof(struct ListNode));
        pCurr = pCurr->next;
        pCurr->val =  carry;
    }
    return dummy.next;
}

int main() {
    struct ListNode *l1 = (struct ListNode *)calloc(3, sizeof(struct ListNode));
    struct ListNode *p1 = l1;
    p1->val = 2;
    p1->next = p1 + 1;
    p1++;

    p1->val = 4;
    p1->next = p1 + 1;
    p1++;

    p1->val = 5;
    p1->next = NULL;

    struct ListNode *l2 = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode *p2 = l2;
    p2->val = 5;
    p2->next = p2 + 1;
    p2++;

    p2->val = 6;
    p2->next = p2 + 1;
    p2++;

    p2->val = 4;
    p2->next = p2 + 1;
    p2++;

    p2->val = 9;
    p2->next = p2 + 1;
    p2++;

    p2->val = 9;
    p2->next = NULL;

    struct ListNode *p = addTwoNumbers(l1, l2);
    
    /* 542 + 99465 = 100007 */
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}