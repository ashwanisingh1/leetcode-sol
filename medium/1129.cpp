class Solution {
public:
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
     vector<pair<int,int>> adlist[100001];
        vector<int> ans;
     int i,j,u,v;
     for(i=0;i<red_edges.size();i++) {
         adlist[red_edges[i][0]].push_back({red_edges[i][1],0});
     }
     for(i=0;i<blue_edges.size();i++) {
         adlist[blue_edges[i][0]].push_back({blue_edges[i][1],1});
     }   
     queue<pair<int,int>> q;
     q.push({0,-1});
        int level[100001][2],visited[100001]={0};
        for(i=0;i<100001;i++) {
            level[i][0]=level[i][1]=0;
        }
        while(q.size()) {
            pair<int,int> temp = q.front();
            q.pop();
            visited[temp.first]++;
            for(i=0;i<adlist[temp.first].size();i++) {
                    if(temp.second==-1) {
                        
                        if(!level[adlist[temp.first][i].first][adlist[temp.first][i].second]) {
                            q.push({adlist[temp.first][i].first,adlist[temp.first][i].second});
                        level[adlist[temp.first][i].first][adlist[temp.first][i].second]=1;
                        }
                    } else {
                        if(temp.second!=adlist[temp.first][i].second) {
                            
                            if(!level[adlist[temp.first][i].first][adlist[temp.first][i].second]) {
                                q.push({adlist[temp.first][i].first,adlist[temp.first][i].second});
                            level[adlist[temp.first][i].first][adlist[temp.first][i].second]=level[temp.first][temp.second]+1;
                            }
                        }
                    }
            }
        }
        ans.push_back(0);
        for(i=1;i<n;i++) {
            if(!level[i][0]&&!level[i][1]) {
                ans.push_back(-1);
            } else {
                if(level[i][0]==0) {
                    ans.push_back(level[i][1]);  
                } else {
                    if(level[i][1]!=0) {
                        ans.push_back(min(level[i][0],level[i][1])); 
                    } else {
                    ans.push_back(level[i][0]); 
                    }
                }
              
            }
        }
     return ans;
    }
};
