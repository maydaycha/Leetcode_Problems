/**
 * https://leetcode.com/problems/reverse-linked-list/description/
 * Reverse a singly linked list.
 *
 * click to show more hints.
 *
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both? */



#include <stdio.h>

/**
 * Definition for singly-linked list. */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode *prev = NULL, *next = NULL;

    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

int main(int argc, char *argv[])
{
    struct ListNode a, b, c, d;
    struct ListNode *head, *new_head;

    a.val = 1;
    b.val = 2;
    c.val = 3;
    d.val = 4;
    d.next = NULL;

    a.next = &b;
    b.next = &c;
    c.next = &d;

    head = &a;

    new_head = head;

    for (; new_head; new_head = new_head->next) {
        printf("%d \n", new_head->val);
    }


    new_head = reverseList(head);
    printf("--------------------- \n");

    for (; new_head; new_head = new_head->next) {
        printf("%d \n", new_head->val);
    }

    return 0;
}


