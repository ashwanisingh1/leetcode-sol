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
    TreeNode* solve(TreeNode* root, int target) {
        if(root==NULL) {
            return NULL;
        }
        root->left=solve(root->left,target);
        root->right=solve(root->right,target);
        if(root->left==NULL&&root->right==NULL&&root->val==target) {
            return NULL;
        }
        return root;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root,target);
    }
};
