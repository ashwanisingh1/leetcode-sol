class Solution {
public:
    int dp[5005][7][100];
    int mod=1000000007;
    
    int solve(int i,int prev,int count,vector<int>& rollMax,int n) {
       if(i==n){
          return 1;
       }
        if(dp[i][prev][count]!=-1) {
            return dp[i][prev][count];
        }
       int a,b,c,ans=0;
       for(a=1;a<=6;a++) {
           if(a==prev) {
               if(rollMax[a-1]>=count+1) {
                  ans=(ans%mod+solve(i+1,prev,count+1,rollMax,n)%mod)%mod;
               }
           } else {
               ans=(ans%mod+solve(i+1,a,1,rollMax,n)%mod)%mod;
           }
       }
        return dp[i][prev][count]=ans;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        for(int i=0;i<5005;i++) {
            for(int j=0;j<7;j++) {
                for(int k=0;k<100;k++) {
                    dp[i][j][k]=-1;
                }
            }
        }
        return solve(0,0,0,rollMax,n);
    }
};
