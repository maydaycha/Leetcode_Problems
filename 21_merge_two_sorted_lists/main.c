/**
* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*
* Example:
*
* Input: 1->2->4, 1->3->4
* Output: 1->1->2->3->4->4 */

#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    struct listNode *merged, head;

    merged = (l1->val < l2->val) ? l1 : l2;
    head = merged;

    while (l1 && l2) {
        if (l1->val < l2->val)
            merged->next = l1;

    }

}


int main(int argc, const char *argv[])
{
    
    return 0;
}
