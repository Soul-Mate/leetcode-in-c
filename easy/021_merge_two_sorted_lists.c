#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy, *l3 = &dummy;
    while (l1 != NULL && l2 != NULL) {
        struct ListNode *node = malloc(sizeof(*node));
        if (l1->val <= l2->val) {
            node->val = l1->val;
            l1 = l1->next;
        } else {
            node->val = l2->val;
            l2 = l2->next;
        }
        node->next = NULL;
        l3->next = node;
        l3 = l3->next;
    }

    if (l1 != NULL) {
        l3->next = l1;
    }

    if (l2 != NULL) {
        l3->next = l2;
    }

    return dummy.next;
}

struct ListNode* mergeTwoListsFast(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *node = NULL;
    struct ListNode **tmp = &node;
    struct ListNode *t1 = l1;
    struct ListNode *t2 = l2;
    while (t1 != NULL || t2 != NULL) {
        if (*tmp == NULL) {
            *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
            memset(*tmp, 0, sizeof(struct ListNode));
        }

        if (t2 == NULL || (t1 != NULL && t1->val < t2->val)) {
            (*tmp)->val = t1->val;
            t1 = t1->next;
            tmp = &(*tmp)->next;
        } else {
            (*tmp)->val = t2->val;
            t2 = t2->next;
            tmp = &(*tmp)->next;
        }
    }
    return node;
}