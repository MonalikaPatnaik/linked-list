class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        long long combinations=0;
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;
            // count posssible combinations abhi tak ke
            combinations+=mp[nums[j]]-1;
            while(i<j && combinations>=k){
                ans+=n-j;
                mp[nums[i]]--;
                combinations-=mp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};