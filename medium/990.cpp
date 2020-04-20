class Solution {
public:
    int size1[1001],arr[1001];
    
    int root(int a) {
        while(a!=arr[a]) {
            arr[a]=arr[arr[a]];
            a=arr[a];
        }
        return a;
    }
    
    void union1(int a,int b) {
        int root1=root(a);
        int root2=root(b);
        if(size1[root1]>size1[root2]) {
            size1[root1]+=size1[root2];
            arr[root2]=arr[root1];
        } else {
            size1[root2]+=size1[root1];
            arr[root1]=arr[root2];
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
       int i;
        for(i=0;i<1001;i++) {
            arr[i]=i;
            size1[i]=1;
        }
        for(i=0;i<equations.size();i++) {
            if(equations[i][1]=='='&&root(equations[i][0])!=root(equations[i][3])) {
                union1(equations[i][0],equations[i][3]);
            }
        }
        for(i=0;i<equations.size();i++) {
            if(equations[i][1]=='!') {
                if(root(equations[i][0])==root(equations[i][3])) {
                    return false;
                }
            }
        }
        return true;
    }
};
