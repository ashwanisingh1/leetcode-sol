/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(ListNode* head, TreeNode* root) {
        if(head==NULL) {
            return true;
        }
        if(root==NULL) {
            return false;
        }
        if(head->val==root->val) {
            return solve(head->next,root->left)||solve(head->next,root->right);
        } else {
            return false;
        }
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==NULL) {
            return true;
        }
        if(root==NULL) {
            return false;
        }
        return solve(head,root)||isSubPath(head,root->left)||isSubPath(head,root->right);
    }
};
