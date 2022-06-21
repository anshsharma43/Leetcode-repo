class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) 
    {
        int n=arr.size();
        
        int i=0,j=0;
        
        int sum=0;
        
        int res=INT_MAX;;
        
        while(j<n)
        {
            sum+=arr[j];
            
            if(sum<target)
            {
                j++;
            }
            
            else if(sum==target)
            {
                res=min(res,j-i+1);
                j++;
            }
            
            else if(sum>target)
            {
                while(sum>target)
                {
                    res=min(res,j-i+1);
                    sum-=arr[i];
                    i++;
                }
                
                if(sum==target)
                {
                    res=min(res,j-i+1);
                }
                
                j++;
            }
        }
        
        return res==INT_MAX?0:res;
    }
};
