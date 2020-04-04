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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=head,*temp;
        if(prev==NULL||prev->next==NULL) {
            return prev;
        }
        ListNode *next=prev->next;
        prev->next=NULL;
        while(next!=NULL) {
            temp=next->next;
            next->next=prev;
            prev=next;
            next=temp;
        }
        head=prev;
        return head;
    }
};
