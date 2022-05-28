class Solution {
public:
    vector<int> findAnagrams(string str, string pat) 
    {
        vector<int> arr;
        
        int n=str.size();
        int k=pat.size();
        
        unordered_map<char,int> mp;
        
        for(char ch:pat)
        {
            mp[ch]++;
        }
        
        int i=0,j=0;
        
        int count=mp.size();
        
        while(j<n)
        {
            if(mp.find(str[j]) != mp.end())
            {
                if(mp[str[j]] == 1)
                {
                    count--;
                }
                
                mp[str[j]]--;
            }
            
            if(j-i+1 < k)
            {
                j++;
            }
            
            else
            {
                if(count == 0)
                {
                    arr.emplace_back(i);
                }
                
                if(mp.find(str[i]) != mp.end())
                {
                    if(mp[str[i]] == 0)
                    {
                        count++;
                    }
                    
                    mp[str[i]]++;
                }
                
                i++;
                j++;
            }
        }
        
        return arr;
    }
};
