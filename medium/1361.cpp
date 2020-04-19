class Solution {
public:
    bool visited[100001];
    bool flag;
    
    void fill(int i,vector<int>& leftChild, vector<int>& rightChild) {
        if(i==-1) {
            return;
        }
        if(visited[i]) {
            flag=1;
            return;
        }
        visited[i]=1;
        fill(leftChild[i],leftChild,rightChild);
        fill(rightChild[i],leftChild,rightChild);
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int i;
        if(n==1) {
            return 1;
        }
        for(i=0;i<n;i++) {
            visited[i]=0;
        }
        flag=0;
        
        for(i=0;i<n;i++) {
            if(leftChild[i]==-1&&rightChild[i]==-1) {
                flag=1;
                continue;
            }
            flag=0;
            fill(i,leftChild,rightChild);
            if(flag==1) {
                return 0;
            }
            break;
        }
        for(i=0;i<n;i++) {
            if(visited[i]==0) {
              return 0;
            }
        }
        return 1;
    }
};
