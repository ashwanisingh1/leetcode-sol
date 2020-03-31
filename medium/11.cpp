class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,ans=0;
        while(l<r) {
            ans=max(ans,(r-l)*min(height[r],height[l]));
            if(height[l]==height[r]) {
                if(height[l]>height[r-1]) {
                    r--;
                } else {
                    l++;
                }
            } else {
                if(height[l]>height[r]) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
