class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        int n=s.length(),i,count[1001]={0},visited[1001]={0};
        for(i=0;i<n;i++) {
            count[s[i]]++;
        }
        for(i=0;i<n;i++) {
            count[s[i]]--;
            if(visited[s[i]]) {
                continue;
            }
            while(ans.size()&&ans.back()>s[i]&&count[ans.back()]>=1) {
                visited[ans.back()]=0;
                ans.pop_back();
            }
            if(visited[s[i]]==0) {
                ans+=s[i];
                visited[s[i]]=1;
            }
        }
        return ans;
    }
};
