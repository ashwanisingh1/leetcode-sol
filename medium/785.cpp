class Solution {
public:
    int col[100001],f,visited[100001];
    
    void dfs(int start,int color,vector<vector<int>>& graph) {
        col[start]=color;
        visited[start]=1;
        for(int i=0;i<graph[start].size();i++) {
            if(!visited[graph[start][i]]) {
                dfs(graph[start][i],1-color,graph);
            } else {
                if(color==col[graph[start][i]]) {
                    f=1;
                }
            }
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i=0;i<100001;i++) {
            col[i]=visited[i]=0;
        }
        f=0;
        for(int i=0;i<graph.size();i++) {
            if(!visited[i]) {
            dfs(i,0,graph);
            }
        }
        return !f;
    }
};
