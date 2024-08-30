// User function Template for C++

class Solution{
public:
void find(int row,int n,vector<vector<int>>&ans,vector<int>&board,vector<bool>&col,vector<bool>&leftdiag,vector<bool>&rightdiag){
    if(row==n){
        ans.push_back(board);
        return ;
    }
    for(int j=0;j<n;j++){
         if(col[j]==0&&leftdiag[row-j+n-1]==0&&rightdiag[row+j]==0){
        col[j]=1;
        leftdiag[row-j+n-1]=1;
        rightdiag[row+j]=1;
        board[j]=row+1;
        find(row+1,n,ans,board,col,leftdiag,rightdiag);
        col[j]=0;
        leftdiag[row-j+n-1]=0;
        rightdiag[row+j]=0;
        board[j]=0;
    }
    }
}
    vector<vector<int>> nQueen(int n) {
         vector<vector<int>>ans;
         vector<int>board(n,0);
         vector<bool>col(n,0);
         vector<bool>leftdiag(2*n-1,0);
         vector<bool>rightdiag(2*n-1,0);
         find(0,n,ans,board,col,leftdiag,rightdiag);
         sort(ans.begin(),ans.end());
         return ans;
    }
};
