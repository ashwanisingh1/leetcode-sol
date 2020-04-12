class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        int i,n=s.length();
        string ans;
        for(i=0;i<n;i++) {
            if(s[i]=='('||s[i]==')') {
                if(s[i]==')') {
                    if(st.size()) {
                        st.pop();
                    }
                    else {
                        s[i]='?';
                    }
                } else {
                    st.push({'(',i});
                }
            }
        }
        while(st.size()) {
            s[st.top().second]='?';
            st.pop();
        }
        for(i=0;i<n;i++) {
            if(s[i]!='?') {
                ans+=s[i];
            }
        }
        return ans;
    }
};
