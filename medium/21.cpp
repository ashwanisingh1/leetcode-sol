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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *temp=NULL,*head=NULL;
        while(l1!=NULL&&l2!=NULL) {
            if(l1->val<=l2->val) {
                if(temp==NULL) {
                    temp=l1;
                    head=temp;
                } else {
                    temp->next=l1;
                    temp=temp->next;
                }
                l1=l1->next;
            } else {
                if(temp==NULL) {
                    temp=l2;
                    head=temp;
                } else {
                    temp->next=l2;
                    temp=temp->next;
                }
                l2=l2->next;
            }
        }
        while(l1!=NULL) {
            if(temp!=NULL) {
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            } else {
                temp=l1;
                head=temp;
                l1=l1->next;
            }
        }
        while(l2!=NULL) {
            if(temp!=NULL) {
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            } else {
                temp=l2;
                head=temp;
                l2=l2->next;
            }
        }
        return head;
    }
};
