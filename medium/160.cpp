/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA,*b=headB;
        while(a!=NULL&&b!=NULL) {
            a=a->next;
            b=b->next;
        }
        if(b!=NULL) {
            a=headB;
            while(b!=NULL) {
                a=a->next;
                b=b->next;
            }
            b=headA;
        } else {
            b=headA;
            while(a!=NULL) {
                a=a->next;
                b=b->next;
            }
            a=headB;
        }
        while(a!=b) {
            b=b->next;
            a=a->next;
        }
        return a;
    }
};
