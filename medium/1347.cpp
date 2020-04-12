class Solution {
public:
    int minSteps(string s, string t) {
        int scount[1001]={0},tcount[1001]={0};
        int i,n=s.length(),ans=0;
        for(i=0;i<n;i++) {
            scount[s[i]]++;
            tcount[t[i]]++;
        }
        for(i=0;i<1001;i++) {
            if(scount[i]-tcount[i]>0) {
                ans+=scount[i]-tcount[i];
            }
        }
        return ans;
    }
};
