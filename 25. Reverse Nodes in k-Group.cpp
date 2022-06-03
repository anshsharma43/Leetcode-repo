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
 
 //Recursive
 
/*class Solution {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        int x=0;
        
        ListNode *temp=head;
        
        while(temp!=NULL)
        {
            temp=temp->next;
            x++;
        }
        
        if(x<k)
            return head;
        
        ListNode *curr=head;
        ListNode *prev=head;
        
        int count=0;
        
        while(curr!=NULL && count<k)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
            count++;
        }
        
        head->next=reverseKGroup(curr,k);
        head=prev;
        
        return head;
    }
};*/
 
 // Iterative
 
class Solution {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode *curr=head;
        ListNode *connect=NULL;
        
        bool firstPass=false;
        
        while(curr!=NULL)
        {
            int count=0;
            
            ListNode *first=curr;
            ListNode *prev=NULL;
            
            ListNode *pass=curr;
            
            while(pass!=NULL)
            {
                pass=pass->next;
                count++;
            }
            
            if(count < k)
            {
                connect->next=curr;
                break;
            }
            
            count=0;
            
            while(curr!=NULL && count<k)
            {
                ListNode *temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                
                count++;
            }
            
            if(firstPass == false)
            {
                head=prev;
                firstPass=true;
            }
            
            else
            {
                connect->next=prev;
            }
            
            connect=first;
        }
        
        return head;
    }
};
