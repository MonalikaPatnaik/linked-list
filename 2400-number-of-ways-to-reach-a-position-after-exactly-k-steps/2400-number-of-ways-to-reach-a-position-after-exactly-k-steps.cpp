class Solution {
public:
    int numberOfWays1(int s, int e, int k,vector<vector<int>>&dp)
     {
        if(k==0 && s==e)return 1;
        if(k<=0)return  0;
        if(dp[s+1000][k]!=-1)return dp[s+1000][k];
        return dp[s+1000][k]=(numberOfWays1(s+1,e,k-1,dp)+numberOfWays1(s-1,e,k-1,dp))%int(1e9+7);
    }
    int numberOfWays(int s, int e, int k) {
       vector<vector<int>>dp(3000,vector<int>(k+1,-1));
       return numberOfWays1(s,e,k,dp)%int(1e9+7);
    }
};