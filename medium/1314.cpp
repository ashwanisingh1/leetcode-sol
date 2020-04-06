class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> sum(n+1,vector<int>(m+1,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        int i,j;
        for(i=1;i<=n;i++) {
            for(j=1;j<=m;j++) {
                sum[i][j]=sum[i][j-1]+mat[i-1][j-1];
            }
        }
        for(i=1;i<=m;i++) {
            for(j=1;j<=n;j++) {
                sum[j][i]+=sum[j-1][i];
            }
        }
        for(i=1;i<=n;i++) {
            for(j=1;j<=m;j++) {
               int a=i,b=j,c=i,d=j;
                a=max(a-K,1);
                b=max(b-K,1);
                c=min(c+K,n);
                d=min(d+K,m);
                int s1,s2,s3,s4;
                s1=sum[c][d];
                s2=sum[a-1][b-1];
                s3=sum[c][b-1];
                s4=sum[a-1][d];
                ans[i-1][j-1]=s1+s2-s3-s4;
            }
        }
        return ans;
    }
};
