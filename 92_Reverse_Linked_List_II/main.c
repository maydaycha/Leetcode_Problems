/**
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *prev = NULL, *next = NULL;
    struct ListNode *start, *end, *start_prev, *end_next, *beginning;
    int tmp = m;

    if (m == n)
        return head;

    beginning = head;

    /* move to the position of list we want to start the reversing. */
    while (--m) {
        next = head->next;
        prev = head;
        head = next;
        n--;
    }

    start_prev = prev;
    start = head;

    /* start to reverse list. (m to n) */
    prev = NULL;
    while (n--) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }


    end = prev;
    end_next = head;

    if (start_prev)
        start_prev->next = prev; /* link m - 1 to the first element of reversed list */

    while (end->next)
        end = end->next; /* go to the last element of reversed list */

    end->next = end_next; /* link last element of reversed list to n + 1 element */


    return tmp <= 1 ? prev : beginning;
}


int main(int argc, const char *argv[])
{
    struct ListNode *new_head = NULL;
    struct ListNode a, b, c, d, e;
    int m = 2, n = 4;

    a.val = 1;
    b.val = 2;
    c.val = 3;
    d.val = 4;
    e.val = 5;


    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;


    new_head = &a;
    while (new_head) {
        printf("%d \n", new_head->val);
        new_head = new_head->next;
    }

    printf("---------------------- \n");


    new_head = reverseBetween(&a, m, n);
    printf("new_head(%p) \n", new_head);

    while (new_head) {
        printf("%d \n", new_head->val);
        new_head = new_head->next;
    }

    return 0;
}
