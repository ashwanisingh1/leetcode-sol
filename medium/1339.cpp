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
    map <TreeNode*,long int> sum;
    long int mod =1e9+7;
    
    void solve(TreeNode* root) {
        if(root==NULL) {
            return;
        }
        if(root->left==NULL&&root->right==NULL) {
            sum[root]=root->val;
            return;
        }
        solve(root->left);
        solve(root->right);
        sum[root]=sum[root->left]+sum[root->right]+root->val;
    }
    
    int maxProduct(TreeNode* root) {
        sum.clear();
        solve(root);
        long int total=sum[root],ans=0;
        for(auto it=sum.begin();it!=sum.end();it++) {
            ans=max(ans,(total-(it->second))*(it->second));
        }
        return ans%mod;
    }
};
