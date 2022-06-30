class Solution {
public:
    string removeDuplicates(string str) 
    {
        int n=str.size();
        
        string res;
        
        stack<char> s;
        
        for(int i=0;i<n;i++)
        {
            if(s.empty()==false && str[i]==s.top())
            {
                s.pop();
            }
            
            else
            {
                s.push(str[i]);
            }
        }
        
        while(s.empty()==false)
        {
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};
