class Solution {
public:
    long int mod=1e9+7;
    
    int solve(int i,int faces,int sum,int target,int d,vector<vector<int>>& dp) {
        if(i>d) {
            return 0;
        }
        if(sum>=target&&d==i) {
            if(sum==target) {
            return 1;
            }
            return 0;
        }
        
        if(dp[i][sum]!=-1) {
            return dp[i][sum];
        }
        long int ans=0;
        for(int k=1;k<=faces;k++) {
            ans=(ans%mod+solve(i+1,faces,sum+k,target,d,dp)%mod)%mod;
        }
        return dp[i][sum]=ans;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(31,vector<int>(1001,-1)); 
        return solve(0,f,0,target,d,dp);
    }
};
