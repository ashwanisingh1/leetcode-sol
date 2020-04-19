class Solution {
public:
    int dp[1000001];
    
    int solve(int i) {
        if(i==1) {
            return 0;
        }
        if(dp[i]!=-1) {
            return dp[i];
        }
        if(i&1) {
            return dp[i]=1+solve(3*i+1);
        }
        return dp[i]=1+solve(i/2);
    }
    
    int getKth(int lo, int hi, int k) {
        for(int i=0;i<1000001;i++) {
            dp[i]=-1;
        }
        vector<pair<int,int>> ans;
        for(int i=lo;i<=hi;i++) {
            ans.push_back({solve(i),i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};
