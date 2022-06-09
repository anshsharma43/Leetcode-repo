class Solution {
public:
    
    void helper(vector<int> &arr,vector<int> &temp,vector<vector<int>> &res,
                unordered_set<int> &s,int n)
    {
        if(n==0)
        {
            res.push_back(temp);
            return;
        }
        
        if(s.count(arr[n-1])>0)
        {
            temp.push_back(arr[n-1]);
        
            s.insert(arr[n-1]);

            helper(arr,temp,res,s,n-1);

            s.erase(arr[n-1]);

            temp.pop_back();
            return;
        }
        
        helper(arr,temp,res,s,n-1);
        
        temp.push_back(arr[n-1]);
        
        s.insert(arr[n-1]);
        
        helper(arr,temp,res,s,n-1);
        
        s.erase(arr[n-1]);
        
        temp.pop_back();
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<vector<int>> res;
        
        unordered_set<int> s;
        
        vector<int> temp;
        
        sort(arr.begin(),arr.end());
        
        helper(arr,temp,res,s,n);
        
        return res;
    }
};
