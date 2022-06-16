class Solution {
public:
    
    bool isHelper(vector<int> &arr,int val,int k)
    {
        int n=arr.size();
        
        int sum=0;
        int res=1;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>val)
            {
                return false;
            }
            
            sum+=arr[i];
            
            if(sum>val)
            {
                res++;
                sum=arr[i];
            }
        }
        
        return res>k?false:true;
    }
    
    int shipWithinDays(vector<int>& arr, int k) 
    {
        int n=arr.size();
        
        if(n<k)
        {
            return -1;
        }
        
        int maxEle=*max_element(arr.begin(),arr.end());
        int sumAll=accumulate(arr.begin(),arr.end(),0);
        
        int low=0;
        int high=sumAll;
        
        int res=-1;
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            if(isHelper(arr,mid,k)==true)
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
