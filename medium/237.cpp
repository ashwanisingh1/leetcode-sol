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
    void deleteNode(ListNode* node) {
        ListNode *next=node->next;
        int temp = next->val;
        next->val=node->val;
        node->val=temp;
        next=next->next;
        node->next=next;
    }
};
