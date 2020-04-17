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
    int total(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        return total(root->left)+total(root->right)+1;
    }
    
    TreeNode* find(TreeNode* root,int x) {
        if(root==NULL) {
            return NULL;
        }
        if(root->val==x) {
            return root;
        }
        TreeNode* a=find(root->left,x);
        TreeNode* b=find(root->right,x);
        if(a!=NULL) {
            return a;
        }
        return b;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* a=find(root, x);
        int left=total(a->left);
        int right=total(a->right);
        if(((right+left)<n/2)||(right>n/2)||(left>n/2)) {
            return 1;
        }
        return 0;
    }
};
