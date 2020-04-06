class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector <int> dp(1001,0);
        cost.push_back(0);
        int i,j,n=cost.size();
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(i=2;i<n;i++) {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return dp[n-1];
    }
};
