class Solution {
public:
    int alternateDigitSum(int n) {
        int sum=0;int flag;
        string str=to_string(n);
        for(int i=0;i<str.size();i++){
            if(i%2==0)flag=1;
            else flag=-1;
            sum+=(str[i]-'0')*flag;
        }
        return sum;
    }
};