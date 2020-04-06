class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 100000000,i,ans=0;
        for(i=0;i<prices.size();i++) {
            if(prices[i]<minPrice) {
                minPrice=prices[i];
            } else {
                ans=max(ans,prices[i]-minPrice);
            }
        }
        return ans;
    }
};
