class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n,m,i,j,k;
        if (mat.size()==0) {
            return mat;
        }
        n= mat[0].size();
        m=mat.size();
        vector <int> temp;
        for (k=0;k<n;k++) {
            for(j=k;j<n;j++) {
                for(i=0;i<m && i+j<n ;i++) {
                    temp.push_back(mat[i][i+j]);
                }
                sort(temp.begin(),temp.end());
                for(i=0;i<m && i+j<n;i++) {
                    mat[i][i+j] = temp[i];
                }
                temp.clear();
            }
        }
        for (k=0;k<m;k++) {
            for(j=k;j<m;j++) {
                for(i=0;i<n && i+j<m ;i++) {
                    temp.push_back(mat[i+j][i]);
                }
                sort(temp.begin(),temp.end());
                for(i=0;i<n && i+j<m ;i++) {
                    mat[i+j][i] = temp[i];
                }
                temp.clear();
            }
        }
        return mat;
    }
};
