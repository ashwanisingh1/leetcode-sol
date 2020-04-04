class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> temp;
        int i,f=1,n,m,l,r,u,d;
        n=matrix.size();
        if(n==0){
            return temp;
        }
        m=matrix[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        int currentdir=0,nextx,nexty,prevx=0,prevy=0;
        for(i=0;i<n*m;i++) {
            nextx=dx[currentdir]+prevx;
            nexty=dy[currentdir]+prevy;
            temp.push_back(matrix[prevy][prevx]);
            visited[prevy][prevx]=1;
            if(nextx<m&&nextx>=0&&nexty<n&&nexty>=0&&visited[nexty][nextx]==0) {
                prevx=nextx;
                prevy=nexty;
            } else {
                currentdir=(currentdir+1)%4;
                prevx=dx[currentdir]+prevx;
                prevy=dy[currentdir]+prevy;
            }
        }
        return temp;
    }
};
