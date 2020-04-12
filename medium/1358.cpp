class Solution {
public:
    int numberOfSubstrings(string s) {
        int a[100001],b[100001],c[100001],i,j;
        int n=s.length(),ans=0;
        for(i=0;i<100001;i++) {
            a[i]=b[i]=c[i]=-1;
        }
        for(i=n-1;i>=0;i--) {
            if(s[i]=='a') {
               a[i]=i; 
            } else {
               a[i]=a[i+1]; 
            }
            if(s[i]=='b') {
               b[i]=i; 
            } else {
               b[i]=b[i+1]; 
            }
            if(s[i]=='c') {
               c[i]=i; 
            } else {
               c[i]=c[i+1]; 
            }
        }
        for(i=0;i<n;i++) {
            if(s[i]=='a') {
                if(c[i]!=-1&&b[i]!=-1) {
                    ans+=n-max(c[i],b[i]);
                }
            }
            if(s[i]=='b') {
                if(a[i]!=-1&&c[i]!=-1) {
                    ans+=n-max(a[i],c[i]);
                }
            }
            if(s[i]=='c') {
                if(a[i]!=-1&&b[i]!=-1) {
                    ans+=n-max(a[i],b[i]);
                }
            }
        }
        return ans;
    }
};
