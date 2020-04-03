class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,dist=nums.size()-1;
        for(i=nums.size()-2;i>=0;i--) {
            if(nums[i]+i>=dist){
                dist=i;
            }
        }
        if(dist==0) {
            return 1;
        }
        return 0;
    }
};
