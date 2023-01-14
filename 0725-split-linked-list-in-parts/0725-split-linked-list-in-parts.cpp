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
    int getlen(ListNode* head){
        int c=0;
        while(head){
            c++;
            head=head->next;
        }
        return c;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // if(k==1)return head;
        int n=getlen(head);
        ListNode* temp=head;
        
        vector<ListNode*> ans;
           int extra=n%k;
               
            int lenofparts=n/k;
            while(temp){
                int c=1;
                ListNode*headofpart=temp;
                while(c<lenofparts){
                    c++;
                    temp=temp->next;
                }
                if(extra && n>k){
                    extra--;
                    temp=temp->next;
                }
                ListNode*a=temp->next;
               
                temp->next=NULL;
                temp=a;
                ans.push_back(headofpart);
            }
        // while(temp){
        //      ListNode*a=temp->next;
        //      temp->next=NULL;
        //     ans.push_back(temp);
        //     temp=a;
        //     k--;
        // }
         while(k-n>0){ans.push_back(NULL);n++;}
        return ans;
        
    }
};