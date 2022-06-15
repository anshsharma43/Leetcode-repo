class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) 
    {
        int n=arr.size();
        
        if(n==1)
        {
            return arr[0];
        }

        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            if(mid-1>=0 && mid+1<n)
            {
                if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
                {
                    return arr[mid];
                }
                
                if(arr[mid]==arr[mid-1])
                {
                    if(mid%2==0)
                    {
                        high=mid-1;
                    }
                    
                    else
                    {
                        low=mid+1;
                    }
                }
                
                else if(arr[mid]==arr[mid+1])
                {
                    if(mid%2==0)
                    {
                        low=mid+1;
                    }
                    
                    else
                    {
                        high=mid-1;
                    }
                }
            }
            
            else
            {
                return arr[mid];
            }
                
        }
        
        return -1;
    }
};
