class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j,k,n,m;
        int flag1=0,flag2=0;
        n=matrix.size();
        if(n==0) {
            return;
        }
        m=matrix[0].size();
        for(i=0;i<n;i++) {
                if(matrix[i][0] == 0) {
                    flag1=1;
                }
            }
            for(i=0;i<m;i++) {
                if(matrix[0][i] == 0) {
                    flag2=1;
                }
            }
        for(i=1;i<n;i++) {
            for(j=1;j<m;j++) {
                if(matrix[i][j]==0) {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(i=1;i<n;i++) {
            for(j=1;j<m;j++) {
                if(matrix[0][j]==0||matrix[i][0]==0) {
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0) {
            for(i=0;i<n;i++) {
                matrix[i][0]=0;
            }
            for(i=0;i<m;i++) {
                matrix[0][i]=0;
            }
        } else {
            
            if(flag1==1) {
                for(i=0;i<n;i++) {
                matrix[i][0]=0;
            }
            }
                if(flag2==1){
            for(i=0;i<m;i++) {
                matrix[0][i]=0;
            }
            }
        }
    }
};
