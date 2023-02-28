class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto e:nums){mp[e]++;
        if(mp[e]>1)return 1;}
        return 0;
    }
};