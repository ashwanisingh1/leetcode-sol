class Solution {
public:
    long int mod = 2000000011;
    long int power(long int a,long int b) {
        long int ans=1;
        while(b) {
            if(b%2) {
                ans=((ans%mod)*(a%mod))%mod;
            } 
            a=((a%mod)*(a%mod))%mod;
            b=b/2;
        }
        return ans;
    }
    
    long int inverse(long int a) {
        return power(a,mod-2);
    }
    
    int uniquePaths(int m, int n) {
        m--,n--;
        if(m==0 || n==0) {
            return 1;
        }
        long long int ans=1,temp=1;
        for(int i=1;i<=m+n;i++) {
            ans=(ans*i)%mod;
        }
        for(int i=1;i<=n;i++) {
            ans=(ans*inverse(i))%mod;
        }
        for(int i=1;i<=m;i++) {
            ans=(ans*inverse(i))%mod;
        }
        return min((long long int)2000000000,ans);
    }
};
