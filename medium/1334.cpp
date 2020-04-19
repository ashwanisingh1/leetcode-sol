class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int i,j,k;
        int distance[101][101],count[101];
        for(i=0;i<101;i++) {
            count[i]=0;
            for(j=0;j<101;j++) {
                distance[i][j]=1e6;
                distance[j][i]=1e6;
            }
        }
        for(i=0;i<edges.size();i++) {
            distance[edges[i][0]][edges[i][1]]=edges[i][2];
            distance[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(k=0;k<n;k++) {
            for(i=0;i<n;i++) {
                for(j=0;j<n;j++) {
                    distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
                }
            }
        }
        for(i=0;i<n;i++) {
            for(j=i+1;j<n;j++) {
                if(distance[i][j]<=distanceThreshold) {
                count[i]++;
                count[j]++;
                }
            }
        }
        int ans=1e6,fans;
        for(i=n-1;i>=0;i--) {
            if(ans>count[i]) {
                ans=count[i];
                fans=i;
            }
        }
        return fans;
    }
};
