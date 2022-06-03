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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL)
        {
            return head;
        }
        
        ListNode *curr=head;
        ListNode *prev=NULL;
        
        int count=0;
        
        while(curr!=NULL)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        
        k=count-(k%count)-1;
        
        prev->next=head;
        curr=head;
        
        for(int i=0;i<k;i++)
        {
            curr=curr->next;
        }
        
        head=curr->next;
        curr->next=NULL;
        
        return head;
    }
};
