class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int i,j;
        int outEdges[10001]={0};
        vector<int> reverseGraph[100001];
        queue <int> q;
        for(i=0;i<graph.size();i++) {
            for(j=0;j<graph[i].size();j++) {
                reverseGraph[graph[i][j]].push_back(i);
                outEdges[i]++;
            }
            if(!outEdges[i]) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(q.size()) {
            j=q.front();
            q.pop();
            ans.push_back(j);
            for(i=0;i<reverseGraph[j].size();i++) {
                outEdges[reverseGraph[j][i]]--;
                if(!outEdges[reverseGraph[j][i]]) {
                    q.push(reverseGraph[j][i]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
