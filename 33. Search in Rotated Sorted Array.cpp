class Solution {
public:
    
    
    int search(vector<int>& arr, int x) 
    {
        int n=arr.size();
        
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            if(arr[mid]==x)
            {
                return mid;
            }
            
            if(arr[low]<=arr[mid])
            {
                if(x>=arr[low] && x<arr[mid])
                {
                    high=mid-1;
                }
                
                else
                {
                    low=mid+1;
                }
            }
            
            else if(arr[mid]<=arr[high])
            {
                if(x>arr[mid] && x<=arr[high])
                {
                    low=mid+1;
                }
                
                else
                {
                    high=mid-1;
                }
            }
        }
        
        return -1;
    }
};
