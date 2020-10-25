/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    [1,2,3,4,5,6] = 654321
    [5,6,7,8]     =   8765    
    [6,8,0,3,6,6] = 663086
    
    ToDo: enchance performance
          current score:
           - Runtime: 20 ms
           - Memory Usage: 13.6 MB
*/

#define MAX_RESULT_LEN (200+1)

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* resultList = (struct ListNode*) malloc(MAX_RESULT_LEN * sizeof(struct ListNode));
    struct ListNode* l3 = resultList;
    
    int n = 0;
    
    while ( l1 && l2 ) {
        l3->val =         (l1->val + l2->val + n) % 10;
        n       = (int) ( (l1->val + l2->val + n) / 10 );
        l1 = l1->next;
        l2 = l2->next;
        (l3++)->next = (l1 || l2 || n) ? (l3 + 1) : NULL;
    }
    
    if (!l1 && !l2 && n) { /* 'n' is what is left to add up */
        l3->val = n;
        l3->next = NULL;
    } else if (l1 || l2) { /* we have either l1 or l2 non-NULL */
        struct ListNode* l = l1 ? l1 : l2;
        
        while (l) {
            l3->val = (l->val + n) % 10;
            n = (int) (l->val + n) / 10;
            l = l->next;
            (l3++)->next = (l || n) ? (l3 + 1) : NULL;
        }

        if (n) { /* 'l' is exceeded but 'n' needs to be added up */
            l3->val = n;
            l3->next = NULL;
        } 
    }
    
    return resultList;
}
