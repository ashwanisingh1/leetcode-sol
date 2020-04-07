class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i,j,ans=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(i=1;i<=n;i++) {
            for(j=1;j<=m;j++) {
                if(matrix[i-1][j-1]) {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
