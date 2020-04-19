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
    int ans=0;
    
    void solve(TreeNode* root, int max1,int min1) {
        if(root==NULL) {
            return;
        }
        ans=max(ans,(int)max(abs(min1-(root->val)),(int)abs(max1-(root->val))));
        solve(root->left,max(max1,root->val),min(min1,root->val));
        solve(root->right,max(max1,root->val),min(min1,root->val));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        solve(root->left,root->val,root->val);
        solve(root->right,root->val,root->val);
        return ans;
    }
};
