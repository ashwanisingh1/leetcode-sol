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
    int solve(TreeNode* root, int parent, int grandParent) {
        if(root==NULL) {
            return 0;
        }
        int a=solve(root->left,root->val,parent);
        int b=solve(root->right,root->val,parent);
        int c=0;
        if(!(grandParent&1)) {
            c=root->val;
        }
        return a+b+c;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root,-1,-1);
    }
};
