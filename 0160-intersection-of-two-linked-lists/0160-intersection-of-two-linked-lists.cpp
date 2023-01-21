/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getlen(ListNode *head){
        int  c=0;
        while(head){
            head=head->next;
            c++;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA;
        ListNode *temp2=headB;
      int l1= getlen(temp1);
        int l2=getlen(temp2);
        if(l1>l2){
            while(l1-l2){
                temp1=temp1->next;
                l1--;
            }
        }
        else{
            while(l2-l1){
                temp2=temp2->next;
                l2--;
            }
        }
        while(temp1 &&temp2){
            if(temp1==temp2)
                return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};