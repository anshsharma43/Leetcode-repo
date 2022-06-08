class Solution {
public:
    
    void helper(int open,int close,int n,string &input,vector<string> &res)
    {
        if(open==n && close==n)
        {
            res.push_back(input);
            return;
        }
        
        if(open<=close)
        {
            input.push_back('(');
            helper(open+1,close,n,input,res);
            input.pop_back();
        }
        
        else
        {
            if(open!=n)
            {
                input.push_back('(');
                helper(open+1,close,n,input,res);
                input.pop_back();
            }
            
            input.push_back(')');
            helper(open,close+1,n,input,res);
            input.pop_back();
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        
        int open=0,close=0;
        
        string input="";
        
        helper(open,close,n,input,res);
        
        return res;
    }
};
