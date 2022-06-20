class LRUCache {
public:
    
    class Node
    {
        public:
        int key_;
        int val_;
        Node *prev;
        Node *next;
        
        Node(int key,int val)
        {
            key_=key;
            val_=val;
            prev=NULL;
            next=NULL;
        }
    };
    
    Node *head=new Node(0,0);
    Node *tail=new Node(0,0);
    
    int capacity;
    
    unordered_map<int,Node *> mp;
    
    LRUCache(int c) 
    {
        capacity=c;
        head->next=tail;
        tail->prev=head;
    }
    
    void insertnode(Node *currnode)
    {
        Node *tempnode=head->next;
        currnode->next=tempnode;
        tempnode->prev=currnode;
        head->next=currnode;
        currnode->prev=head;
    }
    
    void deletenode(Node *currnode)
    {
        Node *delprev=currnode->prev;
        Node *delnext=currnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            int result=mp[key]->val_;
            
            Node *tempnode=mp[key];
            mp.erase(key);
            
            deletenode(tempnode);
            insertnode(tempnode);
            mp[key]=head->next;
            
            return result;
        }
        
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            Node *tempnode=mp[key];
            mp.erase(key);
            
            deletenode(tempnode);
        }
        
        if(mp.size()==capacity)
        {
            Node *tempnode=tail->prev;
            mp.erase(tempnode->key_);
            deletenode(tempnode);
        }
        
        insertnode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
