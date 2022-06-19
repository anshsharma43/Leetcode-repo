class Solution {
public:
    
    // can also use unordered_map<char,char> to acheive the same as the function
    
    bool isHelper(char &a,char &b)
    {
        return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
    }
    
    bool isValid(string str) 
    {
        int n=str.size();
        
        stack<char> s;
        
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            {
                s.push(str[i]);
            }
            
            else
            {
                if(s.empty()==false && isHelper(s.top(),str[i])==true)
                {
                    s.pop();
                }
                
                else
                {
                    return false;
                }
            }
        }
        
        return s.empty()==true;
    }
};
