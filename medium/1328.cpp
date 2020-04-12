class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size(),i,f=0;
        if(n==1) {
            return "";
        }
        for(i=0;i<n/2;i++) {
            if(palindrome[i]!='a') {
                palindrome[i]='a';
                f=1;
                break;
            }
        }
        if(!f) {
            palindrome[n-1]='b';
        }
        return palindrome;
    }
};
