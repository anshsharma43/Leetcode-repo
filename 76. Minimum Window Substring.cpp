class Solution {
public:
    string minWindow(string str, string t) 
    {
        int n=str.size();
        
        if(t.size() > n)
        {
            return "";
        }
        
        unordered_map<char,int> mp;
        
        for(char ch:t)
        {
            mp[ch]++;
        }
        
        int i=0,j=0;
        
        int count=mp.size();
        
        int start=0,end=0;
        
        int res=INT_MAX;
        
        while(j<n)
        {
            if(mp.find(str[j]) != mp.end())
            {
                mp[str[j]]--;
                
                if(mp[str[j]] == 0)
                {
                    count--;
                }
            }   
            
            if(count > 0)
            {
                j++;
            }
            
            else if(count == 0)
            {
                if(res > j-i+1)
                {
                    res=j-i+1;
                    start=i;
                    end=j;
                }
                
                //res=min(res,j-i+1);
                
                while(count == 0)
                {
                    if(mp.find(str[i]) != mp.end())
                    {   
                        mp[str[i]]++;
                        
                        if(mp[str[i]] == 1)
                        {
                            count++;
                            
                            if(res > j-i+1)
                            {
                                res=j-i+1;
                                start=i;
                                end=j;
                            }
                            
                            //res=min(res,j-i+1);
                        }
                    }
                    
                    i++;
                }
            
                j++;
            }
        }
        
        return res==INT_MAX?"":str.substr(start,res);
    }
};
