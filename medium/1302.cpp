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
    int ans,curdepth;
    
    void solve(TreeNode* root,int depth) {
        if(root==NULL) {
            return;
        }
        if(depth==curdepth) {
            ans+=root->val;
        }
        if(depth>curdepth) {
            ans=root->val;
            curdepth=depth;
        }
        solve(root->left,depth+1);
        solve(root->right,depth+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        ans=0,curdepth=0;
        solve(root,0);
        return ans;
    }
};
