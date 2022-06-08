class Solution {
public:
    
    void helper(vector<int> &input,vector<int> &output,int n,vector<vector<int>> &res)
    {
        if(n==0)
        {
            res.push_back(output);
            
            return;
        }
        
        helper(input,output,n-1,res);
        
        output.push_back(input[n-1]);
        
        helper(input,output,n-1,res);
        
        output.pop_back();
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<vector<int>> res;
        
        vector<int> output;
        
        helper(arr,output,n,res);
        
        return res;
    }
};
