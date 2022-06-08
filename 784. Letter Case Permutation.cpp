class Solution {
public:
    
    void helper(string &input,string &output,int i,vector<string> &res)
    {
        if(i==input.size())
        {
            res.push_back(output);
            return;
        }
        
        if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z'))
        {
            output.push_back(tolower(input[i]));
            
            helper(input,output,i+1,res);
            
            output[output.size()-1]=toupper(output[output.size()-1]);
            
            helper(input,output,i+1,res);
            
            output.pop_back();
        }
        
        else
        {
            output.push_back(input[i]);
            helper(input,output,i+1,res);
            output.pop_back();
        }
    }
    
    vector<string> letterCasePermutation(string str) 
    {
        int n=str.size();
        
        vector<string> res;
        
        string output="";
        
        helper(str,output,0,res);
        
        return res;
    }
};
