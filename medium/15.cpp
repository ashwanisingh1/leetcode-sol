class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l=0,r=nums.size()-1,i;
        vector <int> temp;
        vector<vector<int>> ans;
        if(nums.size()<3) {
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size()-2;i++) {
            l=i+1;
            r=nums.size()-1;
            if(i>0&&nums[i]==nums[i-1]) {
                continue;
            }
            while(l<r){
                if(nums[l]+nums[r]+nums[i]==0) {
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    temp.push_back(nums[i]);
                    ans.push_back(temp);
                    temp.clear();
                    int a=nums[l];
                    int b=nums[r];
                    while(l+1<nums.size()&&nums[l]==a) {
                        l++;
                    } 
                    while(nums[r]==b&&r>0){
                        r--;
                    }
                } else {
                    if(nums[l]+nums[r]+nums[i]>0) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
