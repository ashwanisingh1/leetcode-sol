class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),odd=0,ans=0,count[1000001]={0};
        count[0]=1;
        for(i=0;i<n;i++) {
            if(nums[i]&1) {
                odd++;
            }
            count[odd]++;
            if(k<=odd) {
                ans+=count[odd-k];
            }
        }
        return ans;
    }
};
