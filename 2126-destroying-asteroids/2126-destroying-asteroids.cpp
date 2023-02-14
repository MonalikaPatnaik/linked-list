class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long sum=mass;
        for(int i=0;i<a.size();i++){
            if(a[i]>sum)return false;
            sum=(sum+a[i]);
        }
        return true;
    }
};