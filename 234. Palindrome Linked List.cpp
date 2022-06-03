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
    
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr=head;
        ListNode *prev=NULL;
        
        while(curr!=NULL)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        fast=reverse(slow->next);
        slow=head;
        
        while(fast!=NULL)
        {
            if(slow->val != fast->val)
                return false;
            
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
    }
};
