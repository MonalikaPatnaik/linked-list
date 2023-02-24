class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int n,int m,int i,int j,int k){
        if(k==word.size())return 1;
        if(i<0 ||i>=n || j<0 || j>=m || board[i][j]!=word[k])return 0;
        board[i][j]='0';
        bool l=dfs(board,word,n,m,i,j-1,k+1);
        bool r=dfs(board,word,n,m,i-1,j,k+1);
        bool u=dfs(board,word,n,m,i,j+1,k+1);
        bool d=dfs(board,word,n,m,i+1,j,k+1);
        board[i][j]=word[k];
        return l|| r|| u||d;
    } 
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();bool ans;
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0])
                    {if(dfs(board,word,n,m,i,j,0))return 1;}
            }
        }
        return 0;
    }
};