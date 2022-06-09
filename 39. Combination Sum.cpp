class Solution {
public:
    
    void helper(vector<int> &arr,vector<int> &temp,vector<vector<int>> &res,
               int n,int target)
    {
        if(n==0)
        {
            if(target==0)
            {
                res.push_back(temp);
            }
            
            return;
        }
        
        if(arr[n-1]<=target)
        {            
            temp.push_back(arr[n-1]);
            helper(arr,temp,res,n,target-arr[n-1]);
            temp.pop_back();
        }
        
        helper(arr,temp,res,n-1,target);
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) 
    {
        int n=arr.size();
        
        vector<vector<int>> res;
        
        vector<int> temp;
        
        helper(arr,temp,res,n,target);
        
        return res;
    }
};
