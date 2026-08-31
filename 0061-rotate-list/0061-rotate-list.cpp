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
    ListNode* rotateRight(ListNode* head, int k) {
        
if(head==NULL || head->next==NULL)
return head;


        ListNode* last=head;
        int n=1;

        while(last->next!=NULL)
        {    n++;
             last=last->next;
        }

        k=k%n;
        if(k==0)
        return head;

        int count=1;
        ListNode *temp=head;
               
               while(temp->next!=NULL){
            if(count == n-k){
            break;
            }
            count++;

            temp=temp->next;
        }
        ListNode* res;
       
         last->next=head;
           res=temp->next;
        temp->next=NULL;

        return res;


    }
};