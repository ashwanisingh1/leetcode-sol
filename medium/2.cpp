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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1,*temp2,*temp=NULL,*head;
        int carry = 0;
        temp1=l1,temp2=l2;
        while(temp1!=NULL||temp2!=NULL) {
            int a = 0;
            int b = 0;
            if(temp1!=NULL) {
                a=temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=NULL) {
                b=temp2->val;
                temp2=temp2->next;
            }
            if(carry) {
                if(temp==NULL) {
                    temp=new ListNode((a+b+1)%10);
                    head=temp;
                } else {
                    temp->next=new ListNode((a+b+1)%10);
                    temp=temp->next;
                }
            } else {
                if(temp==NULL) {
                    temp=new ListNode((a+b)%10);
                    head=temp;
                } else {
                    temp->next=new ListNode((a+b)%10);
                    temp=temp->next;
                }
            }
            if(a+b+carry>=10) {
                carry=1;
            } else {
                carry=0;
            }
        }
        if(carry) {
            temp->next=new ListNode(1);
            temp=temp->next;
        }
        return head;
    }
};
