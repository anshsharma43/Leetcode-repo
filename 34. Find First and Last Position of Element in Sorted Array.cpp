class Solution {
public:
    
    int helperFirst(vector<int> &arr,int low,int high,int x)
    {
        int res=-1;
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            if(arr[mid]==x)
            {
                res=mid;
                high=mid-1;
            }
            
            else if(arr[mid] > x)
            {
                high=mid-1;
            }
            
            else
            {
                low=mid+1;
            }
        }
        
        return res;
    }
    
    int helperSecond(vector<int> &arr,int low,int high,int x)
    {
        int res=-1;
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            if(arr[mid]==x)
            {
                res=mid;
                low=mid+1;
            }
            
            else if(arr[mid] > x)
            {
                high=mid-1;
            }
            
            else
            {
                low=mid+1;
            }
        }
        
        return res;
    }
    
    vector<int> searchRange(vector<int>& arr, int x) 
    {
        int n=arr.size();
        
        vector<int> res;
        
        int first=helperFirst(arr,0,n-1,x);
        
        res.push_back(first);
        
        if(first==-1)
        {
            res.push_back(-1);
            return res;
        }
        
        int second=helperSecond(arr,0,n-1,x);
        
        res.push_back(second);
        
        return res;
    }
};
