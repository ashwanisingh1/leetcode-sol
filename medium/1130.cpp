class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size(),i,j,k,a,max1,max2,from,to,ans;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(i=2;i<=n;i++) {
            for(j=0;j+i-1<n;j++) {
                from=j;
                to=j+i-1;
                ans=100000;
                for(k=from;k<to;k++) {
                    max1=max2=0;
                    for(a=from;a<=k;a++) {
                        max1=max(max1,arr[a]);
                    }
                    for(a=k+1;a<=to;a++) {
                        max2=max(max2,arr[a]);
                    }
                    ans=min(ans,max1*max2+dp[from][k]+dp[k+1][to]);
                 }
                dp[from][to]=ans;
            }
        }
        return dp[0][n-1];
    }
};
