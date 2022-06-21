class Solution {
public:
    vector<string> findRepeatedDnaSequences(string str) 
    {
        int n=str.size();
        
        vector<string> res;
        
        int i=0,j=0;
        
        unordered_map<string,int> mp;
        
        while(j<n)
        {
            if(j-i+1<10)
            {
                j++;
            }
            
            else if(j-i+1==10)
            {
                mp[str.substr(i,j-i+1)]++;
                i++;
                j++;
            }
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second > 1)
            {
                res.push_back(it->first);
            }
        }
        
        return res;
    }
};
