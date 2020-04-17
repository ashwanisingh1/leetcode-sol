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
    int maxdepth;
    
    int depth(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        return max(depth(root->left),depth(root->right))+1;
    }
    
    TreeNode* solve(TreeNode* root,int height) {
        if(root==NULL) {
            return NULL;
        }
        if(height==maxdepth) {
            return root;
        }
        TreeNode* a=solve(root->left,height+1);
        TreeNode* b=solve(root->right,height+1);
        if(a!=NULL&&b!=NULL) {
            return root;
        }
        if(a!=NULL) {
            return a;
        }
        return b;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        maxdepth=depth(root);
        return solve(root,1);
    }
};
