class Solution {
public:
    
    bool isPalindrome(string str,int low,int high)
    {   
        while(low<high)
        {
            if(str[low]!=str[high])
            {
                return false;
            }
            
            low++;
            high--;
        }
        
        return true;
    }
    
    void helper(string &str,vector<string> &temp,
                vector<vector<string>> &res,int index)
    {
        if(index==str.size())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<str.size();i++)
        {
            if(isPalindrome(str,index,i)==true)
            {
                temp.push_back(str.substr(index,i-index+1));
                helper(str,temp,res,i+1);
                temp.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> partition(string str) 
    {
        int n=str.size();
        
        vector<vector<string>> res;
        vector<string> temp;

        int index=0;
        
        helper(str,temp,res,index);
        
        return res;
    }
};
