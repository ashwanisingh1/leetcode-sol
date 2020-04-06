class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n,m,i,j;
        n=s.length();
        m=t.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        for(i=0;i<=m;i++) {
            dp[0][i]=1;
        }
        for(i=1;i<=n;i++) {
            for(j=1;j<=m;j++) {
                if(t[j-1]==s[i-1]) {
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
