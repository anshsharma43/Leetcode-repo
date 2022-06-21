class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string str) 
    {
        int n=str.size();
        
        int i=0,j=0;
        
        int res=0;
        
        unordered_map<char,int> mp;
        
        while(j<n)
        {
            mp[str[j]]++;
            
            if(mp.size()<2)
            {
                res=max(res,j-i+1);
                j++;
            }
            
            else if(mp.size()==2)
            {
                res=max(res,j-i+1);
                j++;
            }
            
            else if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[str[i]]--;
                    
                    if(mp[str[i]]==0)
                    {
                        mp.erase(str[i]);
                    }
                    
                    i++;
                }
                
                res=max(res,j-i+1);
                
                j++;
            }
        }
        
        return res;
    }
};
