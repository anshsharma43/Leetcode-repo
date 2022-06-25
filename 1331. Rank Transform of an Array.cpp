class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<int> res=arr;
        
        sort(res.begin(),res.end());
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(res[i])!=mp.end())
            {
                mp[res[i]]=mp.size();
            }
            
            else
            {
                mp[res[i]]=mp.size()+1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            res[i]=mp[arr[i]];
        }
        
        return res;
    }
};
