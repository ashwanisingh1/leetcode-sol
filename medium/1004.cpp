class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l=0,r=0,k=0,n=A.size(),ans=0;
        while(r<n) {
            if(A[r]==0) {
                if(k<K) {
                    k++;
                    r++;
                } else {
                    k=(A[l]==1?k:k-1);
                    l++;
                }
            } else {
                r++;
            }
            ans=max(ans,r-l+1);
        }
        return ans-1;
    }
};
