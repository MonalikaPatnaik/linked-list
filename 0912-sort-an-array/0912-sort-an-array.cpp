class Solution {
public:
  void  merge(vector<int>& nums,int s,int e){
        int m=s+(e-s)/2;
        int l1=m-s+1;int l2=e-m;
            int *first=new int[l1];
        int *second=new int[l2];
        int i=s;int j=m+1;
        for(int j=0;j<l1;j++)
          first[j]=nums[i++];
        for(int j=0;j<l2;j++)
          second[j]=nums[i++];
        i=s;int p=0;int q=0;
        while(p<l1 && q<l2){
            if(first[p]<second[q])nums[i++]=first[p++];
            else nums[i++]=second[q++];
        }
        while(p<l1){
            nums[i++]=first[p++];
          
        }
        while(q<l2){
           nums[i++]=second[q++];
        }
        
    }
   void sort(vector<int>& nums,int s,int e){
        int m=s+(e-s)/2;
        if(s>=e)return ;
        sort(nums,s,m);
        sort(nums,m+1,e);
        merge(nums,s,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums,0,nums.size()-1);
        return nums;
    }
};