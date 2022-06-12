class Solution {
public:
    
    // Naive approach
    
    /*void helper(vector<int> &arr,vector<int> &temp,vector<vector<int>> &res,
               unordered_map<int,int> &mp)
    {
        if(mp.size()==arr.size())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=0;i<arr.size();i++)
        {
            if(mp.find(arr[i])==mp.end())
            {
                mp[arr[i]]++;
                temp.push_back(arr[i]);
                helper(arr,temp,res,mp);
                temp.pop_back();
                mp[arr[i]]--;

                if(mp[arr[i]]==0)
                {
                    mp.erase(arr[i]);
                }
            }
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<vector<int>> res;
        vector<int> temp;
        unordered_map<int,int> mp;
        
        helper(arr,temp,res,mp);
        
        return res;
    }*/
    
    //Optimal approach
    
    void helper(vector<int> &arr,vector<int> &temp,vector<vector<int>> &res,
               int index)
    {
        if(index==arr.size())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<arr.size();i++)
        {
            temp.push_back(arr[i]);
            swap(arr[i],arr[index]);
            helper(arr,temp,res,index+1);
            swap(arr[index],arr[i]);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<vector<int>> res;
        vector<int> temp;
        
        int index=0;
        
        helper(arr,temp,res,index);
        
        return res;
    }
};
