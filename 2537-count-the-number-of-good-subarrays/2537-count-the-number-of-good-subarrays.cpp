class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i = 0, j = 0 , n = nums.size();
        unordered_map<int,int> mp;
        long long int c = 0 , ans = 0;
        while(j < n){
            mp[nums[j]]++;
            c += mp[nums[j]] - 1;
			while(i < j and c >= k){
				ans += n - j;
				mp[nums[i]]--;
				c -= mp[nums[i]];
				i++;
			}
            j++;
        }
        return ans;
    }
};