class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       long int ans=-100000000000,maxNow=0,i;
        for(i=0;i<nums.size();i++) {
            if(maxNow+nums[i]<=0) {
                maxNow=0;
            } else {
                maxNow=nums[i]+maxNow;
                ans=max(maxNow,ans);
            }
            ans=max(ans,(long int)nums[i]);
        }
        return ans;
    }
};
