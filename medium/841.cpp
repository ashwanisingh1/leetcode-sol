class Solution {
public:
    int visited[1001];
    
    void dfs(int start,vector<vector<int>>& rooms) {
        visited[start]=1;
        for(int i=0;i<rooms[start].size();i++) {
            if(!visited[rooms[start][i]]) {
                dfs(rooms[start][i],rooms);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        for(int i=0;i<1001;i++) {
            visited[i]=0;
        }
        dfs(0,rooms);
        for(int i=0;i<rooms.size();i++) {
            if(!visited[i]) {
                return 0;
            }
        }
        return 1;
    }
};
