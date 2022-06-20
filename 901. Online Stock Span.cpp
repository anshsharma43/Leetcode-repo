class StockSpanner {
public:
    
    stack<pair<int,int>> s;
    
    int count=0;
    
    StockSpanner() 
    {
        
    }
    
    int next(int x) 
    {   
        while(s.empty()==false && s.top().first<=x)
        {
            s.pop();
        }
        
        int res=s.empty()==true?count+1:count-s.top().second;
        
        s.push({x,count});
        
        count++;
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
