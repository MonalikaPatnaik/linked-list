

class TweetCounts {
public:
   unordered_map<string,vector<int>>mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int s, int e) {
        int k;
       
        if(freq=="minute"){
            k=60;
        }
        else if(freq=="hour"){
           k=3600;
        }
        else{
            k=86400;
            }
        int c=(e-s)/k;
        vector<int>ans(c+1,0);
        for(auto time:mp[tweetName]){
            if(time>=s && time<=e){
                ans[(time-s)/k]++;
            }
        }
       
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */