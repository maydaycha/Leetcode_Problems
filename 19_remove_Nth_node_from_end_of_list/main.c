/**
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/ */


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


#include <stdio.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int total_len = 0, pos_of_remove = 0;
    struct ListNode *cur = head;

    while (cur) {
        total_len++;
        cur = cur->next;
    }
    if (total_len ==  1 && n == 1) /* return NULL if remove one but only one element in list */
        return NULL;
    else if (total_len == n) { /* remove fist element if length of list is equal to n */
        return head->next;
    }

    pos_of_remove = total_len - n;

    cur = head;

    while (--pos_of_remove)
        cur = cur->next;

    cur->next = cur->next->next;

    return head;
}


int main(int argc, const char *argv[])
{
    struct ListNode a, b, c, d, e;
    struct ListNode *new_head;

    a.val = 1;
    b.val = 2;

    a.next = &b;
    b.next = NULL;

    new_head = removeNthFromEnd(&a, 2);

    while (new_head) {
        printf("%d \n", new_head->val);
        new_head = new_head->next;
    }

    return 0;
}
