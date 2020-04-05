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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp1,*temp2;
        temp1=head;
        temp2=head;
        if(head==NULL||head->next==NULL) {
            return NULL;
        }
        while(n--) {
            temp2=temp2->next;
        }
        if(temp2==NULL) {
            head=head->next;
            return head;
        }
        while(temp2!=NULL&&temp2->next!=NULL) {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1->next=temp1->next->next;
        return head;
    }
};
