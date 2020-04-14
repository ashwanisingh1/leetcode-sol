class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int l=0,r=0,ans=0,sum=0,n=A.size();
        while(r<n) {
            sum+=A[r];
            while(l<=r&&sum>S) {
                sum-=A[l];
                l++;
            }
            r++;
            ans+=r-l+1;
        }
        l=r=sum=0;
        while(r<n) {
            sum+=A[r];
            while(l<=r&&sum>S-1) {
                sum-=A[l];
                l++;
            }
            r++;
            ans-=r-l+1;
        }
        return ans;
    }
};
