class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n,m,i,j;
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> col(n+1,vector<int> (m+1,0));
        vector<vector<int>> row(n+1,vector<int> (m+1,0));
        for(i=1;i<=n;i++) {
            for(j=1;j<=m;j++) {
                if(grid[i-1][j-1]) {
                    row[i][j]=row[i][j-1]+1;
                } else {
                    row[i][j]=0;
                }
            }
        }
        for(i=1;i<=m;i++) {
            for(j=1;j<=n;j++) {
                if(grid[j-1][i-1]) {
                    col[j][i]=col[j-1][i]+1;
                } else {
                    col[j][i]=0;
                }
            }
        }
        int maxSide=0,len=0;
        for(i=1;i<=n;i++) {
            for(j=1;j<=m;j++) {
                if(grid[i-1][j-1]) {
                len=min(col[i][j],row[i][j]);
                for(int k=len;i-k+1>0&&i-k+1<=n&&j-k+1<=m&&j-k+1>0;k--) {
                    if(row[i-k+1][j]>=len&&col[i][j-k+1]>=len) {
                      break;
                    }
                    len--;
                }
                maxSide=max(len,maxSide);
                }
            }
        }
        return maxSide*maxSide;
    }
};
