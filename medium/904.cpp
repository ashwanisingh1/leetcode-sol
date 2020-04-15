class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int l=0,r=0,n=tree.size(),ans=0;
        unordered_map<int,int> mp;
        for(r=0;r<n;r++) {
            mp[tree[r]]++;
            while(mp.size()>2) {
                if(mp[tree[l]]==1) {
                    mp.erase(tree[l]);
                } else {
                    mp[tree[l]]--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
