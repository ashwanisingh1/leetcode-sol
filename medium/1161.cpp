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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*,int> level;
        int sum[100001]={0};
        level[root]=0;
        sum[0]=root->val;
        while(q.size()) {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=NULL) {
                q.push(temp->left);
                level[temp->left]=level[temp]+1;
                sum[level[temp->left]]+=temp->left->val;
            }
            if(temp->right!=NULL) {
                q.push(temp->right);
                level[temp->right]=level[temp]+1;
                sum[level[temp->right]]+=temp->right->val;
            }
        }
        long int ans=-1e10;
        int fans,i;
        for(i=0;i<100001;i++) {
            if(sum[i]>ans) {
                ans=sum[i];
                fans=i;
            }
        }
        return fans+1;
    }
};
