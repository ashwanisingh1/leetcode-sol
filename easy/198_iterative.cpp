class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(),i;
        vector<int>dp(n+1,0);
        for(i=1;i<=n;i++) {
            if(i==1) {
              dp[i]=max(dp[i-1],nums[i-1]);
            } else {
              dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
            }
        }
        return dp[n];
    }
};
