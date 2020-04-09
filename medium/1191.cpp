class Solution {
public:
    long int mod=1e9+7;
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long int preMax=0,prei=-1,suffi=-1,suffMax=0,i,n=arr.size(),temp,posl,posr,sum=0;
        temp=0;
        for(i=0;i<n;i++) {
            sum+=arr[i];
            temp+=arr[i];
            if(preMax<temp) {
                preMax=temp;
                prei=i;
            }
        }
        temp=0;
        for(i=n-1;i>=0;i--) {
            temp+=arr[i];
            if(suffMax<temp) {
                suffMax=temp;
                suffi=i;
            }
        }
        temp=arr[0];
        posl=0;
        posr=0;
        long int ans=0;
        for(i=1;i<n;i++) {
            ans=max(ans,temp);
            if(temp<=0) {
                posl=i;
                posr=i;
                temp=arr[i];
            } else {
                temp+=arr[i];
                posr++;
            }
        }
        ans=max(temp,ans);
        if(k==1) {
            return ans;
        }
        if(k>=3) {
            return max(max(max(((sum%mod)*(k%mod))%mod,((suffMax%mod+preMax%mod)%mod+(((k-2)%mod)*(sum%mod)%mod))%mod),ans),(suffMax%mod+preMax%mod)%mod);
        }
        return max(max(((sum%mod)*(k%mod))%mod,ans),(suffMax%mod+preMax%mod)%mod);
    }
};
