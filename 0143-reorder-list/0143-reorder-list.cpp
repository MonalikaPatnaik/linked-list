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
        if(!head || !head->next)return head;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode*reverse(ListNode*head){
        if(!head || !head->next)return head;
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
    void reorderList(ListNode* head) {
        if(!head->next)return;
        ListNode*mid=findmid(head);
        ListNode*head1=reverse(mid->next);
        ListNode*temp=head;
        // ListNode*head3=temp->next;
        // ListNode*head2=head1->next;
        while(temp!=mid){
            ListNode*head3=temp->next;
        ListNode*head2=head1->next;
            temp->next=head1;
            head1->next=head3;
            temp=head3;
            head1=head2;
        }
        if(head1)mid->next=head1;
        else mid->next=NULL;
        
    }
};