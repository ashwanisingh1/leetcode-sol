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
    void solve(TreeNode* root,vector<int>& a) {
        if(root==NULL) {
            return;
        }
        solve(root->left,a);
        a.push_back(root->val);
        solve(root->right,a);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1,tree2,ans;
        solve(root1,tree1);
        solve(root2,tree2);
        int l=0,r=0;
        while(l<tree1.size()&&r<tree2.size()) {
            if(tree1[l]<=tree2[r]) {
                ans.push_back(tree1[l]);
                l++;
            } else {
                ans.push_back(tree2[r]);
                r++;
            }
        }
        while(l<tree1.size()) {
            ans.push_back(tree1[l]);
            l++;
        }
        while(r<tree2.size()) {
            ans.push_back(tree2[r]);
            r++;
        }
        return ans;
    }
};
