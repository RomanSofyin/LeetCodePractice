/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    1 2 3 4 5 6     =       654321
    5 6 7 8         =         8765
    
    6 8 0 3 6 6     =       663086
    
    Wrong Answer, Details 
    Input
    [9,9,9,9,9,9,9]
    [9,9,9,9]
    Output
    [8,9,9,9,10,9]
    Expected
    [8,9,9,9,0,0,0,1]
*/


#define MAX_RESULT_LEN (200+1)

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* resultList = (struct ListNode*) malloc(MAX_RESULT_LEN * sizeof(struct ListNode));
    struct ListNode* l3 = resultList;
    
    int n = 0;
    
    while ( l1 && l2 ) {
        l3->val = (l1->val + l2->val + n) % 10;
        n = (int) ( (l1->val + l2->val) / 10 );
        l1 = l1->next;
        l2 = l2->next;
        (l3++)->next = (l1 || l2 || n) ? (l3 + 1) : NULL;
    }
    
    if (!l1 && !l2) {
        l3->val = n;
    } else {
        struct ListNode* l = l1 ? l1 : l2;
        l3->val = l->val + n;
        (l3++)->next = l3 + 1;
        l = l->next;
        
        while (l) {
            l3->val = l->val;
            (l3++)->next = (l->next) ? (l3+1) : NULL;
            l = l->next;
        }
    }
    
    return resultList;
}

