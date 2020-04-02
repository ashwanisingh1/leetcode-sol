class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        if(intervals.size()==0) {
            return ans;
        }
        vector<int> temp;
        int i,j,n,left,right;
        n=intervals.size();
        left=intervals[0][0];
        right=intervals[0][1];
        for(i=1;i<n;i++) {
            if(intervals[i][0]<=right) {
                right=max(right,intervals[i][1]);
            } else {
                temp.push_back(left);
                temp.push_back(right);
                ans.push_back(temp);
                temp.clear();
                left=intervals[i][0];
                right=intervals[i][1];
            }
        }
        temp.push_back(left);
        temp.push_back(right);
        ans.push_back(temp);
        return ans;
    }
};
