class Solution {
public:
    bool divisorGame(int N) {
        int i,j;
        bool dp[1001]={0};
        dp[2]=1;
        for(i=3;i<=N;i++) {
            for(j=1;j<i;j++) {
                if(i%j==0&&dp[i-j]==0) {
                    dp[i]=1;
                }
            }
        }
        return dp[N];
    }
};
