class Solution {
public:
    string removeDuplicates(string str, int k) 
    {
        int n=str.size();
        
        stack<pair<char,int>> s;
        
        for(int i=0;i<n;i++)
        {
            if(s.empty()==false && s.top().first==str[i])
            {
                s.top().second+=1;
            }
            
            else
            {
                s.push({str[i],1});
            }
            
            if(s.empty()==false && s.top().second==k)
            {
                s.pop();
            }
        }
        
        string res;
        
        while(s.empty()==false)
        {
            int count=s.top().second;
            
            while(count>=1)
            {
                res.push_back(s.top().first);
                count--;
            }
            
            s.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};
