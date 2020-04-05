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
    ListNode* merge(ListNode *head1,ListNode *head2) {
        ListNode *head,*temp1=head1,*temp2=head2,*temp=NULL;
        while(temp1!=NULL&&temp2!=NULL) {
            if(temp1->val<=temp2->val) {
                if(temp==NULL) {
                    temp=temp1;
                    head=temp;
                } else {
                    temp->next=temp1;
                    temp=temp1;
                }
                temp1=temp1->next;
            } else {
                if(temp==NULL) {
                    temp=temp2;
                    head=temp;
                } else {
                    temp->next=temp2;
                    temp=temp2;
                }
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL) {
            if(temp==NULL) {
                temp=temp1;
                head=temp;
            } else {
                temp->next=temp1;
                temp=temp->next;
            }
            temp1=temp1->next;
        }
        while(temp2!=NULL) {
            if(temp==NULL) {
                temp=temp2;
                head=temp;
            } else {
                temp->next=temp2;
                temp=temp->next;
            }
            temp2=temp2->next;
        }
        return head;
    }
    
    ListNode* mergeSort(ListNode *head) {
        ListNode *slow,*fast,*prev;
        slow=head;
        fast=head;
        if(head==NULL||head->next==NULL) {
            return head;
        }
        while(fast!=NULL&&fast->next!=NULL) {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        fast = mergeSort(head);
        prev = mergeSort(slow);
        return merge(fast,prev);
    }
    
    ListNode* sortList(ListNode* head) {
        head=mergeSort(head);
        return head;
    }
};
