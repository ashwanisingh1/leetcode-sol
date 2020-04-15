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
    TreeNode* solve(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL) {
            return NULL;
        }
        if(original==target) {
            return cloned;
        }
        TreeNode* a=solve(original->left,cloned->left,target);
        TreeNode* b=solve(original->right,cloned->right,target);
        if(a==NULL) {
            return b;
        }
        return a;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(original,cloned,target);
    }
};
