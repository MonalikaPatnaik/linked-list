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
    ListNode* reverse(ListNode*head){
        ListNode*curr=head;
        ListNode*prev=NULL;
            ListNode*nxt;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode*r1=reverse(l1);
         ListNode*r2=reverse(l2);
         ListNode*sum=new ListNode(-1);
         ListNode*st=sum;
        int carry=0;
        while(r1 || r2|| carry){
            int val1=0;int val2=0;
            if(r1){
             val1=r1->val;
                r1=r1->next;
            }
            if(r2){
                 val2=r2->val;
                r2=r2->next;
            }
            int s=val1+val2+carry;
            sum->next=new  ListNode(s%10);
            sum=sum->next;
            carry=s/10;
        }
       return reverse(st->next);
        
    }
};