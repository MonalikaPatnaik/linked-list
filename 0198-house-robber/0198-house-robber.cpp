class Solution {
public:
    int solve(vector<int>& nums,int n){
        if(n<=0)return 0;
       return max(nums[n-1]+solve(nums,n-2),solve(nums,n-1));
    }
    int rob(vector<int>& nums) {
        // int s1=0;int s2=0;
        // for(int i=0;i<nums.size();i++){
        //     if(i%2==0)s1+=nums[i];
        //     else s2+=nums[i];
        // }
        // return max(s1,s2);
        // return solve(nums,nums.size());
        int n=nums.size();
        vector<int>dp(n+1);
        
        dp[0]=0;dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];
    }
};