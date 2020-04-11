class Solution {
public:
    int numSteps(string s) {
        int i,one=0,zero=0,n=s.length(),ans=0;
        for(i=n-1;i>=0;i--) {
            if(s[i]=='1') {
                if(zero!=0) {
                    ans+=zero;
                    zero=0;
                }
                one++;
            } else {
                if(one!=0) {
                    ans+=one+1;
                    one=1;
                    zero=0;
                } else {
                    zero++;
                }
            }
        }
        if(one>1) {
            ans+=one+1;
        }
        return ans;
    }
};
