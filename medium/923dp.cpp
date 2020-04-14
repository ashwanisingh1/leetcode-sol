class Solution {
public:
    long int mod=1e9+7;
    int dp[3001][4][301];
    int solve(int i,int f,int sum,vector<int>& A, int target) {
        if(sum==target&&f==3) {
            return 1;
        }
        if(i==A.size()||f>=3||sum>target) {
            return 0;
        }
        if(dp[i][f][sum]!=-1) {
            return dp[i][f][sum];
        }
        return dp[i][f][sum]=(solve(i+1,f+1,sum+A[i],A,target)%mod+solve(i+1,f,sum,A,target)%mod)%mod;
    }
    
    int threeSumMulti(vector<int>& A, int target) {
        for(int i=0;i<3001;i++) {
            for(int j=0;j<4;j++) {
                for(int k=0;k<301;k++) {
                    dp[i][j][k]=-1;
                }
            }
        }
        return solve(0,0,0,A,target);
    }
};
