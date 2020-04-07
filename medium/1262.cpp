class Solution {
public:
    int solve(int i,int sum,vector<int>& nums,vector<vector<int>> &dp) {
        if(i==nums.size()) {
            if(sum==0) {
               return 0;
            }
            return -1000000;
        }
        if(dp[i][sum]!=-1) {
            return dp[i][sum];
        }
        int a=solve(i+1,(sum+nums[i])%3,nums,dp);
        int b=solve(i+1,sum,nums,dp);
        if(a>-1000) {
            a+=nums[i];
        }
        return dp[i][sum]=max(a,b);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return solve(0,0,nums,dp);
    }
};
