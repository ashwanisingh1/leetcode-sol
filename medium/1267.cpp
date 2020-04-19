class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row[301]={0},col[301]={0},n,m,i,j;
        n=grid.size();
        m=grid[0].size();
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans=0;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(grid[i][j]) {
                    if(row[i]>=2||col[j]>=2) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
