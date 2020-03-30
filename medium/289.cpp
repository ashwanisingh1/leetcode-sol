class Solution {
public:
    bool check(int a, int b, int n,int m) {
        if(a>=0&&a<n&&b>=0&&b<m) {
            return 1;
        }
        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n,m,i,j,count;
        n=board.size();
        m=board[0].size();
        int directionx[] = {0,0,1,-1,1,-1,-1,1};
        int directiony[] = {1,-1,0,0,1,-1,1,-1};
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                count=0;
                for(int k=0;k<8;k++) {
                    // 0 -> same 1-> same 2-> got 1 from 0 3->got 0 from 1
                    if(check(i+directionx[k],j+directiony[k],n,m)) {
                        if(board[i+directionx[k]][j+directiony[k]]==1||board[i+directionx[k]][j+directiony[k]]==3) {
                            count++;
                        }
                    }
                }
                if(board[i][j]==0) {
                    if(count!=3) {
                        board[i][j]=0;
                    } else {
                        board[i][j]=2; 
                    }
                } else {
                    if (count<2) {
                        board[i][j]=3;
                    } else {
                        if(count>3) {
                           board[i][j]=3; 
                        } else {
                            board[i][j]=1;
                        }
                    }
                }
            }
        }
         for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(board[i][j]==2) {
                    board[i][j]=1;
                }
                if(board[i][j]==3) {
                    board[i][j]=0;
                }
            }
         }
    }
};
