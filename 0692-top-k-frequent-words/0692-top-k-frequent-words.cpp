
class MyComp{
    public:
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first < b.first;
            }
            else {
                return a.second > b.second;
            }
        }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        vector<string>ans;
        for(auto i:words)
            mp[i]++;
    
        priority_queue<pair<int,string>,vector<pair<int,string>>,MyComp>pq;
        for(auto i:mp)
            pq.push({i.second,i.first});
        while(k--){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
         // sort(ans.begin(),ans.end());
        return ans;
    }
};