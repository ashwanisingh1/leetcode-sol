class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l=0,r=people.size()-1,ans=0;
        sort(people.begin(),people.end());
        while(l<=r) {
            if(people[l]+people[r]<=limit) {
                ans++;
                l++,r--;
            } else {
                ans++;
                r--;
            }
        }
        return ans;
    }
};
