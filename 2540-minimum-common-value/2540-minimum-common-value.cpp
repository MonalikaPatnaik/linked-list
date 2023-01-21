class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       map<int,int>mp;
        for(auto e:nums1)mp[e]++;
        for(auto e:nums2){
            if(mp.find(e)!=mp.end()){
                return e;
                break;
            }
        }
        return -1;
    }
};