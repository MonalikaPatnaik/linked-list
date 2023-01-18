/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto e:nums)mp[e]++;
        int c=0;bool flag=true;
        ListNode*temp=head;
//         while(temp->next)
//             {mp[temp->next->val]=temp->val;
//              temp=temp->next;
//         n++;}
//        vector<int>v(n+1,0);
// sort(nums.begin(),nums.end());
//         mp[head->val]=head->val;
//         for(auto e:nums){
//             if(!v[e] && !v[mp[e]]){
//                 v[mp[e]]=1;
//                 c++;
//             }
//             v[e]=1;
//         }
//         return c;
        while(head){
          if(mp.find(head->val)==mp.end()){
               
              flag=true;
           } 
        else {
            if(flag){
              c++;
               flag=false;  
            }
        } 
        head=head->next;
        }
        return c;
    }
};