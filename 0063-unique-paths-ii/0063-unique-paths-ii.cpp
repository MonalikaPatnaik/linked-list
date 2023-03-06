class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i<0||i>=m || j<0 || j>=n || grid[i][j]==1)return 0;
        if( grid[i][j]!=1 && i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(grid,i+1,j,m,n,dp)+solve(grid,i,j+1,m,n,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(obstacleGrid,0,0,obstacleGrid.size(),obstacleGrid[0].size(),dp);
        
        // int m=obstacleGrid.size();
        // int n=obstacleGrid[0].size();
        // if(obstacleGrid[m-1][n-1]==1)return 0;
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(obstacleGrid[i][j]==1 &&(i==0 || j==0)){dp[m-1][n-1]=0;}
        //          else if(obstacleGrid[i][j]!=1)dp[i][j]=1;
        //         else{
        //             if(dp[i-1][j]==0 && dp[i][j-1]==0)dp[i][j]=0;
        //             else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
        
    }
};