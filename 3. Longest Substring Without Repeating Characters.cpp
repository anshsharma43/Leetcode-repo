// T - O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string str) 
    {
        int n=str.size();
        
        int l=0,r=0;
        
        unordered_map<char,int> m;
        int res=0;
        
        while(r<n)
        {
            if(m.find(str[r])==m.end())
            {
                res=max(res,r-l+1);
                m[str[r]]=r;
                r++;
            }
            
            else
            {
                l=max(l,m[str[r]]+1);
                res=max(res,r-l+1);
                m[str[r]]=r;
                r++;
            }
        }
        
        return res;
    }
};

//Another Approach : T - O(2n)

/*class Solution {
public:
    int lengthOfLongestSubstring(string str) 
    {
        int n=str.size();
        
        int l=0,r=0;
        
        unordered_map<char,int> m;
        int res=0;
        
        while(r<n)
        {
            if(m.find(str[r]) != m.end())
            {
                char ch=str[r];
                
                while(l<r && m.find(ch) != m.end())
                {
                    m.erase(str[l]);
                    l++;
                }
                
                m[str[r]]=r;
                
                res=max(res,r-l+1);
                r++;
            }
            
            else
            {
                m[str[r]]=r;
                
                res=max(res,r-l+1);
                r++;
            }
        }
        
        return res;
    }
};*/
