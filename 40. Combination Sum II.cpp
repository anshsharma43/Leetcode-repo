class Solution {
public:
    
    void helper(vector<int> &arr,vector<int> &temp,vector<vector<int>> &res,
               int index,int target)
    {
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<arr.size();i++)
        {
            if(i!=index && arr[i]==arr[i-1])
            {
                continue;
            }
            
            if(arr[i] > target)
            {
                break;
            }
            
            temp.push_back(arr[i]);
            helper(arr,temp,res,i+1,target-arr[i]);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) 
    {
        int n=arr.size();
        vector<vector<int>> res;
        vector<int> temp;
        
        sort(arr.begin(),arr.end());
        
        int index=0;
        
        helper(arr,temp,res,index,target);
        
        return res;
    }
};
