/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node *curr=head;
        
        while(curr!=NULL)
        {
            Node *temp=new Node(curr->val);
            Node *next=curr->next;
            temp->next=curr->next;
            curr->next=temp;
            curr=curr->next->next;
        }
        
        curr=head;
        
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->random!=NULL)
            {
                curr->next->random=curr->random->next;
            }
            
            else
            {
                curr->next->random=NULL;
            }
            
            curr=curr->next->next;
        }
        
        curr=head;
        
        Node *newHead=new Node(1);
        Node *tail=newHead;
        
        while(curr!=NULL)
        {
            Node *temp=curr->next;
            curr->next=temp->next;
            tail->next=temp;
            tail=tail->next;
            curr=curr->next;
        }
        
        return newHead->next;
        
    }
};
