class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        vector<int>left(n);left[0]=1;
        vector<int>right(n);right[n-1]=1;
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i-1];
            right[n-i-1]=right[n-i]*nums[n-i];
        }
        for(int i=0;i<n;i++){
            ans.push_back(left[i]*right[i]);
        }
        return ans;
    }
};