class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string str, int k) 
    {
        int n=str.size();
        
        int i=0,j=0;
        
        int res=0;
        
        unordered_map<char,int> mp;
        
        while(j<n)
        {
            mp[str[j]]++;
            
            if(mp.size() < k)
            {
                res=max(res,j-i+1);
                j++;
            }
            
            else if(mp.size() == k)
            {
                res=max(res,j-i+1);
                j++;
            }
            
            else if(mp.size() > k)
            {
                while(mp.size() > k)
                {
                    char ch=str[i];
                    
                    if(mp.find(ch) != mp.end())
                    {
                        mp[ch]--;
                        
                        if(mp[ch] == 0)
                        {
                            mp.erase(ch);
                        }
                    }
                    
                    i++;
                }
                
                j++;
            }
        }
        
        return res;
    }
};
