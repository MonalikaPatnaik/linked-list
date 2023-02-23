class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&v,int n,int m,vector<vector<int>>&grid){
        if(v[i][j] || grid[i][j]==1)return 1;
        if((i<=0 || i>=n-1 || j<=0 ||j>=m-1) )return 0;
        if(grid[i][j]==1)return 1;
        v[i][j]=1;
        
        int up=dfs(i+1,j,v,n,m,grid);
        int down=dfs(i,j+1,v,n,m,grid);
        int left=dfs(i-1,j,v,n,m,grid);
        int right=dfs(i,j-1,v,n,m,grid);
        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();int a=0;
        vector<vector<int>>v(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
               if( grid[i][j]==0 && v[i][j]==0)
                  a+=(dfs(i,j,v,n,m,grid));
          }
      }
        return a;
    }
};