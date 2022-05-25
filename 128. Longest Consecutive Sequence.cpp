class Solution {
public:
    int longestConsecutive(vector<int>& arr) 
    {
        int n=arr.size();
        
        unordered_set<int> s(arr.begin(),arr.end());
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            int x=arr[i]-1;
            
            if(s.count(x) == 0)
            {
                int a=arr[i]+1;
                
                int count=1;
                
                while(s.count(a) > 0)
                {
                    a++;
                    count++;
                }
                
                res=max(res,count);
            }
        }
        
        return res;
    }
};
