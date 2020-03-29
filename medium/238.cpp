class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),i;
        vector <int> ans(n,1);
        for(i=1;i<n;i++) {
            ans[i]=ans[i-1]*nums[i-1];
        }
        for(i=n-2;i>=0;i--) {
            nums[i]=nums[i+1]*nums[i];
            ans[i]=ans[i]*nums[i+1];
        }
        return ans;
    }
};
