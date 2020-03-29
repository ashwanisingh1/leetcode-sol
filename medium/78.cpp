class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        long int i,n=nums.size(),j;
        vector <vector<int>> ans;
        vector <int> temp;
        for(i=0;i<(1<<n);i++) {
            for(j=0;j<n;j++) {
                if(i&(1<<j)) {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
