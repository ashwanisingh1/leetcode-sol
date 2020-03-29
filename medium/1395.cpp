class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n,i,ans=0,sright=0,sleft=0,lleft=0,lright=0,j;
        n=rating.size();
        for(i=1;i<n-1;i++) {
            for(j=0;j<i;j++) {
                if(rating[i]<rating[j]) {
                    lleft++;
                }
                if(rating[i]>rating[j]) {
                    sleft++;
                }
            }
            for(j=i+1;j<n;j++) {
                if(rating[i]>rating[j]) {
                    sright++;
                }
                if(rating[i]<rating[j]) {
                    lright++;
                }
            }
            ans+=lleft*sright+lright*sleft;
            sright=sleft=lright=lleft=0;
        }
        return ans;
    }
};
