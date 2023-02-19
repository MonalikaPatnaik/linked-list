class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;int j=0;int mx=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[fruits[j]]++;
             if(mp.size()<=2){
                 mx=max(j-i+1,mx);j++;
             }
            else{
                while(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                    i++;
                }
                mx=max(j-i+1,mx);j++;
            }
        }
        return mx;
    }
};