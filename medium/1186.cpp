class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size(),i;
        vector<int> dp1(n,0);vector<int> dp2(n,-1000000);
        dp1[0]=arr[0];
        dp2[n-1]=arr[n-1];
        int ans=arr[0];
        int sumNow=arr[0];
        for(i=1;i<n;i++) {
            sumNow+=arr[i];
            if(sumNow<=arr[i]) {
                sumNow=arr[i];
            } 
            dp1[i]=sumNow;
            ans=max(ans,sumNow);
        }
        sumNow=dp2[n-1];
        for(i=n-2;i>0;i--) {
            sumNow+=arr[i];
            if(sumNow<=arr[i]) {
                sumNow=arr[i];
            } 
            dp2[i]=sumNow;
        }
        for(i=1;i<n-1;i++) {
            ans=max(dp1[i-1]+dp2[i+1],ans);
        }
        return ans;
    }
};
