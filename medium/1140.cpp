class Solution {
public:
    int dp[10001][2][101];
    
    int solve(int i,int turn,int m,vector<int>& sum) {
        if(i>=sum.size()-1) {
            return 0;
        }
        if(dp[i][turn][m]!=-1) {
            return dp[i][turn][m];
        }
        int ans;
        if(turn==0) {
            ans=-1000000;
        } else {
            ans=1000000;
        }
        for(int j=1;j<=2*m;j++) {
            int temp=solve(i+j,1-turn,max(j,m),sum);
            if((i+j)<sum.size()){
            if(turn==0) {
                temp=temp+sum[i+j]-sum[i];
            }
            }
            if(turn==0) {
              ans=max(ans,temp); 
            } else {
              ans=min(ans,temp);  
            }
        }
        return dp[i][turn][m]=ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        vector<int> prefixSum(piles.size()+1,0);
        for(int i=0;i<10001;i++) {
            for(int j=0;j<101;j++) {
                dp[i][0][j]=dp[i][1][j]=-1;
            }
        }
        for(int i=1;i<=piles.size();i++) {
            prefixSum[i]=prefixSum[i-1]+piles[i-1];
        }
        return solve(0,0,1,prefixSum);
    }
};
