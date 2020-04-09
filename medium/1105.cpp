class Solution {
public:
    int solve(int i,vector<int>& dp,int shelf_width,vector<vector<int>>& books) {
        if(i>=books.size()) {
            return 0;
        }
        if(dp[i]!=-1) {
            return dp[i];
        }
        int width=0,maxHeight=0,ans=1000000;
        for(int j=i;j<books.size();j++) {
            maxHeight=max(maxHeight,books[j][1]);
            width+=books[j][0];
            if(width>shelf_width) {
                break;
            }
            ans=min(ans,solve(j+1,dp,shelf_width,books)+maxHeight);
        }
        return dp[i]=ans;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n=books.size();
        vector<int> dp(n+1,-1);
        return solve(0,dp,shelf_width,books);
    }
};
