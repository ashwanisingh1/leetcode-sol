/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    set<int> visited;
    
    void clear(TreeNode* root,int val) {
        if(root==NULL) {
            return; 
        }
        root->val=val;
        visited.insert(val);
        clear(root->left,2*val+1);
        clear(root->right,2*val+2);
    }
   
    
    FindElements(TreeNode* root) {
        visited.clear();
        clear(root,0);
    }
    
    bool find(int target) {
        return visited.find(target)==visited.end()?0:1;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
