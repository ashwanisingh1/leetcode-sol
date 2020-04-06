class Solution {
public:
    int dp[100001];
    
    int solve(vector<int>& nums, int i) {
        if(i>=nums.size()) {
            return 0;
        }
        if(dp[i]!=-1) {
            return dp[i];
        }
        return dp[i]=max(solve(nums,i+2)+nums[i],solve(nums,i+1));
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size(),i;
        for(i=0;i<n;i++) {
            dp[i]=-1;
        }
        return solve(nums,0);
    }
};
