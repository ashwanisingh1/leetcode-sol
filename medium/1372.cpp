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
    int ans;
    // dir 0 ->right 1->left
    int solve(TreeNode *root,int dir) {
        if(root==NULL) {
            return -1;
        }
        if(root->left==NULL&&root->right==NULL) {
            return 0;
        }
        int a=0,b=0;
        a=solve(root->left,1);
        b=solve(root->right,0);
        ans=max(ans,1+max(a,b));
        if(dir==0) {
            return 1+a;
        } else {
            return 1+b;
        }
    }
    
    int longestZigZag(TreeNode* root) {
        ans=0;
        TreeNode *temp1=root,*temp2=root;
        solve(temp1,0);
        solve(temp2,1);
        return ans;
    }
};
