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
    set<int> deleteNode;
    vector<TreeNode*> ans;
    
    TreeNode* solve(TreeNode* root, bool isRoot) {
        if(root==NULL) {
            return NULL;
        }
        bool toDelete = 0;
        if(deleteNode.find(root->val)!=deleteNode.end()) {
            toDelete = 1;
        }
        if(!toDelete&&isRoot) {
            ans.push_back(root);
            root->left=solve(root->left, 0);
            root->right=solve(root->right, 0);
            return root;
        } 
        if(toDelete) {
            solve(root->left, 1);
            solve(root->right, 1);
            return NULL;
        }
        root->left=solve(root->left, 0);
        root->right=solve(root->right, 0);
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        deleteNode.clear();
        ans.clear();
        for(int i=0;i<to_delete.size();i++) {
          deleteNode.insert(to_delete[i]);  
        }
        solve(root,1);
        return ans;
    }
};
