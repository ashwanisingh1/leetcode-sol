class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i=0,j=0,n=A.size(),m=B.size();
        vector<vector<int>> ans;
        vector<int> temp;
        while(i<n&&j<m) {
            temp.clear();
            if((A[i][0]>=B[j][0]&&A[i][0]<=B[j][1])||(A[i][0]<=B[j][0]&&A[i][1]>=B[j][1])) {
                temp.push_back(max(A[i][0],B[j][0]));
                temp.push_back(min(A[i][1],B[j][1]));
                ans.push_back(temp);
                if((A[i][0]>=B[j][0]&&A[i][1]<=B[j][1])) {
                 i++;   
                } else {
                j++;
                }
            } else {
                if(A[i][1]>=B[j][0]&&A[i][1]<=B[j][1]) {
                    temp.push_back(max(A[i][0],B[j][0]));
                    temp.push_back(min(A[i][1],B[j][1]));
                    ans.push_back(temp);
                    i++;
                } else {
                    if(A[i][0]>=B[j][1]) {
                        j++;
                    } else {
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};
