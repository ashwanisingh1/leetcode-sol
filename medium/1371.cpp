class Solution {
public: 
    int findTheLongestSubstring(string s) {
        int n=s.length();
        int i=0,bitmask=0,ans=0,j;
        map<int,int> mp;
        mp[0]=-1;
        string str="aeiou";
        for(i=0;i<n;i++) {
            for(j=0;j<5;j++) {
                if(str[j]==s[i]) {
                    bitmask=(bitmask^(1<<j));
                }
            }
            if(mp.find(bitmask)!=mp.end()) {
                    ans=max(ans,i-mp[bitmask]);
                } else {
                    mp[bitmask]=i;
                }
        }
        return ans;
    }
};
