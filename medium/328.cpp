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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd,*even,*evenHead;
        odd=head;
        if(head==NULL) {
            return head;
        }
        even=head->next;
        evenHead=head->next;
        while(even!=NULL) {
            odd->next=even->next;
            if(even->next==NULL) {
                odd->next=evenHead;
                return head;
            }
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};
