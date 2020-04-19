class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited) {
        if(i>=0&&j>=0&&i<grid.size()&&j<grid[0].size()&&grid[i][j]==0&&visited[i][j]==0) {
            return 1;
        }
        return 0;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue <pair<int,int>> q;
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        int i,j,n,m;
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(grid[i][j]) {
                    q.push({i,j});
                }
            }
        }
        int ans=-1;
        while(q.size()) {
            pair<int,int> curr;
            curr=q.front();
            q.pop();
            for(i=0;i<4;i++) {
                if(check(curr.first+dx[i],curr.second+dy[i],grid,visited)) {
                    q.push({curr.first+dx[i],curr.second+dy[i]});
                    visited[curr.first+dx[i]][curr.second+dy[i]]=visited[curr.first][curr.second]+1;
                    ans=max(ans,visited[curr.first+dx[i]][curr.second+dy[i]]);
                }
            }
        }
        return ans;
    }
};
