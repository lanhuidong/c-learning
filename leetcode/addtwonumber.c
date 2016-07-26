#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(void)
{
    struct ListNode node1;
    node1.next = NULL;
    node1.val = 5;
    struct ListNode node2;
    node2.next = NULL;
    node2.val = 5;
    struct ListNode* l1 = &node1;
    struct ListNode* l2 = &node2;
    struct ListNode* result = addTwoNumbers(l1, l2);
    while(result != NULL){
        printf("%d\n", result->val);
        result = result->next;
    }
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = NULL;
    struct ListNode* last;
    struct ListNode* node;
    int addOne = 0;
    while(l1 != NULL || l2 != NULL){
        int sum = 0;
        if(l1 != NULL && l2 != NULL){
            l1->val = l1->val + l2->val;
            node = l1;
            l1 = l1->next;
            l2 = l2->next;
        } else if(l1 != NULL){
            node = l1;
            l1 = l1->next;
        } else if(l2 != NULL){
            node = l2;
            l2 = l2->next;
        }
        node->val = node->val + addOne;
        if(node->val >= 10){
            node->val = node->val - 10;
            addOne = 1;
        } else {
            addOne = 0;
        }
        if(result == NULL){
            result = node;
            last = node;
        } else {
            last->next = node;
            last = node;
        }
    }
    if(addOne){
        node = malloc(sizeof(struct ListNode));
        node->val = 1;
        last->next = node;
        last = node;
    }
    last->next = NULL;
    return result;
}
