class Solution {
public:
    vector<int>v1;vector<int>v2;
    Solution(vector<int>& nums) {
        v1=v2=nums;
    }
    
    vector<int> reset() {
        return v1;
    }
    
    vector<int> shuffle() {
      int x=  rand()%v1.size();
        int y=rand()%v1.size();
        swap(v2[x],v2[y]);
        return v2;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */