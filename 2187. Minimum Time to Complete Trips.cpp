class Solution {
public:
    
    bool helper(vector<int> &arr,long long val,int x)
    {
        int n=arr.size();
        
        long long sum=0;
        
        for(int i=0;i<n;i++)
        {   
            sum+=(val/arr[i]);
            
            if(sum>=x)
            {
                return true;
            }
        }

        return false;
    }
    
    long long minimumTime(vector<int>& arr, int x) 
    {
        int n=arr.size();
        
        long long low=0;
        
        long long high=1e14;
        
        long long res=0;
        
        while(low<=high)
        {
            long long mid=low + (high-low)/2;
            
            if(helper(arr,mid,x)==true)
            {
                res=mid;
                high=mid-1;
            }
            
            else
            {
                low=mid+1;
            }
        }
        
        return res;
    }
};
