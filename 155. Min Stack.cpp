class MinStack {
public:
    
    stack<long long int> s;
    long long int minVal;
    
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(s.size()==0)
        {
            minVal=val*1LL;
            s.push(val*1LL);
        }
        
        else
        {
            if(val<minVal)
            {
                long long int a=val*1LL;
                a*=2;
                
                s.push(a-minVal);
                minVal=val;
            }
            
            else
            {
                s.push(val*1LL);
            }
        }
    }
    
    void pop() 
    {
        if(s.size()==0)
        {
            return;
        }
        
        else
        {
            if(s.top()<minVal)
            {
                long long int a=s.top();
                
                minVal=(2*minVal)-a;
            }
            
            s.pop();
        }
    }
    
    int top() 
    {
        if(s.size()==0)
        {
            return INT_MIN;
        }
        
        else
        {
            if(s.top()<minVal)
            {
                return minVal;
            }
            
            else
            {
                return s.top();
            }
        }
    }
    
    int getMin() 
    {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
