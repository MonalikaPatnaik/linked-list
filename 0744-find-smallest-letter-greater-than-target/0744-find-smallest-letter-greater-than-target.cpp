class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto e:letters){
            if(e>target)return e;
            
        }
        return letters[0];
    }
};