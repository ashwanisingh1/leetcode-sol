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
    bool isPalindrome(ListNode* head) {
        ListNode *temp=head,*slow=head,*fast=head,*curr,*prev,*temp1;
        if(head==NULL||head->next==NULL) {
            return 1;
        }
        while(1) {
            slow=slow->next;
            if(fast->next==NULL||fast->next->next==NULL) {
                break;
            }
            fast=fast->next->next;
        }
        //reverse
        curr=slow->next;
        prev=slow;
        slow->next=NULL;
        while(curr) {
            temp1=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp1;
        }
        while(prev!=NULL) {
            if(prev->val!=temp->val) {
                return 0;
            }
            prev=prev->next;
            temp=temp->next;
        }
        return 1;
    }
};
