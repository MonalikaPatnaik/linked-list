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
    ListNode*findmid(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode*merge(ListNode*&head1,ListNode*&head2){
        ListNode*ans=new ListNode(-1);
        
        ListNode*dummy=ans;
         if(!head1)return head2;
        if(!head2)return head1;
        while(head1 && head2){
                if(head1->val<head2->val){
                    dummy->next=head1;
                    head1=head1->next;
                    
                }
                else {dummy->next=head2; head2=head2->next;}
                dummy=dummy->next;
            }
        while(head1){
            dummy->next=head1;
            head1=head1->next;
            dummy=dummy->next;
        }
        while(head2){
            dummy->next=head2;
            head2=head2->next;
            dummy=dummy->next;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* &head) {
        if(!head || !head->next)return head;
        ListNode*mid=findmid(head);
        
        ListNode*a=mid->next;
         
        mid->next=NULL;
       ListNode*left= sortList(head);
       ListNode* right= sortList(a);
       return  merge(left,right);   
           
    }
};