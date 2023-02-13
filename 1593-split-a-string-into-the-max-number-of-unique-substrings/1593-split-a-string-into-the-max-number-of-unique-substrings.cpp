class Solution {
public:
    int find(int i,string s,unordered_map<string,int>&mp,string temp){
        if(i==s.size())return 0;
        temp+=s[i];
        int op1=0,op2=0;
        if(mp.find(temp)==mp.end()){
            mp[temp]++;
            op1=max(op1,1+find(i+1,s,mp,""));
            mp.erase(temp);
        }
        op2=max(op2,find(i+1,s,mp,temp));
        return max(op1,op2);
    }
    int maxUniqueSplit(string s) {
        unordered_map<string,int>mp;
     return find(0,s,mp,"");
    }
};