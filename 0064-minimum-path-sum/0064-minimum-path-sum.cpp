class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i<0 || i>=m || j<0 || j>=n)return 1e3;
        if(i==m-1 && j==n-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]= min(grid[i][j]+solve(grid,i+1,j,m,n,dp),grid[i][j]+solve(grid,i,j+1,m,n,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        // return solve(grid,0,0,m,n,dp);
        // dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j]=grid[i][j];
                else if(i==0){
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                }
                else if(j==0)dp[i][j]=grid[i][j]+dp[i-1][j];
                else dp[i][j]=min(grid[i][j]+dp[i-1][j],grid[i][j]+dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};