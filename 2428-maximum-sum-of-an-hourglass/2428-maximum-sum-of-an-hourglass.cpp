class Solution {
public:
int find(vector<vector<int>>& grid,int row,int col,int m,int n){
    if(n-col<=2 || m-row<=2)return 0;
    int ans=0;
    for(int i=row;i<row+3;i++){
        for(int j=col;j<col+3;j++){
           
            if(i==row+1){ans+=grid[i][col+1];break;}
            else ans+=grid[i][j];
             // cout<<ans<<" ";
        }
        // cout<<endl;
    }
    return ans;
}
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int mx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              mx=max(mx,find(grid,i,j,m,n));
            }
        }
        return mx;
    }
};