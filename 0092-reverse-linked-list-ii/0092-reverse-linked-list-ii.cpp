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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode *temp=head;

       for(int i = 1; i < left-1; i++)
       {
        temp=temp->next;
       }

       ListNode *before = NULL;
       if(left==1)
       {
        before=NULL;
       }
       else
       {
        before=temp;
       }
       ListNode *curr;

       if(left==1)
       {
        curr=head;
       }
       else
       {
        curr=temp->next;
       }

       ListNode *prev =NULL;
       int time = right -left +1;

        ListNode *next = curr->next;

        while(time--)
        {
             ListNode *next = curr->next;
             curr->next=prev;
             prev=curr;
             curr=next;
        }
        if(before != NULL)
        {
            before->next->next=curr;
            before->next=prev;
        }
        else
        {
            head->next=curr;
            head=prev;
        }
        return head;
       
    }
};