class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j,n,m;
        if(matrix.size()==0) {
            return;
        }
        n=matrix.size();
        m=matrix[0].size();
        //transpose
        for(i=0;i<n;i++) {
            for(j=i;j<m;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse
        for(i=0;i<n;i++) {
            for(j=0;j<m/2;j++) {
                swap(matrix[i][j],matrix[i][m-j-1]);
            }
        }
    }
};
