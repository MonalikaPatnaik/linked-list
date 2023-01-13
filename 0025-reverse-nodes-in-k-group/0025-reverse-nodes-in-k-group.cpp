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
    int getlen(ListNode*head){
        int c=0;
        while(head)
        {
            head=head->next;
            c++;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next)return head;
        // ListNode*temp=head;
        // for(int i=0;i<k;i++){
        //     if(!temp)return head;
        //     temp=temp->next;
        // }
        // ListNode* curr=head;
        //     ListNode*prev=NULL;
        //     ListNode*nxt=NULL;
        // int cnt=0;
        // while(curr&& cnt<k ){
        //     nxt=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=nxt;
        //     cnt++;
        // }
        // head->next=reverseKGroup(curr,k);
        // return prev;
        int n=getlen(head);
        ListNode*dummy=new ListNode(-1);
        ListNode*start=dummy;
        
        
        ListNode*nxt;
        for(int i=0;i<n/k;i++){
            ListNode*prev=NULL;
            ListNode*curr=head;
            for(int j=0;j<k;j++){
                nxt=head->next;
             head->next=prev;
             prev=head;
             head=nxt;
            }
            dummy->next=prev;
            dummy=curr;
            curr->next=head;
            // head=curr;
        }
        return start->next;
    }
};