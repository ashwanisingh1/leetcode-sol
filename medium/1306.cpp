class Solution {
public:
    bool visited[60001];
    
    void check(int i,vector<int>& arr) {
        if(i>=arr.size()||i<0) {
            return;
        }
        if(visited[i]) {
            return;
        }
        visited[i]=1;
        check(i+arr[i],arr);
        check(i-arr[i],arr);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int i;
        for(i=0;i<60001;i++) {
            visited[i]=0;
        }
        check(start,arr);
        for(i=0;i<arr.size();i++) {
            if(arr[i]==0&&visited[i]) {
                return 1;
            }
        }
        return 0;
    }
};
