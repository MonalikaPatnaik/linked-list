class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int n1=left.size();
        int n2=right.size();
       int ans=0;
        for(auto i:left)ans=max(ans,i);
        for(auto i:right)ans=max(ans,n-i);
        return ans;
    }
};