class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map <int,int> dp;
        int i,ans=1;
        dp[arr[0]]=1;
        for(i=1;i<arr.size();i++) {
            dp[arr[i]]=dp[arr[i]-difference]+1;
            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};
