class Solution {
public:
    int totalFruit(vector<int>& arr) 
    {
        int n=arr.size();
        
        unordered_map<int,int> mp;
        
        int i=0,j=0;
        
        int res=0;
        
        while(j<n)
        {
            mp[arr[j]]++;
            
            if(mp.size() < 2)
            {
                res=max(res,j-i+1);
                j++;
            }
            
            else if(mp.size() == 2)
            {
                res=max(res,j-i+1);
                j++;
            }
            
            else if(mp.size() > 2)
            {
                while(mp.size() > 2)
                {
                    mp[arr[i]]--;
                    
                    if(mp[arr[i]] == 0)
                    {
                        mp.erase(arr[i]);
                    }
                    
                    i++;
                }
                
                j++;
            }
        }
        
        return res;
    }
};
