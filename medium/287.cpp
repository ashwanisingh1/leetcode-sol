class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowp=0,fastp=0,i,j;
        do {
            slowp=nums[slowp];
            fastp=nums[nums[fastp]];
        }while(nums[slowp]!=nums[fastp]); 
        slowp=0;
        while(nums[slowp]!=nums[fastp]) {
          slowp=nums[slowp];
          fastp=nums[fastp];  
        }
        return nums[slowp];
    }
};
