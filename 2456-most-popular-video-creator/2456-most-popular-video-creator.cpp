
class mycomp{
    public:
    bool operator()(pair<int,string>&a,pair<int,string>&b){
        if(a.first==b.first)
            return a.second>b.second;
        else return a.first<b.first;    
            
    }
};
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& v) {
        unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,mycomp>>mp;
        vector<vector<string>>ans;
        for(int i=0;i<c.size();i++){
            mp[c[i]].push({v[i],ids[i]});
        }
        unordered_map<string,int>m;
        for(int i=0;i<c.size();i++){
            if(m.find(c[i])!=m.end()){
                m[c[i]]=(m[c[i]]+v[i])% int(1e9+7);
            }
            else{
                m[c[i]]=v[i];
            }
        }
        priority_queue<pair<int,string>>pq;
        for(auto e:m){
            pq.push({e.second,e.first});
        }
        auto top=pq.top();
        pq.pop();
        string t=top.second;
        auto e=(mp[t].top());
        // if(mp[t].size()>1)ans.push_back({t,e.second});
           ans.push_back({t,e.second});
        while(!pq.empty() && pq.top().first==top.first){
            string r=pq.top().second;
            pq.pop();
             auto k=(mp[r].top());
            ans.push_back({r,k.second});
        }
        return ans;
    }
};