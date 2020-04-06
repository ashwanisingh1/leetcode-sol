class NumArray {
public:
    vector<int> num;
    NumArray(vector<int>& nums) {
       int i;
        for(i=0;i<nums.size();i++) {
            num.push_back(0);
        }
        if(nums.size()){
        num[0]=nums[0];
        }
        for(i=1;i<nums.size();i++) {
            num[i]=num[i-1]+nums[i];
        }
    }
    
    int sumRange(int i, int j) {
     if(i==0) {
         return num[j];
     }   
        return num[j]-num[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
