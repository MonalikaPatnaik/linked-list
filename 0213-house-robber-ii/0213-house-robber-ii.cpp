class Solution {
public:
    int solve(vector<int>& nums,int n, vector<int>&dp){
        if(n<=0)return 0;
        if(dp[n]!=-1)return dp[n];
        // if(n==0){
        //     if(flag)return 0;
        //     return nums[0];
        // }
        return dp[n]= max(nums[n-1]+solve(nums,n-2,dp),solve(nums,n-1,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        // if(n==1)return nums[0];
        // return solve(nums,0,0,n);
        // return max(nums[n-1]+solve(nums,n-3,1),solve(nums,n-2,0));
      
        // dp[0]=0;bool flag=0;
        // dp[1]=nums[0];
        // dp[2]=max(nums[0],nums[1]);
        // if(dp[2]==nums[0])flag=1;
        // for(int i=3;i<=n;i++){
        //     if(i==n){
        //         if(flag)dp[i]=max(dp[i-2],dp[i-1]);
        //         else dp[i]=nums[n-1];
        //     }
        //    else dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        // }
        // return dp[n];
        
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int>v2(nums.begin()+1,nums.end());
          vector<int>dp1(n);dp1[0]=0;dp1[1]=v1[0];
        vector<int>dp2(n);dp2[0]=0;dp2[1]=v2[0];
        for(int i=2;i<n;i++){
            dp1[i]=max(dp1[i-1],v1[i-1]+dp1[i-2]);
             dp2[i]=max(dp2[i-1],v2[i-1]+dp2[i-2]);
        }
        // int a1=solve(v1,n-1,dp);
        // int a2=solve(v2,n-1,dp);
        return max(dp1[n-1],dp2[n-1]);
    }
};